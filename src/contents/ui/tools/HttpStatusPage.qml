import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.ScrollablePage {
    title: "HTTP Status Codes"

    ListModel {
        id: statusModel
        ListElement { code: "100"; name: "Continue"; desc: "Everything so far is OK and the client should continue with the request." }
        ListElement { code: "101"; name: "Switching Protocols"; desc: "The server is switching protocols as requested by the client." }
        ListElement { code: "200"; name: "OK"; desc: "The request has succeeded." }
        ListElement { code: "201"; name: "Created"; desc: "The request has succeeded and a new resource has been created." }
        ListElement { code: "202"; name: "Accepted"; desc: "The request has been received but not yet acted upon." }
        ListElement { code: "204"; name: "No Content"; desc: "There is no content to send for this request." }
        ListElement { code: "301"; name: "Moved Permanently"; desc: "The URL of the requested resource has been changed permanently." }
        ListElement { code: "302"; name: "Found"; desc: "The URL of the requested resource has been changed temporarily." }
        ListElement { code: "304"; name: "Not Modified"; desc: "The client can continue to use the cached version of the response." }
        ListElement { code: "400"; name: "Bad Request"; desc: "The server could not understand the request due to invalid syntax." }
        ListElement { code: "401"; name: "Unauthorized"; desc: "The client must authenticate itself to get the requested response." }
        ListElement { code: "403"; name: "Forbidden"; desc: "The client does not have access rights to the content." }
        ListElement { code: "404"; name: "Not Found"; desc: "The server can not find requested resource." }
        ListElement { code: "405"; name: "Method Not Allowed"; desc: "The request method is known by the server but has been disabled." }
        ListElement { code: "408"; name: "Request Timeout"; desc: "The server would like to shut down this unused connection." }
        ListElement { code: "429"; name: "Too Many Requests"; desc: "The user has sent too many requests in a given amount of time." }
        ListElement { code: "500"; name: "Internal Server Error"; desc: "The server has encountered a situation it doesn't know how to handle." }
        ListElement { code: "501"; name: "Not Implemented"; desc: "The request method is not supported by the server." }
        ListElement { code: "502"; name: "Bad Gateway"; desc: "The server got an invalid response while working as a gateway." }
        ListElement { code: "503"; name: "Service Unavailable"; desc: "The server is not ready to handle the request." }
        ListElement { code: "504"; name: "Gateway Timeout"; desc: "The server is acting as a gateway and cannot get a response in time." }
    }

    ColumnLayout {
        width: parent.width
        spacing: Kirigami.Units.largeSpacing

        Kirigami.SearchField {
            id: statusSearch
            placeholderText: "Search by code or name..."
            Layout.fillWidth: true
        }

        Repeater {
            model: statusModel
            delegate: Kirigami.AbstractCard {
                Layout.fillWidth: true
                visible: code.includes(statusSearch.text) || name.toLowerCase().includes(statusSearch.text.toLowerCase())
                height: visible ? implicitHeight : 0
                
                contentItem: ColumnLayout {
                    RowLayout {
                        Label {
                            text: code
                            font.bold: true
                            font.pixelSize: 20
                            color: Kirigami.Theme.highlightColor
                        }
                        Label {
                            text: name
                            font.bold: true
                            font.pixelSize: 18
                        }
                    }
                    Label {
                        text: desc
                        wrapMode: Text.WordWrap
                        Layout.fillWidth: true
                        opacity: 0.8
                    }
                }
            }
        }
    }
}
