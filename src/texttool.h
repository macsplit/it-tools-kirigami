#ifndef TEXTTOOL_H
#define TEXTTOOL_H

#include <QObject>
#include <QString>
#include <QRegularExpression>
#include <QStringList>
#include <QHash>
#include <QUrl>
#include <QByteArray>
#include <QVariantMap>

class TextTool : public QObject
{
    Q_OBJECT
public:
    explicit TextTool(QObject *parent = nullptr) : QObject(parent) {}

    Q_INVOKABLE QString convertCase(const QString &text, const QString &mode) const {
        if (mode == QStringLiteral("upper")) {
            return text.toUpper();
        }
        if (mode == QStringLiteral("lower")) {
            return text.toLower();
        }
        return convertPreservingSymbols(text, mode);
    }

    Q_INVOKABLE QString convertToNato(const QString &text) const {
        static const QStringList alphabet = {
            QStringLiteral("Alpha"), QStringLiteral("Bravo"), QStringLiteral("Charlie"), QStringLiteral("Delta"),
            QStringLiteral("Echo"), QStringLiteral("Foxtrot"), QStringLiteral("Golf"), QStringLiteral("Hotel"),
            QStringLiteral("India"), QStringLiteral("Juliet"), QStringLiteral("Kilo"), QStringLiteral("Lima"),
            QStringLiteral("Mike"), QStringLiteral("November"), QStringLiteral("Oscar"), QStringLiteral("Papa"),
            QStringLiteral("Quebec"), QStringLiteral("Romeo"), QStringLiteral("Sierra"), QStringLiteral("Tango"),
            QStringLiteral("Uniform"), QStringLiteral("Victor"), QStringLiteral("Whiskey"), QStringLiteral("X-ray"),
            QStringLiteral("Yankee"), QStringLiteral("Zulu")
        };

        QStringList output;
        output.reserve(text.size());
        for (const QChar ch : text) {
            const ushort code = ch.toLower().unicode();
            if (code >= 'a' && code <= 'z') {
                output.append(alphabet.at(code - 'a'));
            } else {
                output.append(QString(ch));
            }
        }
        return output.join(QStringLiteral(" "));
    }

    Q_INVOKABLE QString htmlEntitiesEncode(const QString &text) const {
        const QHash<QChar, QString> namedEntities = {
            {QLatin1Char('&'), QStringLiteral("&amp;")},
            {QLatin1Char('<'), QStringLiteral("&lt;")},
            {QLatin1Char('>'), QStringLiteral("&gt;")},
            {QLatin1Char('"'), QStringLiteral("&quot;")},
            {QLatin1Char('\''), QStringLiteral("&#39;")},
            {QChar(0x00A0), QStringLiteral("&nbsp;")},
            {QChar(0x00A9), QStringLiteral("&copy;")},
            {QChar(0x00AE), QStringLiteral("&reg;")},
            {QChar(0x00B0), QStringLiteral("&deg;")},
            {QChar(0x00B7), QStringLiteral("&middot;")},
            {QChar(0x00D7), QStringLiteral("&times;")},
            {QChar(0x00F7), QStringLiteral("&divide;")},
            {QChar(0x2013), QStringLiteral("&ndash;")},
            {QChar(0x2014), QStringLiteral("&mdash;")},
            {QChar(0x2018), QStringLiteral("&lsquo;")},
            {QChar(0x2019), QStringLiteral("&rsquo;")},
            {QChar(0x201C), QStringLiteral("&ldquo;")},
            {QChar(0x201D), QStringLiteral("&rdquo;")},
            {QChar(0x2022), QStringLiteral("&bull;")},
            {QChar(0x2026), QStringLiteral("&hellip;")},
            {QChar(0x20AC), QStringLiteral("&euro;")},
            {QChar(0x2122), QStringLiteral("&trade;")}
        };

        QString output;
        output.reserve(text.size() * 2);
        for (const QChar ch : text) {
            const QString named = namedEntities.value(ch);
            if (!named.isEmpty()) {
                output += named;
            } else if (ch.unicode() < 32 && ch != QLatin1Char('\n') && ch != QLatin1Char('\r') && ch != QLatin1Char('\t')) {
                output += QStringLiteral("&#x%1;").arg(ch.unicode(), 0, 16).toUpper();
            } else if (ch.unicode() > 127) {
                output += QStringLiteral("&#x%1;").arg(ch.unicode(), 0, 16).toUpper();
            } else {
                output += ch;
            }
        }
        return output;
    }

