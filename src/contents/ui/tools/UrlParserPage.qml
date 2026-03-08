import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.ScrollablePage {
    title: "URL Parser"

    property var urlData: urlTool.parse(urlInput.text)

    ColumnLayout {
        width: parent.width
        spacing: Kirigami.Units.largeSpacing

        Label { text: "URL to parse:"; font.bold: true }
        TextField {
            id: urlInput
            text: "https://me:pwd@it-tools.tech:3000/url-parser?key1=value&key2=value2#the-hash"
            Layout.fillWidth: true
        }

        Kirigami.FormLayout {
            Layout.fillWidth: true
            wideMode: true

            TextField {
                Kirigami.FormData.label: "Protocol:"
                text: urlData.scheme || ""
                readOnly: true
                Layout.fillWidth: true
            }
            TextField {
                Kirigami.FormData.label: "Username:"
                text: urlData.username || ""
                readOnly: true
                Layout.fillWidth: true
            }
            TextField {
                Kirigami.FormData.label: "Password:"
                text: urlData.password || ""
                readOnly: true
                Layout.fillWidth: true
            }
            TextField {
                Kirigami.FormData.label: "Hostname:"
                text: urlData.host || ""
                readOnly: true
                Layout.fillWidth: true
            }
            TextField {
                Kirigami.FormData.label: "Port:"
                text: urlData.port || ""
                readOnly: true
                Layout.fillWidth: true
            }
            TextField {
                Kirigami.FormData.label: "Path:"
                text: urlData.path || ""
                readOnly: true
                Layout.fillWidth: true
            }
            TextField {
                Kirigami.FormData.label: "Query:"
                text: urlData.query || ""
                readOnly: true
                Layout.fillWidth: true
            }
            TextField {
                Kirigami.FormData.label: "Fragment:"
                text: urlData.fragment || ""
                readOnly: true
                Layout.fillWidth: true
            }
        }

        Label { text: "Query Parameters:"; font.bold: true; visible: Object.keys(urlData.params || {}).length > 0 }
        
        Repeater {
            model: urlData.params ? Object.keys(urlData.params) : []
            delegate: RowLayout {
                Layout.fillWidth: true
                TextField {
                    text: modelData
                    readOnly: true
                    Layout.fillWidth: true
                }
                TextField {
                    text: urlData.params[modelData]
                    readOnly: true
                    Layout.fillWidth: true
                }
            }
        }
    }
}
