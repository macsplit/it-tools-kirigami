#ifndef CONVERSIONTOOL_H
#define CONVERSIONTOOL_H

#include <QObject>
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QVariant>
#include <QDomDocument>
#include <QDomNode>
#include <QDomNamedNodeMap>
#include <QRegExp>
#include <QTextDocument>
#include <QColor>
#include <QVariantMap>
#include <QLocale>
#include <QStringList>
#include <QJsonValue>
#include <QJsonObject>
#include <QJsonArray>
#include <cmath>
#include <limits>
#include <sstream>

#include <yaml-cpp/yaml.h>
#include <toml.hpp>

class ConversionTool : public QObject
{
    Q_OBJECT
public:
    explicit ConversionTool(QObject *parent = nullptr) : QObject(parent) {}

    Q_INVOKABLE QString jsonToYaml(const QString &jsonStr) {
        if (jsonStr.trimmed().isEmpty()) return "";
        QJsonParseError error;
        const QJsonDocument doc = QJsonDocument::fromJson(jsonStr.toUtf8(), &error);
        if (error.error != QJsonParseError::NoError) return "Invalid JSON: " + error.errorString();

        YAML::Emitter emitter;
        emitter.SetSeqFormat(YAML::Block);
        emitter.SetMapFormat(YAML::Block);
        emitter.SetStringFormat(YAML::DoubleQuoted);
        emitter << variantToYamlNode(doc.toVariant());
        if (!emitter.good()) return QStringLiteral("Failed to emit YAML");

        return QString::fromUtf8(emitter.c_str()).trimmed();
    }

    Q_INVOKABLE QString yamlToJson(const QString &yamlStr) {
        if (yamlStr.trimmed().isEmpty()) return "";

        try {
            QString error;
            const QVariant parsed = yamlNodeToVariant(YAML::Load(yamlStr.toStdString()), error);
            if (!error.isEmpty()) return error;
            return variantToJsonText(parsed);
        } catch (const YAML::Exception &e) {
            return QStringLiteral("Invalid YAML: ") + QString::fromStdString(e.what());
        }
    }

    Q_INVOKABLE QString formatXml(const QString &xmlStr, int indent) {
        if (xmlStr.trimmed().isEmpty()) return "";
        QDomDocument doc;
        QString errorMsg;
        int errorLine, errorColumn;
        if (!doc.setContent(xmlStr, &errorMsg, &errorLine, &errorColumn)) {
            return QString("Invalid XML: %1 (Line: %2, Column: %3)").arg(errorMsg).arg(errorLine).arg(errorColumn);
        }
        return doc.toString(indent);
    }

    Q_INVOKABLE QString xmlToJson(const QString &xmlStr) {
        if (xmlStr.trimmed().isEmpty()) return "";
        QDomDocument doc;
        if (!doc.setContent(xmlStr)) return "Invalid XML";
        
        QVariantMap root = domToVariant(doc.documentElement());
        QJsonDocument jsonDoc = QJsonDocument::fromVariant(root);
        return jsonDoc.toJson(QJsonDocument::Indented);
    }

    Q_INVOKABLE QString formatSql(const QString &sql) {
        if (sql.trimmed().isEmpty()) return "";

        QString input = sql.trimmed();
        QString result;
        QStringList keywords = {"SELECT", "FROM", "WHERE", "AND", "OR", "GROUP BY", "ORDER BY", "HAVING", "LIMIT", "INSERT INTO", "UPDATE", "DELETE FROM", "VALUES", "SET", "JOIN", "LEFT JOIN", "RIGHT JOIN", "INNER JOIN", "OUTER JOIN", "ON", "UNION"};

        QString prepared = input;
        for (const QString &kw : keywords) {
            prepared.replace(QRegExp("\\b" + kw + "\\b", Qt::CaseInsensitive), "\n" + kw);
        }

        QStringList lines = prepared.split("\n", Qt::SkipEmptyParts);
        for (QString line : lines) {
            line = line.trimmed();
            if (line.isEmpty()) continue;

            bool isMainKw = false;
            for (const QString &kw : keywords) {
                if (line.startsWith(kw, Qt::CaseInsensitive)) {
                    isMainKw = true;
                    break;
                }
            }

            if (isMainKw) {
                result += "\n" + line;
            } else {
                result += " " + line;
            }
        }

        return result.trimmed();
    }

