import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.ScrollablePage {
    title: "Morse Code Converter"

    ColumnLayout {
        width: parent.width
        spacing: Kirigami.Units.largeSpacing

        Label {
            text: "Plain text"
            font.bold: true
        }

        AppTextArea {
            id: plainInput
            Layout.fillWidth: true
            Layout.preferredHeight: 120
            text: "SOS HELP"
        }

        Label {
            text: "Morse code"
            font.bold: true
        }

        OutputArea {
            id: morseOutput
            Layout.fillWidth: true
            Layout.preferredHeight: 120
            font.family: "monospace"
            text: textTool.textToMorse(plainInput.text)
        }

        RowLayout {
            Button {
                text: "Plain -> Morse"
                onClicked: morseOutput.text = textTool.textToMorse(plainInput.text)
            }
            Button {
                text: "Morse -> Plain"
                onClicked: plainInput.text = textTool.morseToText(morseOutput.text)
            }
        }
    }
}
