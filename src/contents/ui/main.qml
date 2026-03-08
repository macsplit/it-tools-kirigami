import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Window 2.15
import org.kde.kirigami 2.19 as Kirigami
import ittools.kirigami 1.0

Kirigami.ApplicationWindow {
    id: root

    title: "IT-Tools Kirigami"
    width: 600
    height: 700

    HashTool { id: hashTool }

    globalDrawer: Kirigami.GlobalDrawer {
        isMenu: true
        header: Kirigami.SearchField {
            id: searchField
            focus: true
            placeholderText: "Search tools..."
        }

        actions: [
            Kirigami.Action {
                text: "Tools"
                visible: searchField.text === ""
            },
            Kirigami.Action {
                separator: true
                visible: searchField.text === ""
            },
            Kirigami.Action {
                text: "UUID Generator"
                onTriggered: root.pageStack.replace(uuidPage)
                visible: text.toLowerCase().includes(searchField.text.toLowerCase())
            },
            Kirigami.Action {
                text: "Base64 Converter"
                onTriggered: root.pageStack.replace(base64Page)
                visible: text.toLowerCase().includes(searchField.text.toLowerCase())
            },
            Kirigami.Action {
                text: "Case Converter"
                onTriggered: root.pageStack.replace(caseConverterPage)
                visible: text.toLowerCase().includes(searchField.text.toLowerCase())
            },
            Kirigami.Action {
                text: "JSON Formatter"
                onTriggered: root.pageStack.replace(jsonFormatterPage)
                visible: text.toLowerCase().includes(searchField.text.toLowerCase())
            },
            Kirigami.Action {
                text: "Token Generator"
                onTriggered: root.pageStack.replace(tokenGeneratorPage)
                visible: text.toLowerCase().includes(searchField.text.toLowerCase())
            },
            Kirigami.Action {
                text: "Lorem Ipsum"
                onTriggered: root.pageStack.replace(loremIpsumPage)
                visible: text.toLowerCase().includes(searchField.text.toLowerCase())
            },
            Kirigami.Action {
                text: "URL Encoder/Decoder"
                onTriggered: root.pageStack.replace(urlEncoderPage)
                visible: text.toLowerCase().includes(searchField.text.toLowerCase())
            },
            Kirigami.Action {
                text: "HTML Entities"
                onTriggered: root.pageStack.replace(htmlEntitiesPage)
                visible: text.toLowerCase().includes(searchField.text.toLowerCase())
            },
            Kirigami.Action {
                text: "Text Statistics"
                onTriggered: root.pageStack.replace(textStatisticsPage)
                visible: text.toLowerCase().includes(searchField.text.toLowerCase())
            },
            Kirigami.Action {
                text: "Chmod Calculator"
                onTriggered: root.pageStack.replace(chmodPage)
                visible: text.toLowerCase().includes(searchField.text.toLowerCase())
            },
            Kirigami.Action {
                text: "Hash Text"
                onTriggered: root.pageStack.replace(hashPage)
                visible: text.toLowerCase().includes(searchField.text.toLowerCase())
            },
            Kirigami.Action {
                text: "JWT Parser"
                onTriggered: root.pageStack.replace(jwtPage)
                visible: text.toLowerCase().includes(searchField.text.toLowerCase())
            }
        ]
    }

    pageStack.initialPage: welcomePage

    Component {
        id: welcomePage
        Kirigami.Page {
            title: "Welcome"
            Kirigami.PlaceholderMessage {
                anchors.centerIn: parent
                width: parent.width - (Kirigami.Units.largeSpacing * 4)
                text: "Welcome to IT-Tools"
                explanation: "Select a tool from the drawer to get started."
            }
        }
    }

    Component {
        id: uuidPage
        Kirigami.Page {
            title: "UUID Generator"
            ColumnLayout {
                anchors.fill: parent
                anchors.margins: Kirigami.Units.largeSpacing
                spacing: Kirigami.Units.smallSpacing

                Label {
                    text: "Generated UUID:"
                    font.bold: true
                }
                TextField {
                    id: uuidField
                    readOnly: true
                    Layout.fillWidth: true
                }
                Button {
                    text: "Generate"
                    onClicked: uuidField.text = generateUUID()
                    Layout.alignment: Qt.AlignLeft
                }
                Item { Layout.fillHeight: true }
            }
            function generateUUID() {
                return 'xxxxxxxx-xxxx-4xxx-yxxx-xxxxxxxxxxxx'.replace(/[xy]/g, function(c) {
                    var r = Math.random() * 16 | 0, v = c == 'x' ? r : (r & 0x3 | 0x8);
                    return v.toString(16);
                });
            }
        }
    }

    Component {
        id: base64Page
        Kirigami.Page {
            title: "Base64 Converter"
            ColumnLayout {
                anchors.fill: parent
                anchors.margins: Kirigami.Units.largeSpacing
                TextArea {
                    id: inputField
                    placeholderText: "Input text..."
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    wrapMode: TextEdit.WrapAnywhere
                }
                RowLayout {
                    Layout.alignment: Qt.AlignHCenter
                    Button {
                        text: "Encode"
                        onClicked: outputField.text = Qt.btoa(inputField.text)
                    }
                    Button {
                        text: "Decode"
                        onClicked: {
                            try {
                                outputField.text = Qt.atob(inputField.text)
                            } catch (e) {
                                outputField.text = "Error: Invalid Base64"
                            }
                        }
                    }
                }
                TextArea {
                    id: outputField
                    placeholderText: "Output text..."
                    readOnly: true
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    wrapMode: TextEdit.WrapAnywhere
                }
            }
        }
    }

    Component {
        id: caseConverterPage
        Kirigami.Page {
            title: "Case Converter"
            ColumnLayout {
                anchors.fill: parent
                anchors.margins: Kirigami.Units.largeSpacing
                TextArea {
                    id: caseInputField
                    placeholderText: "Input text..."
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                }
                RowLayout {
                    spacing: Kirigami.Units.largeSpacing
                    Button {
                        text: "UPPERCASE"
                        onClicked: caseInputField.text = caseInputField.text.toUpperCase()
                    }
                    Button {
                        text: "lowercase"
                        onClicked: caseInputField.text = caseInputField.text.toLowerCase()
                    }
                }
            }
        }
    }

    Component {
        id: jsonFormatterPage
        Kirigami.Page {
            title: "JSON Formatter"
            ColumnLayout {
                anchors.fill: parent
                anchors.margins: Kirigami.Units.largeSpacing
                TextArea {
                    id: jsonInput
                    placeholderText: "Paste JSON here..."
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    font.family: "monospace"
                }
                RowLayout {
                    Button {
                        text: "Format"
                        onClicked: {
                            try {
                                var obj = JSON.parse(jsonInput.text);
                                jsonInput.text = JSON.stringify(obj, null, 4);
                            } catch (e) {
                                root.showMessage("Invalid JSON format")
                            }
                        }
                    }
                    Button {
                        text: "Minify"
                        onClicked: {
                            try {
                                var obj = JSON.parse(jsonInput.text);
                                jsonInput.text = JSON.stringify(obj);
                            } catch (e) {
                                root.showMessage("Invalid JSON format")
                            }
                        }
                    }
                }
            }
        }
    }

    Component {
        id: tokenGeneratorPage
        Kirigami.Page {
            title: "Token Generator"
            ColumnLayout {
                anchors.fill: parent
                anchors.margins: Kirigami.Units.largeSpacing
                spacing: Kirigami.Units.smallSpacing

                Label {
                    text: "Length:"
                    font.bold: true
                }
                SpinBox {
                    id: tokenLength
                    from: 1
                    to: 128
                    value: 32
                    editable: true
                    Layout.fillWidth: false
                }
                
                Label {
                    text: "Token:"
                    font.bold: true
                }
                TextField {
                    id: tokenOutput
                    readOnly: true
                    Layout.fillWidth: true
                }
                Button {
                    text: "Generate"
                    onClicked: {
                        var charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+";
                        var retVal = "";
                        for (var i = 0; i < tokenLength.value; ++i) {
                            retVal += charset.charAt(Math.floor(Math.random() * charset.length));
                        }
                        tokenOutput.text = retVal;
                    }
                    Layout.alignment: Qt.AlignLeft
                }
                Item { Layout.fillHeight: true }
            }
        }
    }

    Component {
        id: loremIpsumPage
        Kirigami.Page {
            title: "Lorem Ipsum"
            ColumnLayout {
                anchors.fill: parent
                anchors.margins: Kirigami.Units.largeSpacing
                TextArea {
                    id: loremOutput
                    readOnly: true
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    wrapMode: TextEdit.WordWrap
                }
                Button {
                    text: "Generate Standard Paragraph"
                    onClicked: {
                        loremOutput.text = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
                    }
                }
            }
        }
    }

    Component {
        id: urlEncoderPage
        Kirigami.Page {
            title: "URL Encoder/Decoder"
            ColumnLayout {
                anchors.fill: parent
                anchors.margins: Kirigami.Units.largeSpacing
                TextArea {
                    id: urlInput
                    placeholderText: "Input text..."
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                }
                RowLayout {
                    Button {
                        text: "Encode"
                        onClicked: urlInput.text = encodeURIComponent(urlInput.text)
                    }
                    Button {
                        text: "Decode"
                        onClicked: {
                            try {
                                urlInput.text = decodeURIComponent(urlInput.text)
                            } catch (e) {
                                root.showMessage("Invalid URL encoding")
                            }
                        }
                    }
                }
            }
        }
    }

    Component {
        id: htmlEntitiesPage
        Kirigami.Page {
            title: "HTML Entities"
            ColumnLayout {
                anchors.fill: parent
                anchors.margins: Kirigami.Units.largeSpacing
                TextArea {
                    id: htmlInput
                    placeholderText: "Input text..."
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                }
                RowLayout {
                    Button {
                        text: "Encode"
                        onClicked: {
                            var entities = {
                                '&': '&amp;',
                                '<': '&lt;',
                                '>': '&gt;',
                                '"': '&quot;',
                                "'": '&#39;'
                            };
                            htmlInput.text = htmlInput.text.replace(/[&<>"']/g, function(m) {
                                return entities[m];
                            });
                        }
                    }
                    Button {
                        text: "Decode"
                        onClicked: {
                            var entities = {
                                '&amp;': '&',
                                '&lt;': '<',
                                '&gt;': '>',
                                '&quot;': '"',
                                '&#39;': "'",
                                '&apos;': "'"
                            };
                            htmlInput.text = htmlInput.text.replace(/&amp;|&lt;|&gt;|&quot;|&#39;|&apos;/g, function(m) {
                                return entities[m];
                            });
                        }
                    }
                }
            }
        }
    }

    Component {
        id: textStatisticsPage
        Kirigami.Page {
            title: "Text Statistics"
            ColumnLayout {
                anchors.fill: parent
                anchors.margins: Kirigami.Units.largeSpacing
                TextArea {
                    id: statsInput
                    placeholderText: "Input text..."
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                }
                ColumnLayout {
                    Layout.fillWidth: true
                    spacing: Kirigami.Units.smallSpacing
                    Label {
                        text: "Characters: " + statsInput.text.length
                        font.bold: true
                    }
                    Label {
                        text: "Words: " + statsInput.text.trim().split(/\s+/).filter(function(w) { return w !== ""; }).length
                        font.bold: true
                    }
                    Label {
                        text: "Lines: " + statsInput.text.split(/\r\n|\r|\n/).length
                        font.bold: true
                    }
                }
            }
        }
    }

    Component {
        id: chmodPage
        Kirigami.Page {
            title: "Chmod Calculator"
            ColumnLayout {
                anchors.fill: parent
                anchors.margins: Kirigami.Units.largeSpacing
                spacing: Kirigami.Units.largeSpacing

                GridLayout {
                    columns: 4
                    Layout.fillWidth: true
                    Label { text: "" }
                    Label { text: "Owner"; font.bold: true; horizontalAlignment: Text.AlignHCenter; Layout.fillWidth: true }
                    Label { text: "Group"; font.bold: true; horizontalAlignment: Text.AlignHCenter; Layout.fillWidth: true }
                    Label { text: "Public"; font.bold: true; horizontalAlignment: Text.AlignHCenter; Layout.fillWidth: true }

                    Label { text: "Read (4)"; font.bold: true }
                    CheckBox { id: ownerRead; Layout.alignment: Qt.AlignHCenter }
                    CheckBox { id: groupRead; Layout.alignment: Qt.AlignHCenter }
                    CheckBox { id: publicRead; Layout.alignment: Qt.AlignHCenter }

                    Label { text: "Write (2)"; font.bold: true }
                    CheckBox { id: ownerWrite; Layout.alignment: Qt.AlignHCenter }
                    CheckBox { id: groupWrite; Layout.alignment: Qt.AlignHCenter }
                    CheckBox { id: publicWrite; Layout.alignment: Qt.AlignHCenter }

                    Label { text: "Execute (1)"; font.bold: true }
                    CheckBox { id: ownerExec; Layout.alignment: Qt.AlignHCenter }
                    CheckBox { id: groupExec; Layout.alignment: Qt.AlignHCenter }
                    CheckBox { id: publicExec; Layout.alignment: Qt.AlignHCenter }
                }

                Label {
                    Layout.alignment: Qt.AlignHCenter
                    text: calculateOctal()
                    font.pixelSize: 48
                    font.family: "monospace"
                }

                Label {
                    Layout.alignment: Qt.AlignHCenter
                    text: calculateSymbolic()
                    font.pixelSize: 24
                    font.family: "monospace"
                }

                TextField {
                    Layout.fillWidth: true
                    readOnly: true
                    text: "chmod " + calculateOctal() + " path"
                }
                Item { Layout.fillHeight: true }
            }

            function calculateOctal() {
                var o = (ownerRead.checked ? 4 : 0) + (ownerWrite.checked ? 2 : 0) + (ownerExec.checked ? 1 : 0);
                var g = (groupRead.checked ? 4 : 0) + (groupWrite.checked ? 2 : 0) + (groupExec.checked ? 1 : 0);
                var p = (publicRead.checked ? 4 : 0) + (publicWrite.checked ? 2 : 0) + (publicExec.checked ? 1 : 0);
                return "" + o + g + p;
            }

            function calculateSymbolic() {
                var s = "";
                s += (ownerRead.checked ? "r" : "-");
                s += (ownerWrite.checked ? "w" : "-");
                s += (ownerExec.checked ? "x" : "-");
                s += (groupRead.checked ? "r" : "-");
                s += (groupWrite.checked ? "w" : "-");
                s += (groupExec.checked ? "x" : "-");
                s += (publicRead.checked ? "r" : "-");
                s += (publicWrite.checked ? "w" : "-");
                s += (publicExec.checked ? "x" : "-");
                return s;
            }
        }
    }

    Component {
        id: hashPage
        Kirigami.Page {
            title: "Hash Text"
            ColumnLayout {
                anchors.fill: parent
                anchors.margins: Kirigami.Units.largeSpacing
                TextArea {
                    id: hashInput
                    placeholderText: "Input text..."
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    wrapMode: TextEdit.WrapAnywhere
                }
                
                ColumnLayout {
                    Layout.fillWidth: true
                    spacing: Kirigami.Units.smallSpacing
                    Label { text: "MD5:"; font.bold: true }
                    TextField {
                        readOnly: true
                        Layout.fillWidth: true
                        text: hashTool.md5(hashInput.text)
                    }
                    Label { text: "SHA1:"; font.bold: true }
                    TextField {
                        readOnly: true
                        Layout.fillWidth: true
                        text: hashTool.sha1(hashInput.text)
                    }
                    Label { text: "SHA256:"; font.bold: true }
                    TextField {
                        readOnly: true
                        Layout.fillWidth: true
                        text: hashTool.sha256(hashInput.text)
                    }
                }
            }
        }
    }

    Component {
        id: jwtPage
        Kirigami.Page {
            title: "JWT Parser"
            ColumnLayout {
                anchors.fill: parent
                anchors.margins: Kirigami.Units.largeSpacing
                TextArea {
                    id: jwtInput
                    placeholderText: "Paste JWT here..."
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.preferredHeight: 100
                    wrapMode: TextEdit.WrapAnywhere
                }
                TextArea {
                    id: jwtHeaderOutput
                    placeholderText: "Header"
                    readOnly: true
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.preferredHeight: 100
                    font.family: "monospace"
                    text: parseJwt(jwtInput.text, 0)
                }
                TextArea {
                    id: jwtPayloadOutput
                    placeholderText: "Payload"
                    readOnly: true
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.preferredHeight: 200
                    font.family: "monospace"
                    text: parseJwt(jwtInput.text, 1)
                }
            }

            function parseJwt(token, part) {
                try {
                    var parts = token.split('.');
                    if (parts.length < 2) return "";
                    var base64Url = parts[part];
                    var base64 = base64Url.replace(/-/g, '+').replace(/_/g, '/');
                    while (base64.length % 4) base64 += '=';
                    var jsonPayload = Qt.atob(base64);
                    return JSON.stringify(JSON.parse(jsonPayload), null, 4);
                } catch (e) {
                    return "";
                }
            }
        }
    }

    // Helper for showing temporary messages
    function showMessage(msg) {
        root.showPassiveNotification(msg)
    }
}
