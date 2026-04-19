import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.ScrollablePage {
    title: "WiFi QR Code Generator"

    ColumnLayout {
        width: parent.width
        spacing: Kirigami.Units.largeSpacing

        Label { text: "SSID (Network Name):"; font.bold: true }
        AppTextField { id: ssidInput; Layout.fillWidth: true }

        Label { text: "Password:"; font.bold: true }
        AppTextField { id: passwordInput; Layout.fillWidth: true; echoMode: TextField.Password }

        Label { text: "Encryption:"; font.bold: true }
        ComboBox {
            id: encryptionType
            model: ["WPA", "WEP", "None"]
            Layout.fillWidth: true
        }

        Label { text: "WiFi QR Code Image:"; font.bold: true }
        
        Rectangle {
            Layout.alignment: Qt.AlignHCenter
            width: 200
            height: 200
            color: "white"
            Image {
                anchors.fill: parent
                anchors.margins: 10
                source: idTool.wifiQrImageSource(ssidInput.text, passwordInput.text, encryptionType.currentText)
                cache: false
            }
        }

        Label { text: "WiFi QR Code String:"; font.bold: true }
        OutputField {
            readOnly: true
            Layout.fillWidth: true
            text: idTool.wifiQrPayload(ssidInput.text, passwordInput.text, encryptionType.currentText)
        }
    }
}
