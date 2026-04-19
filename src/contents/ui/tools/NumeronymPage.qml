import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.ScrollablePage {
    title: "Numeronym Generator"

    ColumnLayout {
        width: parent.width
        spacing: Kirigami.Units.largeSpacing

        Label {
            text: "Text to numeronymize:"
            font.bold: true
        }

        AppTextArea {
            id: textInput
            Layout.fillWidth: true
            Layout.preferredHeight: 120
            placeholderText: "e.g. internationalization localization accessibility"
        }

        Label {
            text: "Numeronym:"
            font.bold: true
        }

        OutputArea {
            Layout.fillWidth: true
            Layout.preferredHeight: 120
            font.family: "monospace"
            text: textTool.numeronymizeText(textInput.text)
            placeholderText: "Generated numeronyms will appear here"
        }
    }
}
