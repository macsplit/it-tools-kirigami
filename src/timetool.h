#ifndef TIMETOOL_H
#define TIMETOOL_H

#include <QObject>
#include <QString>
#include <QStringList>
#include <QDateTime>
#include <QTimeZone>
#include <QLocale>
#include <QtGlobal>
#include <QRegularExpression>

class TimeTool : public QObject
{
    Q_OBJECT
public:
    explicit TimeTool(QObject *parent = nullptr) : QObject(parent) {}

    Q_INVOKABLE QString formatEpoch(const QString &input, const QString &timeZoneId) const {
        QString trimmed = input.trimmed();
        if (trimmed.isEmpty()) return QString();

        bool ok = false;
        qint64 value = trimmed.toLongLong(&ok);
        if (!ok) return QStringLiteral("Invalid Unix timestamp");

        QTimeZone zone = resolveTimeZone(timeZoneId);
        if (!zone.isValid()) return QStringLiteral("Invalid timezone");

        bool isMilliseconds = trimmed.length() > 10;
        QDateTime utcDateTime = isMilliseconds
            ? QDateTime::fromMSecsSinceEpoch(value, Qt::UTC)
            : QDateTime::fromSecsSinceEpoch(value, Qt::UTC);

        if (!utcDateTime.isValid()) return QStringLiteral("Invalid Unix timestamp");

        QDateTime zoned = utcDateTime.toTimeZone(zone);
        return describeDateTime(zoned);
    }

    Q_INVOKABLE QString parseNaturalDate(const QString &input, const QString &timeZoneId) const {
        const QTimeZone zone = resolveTimeZone(timeZoneId);
        if (!zone.isValid()) {
            return QStringLiteral("Invalid timezone");
        }

        const QDateTime reference = QDateTime::currentDateTimeUtc().toTimeZone(zone);
        return parseNaturalDateInternal(input, zone, reference);
    }

    Q_INVOKABLE QString parseNaturalDateWithReference(const QString &input,
                                                      const QString &timeZoneId,
                                                      const QString &referenceIso) const {
        const QTimeZone zone = resolveTimeZone(timeZoneId);
        if (!zone.isValid()) {
            return QStringLiteral("Invalid timezone");
        }

        QDateTime reference = QDateTime::fromString(referenceIso.trimmed(), Qt::ISODateWithMs);
        if (!reference.isValid()) {
            reference = QDateTime::fromString(referenceIso.trimmed(), Qt::ISODate);
        }

        if (!reference.isValid()) {
            return QStringLiteral("Invalid reference date/time");
        }

        return parseNaturalDateInternal(input, zone, reference.toTimeZone(zone));
    }

    Q_INVOKABLE QVariantMap buildParseContext(const QString &timeZoneId) const {
        QVariantMap context;
        QTimeZone zone = resolveTimeZone(timeZoneId);
        if (!zone.isValid()) {
            context.insert(QStringLiteral("error"), QStringLiteral("Invalid timezone"));
            return context;
        }

        const QDateTime targetReference = QDateTime::currentDateTimeUtc().toTimeZone(zone);
        const QDateTime systemReference(targetReference.date(),
                                        targetReference.time(),
                                        QTimeZone::systemTimeZone());

        context.insert(QStringLiteral("referenceEpochMs"), systemReference.toMSecsSinceEpoch());
        context.insert(QStringLiteral("timezoneOffsetMinutes"), zone.offsetFromUtc(targetReference) / 60);
        return context;
    }

