#ifndef TIMETOOL_H
#define TIMETOOL_H

#include <QObject>
#include <QString>
#include <QStringList>
#include <QDateTime>
#include <QTimeZone>
#include <QVariantMap>
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
