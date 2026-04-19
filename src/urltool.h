#ifndef URLTOOL_H
#define URLTOOL_H

#include <QObject>
#include <QString>
#include <QUrl>
#include <QUrlQuery>
#include <QVariantMap>
#include <QJsonDocument>
#include <QJsonParseError>

class UrlTool : public QObject
{
    Q_OBJECT
public:
    explicit UrlTool(QObject *parent = nullptr) : QObject(parent) {}

    Q_INVOKABLE QString encode(const QString &text) const {
        return QString::fromUtf8(QUrl::toPercentEncoding(text));
    }

    Q_INVOKABLE QString decode(const QString &text) const {
        const QByteArray bytes = text.toUtf8();
        if (QUrl::fromPercentEncoding(bytes).toUtf8().isEmpty() && !text.isEmpty() && text.contains('%')) {
            // Fall through for obviously invalid percent sequences below.
        }

        for (int i = 0; i < bytes.size(); ++i) {
            if (bytes.at(i) == '%' && (i + 2 >= bytes.size()
                || !QByteArray("0123456789ABCDEFabcdef").contains(bytes.at(i + 1))
                || !QByteArray("0123456789ABCDEFabcdef").contains(bytes.at(i + 2)))) {
                return QStringLiteral("Invalid URL encoding");
            }
        }

        return QUrl::fromPercentEncoding(bytes);
    }

    Q_INVOKABLE QString parseJwtPart(const QString &token, int part) const {
        const QStringList parts = token.split('.');
        if (parts.size() < 2 || part < 0 || part > 1) {
            return QString();
        }

        QByteArray base64 = parts[part].toUtf8();
        base64.replace('-', '+');
        base64.replace('_', '/');
        while (base64.size() % 4) {
            base64.append('=');
        }

        const QByteArray decoded = QByteArray::fromBase64(base64);
        QJsonParseError error;
        const QJsonDocument document = QJsonDocument::fromJson(decoded, &error);
        if (error.error != QJsonParseError::NoError || document.isNull()) {
            return QString();
        }

        return QString::fromUtf8(document.toJson(QJsonDocument::Indented));
    }

    Q_INVOKABLE QString base64Encode(const QString &text) const {
        return QString::fromLatin1(text.toUtf8().toBase64());
    }

    Q_INVOKABLE QString base64Decode(const QString &text) const {
        const QByteArray decoded = QByteArray::fromBase64(text.toLatin1(), QByteArray::AbortOnBase64DecodingErrors);
        if (decoded.isNull()) {
            return QStringLiteral("Error: Invalid Base64");
        }
        return QString::fromUtf8(decoded);
    }

    Q_INVOKABLE QString basicAuthHeader(const QString &username, const QString &password) const {
        return QStringLiteral("Authorization: Basic ") + base64Encode(username + QStringLiteral(":") + password);
    }

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
