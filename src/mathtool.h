#ifndef MATHTOOL_H
#define MATHTOOL_H

#include <QObject>
#include <QString>
#include <QLocale>
#include <QChar>
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

    Q_INVOKABLE QString evaluateExpression(const QString &expressionText) const {
        struct Parser {
            QString text;
            int index = 0;
            bool ok = true;

            void skipWhitespace() {
                while (index < text.size() && text.at(index).isSpace()) {
                    ++index;
                }
            }

            bool match(QChar ch) {
                skipWhitespace();
                if (index < text.size() && text.at(index) == ch) {
                    ++index;
                    return true;
                }
                return false;
            }

            double parseExpression() {
                double value = parseTerm();
                while (ok) {
                    skipWhitespace();
                    if (match(QLatin1Char('+'))) {
                        value += parseTerm();
                    } else if (match(QLatin1Char('-'))) {
                        value -= parseTerm();
                    } else {
                        break;
                    }
                }
                return value;
            }

            double parseTerm() {
                double value = parsePower();
                while (ok) {
                    skipWhitespace();
                    if (match(QLatin1Char('*'))) {
                        value *= parsePower();
                    } else if (match(QLatin1Char('/'))) {
                        const double divisor = parsePower();
                        if (qFuzzyIsNull(divisor)) {
                            ok = false;
                            return 0.0;
                        }
                        value /= divisor;
                    } else if (match(QLatin1Char('%'))) {
                        const double divisor = parsePower();
                        if (qFuzzyIsNull(divisor)) {
                            ok = false;
                            return 0.0;
                        }
                        value = std::fmod(value, divisor);
                    } else {
                        break;
                    }
                }
                return value;
            }

            double parsePower() {
                double base = parseUnary();
                skipWhitespace();
                if (!ok) {
                    return 0.0;
                }
                if (match(QLatin1Char('^'))) {
                    const double exponent = parsePower();
                    base = std::pow(base, exponent);
                }
                return base;
            }

            double parseUnary() {
                skipWhitespace();
                if (match(QLatin1Char('+'))) {
                    return parseUnary();
                }
                if (match(QLatin1Char('-'))) {
                    return -parseUnary();
                }
                return parsePrimary();
            }

            double parsePrimary() {
                skipWhitespace();
                if (match(QLatin1Char('('))) {
                    const double value = parseExpression();
                    if (!match(QLatin1Char(')'))) {
                        ok = false;
                        return 0.0;
                    }
                    return value;
                }

                const int start = index;
                bool hasDigits = false;
                bool hasDot = false;
                while (index < text.size()) {
                    const QChar ch = text.at(index);
                    if (ch.isDigit()) {
                        hasDigits = true;
                        ++index;
                    } else if ((ch == QLatin1Char('.') || ch == QLatin1Char(',')) && !hasDot) {
                        hasDot = true;
                        ++index;
                    } else {
                        break;
                    }
                }

                if (!hasDigits) {
                    ok = false;
                    return 0.0;
                }

                bool numberOk = false;
                const double value = QLocale::c().toDouble(text.mid(start, index - start).replace(',', '.'), &numberOk);
                ok = numberOk;
                return value;
            }
        };

        Parser parser{expressionText};
        const double result = parser.parseExpression();
        parser.skipWhitespace();
        if (!parser.ok || parser.index != parser.text.size() || !std::isfinite(result)) {
            return QString();
        }

        return formatNumber(result);
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
