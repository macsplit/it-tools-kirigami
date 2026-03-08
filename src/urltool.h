#ifndef URLTOOL_H
#define URLTOOL_H

#include <QObject>
#include <QString>
#include <QUrl>
#include <QUrlQuery>
#include <QVariantMap>

class UrlTool : public QObject
{
    Q_OBJECT
public:
    explicit UrlTool(QObject *parent = nullptr) : QObject(parent) {}

    Q_INVOKABLE QVariantMap parse(const QString &urlStr) {
        QUrl url(urlStr);
        QVariantMap res;
        if (!url.isValid()) {
            res["valid"] = false;
            return res;
        }
        res["valid"] = true;
        res["scheme"] = url.scheme();
        res["username"] = url.userName();
        res["password"] = url.password();
        res["host"] = url.host();
        res["port"] = url.port() != -1 ? QString::number(url.port()) : "";
        res["path"] = url.path();
        res["query"] = url.query();
        res["fragment"] = url.fragment();

        QVariantMap params;
        QUrlQuery query(url);
        QList<QPair<QString, QString>> items = query.queryItems();
        for (const auto &item : items) {
            params[item.first] = item.second;
        }
        res["params"] = params;

        return res;
    }
};

#endif // URLTOOL_H
