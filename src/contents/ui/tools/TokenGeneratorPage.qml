import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.Page {
    title: "Token Generator"
    ColumnLayout {
        anchors.fill: parent
        anchors.margins: Kirigami.Units.largeSpacing
        spacing: Kirigami.Units.smallSpacing

        Label {
            text: "Length:"
            font.bold: true
        }
        SpinBox {
            id: tokenLength
            from: 1
            to: 128
            value: 32
            editable: true
            Layout.fillWidth: false
        }
        
        Label {
            text: "Token:"
            font.bold: true
        }
        OutputField {
            id: tokenOutput
            readOnly: true
            Layout.fillWidth: true
        }
        Button {
            text: "Generate"
            onClicked: {
                var charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+";
                var retVal = "";
                for (var i = 0; i < tokenLength.value; ++i) {
                    retVal += charset.charAt(Math.floor(Math.random() * charset.length));
                }
                tokenOutput.text = retVal;
            }
            Layout.alignment: Qt.AlignLeft
        }
        Item { Layout.fillHeight: true }
    }
}
