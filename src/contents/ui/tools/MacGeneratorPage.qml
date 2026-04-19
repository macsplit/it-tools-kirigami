import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.Page {
    title: "MAC Address Generator"
    ColumnLayout {
        anchors.fill: parent
        anchors.margins: Kirigami.Units.largeSpacing
        spacing: Kirigami.Units.smallSpacing

        Label { text: "Generated MAC Address:"; font.bold: true }
        OutputField {
            id: macOutput
            readOnly: true
            Layout.fillWidth: true
        }
        Button {
            text: "Generate"
            onClicked: macOutput.text = idTool.generateMacAddress()
            Layout.alignment: Qt.AlignLeft
        }
        Item { Layout.fillHeight: true }
    }
}
