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

private:
    QVariantMap domToVariant(const QDomElement &element) {
        QVariantMap res;
        
        // Attributes
        QDomNamedNodeMap attrs = element.attributes();
        for (int i = 0; i < attrs.length(); i++) {
            QDomNode attr = attrs.item(i);
            res["@" + attr.nodeName()] = attr.nodeValue();
        }
        
        // Children
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
                if (!text.isEmpty()) {
                    if (res.isEmpty() && children.length() == 1) {
                        // If only text, return as string (simplified)
                        // But for consistency we return as map if we have attributes
                    }
                    res["#text"] = text;
                }
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