    Q_INVOKABLE QString formatParsedDate(const QVariantMap &components, const QString &timeZoneId) const {
        if (components.isEmpty()) {
            return QStringLiteral("Could not parse date string");
        }

        QTimeZone zone = resolveTimeZone(timeZoneId);
        if (!zone.isValid()) {
            return QStringLiteral("Invalid timezone");
        }

        const int year = components.value(QStringLiteral("year")).toInt();
        const int month = components.value(QStringLiteral("month")).toInt();
        const int day = components.value(QStringLiteral("day")).toInt();
        if (!year || !month || !day) {
            return QStringLiteral("Could not parse date string");
        }

        const bool hourCertain = components.value(QStringLiteral("hourCertain")).toBool();
        const int hour = hourCertain ? components.value(QStringLiteral("hour")).toInt() : 0;
        const int minute = hourCertain ? components.value(QStringLiteral("minute")).toInt() : 0;
        const int second = hourCertain ? components.value(QStringLiteral("second")).toInt() : 0;
        const int millisecond = hourCertain ? components.value(QStringLiteral("millisecond")).toInt() : 0;

        const QDate date(year, month, day);
        const QTime time(hour, minute, second, millisecond);
        if (!date.isValid() || !time.isValid()) {
            return QStringLiteral("Could not parse date string");
        }

        const QDateTime dateTime(date, time, zone);
        if (!dateTime.isValid()) {
            return QStringLiteral("Could not parse date string");
        }

        const QDateTime utcDateTime = dateTime.toUTC();
        Q_UNUSED(utcDateTime)
        return describeDateTime(dateTime);
    }

    Q_INVOKABLE QString convertDateTime(const QString &input,
                                        const QString &inputFormat,
                                        const QString &timeZoneId) const {
        const QString trimmed = input.trimmed();
        if (trimmed.isEmpty()) {
            return QString();
        }

        const QTimeZone zone = resolveTimeZone(timeZoneId);
        if (!zone.isValid()) {
            return QStringLiteral("Invalid timezone");
        }

        const QDateTime parsed = parseDateTimeInput(trimmed, inputFormat, zone);
        if (!parsed.isValid()) {
            return QStringLiteral("Could not parse date/time");
        }

        return describeDateTime(parsed.toTimeZone(zone));
    }

private:
    struct ParsedTime {
        QTime value;
        bool isValid = false;
    };

    static QTimeZone resolveTimeZone(const QString &input) {
        QString trimmed = input.trimmed();
        if (trimmed.isEmpty() || trimmed.compare(QStringLiteral("local"), Qt::CaseInsensitive) == 0) {
            return QTimeZone::systemTimeZone();
        }

        if (trimmed.compare(QStringLiteral("utc"), Qt::CaseInsensitive) == 0) {
            return QTimeZone::utc();
        }

        const QString upper = trimmed.toUpper();
        if (upper == QStringLiteral("GMT")) return QTimeZone::utc();
        if (upper == QStringLiteral("BST")) return QTimeZone("Europe/London");
        if (upper == QStringLiteral("PST") || upper == QStringLiteral("PDT")) return QTimeZone("America/Los_Angeles");
        if (upper == QStringLiteral("MST") || upper == QStringLiteral("MDT")) return QTimeZone("America/Denver");
        if (upper == QStringLiteral("CST") || upper == QStringLiteral("CDT")) return QTimeZone("America/Chicago");
        if (upper == QStringLiteral("EST") || upper == QStringLiteral("EDT")) return QTimeZone("America/New_York");

        return QTimeZone(trimmed.toUtf8());
    }

    static QString describeTimeZone(const QTimeZone &zone) {
        if (zone == QTimeZone::utc()) {
            return QStringLiteral("UTC");
        }

        return QString::fromUtf8(zone.id());
    }

    static QString normalizeNaturalDateInput(const QString &input) {
        QString text = input.trimmed().toLower();
        text.replace(QRegularExpression(QStringLiteral("\\b(\\d{1,2})(st|nd|rd|th)\\b")), QStringLiteral("\\1"));
        text.replace(QLatin1Char(','), QLatin1Char(' '));
        text.replace(QRegularExpression(QStringLiteral("\\b(on|at)\\b")), QStringLiteral(" "));
        text.replace(QRegularExpression(QStringLiteral("\\s+")), QStringLiteral(" "));
        return text.trimmed();
    }

