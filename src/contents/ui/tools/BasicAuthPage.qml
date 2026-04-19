import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.Page {
    title: "Basic Auth Generator"
    ColumnLayout {
        anchors.fill: parent
        anchors.margins: Kirigami.Units.largeSpacing
        
        Kirigami.FormLayout {
            AppTextField {
                id: usernameField
                Kirigami.FormData.label: "Username:"
                placeholderText: "Username"
                Layout.fillWidth: true
            }
            AppTextField {
                id: passwordField
                Kirigami.FormData.label: "Password:"
                placeholderText: "Password"
                echoMode: TextField.Password
                Layout.fillWidth: true
            }
        }
        
        Label {
            text: "Authorization header:"
            font.bold: true
        }
        
        OutputArea {
            id: outputField
            text: urlTool.basicAuthHeader(usernameField.text, passwordField.text)
            readOnly: true
            Layout.fillWidth: true
            wrapMode: TextEdit.WrapAnywhere
            font.family: "monospace"
            copiedMessage: "Header copied to clipboard"
        }

        Item { Layout.fillHeight: true }
    }
}
