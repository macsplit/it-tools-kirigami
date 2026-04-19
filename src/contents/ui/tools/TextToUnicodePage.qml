import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.ScrollablePage {
    title: "Text to Unicode"

    ColumnLayout {
        width: parent.width
        spacing: Kirigami.Units.largeSpacing

        Label {
            text: "Text to convert:"
            font.bold: true
        }

        AppTextArea {
            id: textInput
            Layout.fillWidth: true
            Layout.preferredHeight: 100
            placeholderText: "e.g. Hello world"
        }

        Label {
            text: "Unicode entities:"
            font.bold: true
        }

        OutputArea {
            Layout.fillWidth: true
            Layout.preferredHeight: 100
            font.family: "monospace"
            text: textTool.textToUnicode(textInput.text)
            placeholderText: "Decimal entities will appear here"
        }

        Label {
            text: "Unicode entities to convert:"
            font.bold: true
        }

        AppTextArea {
            id: unicodeInput
            Layout.fillWidth: true
            Layout.preferredHeight: 100
            font.family: "monospace"
            placeholderText: "e.g. &#72;&#101;&#108;&#108;&#111;"
        }

        Label {
            text: "Decoded text:"
            font.bold: true
        }

        OutputArea {
            Layout.fillWidth: true
            Layout.preferredHeight: 100
            text: textTool.unicodeToText(unicodeInput.text)
            placeholderText: "Decoded text will appear here"
        }
    }
}
