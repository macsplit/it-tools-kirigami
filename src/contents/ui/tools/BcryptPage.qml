import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.ScrollablePage {
    id: root
    title: "Bcrypt Password Hash"

    property string generatedHash: ""

    ColumnLayout {
        width: parent.width
        spacing: Kirigami.Units.largeSpacing

        Label { text: "Password to hash"; font.bold: true }
        AppTextArea {
            id: passwordInput
            Layout.fillWidth: true
            Layout.preferredHeight: 100
            placeholderText: "Enter the password to hash..."
        }

        RowLayout {
            Layout.fillWidth: true

            Label { text: "Cost"; font.bold: true }
            SpinBox {
                id: costInput
                from: 4
                to: 15
                value: 12
            }
            Button {
                text: "Generate Hash"
                enabled: passwordInput.text.length > 0
                onClicked: root.generatedHash = hashTool.bcryptHash(passwordInput.text, costInput.value)
            }
        }

        Label { text: "Generated bcrypt hash"; font.bold: true }
        OutputArea {
            Layout.fillWidth: true
            Layout.preferredHeight: 120
            font.family: "monospace"
            wrapMode: TextEdit.NoWrap
            text: root.generatedHash
            placeholderText: "Generated bcrypt hash appears here..."
        }

        Label { text: "Password to verify"; font.bold: true }
        AppTextArea {
            id: verifyPasswordInput
            Layout.fillWidth: true
            Layout.preferredHeight: 80
            placeholderText: "Enter the password to verify..."
        }

        Label { text: "Hash to verify against"; font.bold: true }
        AppTextArea {
            id: verifyHashInput
            Layout.fillWidth: true
            Layout.preferredHeight: 120
            wrapMode: TextEdit.NoWrap
            placeholderText: "Paste a bcrypt hash here..."
        }

        Label { text: "Verification result"; font.bold: true }
        OutputField {
            Layout.fillWidth: true
            readOnly: true
            text: {
                if (!verifyPasswordInput.text.length || !verifyHashInput.text.length) {
                    return "";
                }

                return hashTool.verifyBcrypt(verifyPasswordInput.text, verifyHashInput.text)
                    ? "Password matches hash"
                    : "Password does not match hash";
            }
        }
    }
}
