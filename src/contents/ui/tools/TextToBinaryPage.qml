import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.ScrollablePage {
    title: "Text to Binary"

    ColumnLayout {
        width: parent.width
        spacing: Kirigami.Units.largeSpacing

        Label { text: "Text to convert:"; font.bold: true }
        AppTextArea {
            id: textInput
            placeholderText: "e.g. Hello world"
            Layout.fillWidth: true
            Layout.preferredHeight: 100
        }

        Label { text: "Binary representation:"; font.bold: true }
        OutputArea {
            readOnly: true
            Layout.fillWidth: true
            Layout.preferredHeight: 100
            font.family: "monospace"
            text: textTool.textToBinary(textInput.text)
        }

        Label { text: "Binary to convert:"; font.bold: true }
        AppTextArea {
            id: binaryInput
            placeholderText: "e.g. 01001000 01100101..."
            Layout.fillWidth: true
            Layout.preferredHeight: 100
        }

        Label { text: "Text representation:"; font.bold: true }
        OutputArea {
            readOnly: true
            Layout.fillWidth: true
            Layout.preferredHeight: 100
            text: textTool.binaryToText(binaryInput.text)
        }
    }
}
