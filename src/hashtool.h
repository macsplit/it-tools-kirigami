#ifndef HASHTOOL_H
#define HASHTOOL_H

#include <QObject>
#include <QString>
#include <QCryptographicHash>
#include <QMessageAuthenticationCode>
#include <QRandomGenerator>
#include <crypt.h>
#include <cstdlib>

class HashTool : public QObject
{
    Q_OBJECT
public:
    explicit HashTool(QObject *parent = nullptr) : QObject(parent) {}

    Q_INVOKABLE static QString md5(const QString &input) {
        return hash(input, QCryptographicHash::Md5);
    }

    Q_INVOKABLE static QString sha1(const QString &input) {
        return hash(input, QCryptographicHash::Sha1);
    }

    Q_INVOKABLE static QString sha256(const QString &input) {
        return hash(input, QCryptographicHash::Sha256);
    }

    Q_INVOKABLE QString bcryptHash(const QString &input, int cost) const {
        if (input.isEmpty()) return QString();
        if (cost < 4 || cost > 31) return QStringLiteral("Invalid bcrypt cost");

        QByteArray randomBytes(16, Qt::Uninitialized);
        auto *generator = QRandomGenerator::global();
        for (int i = 0; i < randomBytes.size(); ++i) {
            randomBytes[i] = static_cast<char>(generator->bounded(256));
        }

        QByteArray password = input.toUtf8();
        char *setting = crypt_gensalt_ra("$2b$", static_cast<unsigned long>(cost),
                                         randomBytes.constData(), randomBytes.size());
        if (!setting) return QStringLiteral("Failed to generate bcrypt salt");

        void *data = nullptr;
        int size = 0;
        char *hashed = crypt_ra(password.constData(), setting, &data, &size);

        QString result = hashed ? QString::fromLatin1(hashed)
                                : QStringLiteral("Failed to generate bcrypt hash");

        free(setting);
        if (data) {
            free(data);
        }

        return result;
    }

    Q_INVOKABLE bool verifyBcrypt(const QString &input, const QString &hash) const {
        if (input.isEmpty() || hash.isEmpty()) return false;

        QByteArray password = input.toUtf8();
        QByteArray hashedInput = hash.toUtf8();
        void *data = nullptr;
        int size = 0;
        char *hashed = crypt_ra(password.constData(), hashedInput.constData(), &data, &size);
        bool matches = hashed && QString::fromLatin1(hashed) == hash;

        if (data) {
            free(data);
        }

        return matches;
    }

    Q_INVOKABLE QString hmac(const QString &input, const QString &key, const QString &algo) {
        if (input.isEmpty() || key.isEmpty()) return "";
        
        QCryptographicHash::Algorithm hashAlgo = QCryptographicHash::Sha256;
        if (algo == "MD5") hashAlgo = QCryptographicHash::Md5;
        else if (algo == "SHA1") hashAlgo = QCryptographicHash::Sha1;
        else if (algo == "SHA256") hashAlgo = QCryptographicHash::Sha256;
        else if (algo == "SHA512") hashAlgo = QCryptographicHash::Sha512;

        QMessageAuthenticationCode code(hashAlgo);
        code.setKey(key.toUtf8());
        code.addData(input.toUtf8());
        return QString(code.result().toHex());
    }

private:
    static QString hash(const QString &input, QCryptographicHash::Algorithm algo) {
        if (input.isEmpty()) return QString();
        QByteArray data = input.toUtf8();
        return QString(QCryptographicHash::hash(data, algo).toHex());
    }
};

#endif // HASHTOOL_H
