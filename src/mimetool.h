#ifndef MIMETOOL_H
#define MIMETOOL_H

#include <QObject>
#include <QString>
#include <QStringList>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QVariantList>

class MimeTool : public QObject
{
    Q_OBJECT
public:
    explicit MimeTool(QObject *parent = nullptr) : QObject(parent) {}

    Q_INVOKABLE QString search(const QString &queryText) const {
        const QVariantList entries = loadEntries();
        const QString query = queryText.trimmed().toLower();
        QStringList results;

        for (const QVariant &entryVar : entries) {
            const QVariantMap entry = entryVar.toMap();
            const QString mime = entry.value(QStringLiteral("mime")).toString();
            const QString extensions = entry.value(QStringLiteral("extensions")).toString();
            if (query.isEmpty() || mime.toLower().contains(query) || extensions.toLower().contains(query)) {
                results.append(mime + QStringLiteral("\nExtensions: ") + extensions);
            }
        }

        return results.isEmpty() ? QStringLiteral("No matching MIME types found.") : results.join(QStringLiteral("\n\n"));
    }

private:
    static QVariantList loadEntries() {
        QFile file(QStringLiteral(":/contents/ui/mimetypes.json"));
        if (!file.open(QIODevice::ReadOnly)) return QVariantList();
        const QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
        if (!doc.isArray()) return QVariantList();

        QVariantList output;
        const QJsonArray array = doc.array();
        for (const QJsonValue &value : array) {
            const QJsonObject obj = value.toObject();
            QVariantMap row;
            row[QStringLiteral("mime")] = obj.value(QStringLiteral("mime")).toString();
            QStringList exts;
            for (const QJsonValue &ext : obj.value(QStringLiteral("ext")).toArray()) {
                exts.append(ext.toString());
            }
            row[QStringLiteral("extensions")] = exts.join(QStringLiteral(", "));
            output.append(row);
        }
        return output;
    }
};

#endif // MIMETOOL_H