    Q_INVOKABLE QString jsonToXml(const QString &jsonStr) {
        if (jsonStr.trimmed().isEmpty()) return "";
        QJsonParseError error;
        QJsonDocument doc = QJsonDocument::fromJson(jsonStr.toUtf8(), &error);
        if (error.error != QJsonParseError::NoError) return "Invalid JSON";

        QDomDocument xmlDoc;
        QDomElement root = xmlDoc.createElement("root");
        xmlDoc.appendChild(root);
        variantToDom(xmlDoc, root, doc.toVariant());
        return xmlDoc.toString(4);
    }

    Q_INVOKABLE QString jsonToCsv(const QString &jsonStr) {
        if (jsonStr.trimmed().isEmpty()) return "";
        QJsonParseError error;
        QJsonDocument doc = QJsonDocument::fromJson(jsonStr.toUtf8(), &error);
        if (error.error != QJsonParseError::NoError) return "Invalid JSON";

        QVariant var = doc.toVariant();
        if (var.type() != QVariant::List) return "JSON must be an array of objects";

        QVariantList list = var.toList();
        if (list.isEmpty()) return "";

        QStringList headers;
        if (list[0].type() == QVariant::Map) {
            headers = list[0].toMap().keys();
        } else {
            return "JSON must be an array of objects";
        }

        QString res = headers.join(",") + "\n";
        for (const QVariant &item : list) {
            if (item.type() == QVariant::Map) {
                QVariantMap map = item.toMap();
                QStringList row;
                for (const QString &h : headers) {
                    QString val = map[h].toString();
                    if (val.contains(",") || val.contains("\"") || val.contains("\n")) {
                        val = "\"" + val.replace("\"", "\"\"") + "\"";
                    }
                    row.append(val);
                }
                res += row.join(",") + "\n";
            }
        }
        return res.trimmed();
    }

    Q_INVOKABLE QString csvToJson(const QString &csvStr) {
        if (csvStr.trimmed().isEmpty()) return "";

        const QStringList lines = csvStr.trimmed().split(QRegExp("\\r\\n|\\r|\\n"), Qt::SkipEmptyParts);
        if (lines.isEmpty()) return "";
        if (lines.size() < 2) return "[]";

        const QStringList headers = splitCsvLine(lines[0]);
        QVariantList results;

        for (int i = 1; i < lines.size(); ++i) {
            const QStringList values = splitCsvLine(lines[i]);
            QVariantMap row;
            for (int j = 0; j < headers.size(); ++j) {
                row[headers[j].trimmed()] = j < values.size() ? values[j].trimmed() : QString();
            }
            results.append(row);
        }

        return QString::fromUtf8(QJsonDocument::fromVariant(results).toJson(QJsonDocument::Indented));
    }

    Q_INVOKABLE QString jsonToToml(const QString &jsonStr) {
        if (jsonStr.trimmed().isEmpty()) return "";

        QJsonParseError error;
        const QJsonDocument doc = QJsonDocument::fromJson(jsonStr.toUtf8(), &error);
        if (error.error != QJsonParseError::NoError) return "Invalid JSON: " + error.errorString();
        if (!doc.isObject()) return "JSON root must be an object";

        QString conversionError;
        toml::table table;
        if (!fillTomlTable(table, doc.object().toVariantMap(), conversionError)) {
            return conversionError;
        }

        std::ostringstream out;
        out << table;
        return QString::fromStdString(out.str()).trimmed();
    }

    Q_INVOKABLE QString tomlToJson(const QString &tomlStr) {
        if (tomlStr.trimmed().isEmpty()) return "";

        try {
            const QByteArray utf8 = tomlStr.toUtf8();
            const auto parsed = toml::parse(std::string_view(utf8.constData(), static_cast<size_t>(utf8.size())));
            return variantToJsonText(tomlNodeToVariant(parsed));
        } catch (const toml::parse_error &e) {
            return QStringLiteral("Invalid TOML: ") + QString::fromUtf8(e.description().data(), static_cast<int>(e.description().size()));
        }
    }

    Q_INVOKABLE QString markdownToHtml(const QString &md) {
        if (md.trimmed().isEmpty()) return "";
        QTextDocument doc;
        doc.setMarkdown(md);
        return doc.toHtml();
    }