    static ParsedTime parseTimeToken(const QString &input) {
        const QString text = input.trimmed();
        if (text.isEmpty()) {
            return ParsedTime();
        }

        if (text == QStringLiteral("noon")) {
            return ParsedTime{QTime(12, 0), true};
        }

        if (text == QStringLiteral("midnight")) {
            return ParsedTime{QTime(0, 0), true};
        }

        static const QRegularExpression amPmPattern(
            QStringLiteral("^(\\d{1,2})(?::(\\d{2}))?(?::(\\d{2}))?\\s*(am|pm)$")
        );
        const QRegularExpressionMatch amPmMatch = amPmPattern.match(text);
        if (amPmMatch.hasMatch()) {
            int hour = amPmMatch.captured(1).toInt();
            const int minute = amPmMatch.captured(2).isEmpty() ? 0 : amPmMatch.captured(2).toInt();
            const int second = amPmMatch.captured(3).isEmpty() ? 0 : amPmMatch.captured(3).toInt();
            const QString meridiem = amPmMatch.captured(4);

            if (hour < 1 || hour > 12 || minute > 59 || second > 59) {
                return ParsedTime();
            }

            if (hour == 12) {
                hour = 0;
            }
            if (meridiem == QStringLiteral("pm")) {
                hour += 12;
            }

            const QTime time(hour, minute, second);
            return ParsedTime{time, time.isValid()};
        }

        static const QRegularExpression twentyFourHourPattern(
            QStringLiteral("^(\\d{1,2}):(\\d{2})(?::(\\d{2}))?$")
        );
        const QRegularExpressionMatch twentyFourHourMatch = twentyFourHourPattern.match(text);
        if (twentyFourHourMatch.hasMatch()) {
            const int hour = twentyFourHourMatch.captured(1).toInt();
            const int minute = twentyFourHourMatch.captured(2).toInt();
            const int second = twentyFourHourMatch.captured(3).isEmpty() ? 0 : twentyFourHourMatch.captured(3).toInt();
            const QTime time(hour, minute, second);
            return ParsedTime{time, time.isValid()};
        }

        return ParsedTime();
    }

    static QDate parseExplicitDate(const QString &input) {
        const QString text = input.trimmed();
        const QDate isoDate = QDate::fromString(text, QStringLiteral("yyyy-MM-dd"));
        if (isoDate.isValid()) {
            return isoDate;
        }

        const QLocale english(QLocale::English);
        const QStringList formats = {
            QStringLiteral("d MMM yyyy"),
            QStringLiteral("d MMMM yyyy"),
            QStringLiteral("MMM d yyyy"),
            QStringLiteral("MMMM d yyyy")
        };

        for (const QString &format : formats) {
            const QDate date = english.toDate(text, format);
            if (date.isValid()) {
                return date;
            }
        }

        return QDate();
    }

    static QDate parseRelativeDate(const QString &input, const QDate &referenceDate) {
        const QString text = input.trimmed();
        if (text == QStringLiteral("today")) {
            return referenceDate;
        }
        if (text == QStringLiteral("tomorrow")) {
            return referenceDate.addDays(1);
        }
        if (text == QStringLiteral("yesterday")) {
            return referenceDate.addDays(-1);
        }

        static const QRegularExpression relativeCalendarPattern(
            QStringLiteral("^(next|last|this)\\s+(week|month|year)$")
        );
        const QRegularExpressionMatch relativeCalendarMatch = relativeCalendarPattern.match(text);
        if (relativeCalendarMatch.hasMatch()) {
            const QString direction = relativeCalendarMatch.captured(1);
            const QString unit = relativeCalendarMatch.captured(2);

            if (unit == QStringLiteral("week")) {
                if (direction == QStringLiteral("next")) {
                    return referenceDate.addDays(7);
                }
                if (direction == QStringLiteral("last")) {
                    return referenceDate.addDays(-7);
                }
                return referenceDate;
            }

            if (unit == QStringLiteral("month")) {
                if (direction == QStringLiteral("next")) {
                    return referenceDate.addMonths(1);
                }
                if (direction == QStringLiteral("last")) {
                    return referenceDate.addMonths(-1);
                }
                return referenceDate;
            }

            if (direction == QStringLiteral("next")) {
                return referenceDate.addYears(1);
            }
            if (direction == QStringLiteral("last")) {
                return referenceDate.addYears(-1);
            }
            return referenceDate;
        }

        static const QStringList weekdays = {
            QString(),
            QStringLiteral("monday"),
            QStringLiteral("tuesday"),
            QStringLiteral("wednesday"),
            QStringLiteral("thursday"),
            QStringLiteral("friday"),
            QStringLiteral("saturday"),
            QStringLiteral("sunday")
        };
        static const QRegularExpression weekdayPattern(
            QStringLiteral("^(next|last|this)\\s+(monday|tuesday|wednesday|thursday|friday|saturday|sunday)$")
        );
        const QRegularExpressionMatch weekdayMatch = weekdayPattern.match(text);
        if (!weekdayMatch.hasMatch()) {
            return QDate();
        }

        const QString direction = weekdayMatch.captured(1);
        const int targetDay = weekdays.indexOf(weekdayMatch.captured(2));
        const int currentDay = referenceDate.dayOfWeek();
        int delta = targetDay - currentDay;

        if (direction == QStringLiteral("next")) {
            if (delta <= 0) {
                delta += 7;
            }
        } else if (direction == QStringLiteral("last")) {
            if (delta >= 0) {
                delta -= 7;
            }
        }

        return referenceDate.addDays(delta);
    }

