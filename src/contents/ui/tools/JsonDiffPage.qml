import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.ScrollablePage {
    title: "JSON Diff"

    ColumnLayout {
        width: parent.width
        spacing: Kirigami.Units.largeSpacing

        Label {
            text: "Left JSON"
            font.bold: true
        }

        AppTextArea {
            id: leftInput
            Layout.fillWidth: true
            Layout.preferredHeight: 180
            font.family: "monospace"
            placeholderText: "Paste left JSON here..."
            showPasteButton: true
            text: "{\n  \"name\": \"Ada\",\n  \"roles\": [\"admin\", \"editor\"],\n  \"active\": true\n}"
        }

        Label {
            text: "Right JSON"
            font.bold: true
        }

        AppTextArea {
            id: rightInput
            Layout.fillWidth: true
            Layout.preferredHeight: 180
            font.family: "monospace"
            placeholderText: "Paste right JSON here..."
            showPasteButton: true
            text: "{\n  \"name\": \"Ada Lovelace\",\n  \"roles\": [\"admin\"],\n  \"active\": true,\n  \"team\": \"platform\"\n}"
        }

        Label {
            text: "Diff"
            font.bold: true
        }

        OutputArea {
            Layout.fillWidth: true
            Layout.preferredHeight: 220
            font.family: "monospace"
            wrapMode: TextEdit.WrapAnywhere
            text: conversionTool.jsonDiff(leftInput.text, rightInput.text)
            placeholderText: "Differences will appear here..."
        }
    }
}