    Q_INVOKABLE QString jsonMinify(const QString &jsonStr) {
        if (jsonStr.trimmed().isEmpty()) return "";
        QJsonParseError error;
        QJsonDocument doc = QJsonDocument::fromJson(jsonStr.toUtf8(), &error);
        if (error.error != QJsonParseError::NoError) return "Invalid JSON format";

        return QString::fromUtf8(doc.toJson(QJsonDocument::Compact));
    }

    Q_INVOKABLE QString jsonFormat(const QString &jsonStr, int indent = 4) {
        if (jsonStr.trimmed().isEmpty()) return "";
        QJsonParseError error;
        QJsonDocument doc = QJsonDocument::fromJson(jsonStr.toUtf8(), &error);
        if (error.error != QJsonParseError::NoError) return "Invalid JSON format";

        QByteArray formatted = doc.toJson(QJsonDocument::Indented);
        if (indent == 4) return QString::fromUtf8(formatted);

        const QString replacement(indent, QLatin1Char(' '));
        return QString::fromUtf8(formatted).replace(QStringLiteral("    "), replacement);
    }

    Q_INVOKABLE QVariantMap colorFromHex(const QString &hexText) {
        const QString hex = hexText.trimmed().toUpper();
        if (!QRegExp("^#[0-9A-F]{6}$").exactMatch(hex)) return QVariantMap();

        const QColor color(hex);
        if (!color.isValid()) return QVariantMap();
        return buildColorResult(color);
    }

    Q_INVOKABLE QVariantMap colorFromRgb(const QString &rgbText) {
        QRegExp rx("^rgb\\((\\d+),\\s*(\\d+),\\s*(\\d+)\\)$");
        if (!rx.exactMatch(rgbText.trimmed())) return QVariantMap();

        bool okR = false, okG = false, okB = false;
        const int r = rx.cap(1).toInt(&okR);
        const int g = rx.cap(2).toInt(&okG);
        const int b = rx.cap(3).toInt(&okB);
        if (!okR || !okG || !okB || r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) return QVariantMap();

        return buildColorResult(QColor(r, g, b));
    }

    Q_INVOKABLE QVariantMap colorFromHsl(const QString &hslText) {
        QRegExp rx("^hsl\\((\\d+),\\s*(\\d+)%?,\\s*(\\d+)%?\\)$");
        if (!rx.exactMatch(hslText.trimmed())) return QVariantMap();

        bool okH = false, okS = false, okL = false;
        const int h = rx.cap(1).toInt(&okH);
        const int s = rx.cap(2).toInt(&okS);
        const int l = rx.cap(3).toInt(&okL);
        if (!okH || !okS || !okL || h < 0 || h > 360 || s < 0 || s > 100 || l < 0 || l > 100) return QVariantMap();

        const QColor color = QColor::fromHsl(h % 360,
                                             qRound(s * 255.0 / 100.0),
                                             qRound(l * 255.0 / 100.0));
        return buildColorResult(color);
    }

    Q_INVOKABLE QString temperatureToKelvin(const QString &scale, const QString &valueText) {
        bool ok = false;
        QString normalized = valueText.trimmed();
        normalized.replace(',', '.');
        const double value = QLocale::c().toDouble(normalized, &ok);
        if (!ok) return QString();

        double kelvin = 0.0;
        if (scale == QStringLiteral("celsius")) kelvin = value + 273.15;
        else if (scale == QStringLiteral("fahrenheit")) kelvin = (value - 32.0) * 5.0 / 9.0 + 273.15;
        else if (scale == QStringLiteral("kelvin")) kelvin = value;
        else if (scale == QStringLiteral("rankine")) kelvin = value / 1.8;
        else return QString();

        if (kelvin < 0.0) kelvin = 0.0;
        return QString::number(kelvin, 'f', 2);
    }

