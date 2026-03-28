import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.ScrollablePage {
    title: "IPv4 Subnet Calculator"

    property var subnetData: networkTool.ipv4Subnet(cidrInput.text)

    ColumnLayout {
        width: parent.width
        spacing: Kirigami.Units.largeSpacing

        Label { text: "CIDR Notation (IP/Mask):"; font.bold: true }
        AppTextField {
            id: cidrInput
            text: "192.168.0.1/24"
            Layout.fillWidth: true
        }

        Kirigami.FormLayout {
            Layout.fillWidth: true
            wideMode: true

            OutputField {
                Kirigami.FormData.label: "Netmask:"
                text: subnetData.netmask || ""
                readOnly: true
                Layout.fillWidth: true
            }
            OutputField {
                Kirigami.FormData.label: "Network:"
                text: subnetData.network || ""
                readOnly: true
                Layout.fillWidth: true
            }
            OutputField {
                Kirigami.FormData.label: "Broadcast:"
                text: subnetData.broadcast || ""
                readOnly: true
                Layout.fillWidth: true
            }
            OutputField {
                Kirigami.FormData.label: "First IP:"
                text: subnetData.first || ""
                readOnly: true
                Layout.fillWidth: true
            }
            OutputField {
                Kirigami.FormData.label: "Last IP:"
                text: subnetData.last || ""
                readOnly: true
                Layout.fillWidth: true
            }
            OutputField {
                Kirigami.FormData.label: "Hosts:"
                text: subnetData.size || ""
                readOnly: true
                Layout.fillWidth: true
            }
            OutputField {
                Kirigami.FormData.label: "Mask Binary:"
                text: subnetData.maskBinary || ""
                readOnly: true
                Layout.fillWidth: true
            }
        }
    }
}
