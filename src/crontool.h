#ifndef CRONTOOL_H
#define CRONTOOL_H

#include <QObject>
#include <QString>
#include <QStringList>
#include <QVariantList>
#include <QDateTime>

class CronTool : public QObject
{
    Q_OBJECT
public:
    explicit CronTool(QObject *parent = nullptr) : QObject(parent) {}

    Q_INVOKABLE QString describe(const QString &cron) const {
        const QStringList parts = cron.trimmed().split(QRegularExpression(QStringLiteral("\\s+")), Qt::SkipEmptyParts);
        if (parts.size() < 5) return QStringLiteral("Invalid expression");

        const QString min = parts[0], hour = parts[1], dom = parts[2], month = parts[3], dow = parts[4];
        QString desc = QStringLiteral("At ");
        if (min == QStringLiteral("*") && hour == QStringLiteral("*")) desc = QStringLiteral("Every minute ");
        else if (min.contains('/') && hour == QStringLiteral("*")) desc = QStringLiteral("Every %1 minutes ").arg(min.section('/', 1, 1));
        else {
            const QString hStr = hour == QStringLiteral("*") ? QStringLiteral("every hour") : QStringLiteral("hour %1").arg(hour);
            const QString mStr = min == QStringLiteral("*") ? QStringLiteral("00") : min.rightJustified(2, QLatin1Char('0'));
            desc += hStr + QStringLiteral(":") + mStr + QStringLiteral(" ");
        }
        if (dom != QStringLiteral("*") || month != QStringLiteral("*") || dow != QStringLiteral("*")) {
            desc += QStringLiteral("on ");
            if (dom != QStringLiteral("*") && dom != QStringLiteral("?")) desc += QStringLiteral("day %1 ").arg(dom);
            if (month != QStringLiteral("*") && month != QStringLiteral("?")) desc += QStringLiteral("of month %1 ").arg(month);
            if (dow != QStringLiteral("*") && dow != QStringLiteral("?")) {
                static const QStringList days = {QStringLiteral("Sunday"), QStringLiteral("Monday"), QStringLiteral("Tuesday"), QStringLiteral("Wednesday"), QStringLiteral("Thursday"), QStringLiteral("Friday"), QStringLiteral("Saturday")};
                bool ok = false;
                const int index = dow.toInt(&ok);
                desc += QStringLiteral("on ") + (ok && index >= 0 && index < days.size() ? days[index] : dow);
            }
        } else {
            desc += QStringLiteral("every day");
        }
        return desc;
    }

    Q_INVOKABLE QVariantList nextOccurrences(const QString &cron, int count) const {
        QVariantList output;
        const QStringList parts = cron.trimmed().split(QRegularExpression(QStringLiteral("\\s+")), Qt::SkipEmptyParts);
        if (parts.size() < 5 || count < 1) return output;

        QDateTime current = QDateTime::currentDateTime();
        current.setTime(QTime(current.time().hour(), current.time().minute(), 0, 0));

        int iterations = 0;
        while (output.size() < count && iterations < 100000) {
            ++iterations;
            current = current.addSecs(60);
            if (matchesCron(current, parts)) {
                output.append(current.toString());
            }
        }

        return output;
    }

private:
    static bool matchesCron(const QDateTime &dateTime, const QStringList &parts) {
        const QDate date = dateTime.date();
        const QTime time = dateTime.time();
        return fieldMatches(time.minute(), parts[0]) &&
               fieldMatches(time.hour(), parts[1]) &&
               fieldMatches(date.day(), parts[2]) &&
               fieldMatches(date.month(), parts[3]) &&
               fieldMatches(date.dayOfWeek() % 7, parts[4]);
    }

    static bool fieldMatches(int value, const QString &pattern) {
        if (pattern == QStringLiteral("*") || pattern == QStringLiteral("?")) return true;
        if (pattern.contains('/')) {
            const QStringList p = pattern.split('/');
            bool okStart = false, okStep = false;
            const int start = p[0] == QStringLiteral("*") ? 0 : p[0].toInt(&okStart);
            const int step = p.value(1).toInt(&okStep);
            return okStep && step > 0 && (p[0] == QStringLiteral("*") || okStart) && value >= start && ((value - start) % step == 0);
        }
        if (pattern.contains('-')) {
            const QStringList r = pattern.split('-');
            bool okMin = false, okMax = false;
            const int min = r.value(0).toInt(&okMin);
            const int max = r.value(1).toInt(&okMax);
            return okMin && okMax && value >= min && value <= max;
        }
        if (pattern.contains(',')) {
            const QStringList list = pattern.split(',');
            for (const QString &entry : list) {
                bool ok = false;
                if (entry.toInt(&ok) == value && ok) return true;
            }
            return false;
        }
        bool ok = false;
        return pattern.toInt(&ok) == value && ok;
    }
};

#endif // CRONTOOL_H
