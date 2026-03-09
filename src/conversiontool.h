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

class ConversionTool : public QObject
{
    Q_OBJECT
public:
    explicit ConversionTool(QObject *parent = nullptr) : QObject(parent) {}

    Q_INVOKABLE QString jsonToYaml(const QString &jsonStr) {
        if (jsonStr.trimmed().isEmpty()) return "";
        QJsonParseError error;
        QJsonDocument doc = QJsonDocument::fromJson(jsonStr.toUtf8(), &error);
        if (error.error != QJsonParseError::NoError) return "Invalid JSON: " + error.errorString();
        
        return toYaml(doc.toVariant(), 0).trimmed();
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

    Q_INVOKABLE QString markdownToHtml(const QString &md) {
        if (md.trimmed().isEmpty()) return "";
        QTextDocument doc;
        doc.setMarkdown(md);
        return doc.toHtml();
    }

private:
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

    QString toYaml(const QVariant &var, int indent) {
        QString res;
        QString pad = QString("  ").repeated(indent);
        if (var.type() == QVariant::Map) {
            QVariantMap map = var.toMap();
            QMapIterator<QString, QVariant> i(map);
            while (i.hasNext()) {
                i.next();
                QString key = i.key();
                QVariant val = i.value();
                if (val.type() == QVariant::Map || val.type() == QVariant::List) {
                    res += pad + key + ":\n" + toYaml(val, indent + 1);
                } else {
                    res += pad + key + ": " + val.toString() + "\n";
                }
            }
        } else if (var.type() == QVariant::List) {
            QVariantList list = var.toList();
            for (const QVariant &item : list) {
                if (item.type() == QVariant::Map || item.type() == QVariant::List) {
                    res += pad + "-\n" + toYaml(item, indent + 1);
                } else {
                    res += pad + "- " + item.toString() + "\n";
                }
            }
        } else {
            res += pad + var.toString() + "\n";
        }
        return res;
    }
};

#endif // CONVERSIONTOOL_H
