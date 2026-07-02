import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.ScrollablePage {
    title: "ROT13 / ROT47"

    ColumnLayout {
        width: parent.width
        spacing: Kirigami.Units.largeSpacing

        ComboBox {
            id: modeSelector
            Layout.fillWidth: true
            model: [
                { text: "ROT13", value: "rot13" },
                { text: "ROT47", value: "rot47" }
            ]
            textRole: "text"
        }

        Label {
            text: "Input"
            font.bold: true
        }

        AppTextArea {
            id: rotInput
            Layout.fillWidth: true
            Layout.preferredHeight: 140
            text: "Hello, World!"
        }

        Label {
            text: "Output"
            font.bold: true
        }

        OutputArea {
            Layout.fillWidth: true
            Layout.preferredHeight: 140
            font.family: "monospace"
            text: textTool.rotTransform(rotInput.text, modeSelector.currentValue)
        }
    }
}