    static QDateTime parseRelativeOffset(const QString &input,
                                         const QTimeZone &zone,
                                         const QDateTime &reference) {
        static const QRegularExpression relativePattern(
            QStringLiteral("^(?:in\\s+)?(\\d+)\\s+(minute|minutes|hour|hours|day|days|week|weeks)(?:\\s+ago)?$")
        );
        const QRegularExpressionMatch match = relativePattern.match(input);
        if (!match.hasMatch()) {
            return QDateTime();
        }

        const int amount = match.captured(1).toInt();
        const QString unit = match.captured(2);
        const bool isAgo = input.endsWith(QStringLiteral(" ago"));
        const int sign = isAgo ? -1 : 1;

        if (unit.startsWith(QStringLiteral("minute"))) {
            return reference.addSecs(sign * amount * 60);
        }
        if (unit.startsWith(QStringLiteral("hour"))) {
            return reference.addSecs(sign * amount * 60 * 60);
        }
        if (unit.startsWith(QStringLiteral("day"))) {
            return reference.addDays(sign * amount);
        }
        if (unit.startsWith(QStringLiteral("week"))) {
            return reference.addDays(sign * amount * 7);
        }

        Q_UNUSED(zone)
        return QDateTime();
    }

    static QDateTime buildDateTime(const QDate &date, const ParsedTime &time, const QTimeZone &zone) {
        const QTime resolvedTime = time.isValid ? time.value : QTime(0, 0);
        if (!date.isValid() || !resolvedTime.isValid()) {
            return QDateTime();
        }

        return QDateTime(date, resolvedTime, zone);
    }

    static QDateTime parseDateAndOptionalTime(const QString &input,
                                              const QTimeZone &zone,
                                              const QDateTime &reference) {
        const QString text = input.trimmed();
        const QDate explicitDate = parseExplicitDate(text);
        if (explicitDate.isValid()) {
            return buildDateTime(explicitDate, ParsedTime(), zone);
        }

        const QDate relativeDate = parseRelativeDate(text, reference.date());
        if (relativeDate.isValid()) {
            return buildDateTime(relativeDate, ParsedTime(), zone);
        }

        static const QRegularExpression trailingTimePattern(
            QStringLiteral("^(.*)\\s+(noon|midnight|\\d{1,2}(?::\\d{2})?(?::\\d{2})?\\s*(?:am|pm)?|\\d{1,2}:\\d{2}(?::\\d{2})?)$")
        );
        const QRegularExpressionMatch trailingTimeMatch = trailingTimePattern.match(text);
        if (trailingTimeMatch.hasMatch()) {
            const QDate date = parseExplicitDate(trailingTimeMatch.captured(1).trimmed()).isValid()
                ? parseExplicitDate(trailingTimeMatch.captured(1).trimmed())
                : parseRelativeDate(trailingTimeMatch.captured(1).trimmed(), reference.date());
            const ParsedTime time = parseTimeToken(trailingTimeMatch.captured(2));
            return buildDateTime(date, time, zone);
        }

        static const QRegularExpression leadingTimePattern(
            QStringLiteral("^(noon|midnight|\\d{1,2}(?::\\d{2})?(?::\\d{2})?\\s*(?:am|pm)?)\\s+(.+)$")
        );
        const QRegularExpressionMatch leadingTimeMatch = leadingTimePattern.match(text);
        if (leadingTimeMatch.hasMatch()) {
            const ParsedTime time = parseTimeToken(leadingTimeMatch.captured(1));
            const QDate date = parseExplicitDate(leadingTimeMatch.captured(2).trimmed()).isValid()
                ? parseExplicitDate(leadingTimeMatch.captured(2).trimmed())
                : parseRelativeDate(leadingTimeMatch.captured(2).trimmed(), reference.date());
            return buildDateTime(date, time, zone);
        }

        return QDateTime();
    }