    Q_INVOKABLE QString htmlEntitiesDecode(const QString &text) const {
        static const QHash<QString, QChar> namedEntities = {
            {QStringLiteral("amp"), QLatin1Char('&')},
            {QStringLiteral("lt"), QLatin1Char('<')},
            {QStringLiteral("gt"), QLatin1Char('>')},
            {QStringLiteral("quot"), QLatin1Char('"')},
            {QStringLiteral("apos"), QLatin1Char('\'')},
            {QStringLiteral("nbsp"), QChar(0x00A0)},
            {QStringLiteral("copy"), QChar(0x00A9)},
            {QStringLiteral("reg"), QChar(0x00AE)},
            {QStringLiteral("deg"), QChar(0x00B0)},
            {QStringLiteral("middot"), QChar(0x00B7)},
            {QStringLiteral("times"), QChar(0x00D7)},
            {QStringLiteral("divide"), QChar(0x00F7)},
            {QStringLiteral("ndash"), QChar(0x2013)},
            {QStringLiteral("mdash"), QChar(0x2014)},
            {QStringLiteral("lsquo"), QChar(0x2018)},
            {QStringLiteral("rsquo"), QChar(0x2019)},
            {QStringLiteral("ldquo"), QChar(0x201C)},
            {QStringLiteral("rdquo"), QChar(0x201D)},
            {QStringLiteral("bull"), QChar(0x2022)},
            {QStringLiteral("hellip"), QChar(0x2026)},
            {QStringLiteral("euro"), QChar(0x20AC)},
            {QStringLiteral("trade"), QChar(0x2122)}
        };

        QString output;
        output.reserve(text.size());
        static const QRegularExpression entityPattern(QStringLiteral("&(#x[0-9A-Fa-f]+|#\\d+|[A-Za-z][A-Za-z0-9]+);"));
        int lastIndex = 0;
        QRegularExpressionMatchIterator it = entityPattern.globalMatch(text);
        while (it.hasNext()) {
            const QRegularExpressionMatch match = it.next();
            output += text.mid(lastIndex, match.capturedStart() - lastIndex);

            const QString entity = match.captured(1);
            QString replacement = match.captured(0);
            if (entity.startsWith(QStringLiteral("#x"), Qt::CaseInsensitive)) {
                bool ok = false;
                const uint codePoint = entity.mid(2).toUInt(&ok, 16);
                if (ok && codePoint <= 0x10FFFF) {
                    replacement = QString::fromUcs4(&codePoint, 1);
                }
            } else if (entity.startsWith(QLatin1Char('#'))) {
                bool ok = false;
                const uint codePoint = entity.mid(1).toUInt(&ok, 10);
                if (ok && codePoint <= 0x10FFFF) {
                    replacement = QString::fromUcs4(&codePoint, 1);
                }
            } else if (namedEntities.contains(entity)) {
                replacement = namedEntities.value(entity);
            } else if (entity == QStringLiteral("#39")) {
                replacement = QStringLiteral("'");
            }

            output += replacement;
            lastIndex = match.capturedEnd();
        }
        output += text.mid(lastIndex);
        return output;
    }

    Q_INVOKABLE QString slugify(const QString &text) const {
        QString output = text.toLower().trimmed();
        output.remove(QRegularExpression(QStringLiteral("[^\\w\\s-]")));
        output.replace(QRegularExpression(QStringLiteral("[\\s_-]+")), QStringLiteral("-"));
        output.remove(QRegularExpression(QStringLiteral("^-+|-+$")));
        return output;
    }

    Q_INVOKABLE QVariantMap normalizeEmail(const QString &input) const {
        QVariantMap result;
        const QString text = input.trimmed();
        result[QStringLiteral("valid")] = false;

        const int atIndex = text.indexOf(QLatin1Char('@'));
        if (text.isEmpty() || atIndex <= 0 || atIndex != text.lastIndexOf(QLatin1Char('@')) || atIndex == text.size() - 1) {
            result[QStringLiteral("error")] = QStringLiteral("Enter a valid email address");
            return result;
        }

        QString localPart = text.left(atIndex).trimmed();
        QString domain = text.mid(atIndex + 1).trimmed().toLower();
        if (localPart.isEmpty() || domain.isEmpty()) {
            result[QStringLiteral("error")] = QStringLiteral("Enter a valid email address");
            return result;
        }

        const QByteArray aceDomain = QUrl::toAce(domain);
        if (!aceDomain.isEmpty()) {
            domain = QString::fromLatin1(aceDomain);
        }

        static const QRegularExpression localRegex(QStringLiteral("^[A-Za-z0-9.!#$%&'*+/=?^_`{|}~-]+$"));
        static const QRegularExpression domainRegex(QStringLiteral("^(?=.{1,253}$)([A-Za-z0-9](?:[A-Za-z0-9-]{0,61}[A-Za-z0-9])?)(\\.([A-Za-z0-9](?:[A-Za-z0-9-]{0,61}[A-Za-z0-9])?))*$"));

        if (!localRegex.match(localPart).hasMatch() || !domainRegex.match(domain).hasMatch()) {
            result[QStringLiteral("error")] = QStringLiteral("Enter a valid email address");
            return result;
        }

        QString provider = QStringLiteral("generic");
        QString notes;
        if (domain == QStringLiteral("googlemail.com")) {
            domain = QStringLiteral("gmail.com");
            provider = QStringLiteral("gmail");
            notes = QStringLiteral("Normalized googlemail.com to gmail.com and removed Gmail aliases.");
        } else if (domain == QStringLiteral("gmail.com")) {
            provider = QStringLiteral("gmail");
            notes = QStringLiteral("Removed Gmail dot aliases and plus addressing.");
        }

        if (provider == QStringLiteral("gmail")) {
            localPart = localPart.toLower();
            const int plusIndex = localPart.indexOf(QLatin1Char('+'));
            if (plusIndex >= 0) {
                localPart = localPart.left(plusIndex);
            }
            localPart.remove(QLatin1Char('.'));
        }

        result[QStringLiteral("valid")] = true;
        result[QStringLiteral("localPart")] = localPart;
        result[QStringLiteral("domain")] = domain;
        result[QStringLiteral("provider")] = provider;
        result[QStringLiteral("normalized")] = localPart + QStringLiteral("@") + domain;
        result[QStringLiteral("notes")] = notes;
        return result;
    }

