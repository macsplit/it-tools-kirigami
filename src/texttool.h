#ifndef TEXTTOOL_H
#define TEXTTOOL_H

#include <QObject>
#include <QString>
#include <QRegularExpression>
#include <QStringList>

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
        QString output = text;
        output.replace(QStringLiteral("&"), QStringLiteral("&amp;"));
        output.replace(QStringLiteral("<"), QStringLiteral("&lt;"));
        output.replace(QStringLiteral(">"), QStringLiteral("&gt;"));
        output.replace(QStringLiteral("\""), QStringLiteral("&quot;"));
        output.replace(QStringLiteral("'"), QStringLiteral("&#39;"));
        return output;
    }

    Q_INVOKABLE QString htmlEntitiesDecode(const QString &text) const {
        QString output = text;
        output.replace(QStringLiteral("&amp;"), QStringLiteral("&"));
        output.replace(QStringLiteral("&lt;"), QStringLiteral("<"));
        output.replace(QStringLiteral("&gt;"), QStringLiteral(">"));
        output.replace(QStringLiteral("&quot;"), QStringLiteral("\""));
        output.replace(QStringLiteral("&#39;"), QStringLiteral("'"));
        output.replace(QStringLiteral("&apos;"), QStringLiteral("'"));
        return output;
    }

    Q_INVOKABLE QString slugify(const QString &text) const {
        QString output = text.toLower().trimmed();
        output.remove(QRegularExpression(QStringLiteral("[^\\w\\s-]")));
        output.replace(QRegularExpression(QStringLiteral("[\\s_-]+")), QStringLiteral("-"));
        output.remove(QRegularExpression(QStringLiteral("^-+|-+$")));
        return output;
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

private:
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
