import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.Page {
    title: "Text to NATO Alphabet"
    
    property var natoAlphabet: [
        "Alpha", "Bravo", "Charlie", "Delta", "Echo", "Foxtrot", "Golf", "Hotel", "India",
        "Juliet", "Kilo", "Lima", "Mike", "November", "Oscar", "Papa", "Quebec", "Romeo",
        "Sierra", "Tango", "Uniform", "Victor", "Whiskey", "X-ray", "Yankee", "Zulu"
    ]
    
    function convertToNato(text) {
        return text.split("").map(function(character) {
            var code = character.toLowerCase().charCodeAt(0);
            if (code >= 97 && code <= 122) { // a-z
                return natoAlphabet[code - 97];
            }
            return character;
        }).join(" ");
    }

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: Kirigami.Units.largeSpacing
        
        AppTextArea {
            id: inputField
            placeholderText: "Input text..."
            Layout.fillWidth: true
            Layout.fillHeight: true
            wrapMode: TextEdit.WrapAnywhere
            onTextChanged: outputField.text = convertToNato(text)
        }
        
        OutputArea {
            id: outputField
            placeholderText: "NATO Alphabet output..."
            readOnly: true
            Layout.fillWidth: true
            Layout.fillHeight: true
            wrapMode: TextEdit.WrapAnywhere
            font.family: "monospace"
            copiedMessage: "Copied to clipboard"
        }
    }
}
