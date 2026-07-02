import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.ScrollablePage {
    title: "Regex Tester"

    property var regexData: textTool.regexAnalyze(patternInput.text,
                                                  subjectInput.text,
                                                  caseInsensitive.checked,
                                                  multiline.checked,
                                                  dotMatchesNewline.checked)

    function matchesSummary() {
        if (!regexData.valid) {
            return regexData.error || ""
        }
        if (!regexData.hasMatch) {
            return "No matches"
        }

        var lines = []
        for (var i = 0; i < regexData.matches.length; ++i) {
            var match = regexData.matches[i]
            lines.push("Match " + (i + 1) + " [" + match.start + ", " + match.end + "): " + match.text)
            for (var j = 0; j < match.captures.length; ++j) {
                var capture = match.captures[j]
                lines.push("  Group " + capture.group + " [" + capture.start + ", " + capture.end + "): " + capture.text)
            }
        }
        return lines.join("\n")
    }

    ColumnLayout {
        width: parent.width
        spacing: Kirigami.Units.largeSpacing

        Label {
            text: "Pattern"
            font.bold: true
        }

        AppTextField {
            id: patternInput
            Layout.fillWidth: true
            text: "(Ada|Grace)\\s+(Lovelace|Hopper)"
            placeholderText: "Enter a regular expression"
        }

        RowLayout {
            Layout.fillWidth: true

            CheckBox {
                id: caseInsensitive
                text: "Case-insensitive"
            }

            CheckBox {
                id: multiline
                text: "Multiline"
            }

            CheckBox {
                id: dotMatchesNewline
                text: "Dot matches newline"
            }
        }

        Label {
            text: "Subject text"
            font.bold: true
        }

        AppTextArea {
            id: subjectInput
            Layout.fillWidth: true
            Layout.preferredHeight: 180
            font.family: "monospace"
            showPasteButton: true
            text: "Ada Lovelace\nGrace Hopper\nAlan Turing"
        }

        Kirigami.FormLayout {
            Layout.fillWidth: true
            wideMode: true

            OutputField {
                Kirigami.FormData.label: "Valid:"
                Layout.fillWidth: true
                readOnly: true
                text: regexData.valid ? "Yes" : "No"
            }

            OutputField {
                Kirigami.FormData.label: "Match count:"
                Layout.fillWidth: true
                readOnly: true
                text: regexData.valid ? String(regexData.matchCount || 0) : ""
            }

            OutputField {
                Kirigami.FormData.label: "First match:"
                Layout.fillWidth: true
                readOnly: true
                text: regexData.firstMatch || ""
            }
        }

        Label {
            text: "Matches"
            font.bold: true
        }

        OutputArea {
            Layout.fillWidth: true
            Layout.preferredHeight: 220
            font.family: "monospace"
            wrapMode: TextEdit.WrapAnywhere
            text: matchesSummary()
        }
    }
}
