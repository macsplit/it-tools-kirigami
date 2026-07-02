import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.ScrollablePage {
    title: "Regex Reference"

    ColumnLayout {
        width: parent.width
        spacing: Kirigami.Units.largeSpacing

        Label {
            text: "Common regex tokens and examples"
            font.bold: true
        }

        OutputArea {
            Layout.fillWidth: true
            Layout.preferredHeight: 420
            font.family: "monospace"
            wrapMode: TextEdit.NoWrap
            text:
                ".        any character except newline\n" +
                "\\d       digit\n" +
                "\\w       word character\n" +
                "\\s       whitespace\n" +
                "^ $      start / end of line\n" +
                "* + ?    repetition operators\n" +
                "{m,n}    bounded repetition\n" +
                "[abc]    character class\n" +
                "[^abc]   negated class\n" +
                "(...)    capture group\n" +
                "(?:...)  non-capturing group\n" +
                "|        alternation\n" +
                "\\b       word boundary\n" +
                "\n" +
                "Email      [A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}\n" +
                "URL        https?://\\S+\n" +
                "IPv4       \\b(?:\\d{1,3}\\.){3}\\d{1,3}\\b\n" +
                "Date       \\b\\d{4}-\\d{2}-\\d{2}\\b\n" +
                "Hex color  #(?:[0-9A-Fa-f]{3}|[0-9A-Fa-f]{6})\\b"
        }
    }
}