    Q_INVOKABLE QString temperatureFromKelvin(const QString &scale, const QString &kelvinText) {
        bool ok = false;
        const double kelvin = QLocale::c().toDouble(kelvinText, &ok);
        if (!ok) return QStringLiteral("0.00");

        double value = 0.0;
        if (scale == QStringLiteral("celsius")) value = kelvin - 273.15;
        else if (scale == QStringLiteral("fahrenheit")) value = (kelvin - 273.15) * 9.0 / 5.0 + 32.0;
        else if (scale == QStringLiteral("kelvin")) value = kelvin;
        else if (scale == QStringLiteral("rankine")) value = kelvin * 1.8;
        else return QStringLiteral("0.00");

        return QString::number(value, 'f', 2);
    }

private:
    static QString jsonValueToString(const QJsonValue &value, int indentLevel = 0) {
        const QString indent(indentLevel * 2, QLatin1Char(' '));
        const QString childIndent((indentLevel + 1) * 2, QLatin1Char(' '));

        if (value.isNull() || value.isUndefined()) return QStringLiteral("null");
        if (value.isBool()) return value.toBool() ? QStringLiteral("true") : QStringLiteral("false");
        if (value.isDouble()) return QString::number(value.toDouble(), 'g', 15);
        if (value.isString()) {
            QString escaped = value.toString();
            escaped.replace(QStringLiteral("\\"), QStringLiteral("\\\\"));
            escaped.replace(QStringLiteral("\""), QStringLiteral("\\\""));
            escaped.replace(QStringLiteral("\n"), QStringLiteral("\\n"));
            escaped.replace(QStringLiteral("\r"), QStringLiteral("\\r"));
            escaped.replace(QStringLiteral("\t"), QStringLiteral("\\t"));
            return QStringLiteral("\"%1\"").arg(escaped);
        }

        if (value.isArray()) {
            const QJsonArray array = value.toArray();
            if (array.isEmpty()) return QStringLiteral("[]");

            QStringList lines;
            for (const QJsonValue &item : array) {
                lines.append(childIndent + jsonValueToString(item, indentLevel + 1));
            }
            return QStringLiteral("[\n%1\n%2]").arg(lines.join(QStringLiteral(",\n")), indent);
        }

        const QJsonObject object = value.toObject();
        if (object.isEmpty()) return QStringLiteral("{}");

        QStringList lines;
        for (auto it = object.constBegin(); it != object.constEnd(); ++it) {
            lines.append(QStringLiteral("%1\"%2\": %3")
                             .arg(childIndent,
                                  it.key(),
                                  jsonValueToString(it.value(), indentLevel + 1)));
        }
        return QStringLiteral("{\n%1\n%2}").arg(lines.join(QStringLiteral(",\n")), indent);
    }

    static QString variantToJsonText(const QVariant &value) {
        return jsonValueToString(QJsonValue::fromVariant(value)) + QStringLiteral("\n");
    }

    static YAML::Node variantToYamlNode(const QVariant &value) {
        switch (value.type()) {
        case QVariant::Map: {
            YAML::Node node(YAML::NodeType::Map);
            node.SetStyle(YAML::EmitterStyle::Block);
            const QVariantMap map = value.toMap();
            for (auto it = map.constBegin(); it != map.constEnd(); ++it) {
                node[it.key().toStdString()] = variantToYamlNode(it.value());
            }
            return node;
        }
        case QVariant::List: {
            YAML::Node node(YAML::NodeType::Sequence);
            node.SetStyle(YAML::EmitterStyle::Block);
            const QVariantList list = value.toList();
            for (const QVariant &item : list) {
                node.push_back(variantToYamlNode(item));
            }
            return node;
        }
        case QVariant::Bool:
            return YAML::Node(value.toBool());
        case QVariant::Int:
        case QVariant::LongLong:
            return YAML::Node(value.toLongLong());
        case QVariant::UInt:
        case QVariant::ULongLong:
            return YAML::Node(static_cast<long long>(value.toULongLong()));
        case QVariant::Double:
            return YAML::Node(value.toDouble());
        default:
            if (!value.isValid()) return YAML::Node();
            return YAML::Node(value.toString().toStdString());
        }
    }

    static QVariant yamlNodeToVariant(const YAML::Node &node, QString &error) {
        if (!error.isEmpty()) return QVariant();
        if (!node || node.IsNull()) return QVariant();

        if (node.IsSequence()) {
            QVariantList list;
            for (const auto &item : node) {
                list.append(yamlNodeToVariant(item, error));
                if (!error.isEmpty()) return QVariant();
            }
            return list;
        }

        if (node.IsMap()) {
            QVariantMap map;
            for (const auto &entry : node) {
                if (!entry.first.IsScalar()) {
                    error = QStringLiteral("YAML contains non-string mapping keys, which cannot be represented as JSON objects");
                    return QVariant();
                }
                map.insert(QString::fromStdString(entry.first.Scalar()), yamlNodeToVariant(entry.second, error));
                if (!error.isEmpty()) return QVariant();
            }
            return map;
        }

        try { return node.as<bool>(); } catch (const YAML::Exception &) {}
        try { return static_cast<qlonglong>(node.as<long long>()); } catch (const YAML::Exception &) {}
        try { return node.as<double>(); } catch (const YAML::Exception &) {}
        return QString::fromStdString(node.Scalar());
    }

