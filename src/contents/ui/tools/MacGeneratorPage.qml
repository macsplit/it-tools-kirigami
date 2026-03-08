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
        TextField {
            id: macOutput
            readOnly: true
            Layout.fillWidth: true
        }
        Button {
            text: "Generate"
            onClicked: {
                var mac = "";
                for (var i = 0; i < 6; i++) {
                    var val = Math.floor(Math.random() * 256);
                    var hex = ("0" + val.toString(16)).slice(-2);
                    mac += hex + (i < 5 ? ":" : "");
                }
                macOutput.text = mac.toUpperCase();
            }
            Layout.alignment: Qt.AlignLeft
        }
        Item { Layout.fillHeight: true }
    }
}