    Q_INVOKABLE QVariantMap textStatistics(const QString &text) const {
        QVariantMap result;
        result[QStringLiteral("characters")] = text.size();
        const QString trimmed = text.trimmed();
        result[QStringLiteral("words")] = trimmed.isEmpty()
            ? 0
            : trimmed.split(QRegularExpression(QStringLiteral("\\s+")), Qt::SkipEmptyParts).size();
        result[QStringLiteral("lines")] = text.isEmpty()
            ? 0
            : text.split(QRegularExpression(QStringLiteral("\\r\\n|\\r|\\n"))).size();
        return result;
    }

    Q_INVOKABLE QString loremIpsum() const {
        return QStringLiteral("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.");
    }

    Q_INVOKABLE QString obfuscate(const QString &text, int keepFirst, int keepLast, bool keepSpaces) const {
        if (text.isEmpty()) {
            return QString();
        }

        QString result;
        result.reserve(text.size());
        for (int i = 0; i < text.size(); ++i) {
            const bool preserve = i < keepFirst || i >= text.size() - keepLast;
            if (preserve) {
                result += text.at(i);
            } else if (keepSpaces && text.at(i) == QLatin1Char(' ')) {
                result += QLatin1Char(' ');
            } else {
                result += QLatin1Char('*');
            }
        }
        return result;
    }

    Q_INVOKABLE QString transformList(const QString &input,
                                      bool trimItems,
                                      bool removeDuplicates,
                                      bool lowerCase,
                                      bool reverseList,
                                      const QString &separator,
                                      const QString &itemPrefix,
                                      const QString &itemSuffix,
                                      const QString &listPrefix,
                                      const QString &listSuffix) const {
        if (input.isEmpty()) {
            return QString();
        }

        QStringList items = input.split(QRegularExpression(QStringLiteral("\\r\\n|\\r|\\n")), Qt::KeepEmptyParts);
        for (QString &item : items) {
            if (trimItems) item = item.trimmed();
            if (lowerCase) item = item.toLower();
        }

        items.erase(std::remove_if(items.begin(), items.end(), [](const QString &item) { return item.isEmpty(); }), items.end());

        if (removeDuplicates) {
            QStringList deduped;
            for (const QString &item : items) {
                if (!deduped.contains(item)) deduped.append(item);
            }
            items = deduped;
        }

        if (reverseList) {
            std::reverse(items.begin(), items.end());
        }

        for (QString &item : items) {
            item = itemPrefix + item + itemSuffix;
        }

        return listPrefix + items.join(separator) + listSuffix;
    }

    Q_INVOKABLE QString chmodOctal(bool ownerRead, bool ownerWrite, bool ownerExec,
                                   bool groupRead, bool groupWrite, bool groupExec,
                                   bool publicRead, bool publicWrite, bool publicExec) const {
        return QStringLiteral("%1%2%3")
            .arg((ownerRead ? 4 : 0) + (ownerWrite ? 2 : 0) + (ownerExec ? 1 : 0))
            .arg((groupRead ? 4 : 0) + (groupWrite ? 2 : 0) + (groupExec ? 1 : 0))
            .arg((publicRead ? 4 : 0) + (publicWrite ? 2 : 0) + (publicExec ? 1 : 0));
    }

    Q_INVOKABLE QString chmodSymbolic(bool ownerRead, bool ownerWrite, bool ownerExec,
                                      bool groupRead, bool groupWrite, bool groupExec,
                                      bool publicRead, bool publicWrite, bool publicExec) const {
        QString result;
        result.reserve(9);
        result += ownerRead ? QLatin1Char('r') : QLatin1Char('-');
        result += ownerWrite ? QLatin1Char('w') : QLatin1Char('-');
        result += ownerExec ? QLatin1Char('x') : QLatin1Char('-');
        result += groupRead ? QLatin1Char('r') : QLatin1Char('-');
        result += groupWrite ? QLatin1Char('w') : QLatin1Char('-');
        result += groupExec ? QLatin1Char('x') : QLatin1Char('-');
        result += publicRead ? QLatin1Char('r') : QLatin1Char('-');
        result += publicWrite ? QLatin1Char('w') : QLatin1Char('-');
        result += publicExec ? QLatin1Char('x') : QLatin1Char('-');
        return result;
    }

    Q_INVOKABLE QString textToBinary(const QString &text) const {
        if (text.isEmpty()) {
            return QString();
        }

        QStringList parts;
        parts.reserve(text.size());
        for (int i = 0; i < text.size(); ++i) {
            const QString binary = QString::number(text.at(i).unicode(), 2).rightJustified(8, QLatin1Char('0'));
            parts.append(binary);
        }
        return parts.join(QStringLiteral(" "));
    }