    static bool fillTomlArray(toml::array &array, const QVariantList &list, QString &error) {
        for (const QVariant &item : list) {
            if (!appendTomlValue(array, item, error)) return false;
        }
        return true;
    }

    static bool fillTomlTable(toml::table &table, const QVariantMap &map, QString &error) {
        for (auto it = map.constBegin(); it != map.constEnd(); ++it) {
            if (!insertTomlValue(table, it.key().toStdString(), it.value(), error)) return false;
        }
        return true;
    }

    static bool appendTomlValue(toml::array &array, const QVariant &value, QString &error) {
        switch (value.type()) {
        case QVariant::Map: {
            toml::table child;
            if (!fillTomlTable(child, value.toMap(), error)) return false;
            array.push_back(std::move(child));
            return true;
        }
        case QVariant::List: {
            toml::array child;
            if (!fillTomlArray(child, value.toList(), error)) return false;
            array.push_back(std::move(child));
            return true;
        }
        case QVariant::Bool:
            array.push_back(value.toBool());
            return true;
        case QVariant::Int:
        case QVariant::LongLong:
            array.push_back(static_cast<int64_t>(value.toLongLong()));
            return true;
        case QVariant::UInt:
        case QVariant::ULongLong: {
            const qulonglong unsignedValue = value.toULongLong();
            if (unsignedValue > static_cast<qulonglong>(std::numeric_limits<int64_t>::max())) {
                error = QStringLiteral("JSON number is too large to be represented in TOML");
                return false;
            }
            array.push_back(static_cast<int64_t>(unsignedValue));
            return true;
        }
        case QVariant::Double:
            array.push_back(value.toDouble());
            return true;
        case QVariant::Invalid:
            error = QStringLiteral("JSON null values cannot be represented in TOML");
            return false;
        default:
            array.push_back(value.toString().toStdString());
            return true;
        }
    }

    static bool insertTomlValue(toml::table &table, const std::string &key, const QVariant &value, QString &error) {
        switch (value.type()) {
        case QVariant::Map: {
            toml::table child;
            if (!fillTomlTable(child, value.toMap(), error)) return false;
            table.insert_or_assign(key, std::move(child));
            return true;
        }
        case QVariant::List: {
            toml::array child;
            if (!fillTomlArray(child, value.toList(), error)) return false;
            table.insert_or_assign(key, std::move(child));
            return true;
        }
        case QVariant::Bool:
            table.insert_or_assign(key, value.toBool());
            return true;
        case QVariant::Int:
        case QVariant::LongLong:
            table.insert_or_assign(key, static_cast<int64_t>(value.toLongLong()));
            return true;
        case QVariant::UInt:
        case QVariant::ULongLong: {
            const qulonglong unsignedValue = value.toULongLong();
            if (unsignedValue > static_cast<qulonglong>(std::numeric_limits<int64_t>::max())) {
                error = QStringLiteral("JSON number is too large to be represented in TOML");
                return false;
            }
            table.insert_or_assign(key, static_cast<int64_t>(unsignedValue));
            return true;
        }
        case QVariant::Double:
            table.insert_or_assign(key, value.toDouble());
            return true;
        case QVariant::Invalid:
            error = QStringLiteral("JSON null values cannot be represented in TOML");
            return false;
        default:
            table.insert_or_assign(key, value.toString().toStdString());
            return true;
        }
    }

