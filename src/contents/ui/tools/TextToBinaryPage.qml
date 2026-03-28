import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.ScrollablePage {
    title: "Text to Binary"

    ColumnLayout {
        width: parent.width
        spacing: Kirigami.Units.largeSpacing

        Label { text: "Text to convert:"; font.bold: true }
        AppTextArea {
            id: textInput
            placeholderText: "e.g. Hello world"
            Layout.fillWidth: true
            Layout.preferredHeight: 100
        }

        Label { text: "Binary representation:"; font.bold: true }
        OutputArea {
            readOnly: true
            Layout.fillWidth: true
            Layout.preferredHeight: 100
            font.family: "monospace"
            text: textToBinary(textInput.text)
        }

        Label { text: "Binary to convert:"; font.bold: true }
        AppTextArea {
            id: binaryInput
            placeholderText: "e.g. 01001000 01100101..."
            Layout.fillWidth: true
            Layout.preferredHeight: 100
        }

        Label { text: "Text representation:"; font.bold: true }
        OutputArea {
            readOnly: true
            Layout.fillWidth: true
            Layout.preferredHeight: 100
            text: binaryToText(binaryInput.text)
        }
    }

    function textToBinary(str) {
        if (!str) return "";
        var res = "";
        for (var i = 0; i < str.length; i++) {
            var bin = str.charCodeAt(i).toString(2);
            res += "00000000".slice(bin.length) + bin + " ";
        }
        return res.trim();
    }

    function binaryToText(bin) {
        if (!bin) return "";
        try {
            var bins = bin.trim().split(/\s+/);
            var res = "";
            for (var i = 0; i < bins.length; i++) {
                res += String.fromCharCode(parseInt(bins[i], 2));
            }
            return res;
        } catch (e) {
            return "Invalid binary";
        }
    }
}
