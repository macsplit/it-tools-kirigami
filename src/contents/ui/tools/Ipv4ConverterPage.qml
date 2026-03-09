import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.ScrollablePage {
    title: "IPv4 Address Converter"

    property var ipData: networkTool.ipv4Convert(ipInput.text)

    ColumnLayout {
        width: parent.width
        spacing: Kirigami.Units.largeSpacing

        Label { text: "IPv4 Address:"; font.bold: true }
        TextField {
            id: ipInput
            text: "192.168.1.1"
            Layout.fillWidth: true
        }

        Kirigami.FormLayout {
            Layout.fillWidth: true
            wideMode: true

            TextField {
                Kirigami.FormData.label: "Decimal:"
                text: ipData.decimal || ""
                readOnly: true
                Layout.fillWidth: true
            }
            TextField {
                Kirigami.FormData.label: "Hexadecimal:"
                text: ipData.hex || ""
                readOnly: true
                Layout.fillWidth: true
            }
            TextField {
                Kirigami.FormData.label: "Binary:"
                text: ipData.binary || ""
                readOnly: true
                Layout.fillWidth: true
            }
            TextField {
                Kirigami.FormData.label: "IPv6 (mapped):"
                text: ipData.ipv6 || ""
                readOnly: true
                Layout.fillWidth: true
            }
        }
    }
}
