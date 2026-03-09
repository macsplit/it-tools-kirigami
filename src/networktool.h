#ifndef NETWORKTOOL_H
#define NETWORKTOOL_H

#include <QObject>
#include <QString>
#include <QHostAddress>
#include <QVariantMap>
#include <cmath>

class NetworkTool : public QObject
{
    Q_OBJECT
public:
    explicit NetworkTool(QObject *parent = nullptr) : QObject(parent) {}

    Q_INVOKABLE QVariantMap ipv4Convert(const QString &ipStr) {
        QHostAddress addr(ipStr);
        QVariantMap res;
        if (addr.isNull() || addr.protocol() != QAbstractSocket::IPv4Protocol) {
            res["valid"] = false;
            return res;
        }
        res["valid"] = true;
        quint32 ipv4 = addr.toIPv4Address();
        res["decimal"] = QString::number(ipv4);
        res["hex"] = "0x" + QString::number(ipv4, 16).toUpper().rightJustified(8, '0');
        
        QString bin;
        for (int i = 31; i >= 0; i--) {
            bin += (ipv4 & (1 << i)) ? "1" : "0";
            if (i > 0 && i % 8 == 0) bin += ".";
        }
        res["binary"] = bin;
        res["ipv6"] = "::ffff:" + addr.toString();
        return res;
    }

    Q_INVOKABLE QVariantMap ipv4Subnet(const QString &cidr) {
        QVariantMap res;
        QStringList parts = cidr.split('/');
        if (parts.isEmpty()) return res;
        
        QHostAddress addr(parts[0]);
        if (addr.isNull() || addr.protocol() != QAbstractSocket::IPv4Protocol) return res;
        
        int maskBits = (parts.size() > 1) ? parts[1].toInt() : 32;
        if (maskBits < 0 || maskBits > 32) return res;

        quint32 ip = addr.toIPv4Address();
        quint32 mask = (maskBits == 0) ? 0 : (0xFFFFFFFF << (32 - maskBits));
        quint32 network = ip & mask;
        quint32 broadcast = network | (~mask);
        quint32 first = (maskBits <= 30) ? (network + 1) : network;
        quint32 last = (maskBits <= 30) ? (broadcast - 1) : broadcast;
        quint32 size = (maskBits <= 31) ? (broadcast - network + 1) : 1;

        res["valid"] = true;
        res["netmask"] = QHostAddress(mask).toString();
        res["network"] = QHostAddress(network).toString();
        res["broadcast"] = QHostAddress(broadcast).toString();
        res["first"] = QHostAddress(first).toString();
        res["last"] = QHostAddress(last).toString();
        res["size"] = QString::number(size);
        res["cidr"] = "/" + QString::number(maskBits);
        
        QString binMask;
        for (int i = 31; i >= 0; i--) {
            binMask += (mask & (1u << i)) ? "1" : "0";
            if (i > 0 && i % 8 == 0) binMask += ".";
        }
        res["maskBinary"] = binMask;

        return res;
    }
};

#endif // NETWORKTOOL_H