    static QVariant tomlNodeToVariant(const toml::node &node) {
        if (const auto *table = node.as_table()) {
            QVariantMap map;
            for (const auto &[key, value] : *table) {
                const std::string_view keyText = key.str();
                map.insert(QString::fromUtf8(keyText.data(), static_cast<int>(keyText.size())), tomlNodeToVariant(value));
            }
            return map;
        }

        if (const auto *array = node.as_array()) {
            QVariantList list;
            for (const auto &item : *array) {
                list.append(tomlNodeToVariant(item));
            }
            return list;
        }

        if (const auto *str = node.as_string()) return QString::fromStdString(str->get());
        if (const auto *integer = node.as_integer()) return static_cast<qlonglong>(integer->get());
        if (const auto *floating = node.as_floating_point()) return floating->get();
        if (const auto *boolean = node.as_boolean()) return boolean->get();
        if (const auto *date = node.as_date()) {
            std::ostringstream out;
            out << *date;
            return QString::fromStdString(out.str());
        }
        if (const auto *time = node.as_time()) {
            std::ostringstream out;
            out << *time;
            return QString::fromStdString(out.str());
        }
        if (const auto *dateTime = node.as_date_time()) {
            std::ostringstream out;
            out << *dateTime;
            return QString::fromStdString(out.str());
        }

        return QString();
    }

    void variantToDom(QDomDocument &doc, QDomElement &parent, const QVariant &var) {
        if (var.type() == QVariant::Map) {
            QVariantMap map = var.toMap();
            QMapIterator<QString, QVariant> i(map);
            while (i.hasNext()) {
                i.next();
                QDomElement child = doc.createElement(i.key());
                parent.appendChild(child);
                variantToDom(doc, child, i.value());
            }
        } else if (var.type() == QVariant::List) {
            QVariantList list = var.toList();
            for (const QVariant &item : list) {
                QDomElement child = doc.createElement("item");
                parent.appendChild(child);
                variantToDom(doc, child, item);
            }
        } else {
            QDomText text = doc.createTextNode(var.toString());
            parent.appendChild(text);
        }
    }

    QVariantMap domToVariant(const QDomElement &element) {
        QVariantMap res;
        QDomNamedNodeMap attrs = element.attributes();
        for (int i = 0; i < attrs.length(); i++) {
            QDomNode attr = attrs.item(i);
            res["@" + attr.nodeName()] = attr.nodeValue();
        }
        QDomNodeList children = element.childNodes();
        for (int i = 0; i < children.length(); i++) {
            QDomNode child = children.item(i);
            if (child.isElement()) {
                QDomElement childElem = child.toElement();
                QString name = childElem.tagName();
                QVariant val = domToVariant(childElem);
                if (res.contains(name)) {
                    if (res[name].type() == QVariant::List) {
                        QVariantList list = res[name].toList();
                        list.append(val);
                        res[name] = list;
                    } else {
                        QVariantList list;
                        list.append(res[name]);
                        list.append(val);
                        res[name] = list;
                    }
                } else {
                    res[name] = val;
                }
            } else if (child.isText()) {
                QString text = child.toText().data().trimmed();
                if (!text.isEmpty()) res["#text"] = text;
            }
        }
        return res;
    }

    static QVariantMap buildColorResult(const QColor &color) {
        QVariantMap result;
        result[QStringLiteral("hex")] = color.name(QColor::HexRgb).toUpper();
        result[QStringLiteral("rgb")] = QStringLiteral("rgb(%1, %2, %3)")
                                            .arg(color.red())
                                            .arg(color.green())
                                            .arg(color.blue());

        int h = 0, s = 0, l = 0, a = 0;
        color.getHsl(&h, &s, &l, &a);
        if (h < 0) h = 0;
        result[QStringLiteral("hsl")] = QStringLiteral("hsl(%1, %2%, %3%)")
                                            .arg(h)
                                            .arg(qRound(s * 100.0 / 255.0))
                                            .arg(qRound(l * 100.0 / 255.0));
        return result;
    }

    static QStringList splitCsvLine(const QString &line) {
        QStringList values;
        QString current;
        bool inQuotes = false;

        for (int i = 0; i < line.size(); ++i) {
            const QChar ch = line.at(i);
            if (ch == QLatin1Char('"')) {
                if (inQuotes && i + 1 < line.size() && line.at(i + 1) == QLatin1Char('"')) {
                    current += QLatin1Char('"');
                    ++i;
                } else {
                    inQuotes = !inQuotes;
                }
            } else if (ch == QLatin1Char(',') && !inQuotes) {
                values.append(current);
                current.clear();
            } else {
                current += ch;
            }
        }

        values.append(current);
        return values;
    }
};

#endif // CONVERSIONTOOL_H
