import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.ScrollablePage {
    title: "HMAC Generator"

    ColumnLayout {
        width: parent.width
        spacing: Kirigami.Units.largeSpacing

        Label { text: "Plain text to compute the hash:"; font.bold: true }
        TextArea {
            id: plainTextInput
            placeholderText: "Plain text..."
            Layout.fillWidth: true
            Layout.preferredHeight: 100
        }

        Label { text: "Secret key:"; font.bold: true }
        TextField {
            id: secretKeyInput
            placeholderText: "Enter the secret key..."
            Layout.fillWidth: true
        }

        RowLayout {
            spacing: Kirigami.Units.largeSpacing
            ColumnLayout {
                Label { text: "Hashing function:" }
                ComboBox {
                    id: algoSelect
                    model: ["SHA256", "SHA1", "MD5", "SHA512"]
                    Layout.preferredWidth: 150
                }
            }
        }

        Label { text: "HMAC Result:"; font.bold: true }
        TextArea {
            readOnly: true
            Layout.fillWidth: true
            Layout.preferredHeight: 100
            font.family: "monospace"
            text: hashTool.hmac(plainTextInput.text, secretKeyInput.text, algoSelect.currentText)
        }
    }
}
