import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.ScrollablePage {
    title: "XML to JSON Mapping"

    ColumnLayout {
        width: parent.width
        spacing: Kirigami.Units.largeSpacing

        Label { text: "Your XML content:"; font.bold: true }
        AppTextArea {
            id: xmlInput
            placeholderText: "Paste your XML here..."
            Layout.fillWidth: true
            Layout.preferredHeight: 200
            font.family: "monospace"
            text: '<a x="1.234" y="It\'s"/>'
        }

        Label {
            Layout.fillWidth: true
            wrapMode: Text.WordWrap
            text: "Uses the app's simple mapping contract: attributes become @name keys, text becomes #text, and repeated child elements become arrays."
            color: Kirigami.Theme.disabledTextColor
        }

        Label { text: "Converted JSON:"; font.bold: true }
        OutputArea {
            id: jsonOutput
            readOnly: true
            Layout.fillWidth: true
            Layout.preferredHeight: 200
            font.family: "monospace"
            text: conversionTool.xmlToJson(xmlInput.text)
        }
    }
}
