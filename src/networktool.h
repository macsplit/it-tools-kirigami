#ifndef NETWORKTOOL_H
#define NETWORKTOOL_H

#include <QObject>
#include <QString>
#include <QHostAddress>
#include <QVariantMap>
#include <QStringList>
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

    Q_INVOKABLE QVariantMap expandIpv4Range(const QString &input) {
        QVariantMap result;
        result[QStringLiteral("valid")] = false;

        const QString text = input.trimmed();
        if (text.isEmpty()) {
            result[QStringLiteral("error")] = QStringLiteral("Enter an IPv4 address, range, or CIDR block");
            return result;
        }

        quint32 start = 0;
        quint32 end = 0;
        QString normalizedInput = text;

        if (text.contains(QLatin1Char('/'))) {
            const QStringList parts = text.split(QLatin1Char('/'));
            if (parts.size() != 2) {
                result[QStringLiteral("error")] = QStringLiteral("Invalid CIDR block");
                return result;
            }

            bool okMask = false;
            const int maskBits = parts.at(1).toInt(&okMask);
            QHostAddress address(parts.at(0).trimmed());
            if (!okMask || address.protocol() != QAbstractSocket::IPv4Protocol || maskBits < 0 || maskBits > 32) {
                result[QStringLiteral("error")] = QStringLiteral("Invalid CIDR block");
                return result;
            }

            const quint32 ip = address.toIPv4Address();
            const quint32 mask = (maskBits == 0) ? 0u : (0xFFFFFFFFu << (32 - maskBits));
            start = ip & mask;
            end = start | (~mask);
            normalizedInput = QHostAddress(start).toString() + QStringLiteral("/") + QString::number(maskBits);
        } else if (text.contains(QLatin1Char('-'))) {
            const QStringList parts = text.split(QLatin1Char('-'));
            if (parts.size() != 2) {
                result[QStringLiteral("error")] = QStringLiteral("Invalid IPv4 range");
                return result;
            }

            QHostAddress startAddress(parts.at(0).trimmed());
            QHostAddress endAddress(parts.at(1).trimmed());
            if (startAddress.protocol() != QAbstractSocket::IPv4Protocol
                || endAddress.protocol() != QAbstractSocket::IPv4Protocol) {
                result[QStringLiteral("error")] = QStringLiteral("Invalid IPv4 range");
                return result;
            }

            start = startAddress.toIPv4Address();
            end = endAddress.toIPv4Address();
            if (end < start) {
                result[QStringLiteral("error")] = QStringLiteral("Range end must be greater than or equal to the start");
                return result;
            }
            normalizedInput = QHostAddress(start).toString() + QStringLiteral(" - ") + QHostAddress(end).toString();
        } else {
            QHostAddress address(text);
            if (address.protocol() != QAbstractSocket::IPv4Protocol) {
                result[QStringLiteral("error")] = QStringLiteral("Invalid IPv4 address");
                return result;
            }
            start = end = address.toIPv4Address();
            normalizedInput = address.toString();
        }

        const quint64 count = static_cast<quint64>(end) - static_cast<quint64>(start) + 1u;
        if (count > 65536u) {
            result[QStringLiteral("error")] = QStringLiteral("Range too large to expand safely");
            return result;
        }

        QStringList addresses;
        addresses.reserve(static_cast<int>(count));
        for (quint32 value = start; value <= end; ++value) {
            addresses.append(QHostAddress(value).toString());
            if (value == 0xFFFFFFFFu) {
                break;
            }
        }

        result[QStringLiteral("valid")] = true;
        result[QStringLiteral("input")] = normalizedInput;
        result[QStringLiteral("start")] = QHostAddress(start).toString();
        result[QStringLiteral("end")] = QHostAddress(end).toString();
        result[QStringLiteral("count")] = QString::number(count);
        result[QStringLiteral("items")] = addresses.join(QLatin1Char('\n'));
        return result;
    }
};

#endif // NETWORKTOOL_H
