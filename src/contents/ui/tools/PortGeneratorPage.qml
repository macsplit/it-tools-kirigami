import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.Page {
    title: "Random Port Generator"
    ColumnLayout {
        anchors.fill: parent
        anchors.margins: Kirigami.Units.largeSpacing
        spacing: Kirigami.Units.smallSpacing

        Label { text: "Generated Port:"; font.bold: true }
        OutputField {
            id: portOutput
            readOnly: true
            Layout.fillWidth: true
        }
        Button {
            text: "Generate"
            onClicked: portOutput.text = idTool.generatePort()
            Layout.alignment: Qt.AlignLeft
        }
        Item { Layout.fillHeight: true }
    }
}
