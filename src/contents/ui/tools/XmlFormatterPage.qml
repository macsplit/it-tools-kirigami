import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.ScrollablePage {
    title: "XML Formatter"

    ColumnLayout {
        width: parent.width
        spacing: Kirigami.Units.largeSpacing

        Label { text: "Indent size:"; font.bold: true }
        SpinBox {
            id: indentSize
            from: 0; to: 10; value: 2; editable: true
        }

        Label { text: "Your XML:"; font.bold: true }
        TextArea {
            id: xmlInput
            placeholderText: "Paste your XML here..."
            Layout.fillWidth: true
            Layout.preferredHeight: 200
            font.family: "monospace"
            text: "<hello><world>foo</world><world>bar</world></hello>"
        }

        Label { text: "Formatted XML:"; font.bold: true }
        TextArea {
            id: xmlOutput
            readOnly: true
            Layout.fillWidth: true
            Layout.preferredHeight: 200
            font.family: "monospace"
            text: conversionTool.formatXml(xmlInput.text, indentSize.value)
        }
    }
}
