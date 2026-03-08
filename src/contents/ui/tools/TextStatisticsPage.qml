import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.Page {
    title: "Text Statistics"
    ColumnLayout {
        anchors.fill: parent
        anchors.margins: Kirigami.Units.largeSpacing
        TextArea {
            id: statsInput
            placeholderText: "Input text..."
            Layout.fillWidth: true
            Layout.fillHeight: true
        }
        ColumnLayout {
            Layout.fillWidth: true
            spacing: Kirigami.Units.smallSpacing
            Label {
                text: "Characters: " + statsInput.text.length
                font.bold: true
            }
            Label {
                text: "Words: " + statsInput.text.trim().split(/\s+/).filter(function(w) { return w !== ""; }).length
                font.bold: true
            }
            Label {
                text: "Lines: " + statsInput.text.split(/\r\n|\r|\n/).length
                font.bold: true
            }
        }
    }
}
