#ifndef MATHTOOL_H
#define MATHTOOL_H

#include <QObject>
#include <QString>
#include <QLocale>
#include <cmath>

class MathTool : public QObject
{
    Q_OBJECT
public:
    explicit MathTool(QObject *parent = nullptr) : QObject(parent) {}

    Q_INVOKABLE QString percentOf(const QString &percentText, const QString &valueText) const {
        bool okPercent = false;
        bool okValue = false;
        const double percent = parseNumber(percentText, &okPercent);
        const double value = parseNumber(valueText, &okValue);
        if (!okPercent || !okValue) {
            return QString();
        }

        return formatNumber((percent / 100.0) * value);
    }

    Q_INVOKABLE QString whatPercent(const QString &partText, const QString &wholeText) const {
        bool okPart = false;
        bool okWhole = false;
        const double part = parseNumber(partText, &okPart);
        const double whole = parseNumber(wholeText, &okWhole);
        if (!okPart || !okWhole || qFuzzyIsNull(whole)) {
            return QString();
        }

        return formatNumber((part / whole) * 100.0, QStringLiteral("%"));
    }

    Q_INVOKABLE QString percentageChange(const QString &fromText, const QString &toText) const {
        bool okFrom = false;
        bool okTo = false;
        const double fromValue = parseNumber(fromText, &okFrom);
        const double toValue = parseNumber(toText, &okTo);
        if (!okFrom || !okTo || qFuzzyIsNull(fromValue)) {
            return QString();
        }

        return formatNumber(((toValue - fromValue) / fromValue) * 100.0, QStringLiteral("%"));
    }

private:
    static double parseNumber(QString text, bool *ok) {
        text = text.trimmed();
        text.replace(',', '.');
        const double value = QLocale::c().toDouble(text, ok);
        return value;
    }

    static QString formatNumber(double value, const QString &suffix = QString()) {
        if (!std::isfinite(value)) {
            return QString();
        }

        QString text = QString::number(value, 'f', 6);
        while (text.contains('.') && text.endsWith('0')) {
            text.chop(1);
        }
        if (text.endsWith('.')) {
            text.chop(1);
        }

        return text + suffix;
    }
};

#endif // MATHTOOL_H
