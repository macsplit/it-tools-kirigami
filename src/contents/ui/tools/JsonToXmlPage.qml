import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.ScrollablePage {
    title: "JSON to XML"

    ColumnLayout {
        width: parent.width
        spacing: Kirigami.Units.largeSpacing

        Label { text: "Your JSON content:"; font.bold: true }
        AppTextArea {
            id: jsonInput
            placeholderText: "Paste your JSON here..."
            Layout.fillWidth: true
            Layout.preferredHeight: 200
            font.family: "monospace"
            text: '{"hello": "world", "list": [1, 2, 3]}'
        }

        Label { text: "Converted XML:"; font.bold: true }
        OutputArea {
            id: xmlOutput
            readOnly: true
            Layout.fillWidth: true
            Layout.preferredHeight: 200
            font.family: "monospace"
            text: conversionTool.jsonToXml(jsonInput.text)
        }
    }
}