    static QDateTime parseNaturalDateTime(const QString &input,
                                          const QTimeZone &zone,
                                          const QDateTime &reference) {
        // Keep natural-date parsing deterministic and grammar-based.
        // Support only forms with one clear meaning and explicit timezone semantics.
        // If a phrase needs broad heuristics or has multiple plausible readings,
        // leave it unsupported rather than guessing.
        const QString text = normalizeNaturalDateInput(input);
        if (text.isEmpty()) {
            return QDateTime();
        }

        if (text == QStringLiteral("now") || text == QStringLiteral("right now")) {
            return reference;
        }

        const QDateTime relativeOffset = parseRelativeOffset(text, zone, reference);
        if (relativeOffset.isValid()) {
            return relativeOffset;
        }

        const QDateTime dateAndTime = parseDateAndOptionalTime(text, zone, reference);
        if (dateAndTime.isValid()) {
            return dateAndTime;
        }

        const ParsedTime timeOnly = parseTimeToken(text);
        if (timeOnly.isValid) {
            return buildDateTime(reference.date(), timeOnly, zone);
        }

        return QDateTime();
    }

    static QString parseNaturalDateInternal(const QString &input,
                                            const QTimeZone &zone,
                                            const QDateTime &reference) {
        const QDateTime parsed = parseNaturalDateTime(input, zone, reference);
        if (!parsed.isValid()) {
            return QStringLiteral("Could not parse date string");
        }

        return describeDateTime(parsed.toTimeZone(zone));
    }

    static bool hasExplicitOffset(const QString &input) {
        static const QRegularExpression offsetPattern(
            QStringLiteral("(Z|[+-]\\d{2}:?\\d{2})$"),
            QRegularExpression::CaseInsensitiveOption
        );
        return offsetPattern.match(input.trimmed()).hasMatch();
    }

    static QDateTime parseUsingFormat(const QString &input, const QString &format, const QTimeZone &zone) {
        const QDateTime parsed = QDateTime::fromString(input, format);
        if (!parsed.isValid()) {
            return QDateTime();
        }

        return QDateTime(parsed.date(), parsed.time(), zone);
    }

    static QDateTime parseUsingFormats(const QString &input,
                                       const QStringList &formats,
                                       const QTimeZone &zone) {
        for (int i = 0; i < formats.size(); ++i) {
            const QDateTime parsed = parseUsingFormat(input, formats.at(i), zone);
            if (parsed.isValid()) {
                return parsed;
            }
        }

        return QDateTime();
    }

