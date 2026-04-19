#ifndef IDTOOL_H
#define IDTOOL_H

#include <QObject>
#include <QString>
#include <QStringList>
#include <QRandomGenerator>
#include <QUuid>
#include <QUrl>

class IdTool : public QObject
{
    Q_OBJECT
public:
    explicit IdTool(QObject *parent = nullptr) : QObject(parent) {}

    Q_INVOKABLE QString generateToken(int length) const {
        if (length < 1) length = 1;
        if (length > 128) length = 128;
        static const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+";
        auto *generator = QRandomGenerator::global();
        QString result;
        result.reserve(length);
        for (int i = 0; i < length; ++i) {
            result.append(QLatin1Char(charset[generator->bounded(int(sizeof(charset) - 1))]));
        }
        return result;
    }

    Q_INVOKABLE QString generateMacAddress() const {
        auto *generator = QRandomGenerator::global();
        QStringList parts;
        for (int i = 0; i < 6; ++i) {
            parts.append(QStringLiteral("%1").arg(generator->bounded(256), 2, 16, QLatin1Char('0')).toUpper());
        }
        return parts.join(QStringLiteral(":"));
    }

    Q_INVOKABLE QString generatePort() const {
        return QString::number(QRandomGenerator::global()->bounded(1024, 65536));
    }

    Q_INVOKABLE QString generateUuid() const {
        return QUuid::createUuid().toString(QUuid::WithoutBraces);
    }

    Q_INVOKABLE QString generateUlid() const {
        return encodeTime(QDateTime::currentMSecsSinceEpoch()) + encodeRandom(16);
    }

    Q_INVOKABLE QString generateUlids(int quantity, const QString &format) const {
        if (quantity < 1) {
            quantity = 1;
        }
        if (quantity > 100) {
            quantity = 100;
        }

        QStringList items;
        items.reserve(quantity);
        for (int i = 0; i < quantity; ++i) {
            items.append(generateUlid());
        }

        if (format.compare(QStringLiteral("JSON"), Qt::CaseInsensitive) == 0) {
            QStringList escaped;
            for (const QString &item : items) {
                escaped.append(QStringLiteral("\"") + item + QStringLiteral("\""));
            }
            return QStringLiteral("[\n  ") + escaped.join(QStringLiteral(",\n  ")) + QStringLiteral("\n]");
        }

        return items.join(QStringLiteral("\n"));
    }

    Q_INVOKABLE QString wifiQrPayload(const QString &ssid,
                                      const QString &password,
                                      const QString &encryptionType) const {
        const QString trimmedSsid = escapeWifiField(ssid.trimmed());
        const QString normalizedEncryption = encryptionType.compare(QStringLiteral("None"), Qt::CaseInsensitive) == 0
            ? QStringLiteral("nopass")
            : encryptionType.trimmed().toUpper();
        const QString escapedPassword = normalizedEncryption == QStringLiteral("nopass")
            ? QString()
            : escapeWifiField(password);

        return QStringLiteral("WIFI:S:%1;T:%2;P:%3;;")
            .arg(trimmedSsid, normalizedEncryption, escapedPassword);
    }

    Q_INVOKABLE QString wifiQrImageSource(const QString &ssid,
                                          const QString &password,
                                          const QString &encryptionType) const {
        return QStringLiteral("image://qrcode/") + QUrl::toPercentEncoding(
            wifiQrPayload(ssid, password, encryptionType));
    }

private:
    static QChar alphabetAt(int index) {
        static const char alphabet[] = "0123456789ABCDEFGHJKMNPQRSTVWXYZ";
        return QLatin1Char(alphabet[index]);
    }

    static QString encodeTime(qint64 timestamp) {
        QString chars(10, QLatin1Char('0'));
        quint64 value = static_cast<quint64>(timestamp);
        for (int i = 9; i >= 0; --i) {
            chars[i] = alphabetAt(static_cast<int>(value % 32ULL));
            value /= 32ULL;
        }
        return chars;
    }

    static QString encodeRandom(int length) {
        QString result;
        result.reserve(length);
        auto *generator = QRandomGenerator::global();
        for (int i = 0; i < length; ++i) {
            result.append(alphabetAt(generator->bounded(32)));
        }
        return result;
    }

    static QString escapeWifiField(QString value) {
        value.replace(QStringLiteral("\\"), QStringLiteral("\\\\"));
        value.replace(QStringLiteral(";"), QStringLiteral("\\;"));
        value.replace(QStringLiteral(","), QStringLiteral("\\,"));
        value.replace(QStringLiteral(":"), QStringLiteral("\\:"));
        value.replace(QStringLiteral("\""), QStringLiteral("\\\""));
        return value;
    }
};

#endif // IDTOOL_H
