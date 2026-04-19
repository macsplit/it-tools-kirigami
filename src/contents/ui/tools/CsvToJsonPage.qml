import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.ScrollablePage {
    title: "CSV to JSON"

    ColumnLayout {
        width: parent.width
        spacing: Kirigami.Units.largeSpacing

        Label { text: "CSV Input (first line as header):"; font.bold: true }
        AppTextArea {
            id: csvInput
            placeholderText: "id,name,email\n1,John,john@example.com\n2,Jane,jane@example.com"
            Layout.fillWidth: true
            Layout.preferredHeight: 200
            font.family: "monospace"
            text: "id,name,email\n1,John,john@example.com\n2,Jane,jane@example.com"
        }

        Label { text: "JSON Output:"; font.bold: true }
        OutputArea {
            id: jsonOutput
            readOnly: true
            Layout.fillWidth: true
            Layout.preferredHeight: 200
            font.family: "monospace"
            text: conversionTool.csvToJson(csvInput.text)
        }
    }
}
