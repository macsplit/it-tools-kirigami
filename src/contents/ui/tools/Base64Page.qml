import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.Page {
    title: "Base64 Converter"
    ColumnLayout {
        anchors.fill: parent
        anchors.margins: Kirigami.Units.largeSpacing
        AppTextArea {
            id: inputField
            placeholderText: "Input text..."
            Layout.fillWidth: true
            Layout.fillHeight: true
            wrapMode: TextEdit.WrapAnywhere
        }
        RowLayout {
            Layout.alignment: Qt.AlignHCenter
            Button {
                text: "Encode"
                onClicked: outputField.text = urlTool.base64Encode(inputField.text)
            }
            Button {
                text: "Decode"
                onClicked: outputField.text = urlTool.base64Decode(inputField.text)
            }
        }
        OutputArea {
            id: outputField
            placeholderText: "Output text..."
            readOnly: true
            Layout.fillWidth: true
            Layout.fillHeight: true
            wrapMode: TextEdit.WrapAnywhere
        }
    }
}
