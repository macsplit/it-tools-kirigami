import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.ScrollablePage {
    title: "String Obfuscator"

    ColumnLayout {
        width: parent.width
        spacing: Kirigami.Units.largeSpacing

        Label { text: "String to obfuscate:"; font.bold: true }
        TextArea {
            id: obfuscateInput
            placeholderText: "Enter string to obfuscate..."
            Layout.fillWidth: true
            Layout.preferredHeight: 100
            text: "Lorem ipsum dolor sit amet"
        }

        RowLayout {
            spacing: Kirigami.Units.largeSpacing
            ColumnLayout {
                Label { text: "Keep first:" }
                SpinBox { id: keepFirst; from: 0; to: 100; value: 4; editable: true }
            }
            ColumnLayout {
                Label { text: "Keep last:" }
                SpinBox { id: keepLast; from: 0; to: 100; value: 4; editable: true }
            }
            ColumnLayout {
                Label { text: "Keep spaces:" }
                CheckBox { id: keepSpace; checked: true }
            }
        }

        Label { text: "Obfuscated String:"; font.bold: true }
        TextArea {
            readOnly: true
            Layout.fillWidth: true
            Layout.preferredHeight: 100
            font.family: "monospace"
            text: obfuscate(obfuscateInput.text, keepFirst.value, keepLast.value, keepSpace.checked)
        }
    }

    function obfuscate(str, first, last, spaces) {
        if (!str) return "";
        var res = "";
        for (var i = 0; i < str.length; i++) {
            if (i < first || i >= str.length - last) {
                res += str[i];
            } else if (spaces && str[i] === ' ') {
                res += ' ';
            } else {
                res += '*';
            }
        }
        return res;
    }
}