    Q_INVOKABLE QString binaryToText(const QString &binaryText) const {
        const QString trimmed = binaryText.trimmed();
        if (trimmed.isEmpty()) {
            return QString();
        }

        const QStringList parts = trimmed.split(QRegularExpression(QStringLiteral("\\s+")), Qt::SkipEmptyParts);
        QString result;
        result.reserve(parts.size());

        for (const QString &part : parts) {
            bool ok = false;
            const uint value = part.toUInt(&ok, 2);
            if (!ok || part.isEmpty()) {
                return QStringLiteral("Invalid binary");
            }
            result.append(QChar(static_cast<ushort>(value)));
        }

        return result;
    }

    Q_INVOKABLE QString arabicToRoman(const QString &numberText) const {
        bool ok = false;
        int value = numberText.toInt(&ok);
        if (!ok || value < 1 || value > 3999) {
            return QString();
        }

        struct RomanEntry { int value; const char *symbol; };
        static const RomanEntry table[] = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };

        QString result;
        for (const RomanEntry &entry : table) {
            while (value >= entry.value) {
                result += QLatin1String(entry.symbol);
                value -= entry.value;
            }
        }
        return result;
    }

    Q_INVOKABLE QString romanToArabic(const QString &romanText) const {
        const QString text = romanText.trimmed().toUpper();
        if (text.isEmpty()) {
            return QString();
        }

        auto valueFor = [](QChar ch) -> int {
            switch (ch.toLatin1()) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
            }
        };

        int total = 0;
        for (int i = 0; i < text.size(); ++i) {
            const int current = valueFor(text.at(i));
            if (current == 0) {
                return QString();
            }

            const int next = (i + 1 < text.size()) ? valueFor(text.at(i + 1)) : 0;
            if (next > current) {
                total += next - current;
                ++i;
            } else {
                total += current;
            }
        }

        const QString normalized = arabicToRoman(QString::number(total));
        if (normalized != text) {
            return QString();
        }

        return QString::number(total);
    }

    Q_INVOKABLE QString textToUnicode(const QString &text) const {
        if (text.isEmpty()) {
            return QString();
        }

        QString output;
        output.reserve(text.size() * 6);
        for (int i = 0; i < text.size(); ++i) {
            output += QStringLiteral("&#") + QString::number(text.at(i).unicode()) + QLatin1Char(';');
        }
        return output;
    }

    Q_INVOKABLE QString unicodeToText(const QString &unicodeText) const {
        if (unicodeText.isEmpty()) {
            return QString();
        }

        QString output = unicodeText;
        static const QRegularExpression entityPattern(QStringLiteral(R"(&#(\d+);)"));
        QRegularExpressionMatchIterator it = entityPattern.globalMatch(unicodeText);

        int offset = 0;
        while (it.hasNext()) {
            const QRegularExpressionMatch match = it.next();
            bool ok = false;
            const uint codePoint = match.captured(1).toUInt(&ok, 10);
            if (!ok) {
                continue;
            }

            const QString replacement = QString(QChar(static_cast<ushort>(codePoint)));
            output.replace(match.capturedStart(0) + offset, match.capturedLength(0), replacement);
            offset += replacement.size() - match.capturedLength(0);
        }

        return output;
    }

    Q_INVOKABLE QString numeronymizeText(const QString &text) const {
        if (text.isEmpty()) {
            return QString();
        }

        QString output = text;
        static const QRegularExpression wordPattern(QStringLiteral(R"([A-Za-z0-9]+)"));
        QRegularExpressionMatchIterator it = wordPattern.globalMatch(text);

        int offset = 0;
        while (it.hasNext()) {
            const QRegularExpressionMatch match = it.next();
            const QString word = match.captured(0);
            const QString numeronym = numeronymizeWord(word);
            output.replace(match.capturedStart(0) + offset, match.capturedLength(0), numeronym);
            offset += numeronym.size() - match.capturedLength(0);
        }

        return output;
    }

    Q_INVOKABLE QVariantMap regexAnalyze(const QString &pattern,
                                         const QString &subject,
                                         bool caseInsensitive,
                                         bool multiline,
                                         bool dotMatchesNewline) const {
        QVariantMap result;
        QRegularExpression::PatternOptions options = QRegularExpression::NoPatternOption;
        if (caseInsensitive) {
            options |= QRegularExpression::CaseInsensitiveOption;
        }
        if (multiline) {
            options |= QRegularExpression::MultilineOption;
        }
        if (dotMatchesNewline) {
            options |= QRegularExpression::DotMatchesEverythingOption;
        }

        const QRegularExpression regex(pattern, options);
        result[QStringLiteral("valid")] = regex.isValid();
        if (!regex.isValid()) {
            result[QStringLiteral("error")] = regex.errorString();
            return result;
        }

        QVariantList matches;
        QRegularExpressionMatchIterator it = regex.globalMatch(subject);
        int matchCount = 0;
        while (it.hasNext()) {
            const QRegularExpressionMatch match = it.next();
            QVariantMap item;
            item[QStringLiteral("index")] = matchCount;
            item[QStringLiteral("text")] = match.captured(0);
            item[QStringLiteral("start")] = match.capturedStart(0);
            item[QStringLiteral("end")] = match.capturedEnd(0);

            QVariantList captures;
            for (int i = 1; i <= match.lastCapturedIndex(); ++i) {
                QVariantMap capture;
                capture[QStringLiteral("group")] = i;
                capture[QStringLiteral("text")] = match.captured(i);
                capture[QStringLiteral("start")] = match.capturedStart(i);
                capture[QStringLiteral("end")] = match.capturedEnd(i);
                captures.append(capture);
            }
            item[QStringLiteral("captures")] = captures;
            matches.append(item);
            ++matchCount;
        }

        result[QStringLiteral("valid")] = true;
        result[QStringLiteral("hasMatch")] = matchCount > 0;
        result[QStringLiteral("matchCount")] = matchCount;
        result[QStringLiteral("matches")] = matches;

        if (matchCount > 0) {
            const QVariantMap first = matches.first().toMap();
            result[QStringLiteral("firstMatch")] = first.value(QStringLiteral("text"));
            result[QStringLiteral("firstStart")] = first.value(QStringLiteral("start"));
            result[QStringLiteral("firstEnd")] = first.value(QStringLiteral("end"));
        } else {
            result[QStringLiteral("firstMatch")] = QString();
            result[QStringLiteral("firstStart")] = -1;
            result[QStringLiteral("firstEnd")] = -1;
        }

        return result;
    }

    Q_INVOKABLE QVariantMap textDiff(const QString &leftText,
                                     const QString &rightText,
                                     bool ignoreWhitespace,
                                     bool ignoreCase) const {
        QVariantMap result;

        const QStringList leftLines = leftText.split(QRegularExpression(QStringLiteral("\\r\\n|\\r|\\n")), Qt::KeepEmptyParts);
        const QStringList rightLines = rightText.split(QRegularExpression(QStringLiteral("\\r\\n|\\r|\\n")), Qt::KeepEmptyParts);

        const QStringList leftCompare = normalizedDiffLines(leftLines, ignoreWhitespace, ignoreCase);
        const QStringList rightCompare = normalizedDiffLines(rightLines, ignoreWhitespace, ignoreCase);

        const int m = leftCompare.size();
        const int n = rightCompare.size();
        QVector<QVector<int>> lcs(m + 1, QVector<int>(n + 1, 0));

        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (leftCompare.at(i) == rightCompare.at(j)) {
                    lcs[i][j] = lcs[i + 1][j + 1] + 1;
                } else {
                    lcs[i][j] = std::max(lcs[i + 1][j], lcs[i][j + 1]);
                }
            }
        }

        QStringList lines;
        int added = 0;
        int removed = 0;
        int unchanged = 0;
        int i = 0;
        int j = 0;
        while (i < m && j < n) {
            if (leftCompare.at(i) == rightCompare.at(j)) {
                lines.append(QStringLiteral("  %1").arg(leftLines.at(i)));
                ++unchanged;
                ++i;
                ++j;
            } else if (lcs[i + 1][j] >= lcs[i][j + 1]) {
                lines.append(QStringLiteral("- %1").arg(leftLines.at(i)));
                ++removed;
                ++i;
            } else {
                lines.append(QStringLiteral("+ %1").arg(rightLines.at(j)));
                ++added;
                ++j;
            }
        }

        while (i < m) {
            lines.append(QStringLiteral("- %1").arg(leftLines.at(i)));
            ++removed;
            ++i;
        }

        while (j < n) {
            lines.append(QStringLiteral("+ %1").arg(rightLines.at(j)));
            ++added;
            ++j;
        }

        result[QStringLiteral("added")] = added;
        result[QStringLiteral("removed")] = removed;
        result[QStringLiteral("unchanged")] = unchanged;
        result[QStringLiteral("different")] = (added + removed) > 0;
        result[QStringLiteral("diff")] = lines.join(QLatin1Char('\n'));
        return result;
    }

    Q_INVOKABLE QString asciiTextDraw(const QString &text) const {
        if (text.isEmpty()) {
            return QString();
        }

        QStringList rows;
        for (int row = 0; row < 5; ++row) {
            rows.append(QString());
        }
        const QString upper = text.toUpper();
        for (int i = 0; i < upper.size(); ++i) {
            const QStringList glyph = asciiGlyphFor(upper.at(i));
            for (int row = 0; row < 5; ++row) {
                if (!rows.at(row).isEmpty()) {
                    rows[row] += QLatin1Char(' ');
                }
                rows[row] += glyph.at(row);
            }
        }
        return rows.join(QLatin1Char('\n'));
    }

    Q_INVOKABLE QString textToMorse(const QString &text) const {
        if (text.isEmpty()) {
            return QString();
        }

        const QHash<QChar, QString> map = morseMap();
        QStringList output;
        output.reserve(text.size());
        for (const QChar raw : text.toUpper()) {
            if (raw.isSpace()) {
                if (!output.isEmpty() && output.last() != QStringLiteral("/")) {
                    output.append(QStringLiteral("/"));
                }
                continue;
            }

            const QString code = map.value(raw);
            output.append(code.isEmpty() ? QString(raw) : code);
        }
        return output.join(QStringLiteral(" "));
    }

    Q_INVOKABLE QString morseToText(const QString &morse) const {
        const QString trimmed = morse.trimmed();
        if (trimmed.isEmpty()) {
            return QString();
        }

        QHash<QString, QChar> reverse;
        const QHash<QChar, QString> map = morseMap();
        for (auto it = map.constBegin(); it != map.constEnd(); ++it) {
            reverse.insert(it.value(), it.key());
        }

        const QStringList parts = trimmed.split(QRegularExpression(QStringLiteral("\\s+")), Qt::SkipEmptyParts);
        QString output;
        for (const QString &part : parts) {
            if (part == QStringLiteral("/")) {
                output += QLatin1Char(' ');
            } else {
                output += reverse.contains(part) ? reverse.value(part) : QLatin1Char('?');
            }
        }
        return output;
    }

    Q_INVOKABLE QString rotTransform(const QString &text, const QString &mode) const {
        if (text.isEmpty()) {
            return QString();
        }

        QString output = text;
        if (mode == QStringLiteral("rot13")) {
            for (int i = 0; i < output.size(); ++i) {
                const ushort code = output.at(i).unicode();
                if (code >= 'a' && code <= 'z') {
                    output[i] = QChar(((code - 'a' + 13) % 26) + 'a');
                } else if (code >= 'A' && code <= 'Z') {
                    output[i] = QChar(((code - 'A' + 13) % 26) + 'A');
                }
            }
            return output;
        }

        if (mode == QStringLiteral("rot47")) {
            for (int i = 0; i < output.size(); ++i) {
                const ushort code = output.at(i).unicode();
                if (code >= 33 && code <= 126) {
                    output[i] = QChar(33 + ((code - 33 + 47) % 94));
                }
            }
            return output;
        }

        return QString();
    }

