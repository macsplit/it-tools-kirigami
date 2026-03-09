#ifndef HASHTOOL_H
#define HASHTOOL_H

#include <QObject>
#include <QString>
#include <QCryptographicHash>
#include <QMessageAuthenticationCode>

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
