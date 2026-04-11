#ifndef TIMETOOL_H
#define TIMETOOL_H

#include <QObject>
#include <QString>
#include <QStringList>
#include <QDateTime>
#include <QTimeZone>
#include <QVariantMap>
#include <QtGlobal>

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
        QString zoneLabel = describeTimeZone(zone);

        return QStringLiteral("ISO 8601: %1\nDisplay: %2\nTimezone: %3\nUnix seconds: %4\nUnix milliseconds: %5")
            .arg(zoned.toString(Qt::ISODateWithMs))
            .arg(zoned.toString(QStringLiteral("yyyy-MM-dd HH:mm:ss.zzz t")))
            .arg(zoneLabel)
            .arg(utcDateTime.toSecsSinceEpoch())
            .arg(utcDateTime.toMSecsSinceEpoch());
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
        const QString zoneLabel = describeTimeZone(dateTime.timeZone());

        return QStringLiteral("ISO 8601: %1\nTimezone: %2\nUnix seconds: %3\nUnix milliseconds: %4")
            .arg(dateTime.toString(Qt::ISODateWithMs))
            .arg(zoneLabel)
            .arg(utcDateTime.toSecsSinceEpoch())
            .arg(utcDateTime.toMSecsSinceEpoch());
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

};

#endif // TIMETOOL_H
