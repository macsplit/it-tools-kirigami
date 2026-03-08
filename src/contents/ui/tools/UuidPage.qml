import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.Page {
    title: "UUID Generator"
    ColumnLayout {
        anchors.fill: parent
        anchors.margins: Kirigami.Units.largeSpacing
        spacing: Kirigami.Units.smallSpacing

        Label {
            text: "Generated UUID:"
            font.bold: true
        }
        TextField {
            id: uuidField
            readOnly: true
            Layout.fillWidth: true
        }
        Button {
            text: "Generate"
            onClicked: uuidField.text = generateUUID()
            Layout.alignment: Qt.AlignLeft
        }
        Item { Layout.fillHeight: true }
    }
    function generateUUID() {
        return 'xxxxxxxx-xxxx-4xxx-yxxx-xxxxxxxxxxxx'.replace(/[xy]/g, function(c) {
            var r = Math.random() * 16 | 0, v = c == 'x' ? r : (r & 0x3 | 0x8);
            return v.toString(16);
        });
    }
}
