import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.Page {
    title: "Hash Text"
    ColumnLayout {
        anchors.fill: parent
        anchors.margins: Kirigami.Units.largeSpacing
        AppTextArea {
            id: hashInput
            placeholderText: "Input text..."
            Layout.fillWidth: true
            Layout.fillHeight: true
            wrapMode: TextEdit.WrapAnywhere
        }
        
        ColumnLayout {
            Layout.fillWidth: true
            spacing: Kirigami.Units.smallSpacing
            Label { text: "MD5:"; font.bold: true }
            OutputField {
                readOnly: true
                Layout.fillWidth: true
                text: hashTool.md5(hashInput.text)
            }
            Label { text: "SHA1:"; font.bold: true }
            OutputField {
                readOnly: true
                Layout.fillWidth: true
                text: hashTool.sha1(hashInput.text)
            }
            Label { text: "SHA256:"; font.bold: true }
            OutputField {
                readOnly: true
                Layout.fillWidth: true
                text: hashTool.sha256(hashInput.text)
            }
        }
    }
}
