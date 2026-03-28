#ifndef TOOLMANAGER_H
#define TOOLMANAGER_H

#include <QObject>
#include <QVariantList>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QDebug>

class ToolManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariantList tools READ tools NOTIFY toolsChanged)

public:
    explicit ToolManager(QObject *parent = nullptr) : QObject(parent) {
        loadTools();
    }

    QVariantList tools() const { return m_tools; }

    Q_INVOKABLE QVariantList loadJson(const QString &path) {
        QString fullPath = path;
        if (!path.startsWith(":/") && !path.startsWith("qrc:/")) {
            fullPath = ":/contents/ui/" + path;
        }
        
        QFile file(fullPath.replace("qrc:/", ":/"));
        if (!file.open(QIODevice::ReadOnly)) {
            qWarning() << "Could not open JSON file:" << fullPath;
            return QVariantList();
        }

        QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
        if (doc.isNull()) {
            qWarning() << "Failed to parse JSON file:" << fullPath;
            return QVariantList();
        }

        return doc.toVariant().toList();
    }

signals:
    void toolsChanged();

private:
    void loadTools() {
        m_tools = loadJson(":/contents/ui/tools.json");
        emit toolsChanged();
    }

    QVariantList m_tools;
};

#endif // TOOLMANAGER_H
