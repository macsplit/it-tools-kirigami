#ifndef HASHTOOL_H
#define HASHTOOL_H

#include <QObject>
#include <QString>
#include <QCryptographicHash>

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

private:
    static QString hash(const QString &input, QCryptographicHash::Algorithm algo) {
        if (input.isEmpty()) return QString();
        QByteArray data = input.toUtf8();
        return QString(QCryptographicHash::hash(data, algo).toHex());
    }
};

#endif // HASHTOOL_H
