import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.ScrollablePage {
    title: "JSON to CSV"

    ColumnLayout {
        width: parent.width
        spacing: Kirigami.Units.largeSpacing

        Label { text: "Your JSON content (array of objects):"; font.bold: true }
        AppTextArea {
            id: jsonInput
            placeholderText: "Paste your JSON here..."
            Layout.fillWidth: true
            Layout.preferredHeight: 200
            font.family: "monospace"
            text: '[{"id": 1, "name": "John"}, {"id": 2, "name": "Jane"}]'
        }

        Label { text: "Converted CSV:"; font.bold: true }
        OutputArea {
            id: csvOutput
            readOnly: true
            Layout.fillWidth: true
            Layout.preferredHeight: 200
            font.family: "monospace"
            text: conversionTool.jsonToCsv(jsonInput.text)
        }
    }
}
