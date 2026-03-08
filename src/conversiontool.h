#ifndef CONVERSIONTOOL_H
#define CONVERSIONTOOL_H

#include <QObject>
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QVariant>

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

private:
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
