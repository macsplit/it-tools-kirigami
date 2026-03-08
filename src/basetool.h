#ifndef BASETOOL_H
#define BASETOOL_H

#include <QObject>
#include <QString>
#include <QVector>

class BaseTool : public QObject
{
    Q_OBJECT
public:
    explicit BaseTool(QObject *parent = nullptr) : QObject(parent) {}

    Q_INVOKABLE QString convert(const QString &value, int fromBase, int toBase) {
        if (value.isEmpty()) return "0";
        if (fromBase < 2 || fromBase > 64 || toBase < 2 || toBase > 64) return "Error";

        const QString range = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ+/";
        
        QVector<uint32_t> number;
        number.append(0);

        for (int i = 0; i < value.length(); ++i) {
            int digitVal = range.indexOf(value.at(i));
            if (digitVal == -1 || digitVal >= fromBase) {
                if (fromBase <= 36) {
                    digitVal = range.indexOf(value.at(i).toLower());
                }
                if (digitVal == -1 || digitVal >= fromBase) return "Error";
            }

            uint64_t carry = digitVal;
            for (int j = 0; j < number.size(); ++j) {
                uint64_t res = (uint64_t)number[j] * fromBase + carry;
                number[j] = (uint32_t)(res & 0xFFFFFFFF);
                carry = res >> 32;
            }
            while (carry) {
                number.append((uint32_t)(carry & 0xFFFFFFFF));
                carry >>= 32;
            }
        }

        if (number.size() == 1 && number[0] == 0) return "0";

        QString result;
        while (!(number.size() == 1 && number[0] == 0)) {
            uint64_t rem = 0;
            for (int j = number.size() - 1; j >= 0; --j) {
                uint64_t cur = number[j] + (rem << 32);
                number[j] = (uint32_t)(cur / toBase);
                rem = cur % toBase;
            }
            result.prepend(range.at(rem));
            while (number.size() > 1 && number.last() == 0) {
                number.removeLast();
            }
        }

        return result.isEmpty() ? "0" : result;
    }
};

#endif // BASETOOL_H
