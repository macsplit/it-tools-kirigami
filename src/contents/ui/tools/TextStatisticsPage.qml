import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.Page {
    title: "Text Statistics"
    ColumnLayout {
        anchors.fill: parent
        anchors.margins: Kirigami.Units.largeSpacing
        AppTextArea {
            id: statsInput
            placeholderText: "Input text..."
            Layout.fillWidth: true
            Layout.fillHeight: true
        }
        ColumnLayout {
            Layout.fillWidth: true
            spacing: Kirigami.Units.smallSpacing
            Label {
                text: "Characters: " + textTool.textStatistics(statsInput.text).characters
                font.bold: true
            }
            Label {
                text: "Words: " + textTool.textStatistics(statsInput.text).words
                font.bold: true
            }
            Label {
                text: "Lines: " + textTool.textStatistics(statsInput.text).lines
                font.bold: true
            }
        }
    }
}
