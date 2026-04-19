import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.ScrollablePage {
    title: "IPv4 Range Expander"

    property var rangeData: networkTool.expandIpv4Range(rangeInput.text)

    ColumnLayout {
        width: parent.width
        spacing: Kirigami.Units.largeSpacing

        Label {
            text: "IPv4 address, range, or CIDR block"
            font.bold: true
        }

        AppTextField {
            id: rangeInput
            Layout.fillWidth: true
            text: "192.168.0.10-192.168.0.15"
            placeholderText: "192.168.0.10-192.168.0.15 or 192.168.0.0/30"
        }

        Kirigami.FormLayout {
            Layout.fillWidth: true
            wideMode: true

            OutputField {
                Kirigami.FormData.label: "Start:"
                Layout.fillWidth: true
                readOnly: true
                text: rangeData.start || ""
            }

            OutputField {
                Kirigami.FormData.label: "End:"
                Layout.fillWidth: true
                readOnly: true
                text: rangeData.end || ""
            }

            OutputField {
                Kirigami.FormData.label: "Count:"
                Layout.fillWidth: true
                readOnly: true
                text: rangeData.count || ""
            }

            OutputField {
                Kirigami.FormData.label: "Status:"
                Layout.fillWidth: true
                readOnly: true
                text: rangeData.valid ? "Expanded" : (rangeData.error || "")
            }
        }

        Label {
            text: "Expanded addresses"
            font.bold: true
        }

        OutputArea {
            Layout.fillWidth: true
            Layout.preferredHeight: Kirigami.Units.gridUnit * 12
            text: rangeData.items || ""
        }
    }
}