private:
    static QStringList normalizedDiffLines(const QStringList &lines, bool ignoreWhitespace, bool ignoreCase) {
        QStringList normalized;
        normalized.reserve(lines.size());
        for (QString line : lines) {
            if (ignoreWhitespace) {
                line = line.simplified();
            }
            if (ignoreCase) {
                line = line.toLower();
            }
            normalized.append(line);
        }
        return normalized;
    }

    static QHash<QChar, QString> morseMap() {
        return {
            {QLatin1Char('A'), QStringLiteral(".-")},
            {QLatin1Char('B'), QStringLiteral("-...")},
            {QLatin1Char('C'), QStringLiteral("-.-.")},
            {QLatin1Char('D'), QStringLiteral("-..")},
            {QLatin1Char('E'), QStringLiteral(".")},
            {QLatin1Char('F'), QStringLiteral("..-.")},
            {QLatin1Char('G'), QStringLiteral("--.")},
            {QLatin1Char('H'), QStringLiteral("....")},
            {QLatin1Char('I'), QStringLiteral("..")},
            {QLatin1Char('J'), QStringLiteral(".---")},
            {QLatin1Char('K'), QStringLiteral("-.-")},
            {QLatin1Char('L'), QStringLiteral(".-..")},
            {QLatin1Char('M'), QStringLiteral("--")},
            {QLatin1Char('N'), QStringLiteral("-.")},
            {QLatin1Char('O'), QStringLiteral("---")},
            {QLatin1Char('P'), QStringLiteral(".--.")},
            {QLatin1Char('Q'), QStringLiteral("--.-")},
            {QLatin1Char('R'), QStringLiteral(".-.")},
            {QLatin1Char('S'), QStringLiteral("...")},
            {QLatin1Char('T'), QStringLiteral("-")},
            {QLatin1Char('U'), QStringLiteral("..-")},
            {QLatin1Char('V'), QStringLiteral("...-")},
            {QLatin1Char('W'), QStringLiteral(".--")},
            {QLatin1Char('X'), QStringLiteral("-..-")},
            {QLatin1Char('Y'), QStringLiteral("-.--")},
            {QLatin1Char('Z'), QStringLiteral("--..")},
            {QLatin1Char('0'), QStringLiteral("-----")},
            {QLatin1Char('1'), QStringLiteral(".----")},
            {QLatin1Char('2'), QStringLiteral("..---")},
            {QLatin1Char('3'), QStringLiteral("...--")},
            {QLatin1Char('4'), QStringLiteral("....-")},
            {QLatin1Char('5'), QStringLiteral(".....")},
            {QLatin1Char('6'), QStringLiteral("-....")},
            {QLatin1Char('7'), QStringLiteral("--...")},
            {QLatin1Char('8'), QStringLiteral("---..")},
            {QLatin1Char('9'), QStringLiteral("----.")},
            {QLatin1Char('.'), QStringLiteral(".-.-.-")},
            {QLatin1Char(','), QStringLiteral("--..--")},
            {QLatin1Char('?'), QStringLiteral("..--..")},
            {QLatin1Char('!'), QStringLiteral("-.-.--")},
            {QLatin1Char('-'), QStringLiteral("-....-")},
            {QLatin1Char('/'), QStringLiteral("-..-.")},
            {QLatin1Char('@'), QStringLiteral(".--.-.")}
        };
    }

    static QStringList asciiGlyphFor(QChar ch) {
        static const QHash<QChar, QStringList> glyphs = {
            {QLatin1Char('A'), {QStringLiteral(" ### "), QStringLiteral("#   #"), QStringLiteral("#####"), QStringLiteral("#   #"), QStringLiteral("#   #")}},
            {QLatin1Char('B'), {QStringLiteral("#### "), QStringLiteral("#   #"), QStringLiteral("#### "), QStringLiteral("#   #"), QStringLiteral("#### ")}},
            {QLatin1Char('C'), {QStringLiteral(" ####"), QStringLiteral("#    "), QStringLiteral("#    "), QStringLiteral("#    "), QStringLiteral(" ####")}},
            {QLatin1Char('D'), {QStringLiteral("#### "), QStringLiteral("#   #"), QStringLiteral("#   #"), QStringLiteral("#   #"), QStringLiteral("#### ")}},
            {QLatin1Char('E'), {QStringLiteral("#####"), QStringLiteral("#    "), QStringLiteral("#####"), QStringLiteral("#    "), QStringLiteral("#####")}},
            {QLatin1Char('F'), {QStringLiteral("#####"), QStringLiteral("#    "), QStringLiteral("#####"), QStringLiteral("#    "), QStringLiteral("#    ")}},
            {QLatin1Char('G'), {QStringLiteral(" ####"), QStringLiteral("#    "), QStringLiteral("# ###"), QStringLiteral("#   #"), QStringLiteral(" ####")}},
            {QLatin1Char('H'), {QStringLiteral("#   #"), QStringLiteral("#   #"), QStringLiteral("#####"), QStringLiteral("#   #"), QStringLiteral("#   #")}},
            {QLatin1Char('I'), {QStringLiteral("#####"), QStringLiteral("  #  "), QStringLiteral("  #  "), QStringLiteral("  #  "), QStringLiteral("#####")}},
            {QLatin1Char('J'), {QStringLiteral("#####"), QStringLiteral("   # "), QStringLiteral("   # "), QStringLiteral("#  # "), QStringLiteral(" ##  ")}},
            {QLatin1Char('K'), {QStringLiteral("#   #"), QStringLiteral("#  # "), QStringLiteral("###  "), QStringLiteral("#  # "), QStringLiteral("#   #")}},
            {QLatin1Char('L'), {QStringLiteral("#    "), QStringLiteral("#    "), QStringLiteral("#    "), QStringLiteral("#    "), QStringLiteral("#####")}},
            {QLatin1Char('M'), {QStringLiteral("#   #"), QStringLiteral("## ##"), QStringLiteral("# # #"), QStringLiteral("#   #"), QStringLiteral("#   #")}},
            {QLatin1Char('N'), {QStringLiteral("#   #"), QStringLiteral("##  #"), QStringLiteral("# # #"), QStringLiteral("#  ##"), QStringLiteral("#   #")}},
            {QLatin1Char('O'), {QStringLiteral(" ### "), QStringLiteral("#   #"), QStringLiteral("#   #"), QStringLiteral("#   #"), QStringLiteral(" ### ")}},
            {QLatin1Char('P'), {QStringLiteral("#### "), QStringLiteral("#   #"), QStringLiteral("#### "), QStringLiteral("#    "), QStringLiteral("#    ")}},
            {QLatin1Char('Q'), {QStringLiteral(" ### "), QStringLiteral("#   #"), QStringLiteral("#   #"), QStringLiteral("#  ##"), QStringLiteral(" ####")}},
            {QLatin1Char('R'), {QStringLiteral("#### "), QStringLiteral("#   #"), QStringLiteral("#### "), QStringLiteral("#  # "), QStringLiteral("#   #")}},
            {QLatin1Char('S'), {QStringLiteral(" ####"), QStringLiteral("#    "), QStringLiteral(" ### "), QStringLiteral("    #"), QStringLiteral("#### ")}},
            {QLatin1Char('T'), {QStringLiteral("#####"), QStringLiteral("  #  "), QStringLiteral("  #  "), QStringLiteral("  #  "), QStringLiteral("  #  ")}},
            {QLatin1Char('U'), {QStringLiteral("#   #"), QStringLiteral("#   #"), QStringLiteral("#   #"), QStringLiteral("#   #"), QStringLiteral(" ### ")}},
            {QLatin1Char('V'), {QStringLiteral("#   #"), QStringLiteral("#   #"), QStringLiteral("#   #"), QStringLiteral(" # # "), QStringLiteral("  #  ")}},
            {QLatin1Char('W'), {QStringLiteral("#   #"), QStringLiteral("#   #"), QStringLiteral("# # #"), QStringLiteral("## ##"), QStringLiteral("#   #")}},
            {QLatin1Char('X'), {QStringLiteral("#   #"), QStringLiteral(" # # "), QStringLiteral("  #  "), QStringLiteral(" # # "), QStringLiteral("#   #")}},
            {QLatin1Char('Y'), {QStringLiteral("#   #"), QStringLiteral(" # # "), QStringLiteral("  #  "), QStringLiteral("  #  "), QStringLiteral("  #  ")}},
            {QLatin1Char('Z'), {QStringLiteral("#####"), QStringLiteral("   # "), QStringLiteral("  #  "), QStringLiteral(" #   "), QStringLiteral("#####")}},
            {QLatin1Char('0'), {QStringLiteral(" ### "), QStringLiteral("#  ##"), QStringLiteral("# # #"), QStringLiteral("##  #"), QStringLiteral(" ### ")}},
            {QLatin1Char('1'), {QStringLiteral("  #  "), QStringLiteral(" ##  "), QStringLiteral("  #  "), QStringLiteral("  #  "), QStringLiteral(" ### ")}},
            {QLatin1Char('2'), {QStringLiteral(" ### "), QStringLiteral("#   #"), QStringLiteral("   # "), QStringLiteral("  #  "), QStringLiteral("#####")}},
            {QLatin1Char('3'), {QStringLiteral("#### "), QStringLiteral("    #"), QStringLiteral(" ### "), QStringLiteral("    #"), QStringLiteral("#### ")}},
            {QLatin1Char('4'), {QStringLiteral("#   #"), QStringLiteral("#   #"), QStringLiteral("#####"), QStringLiteral("    #"), QStringLiteral("    #")}},
            {QLatin1Char('5'), {QStringLiteral("#####"), QStringLiteral("#    "), QStringLiteral("#### "), QStringLiteral("    #"), QStringLiteral("#### ")}},
            {QLatin1Char('6'), {QStringLiteral(" ### "), QStringLiteral("#    "), QStringLiteral("#### "), QStringLiteral("#   #"), QStringLiteral(" ### ")}},
            {QLatin1Char('7'), {QStringLiteral("#####"), QStringLiteral("    #"), QStringLiteral("   # "), QStringLiteral("  #  "), QStringLiteral(" #   ")}},
            {QLatin1Char('8'), {QStringLiteral(" ### "), QStringLiteral("#   #"), QStringLiteral(" ### "), QStringLiteral("#   #"), QStringLiteral(" ### ")}},
            {QLatin1Char('9'), {QStringLiteral(" ### "), QStringLiteral("#   #"), QStringLiteral(" ####"), QStringLiteral("    #"), QStringLiteral(" ### ")}},
            {QLatin1Char(' '), {QStringLiteral("     "), QStringLiteral("     "), QStringLiteral("     "), QStringLiteral("     "), QStringLiteral("     ")}}
        };
        return glyphs.value(ch, {QStringLiteral("?????"), QStringLiteral("?????"), QStringLiteral("?????"), QStringLiteral("?????"), QStringLiteral("?????")});
    }

    static QStringList extractWords(const QString &segment) {
        QStringList words;
        const QStringList parts = segment.split(QRegularExpression(QStringLiteral("[\\s_-]+")), Qt::SkipEmptyParts);

        static const QRegularExpression matcher(QStringLiteral("[A-Z]+(?![a-z])|[A-Z]?[a-z]+|[0-9]+"));
        for (const QString &part : parts) {
            QRegularExpressionMatchIterator it = matcher.globalMatch(part);
            bool found = false;
            while (it.hasNext()) {
                found = true;
                words.append(it.next().captured(0).toLower());
            }
            if (!found) {
                words.append(part.toLower());
            }
        }

        return words;
    }

    static QString transformSegment(const QString &segment, const QString &mode) {
        const QStringList words = extractWords(segment);
        if (words.isEmpty()) {
            return segment;
        }

        if (mode == QStringLiteral("camel")) {
            QString camel = words.first();
            for (int i = 1; i < words.size(); ++i) {
                camel += words[i].left(1).toUpper() + words[i].mid(1);
            }
            return camel;
        }

        if (mode == QStringLiteral("pascal")) {
            QString pascal;
            for (const QString &word : words) {
                pascal += word.left(1).toUpper() + word.mid(1);
            }
            return pascal;
        }

        if (mode == QStringLiteral("snake")) {
            return words.join(QStringLiteral("_"));
        }

        if (mode == QStringLiteral("kebab")) {
            return words.join(QStringLiteral("-"));
        }

        return segment;
    }

    static QString convertPreservingSymbols(const QString &text, const QString &mode) {
        QString result;
        QString segment;

        for (int i = 0; i < text.size(); ++i) {
            const QChar ch = text.at(i);
            if (ch.isLetterOrNumber() || ch == QLatin1Char(' ') || ch == QLatin1Char('_') || ch == QLatin1Char('-')) {
                segment += ch;
            } else {
                result += transformSegment(segment, mode);
                result += ch;
                segment.clear();
            }
        }

        result += transformSegment(segment, mode);
        return result;
    }

    static QString numeronymizeWord(const QString &word) {
        if (word.size() <= 3) {
            return word;
        }

        return word.left(1) + QString::number(word.size() - 2) + word.right(1);
    }
};

#endif // TEXTTOOL_H