    static QDateTime parseDateTimeInput(const QString &input,
                                        const QString &inputFormat,
                                        const QTimeZone &zone) {
        const QString format = inputFormat.trimmed();

        if (format == QStringLiteral("Unix seconds")) {
            bool ok = false;
            const qint64 seconds = input.toLongLong(&ok);
            return ok ? QDateTime::fromSecsSinceEpoch(seconds, Qt::UTC).toTimeZone(zone) : QDateTime();
        }

        if (format == QStringLiteral("Unix milliseconds")) {
            bool ok = false;
            const qint64 milliseconds = input.toLongLong(&ok);
            return ok ? QDateTime::fromMSecsSinceEpoch(milliseconds, Qt::UTC).toTimeZone(zone) : QDateTime();
        }

        if (format == QStringLiteral("ISO 8601")) {
            if (hasExplicitOffset(input)) {
                QDateTime parsed = QDateTime::fromString(input, Qt::ISODateWithMs);
                if (!parsed.isValid()) {
                    parsed = QDateTime::fromString(input, Qt::ISODate);
                }
                return parsed.isValid() ? parsed.toTimeZone(zone) : QDateTime();
            }

            return parseUsingFormats(input,
                                     QStringList()
                                         << QStringLiteral("yyyy-MM-dd'T'HH:mm:ss.zzz")
                                         << QStringLiteral("yyyy-MM-dd'T'HH:mm:ss")
                                         << QStringLiteral("yyyy-MM-dd'T'HH:mm")
                                         << QStringLiteral("yyyy-MM-dd"),
                                     zone);
        }

        if (format == QStringLiteral("ISO 9075")) {
            return parseUsingFormats(input,
                                     QStringList()
                                         << QStringLiteral("yyyy-MM-dd HH:mm:ss.zzz")
                                         << QStringLiteral("yyyy-MM-dd HH:mm:ss")
                                         << QStringLiteral("yyyy-MM-dd HH:mm")
                                         << QStringLiteral("yyyy-MM-dd"),
                                     zone);
        }

        if (format == QStringLiteral("RFC 2822 / HTTP")) {
            QDateTime parsed = QDateTime::fromString(input, Qt::RFC2822Date);
            return parsed.isValid() ? parsed.toTimeZone(zone) : QDateTime();
        }

        if (format == QStringLiteral("Date only")) {
            const QDate date = QDate::fromString(input, QStringLiteral("yyyy-MM-dd"));
            return date.isValid() ? QDateTime(date, QTime(0, 0, 0, 0), zone) : QDateTime();
        }

        if (format == QStringLiteral("Mongo ObjectID")) {
            bool ok = false;
            const uint seconds = input.left(8).toUInt(&ok, 16);
            return ok ? QDateTime::fromSecsSinceEpoch(seconds, Qt::UTC).toTimeZone(zone) : QDateTime();
        }

        if (format == QStringLiteral("Excel date/time")) {
            bool ok = false;
            const double excelValue = input.toDouble(&ok);
            if (!ok) {
                return QDateTime();
            }

            const qint64 milliseconds = qRound64((excelValue - 25569.0) * 86400.0 * 1000.0);
            return QDateTime::fromMSecsSinceEpoch(milliseconds, Qt::UTC).toTimeZone(zone);
        }

        return QDateTime();
    }

    static QString describeDateTime(const QDateTime &dateTime) {
        if (!dateTime.isValid()) {
            return QStringLiteral("Could not parse date/time");
        }

        const QDateTime utcDateTime = dateTime.toUTC();
        const QString zoneLabel = describeTimeZone(dateTime.timeZone());
        const qint64 excelMilliseconds = utcDateTime.toMSecsSinceEpoch();
        const double excelValue = (excelMilliseconds / 1000.0 / 60.0 / 60.0 / 24.0) + 25569.0;
        const QString mongoObjectId = QStringLiteral("%1").arg(
            static_cast<quint32>(utcDateTime.toSecsSinceEpoch()),
            8,
            16,
            QLatin1Char('0')
        ) + QStringLiteral("0000000000000000");

        return QStringLiteral(
            "ISO 8601: %1\n"
            "ISO 9075: %2\n"
            "RFC 2822: %3\n"
            "Date only: %4\n"
            "Display: %5\n"
            "Timezone: %6\n"
            "Unix seconds: %7\n"
            "Unix milliseconds: %8\n"
            "Excel date/time: %9\n"
            "Mongo ObjectID: %10"
        )
            .arg(dateTime.toString(Qt::ISODateWithMs))
            .arg(dateTime.toString(QStringLiteral("yyyy-MM-dd HH:mm:ss.zzz")))
            .arg(dateTime.toUTC().toString(Qt::RFC2822Date))
            .arg(dateTime.date().toString(QStringLiteral("yyyy-MM-dd")))
            .arg(dateTime.toString(QStringLiteral("yyyy-MM-dd HH:mm:ss.zzz t")))
            .arg(zoneLabel)
            .arg(utcDateTime.toSecsSinceEpoch())
            .arg(utcDateTime.toMSecsSinceEpoch())
            .arg(QString::number(excelValue, 'f', 6))
            .arg(mongoObjectId.toLower());
    }

};

#endif // TIMETOOL_H
