import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.ScrollablePage {
    title: "Email Normalizer"

    property var emailData: textTool.normalizeEmail(emailInput.text)

    ColumnLayout {
        width: parent.width
        spacing: Kirigami.Units.largeSpacing

        Label {
            text: "Email address"
            font.bold: true
        }

        AppTextField {
            id: emailInput
            Layout.fillWidth: true
            text: "John.Smith+alerts@googlemail.com"
            placeholderText: "name@example.com"
        }

        Kirigami.FormLayout {
            Layout.fillWidth: true
            wideMode: true

            OutputField {
                Kirigami.FormData.label: "Normalized:"
                Layout.fillWidth: true
                readOnly: true
                text: emailData.normalized || ""
            }

            OutputField {
                Kirigami.FormData.label: "Local part:"
                Layout.fillWidth: true
                readOnly: true
                text: emailData.localPart || ""
            }

            OutputField {
                Kirigami.FormData.label: "Domain:"
                Layout.fillWidth: true
                readOnly: true
                text: emailData.domain || ""
            }

            OutputField {
                Kirigami.FormData.label: "Provider:"
                Layout.fillWidth: true
                readOnly: true
                text: emailData.provider || ""
            }

            OutputField {
                Kirigami.FormData.label: "Notes:"
                Layout.fillWidth: true
                readOnly: true
                text: emailData.notes || emailData.error || ""
            }
        }
    }
}
