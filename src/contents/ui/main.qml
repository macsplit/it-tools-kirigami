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
    BaseTool { id: baseTool }

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
            },
            Kirigami.Action {
                text: "Integer Base Converter"
                onTriggered: root.pageStack.replace(baseConverterPage)
                visible: text.toLowerCase().includes(searchField.text.toLowerCase())
            },
            Kirigami.Action {
                text: "MAC Address Generator"
                onTriggered: root.pageStack.replace(macGeneratorPage)
                visible: text.toLowerCase().includes(searchField.text.toLowerCase())
            },
            Kirigami.Action {
                text: "Random Port Generator"
                onTriggered: root.pageStack.replace(portGeneratorPage)
                visible: text.toLowerCase().includes(searchField.text.toLowerCase())
            },
            Kirigami.Action {
                text: "Color Converter"
                onTriggered: root.pageStack.replace(colorConverterPage)
                visible: text.toLowerCase().includes(searchField.text.toLowerCase())
            },
            Kirigami.Action {
                text: "Slugify String"
                onTriggered: root.pageStack.replace(slugifyPage)
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

    Component {
        id: baseConverterPage
        Kirigami.Page {
            title: "Integer Base Converter"
            ColumnLayout {
                anchors.fill: parent
                anchors.margins: Kirigami.Units.largeSpacing
                spacing: Kirigami.Units.smallSpacing

                Label { text: "Input number:"; font.bold: true }
                TextField {
                    id: baseInput
                    text: "42"
                    Layout.fillWidth: true
                }
                Label { text: "Input base:"; font.bold: true }
                SpinBox {
                    id: fromBase
                    from: 2; to: 64; value: 10; editable: true
                }

                Label { text: "Binary (2):"; font.bold: true }
                TextField { readOnly: true; Layout.fillWidth: true; text: baseTool.convert(baseInput.text, fromBase.value, 2) }
                Label { text: "Octal (8):"; font.bold: true }
                TextField { readOnly: true; Layout.fillWidth: true; text: baseTool.convert(baseInput.text, fromBase.value, 8) }
                Label { text: "Decimal (10):"; font.bold: true }
                TextField { readOnly: true; Layout.fillWidth: true; text: baseTool.convert(baseInput.text, fromBase.value, 10) }
                Label { text: "Hexadecimal (16):"; font.bold: true }
                TextField { readOnly: true; Layout.fillWidth: true; text: baseTool.convert(baseInput.text, fromBase.value, 16) }
                
                Item { Layout.fillHeight: true }
            }
        }
    }

    Component {
        id: macGeneratorPage
        Kirigami.Page {
            title: "MAC Address Generator"
            ColumnLayout {
                anchors.fill: parent
                anchors.margins: Kirigami.Units.largeSpacing
                spacing: Kirigami.Units.smallSpacing

                Label { text: "Generated MAC Address:"; font.bold: true }
                TextField {
                    id: macOutput
                    readOnly: true
                    Layout.fillWidth: true
                }
                Button {
                    text: "Generate"
                    onClicked: {
                        var mac = "";
                        for (var i = 0; i < 6; i++) {
                            var val = Math.floor(Math.random() * 256);
                            var hex = ("0" + val.toString(16)).slice(-2);
                            mac += hex + (i < 5 ? ":" : "");
                        }
                        macOutput.text = mac.toUpperCase();
                    }
                    Layout.alignment: Qt.AlignLeft
                }
                Item { Layout.fillHeight: true }
            }
        }
    }

    Component {
        id: portGeneratorPage
        Kirigami.Page {
            title: "Random Port Generator"
            ColumnLayout {
                anchors.fill: parent
                anchors.margins: Kirigami.Units.largeSpacing
                spacing: Kirigami.Units.smallSpacing

                Label { text: "Generated Port:"; font.bold: true }
                TextField {
                    id: portOutput
                    readOnly: true
                    Layout.fillWidth: true
                }
                Button {
                    text: "Generate"
                    onClicked: {
                        // 1024 - 65535
                        portOutput.text = Math.floor(Math.random() * (65535 - 1024 + 1) + 1024).toString();
                    }
                    Layout.alignment: Qt.AlignLeft
                }
                Item { Layout.fillHeight: true }
            }
        }
    }

    Component {
        id: colorConverterPage
        Kirigami.Page {
            title: "Color Converter"
            ColumnLayout {
                anchors.fill: parent
                anchors.margins: Kirigami.Units.largeSpacing
                spacing: Kirigami.Units.smallSpacing

                Label { text: "Hex Color:"; font.bold: true }
                TextField {
                    id: hexInput
                    text: "#1EA54C"
                    Layout.fillWidth: true
                    onTextChanged: if (activeFocus) updateFromHex(text)
                }
                Label { text: "RGB:"; font.bold: true }
                TextField {
                    id: rgbInput
                    Layout.fillWidth: true
                    onTextChanged: if (activeFocus) updateFromRgb(text)
                }
                Label { text: "HSL:"; font.bold: true }
                TextField {
                    id: hslInput
                    Layout.fillWidth: true
                    onTextChanged: if (activeFocus) updateFromHsl(text)
                }
                
                Rectangle {
                    Layout.fillWidth: true
                    height: 100
                    color: hexInput.text.match(/^#[0-9a-fA-F]{6}$/) ? hexInput.text : "transparent"
                    border.color: "black"
                }

                Item { Layout.fillHeight: true }
            }

            function pad2(n) {
                var s = n.toString(16);
                return s.length < 2 ? "0" + s : s;
            }

            function updateFromHex(hex) {
                if (!hex.match(/^#[0-9a-fA-F]{6}$/)) return;
                var r = parseInt(hex.slice(1, 3), 16);
                var g = parseInt(hex.slice(3, 5), 16);
                var b = parseInt(hex.slice(5, 7), 16);
                rgbInput.text = "rgb(" + r + ", " + g + ", " + b + ")";
                
                r /= 255; g /= 255; b /= 255;
                var max = Math.max(r, g, b), min = Math.min(r, g, b);
                var h, s, l = (max + min) / 2;
                if (max === min) { h = s = 0; }
                else {
                    var d = max - min;
                    s = l > 0.5 ? d / (2 - max - min) : d / (max + min);
                    switch (max) {
                        case r: h = (g - b) / d + (g < b ? 6 : 0); break;
                        case g: h = (b - r) / d + 2; break;
                        case b: h = (r - g) / d + 4; break;
                    }
                    h /= 6;
                }
                hslInput.text = "hsl(" + Math.round(h * 360) + ", " + Math.round(s * 100) + "%, " + Math.round(l * 100) + "%)";
            }

            function updateFromRgb(rgb) {
                var m = rgb.match(/rgb\((\d+),\s*(\d+),\s*(\d+)\)/);
                if (!m) return;
                var r = parseInt(m[1]), g = parseInt(m[2]), b = parseInt(m[3]);
                var hex = "#" + pad2(r) + pad2(g) + pad2(b);
                hexInput.text = hex.toUpperCase();
                
                r /= 255; g /= 255; b /= 255;
                var max = Math.max(r, g, b), min = Math.min(r, g, b);
                var h, s, l = (max + min) / 2;
                if (max === min) { h = s = 0; }
                else {
                    var d = max - min;
                    s = l > 0.5 ? d / (2 - max - min) : d / (max + min);
                    switch (max) {
                        case r: h = (g - b) / d + (g < b ? 6 : 0); break;
                        case g: h = (b - r) / d + 2; break;
                        case b: h = (r - g) / d + 4; break;
                    }
                    h /= 6;
                }
                hslInput.text = "hsl(" + Math.round(h * 360) + ", " + Math.round(s * 100) + "%, " + Math.round(l * 100) + "%)";
            }

            function updateFromHsl(hsl) {
                var m = hsl.match(/hsl\((\d+),\s*(\d+)%,\s*(\d+)%\)/);
                if (!m) return;
                var h = parseInt(m[1]) / 360;
                var s = parseInt(m[2]) / 100;
                var l = parseInt(m[3]) / 100;

                var r, g, b;
                if (s === 0) {
                    r = g = b = l;
                } else {
                    var hue2rgb = function(p, q, t) {
                        if (t < 0) t += 1;
                        if (t > 1) t -= 1;
                        if (t < 1/6) return p + (q - p) * 6 * t;
                        if (t < 1/2) return q;
                        if (t < 2/3) return p + (q - p) * (2/3 - t) * 6;
                        return p;
                    };
                    var q = l < 0.5 ? l * (1 + s) : l + s - l * s;
                    var p = 2 * l - q;
                    r = hue2rgb(p, q, h + 1/3);
                    g = hue2rgb(p, q, h);
                    b = hue2rgb(p, q, h - 1/3);
                }

                var ri = Math.round(r * 255), gi = Math.round(g * 255), bi = Math.round(b * 255);
                var hex = "#" + pad2(ri) + pad2(gi) + pad2(bi);
                hexInput.text = hex.toUpperCase();
                rgbInput.text = "rgb(" + ri + ", " + gi + ", " + bi + ")";
            }
            
            Component.onCompleted: updateFromHex(hexInput.text)
        }
    }

    Component {
        id: slugifyPage
        Kirigami.Page {
            title: "Slugify String"
            ColumnLayout {
                anchors.fill: parent
                anchors.margins: Kirigami.Units.largeSpacing
                spacing: Kirigami.Units.smallSpacing

                Label { text: "Input string:"; font.bold: true }
                TextField {
                    id: slugInput
                    placeholderText: "Type something..."
                    Layout.fillWidth: true
                }
                Label { text: "Slug:"; font.bold: true }
                TextField {
                    readOnly: true
                    Layout.fillWidth: true
                    text: slugInput.text.toLowerCase()
                                    .trim()
                                    .replace(/[^\w\s-]/g, '')
                                    .replace(/[\s_-]+/g, '-')
                                    .replace(/^-+|-+$/g, '')
                }
                Item { Layout.fillHeight: true }
            }
        }
    }

    // Helper for showing temporary messages
    function showMessage(msg) {
        root.showPassiveNotification(msg)
    }
}
