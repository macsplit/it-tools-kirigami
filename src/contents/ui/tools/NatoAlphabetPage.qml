import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.Page {
    title: "Text to NATO Alphabet"

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: Kirigami.Units.largeSpacing
        
        AppTextArea {
            id: inputField
            placeholderText: "Input text..."
            Layout.fillWidth: true
            Layout.fillHeight: true
            wrapMode: TextEdit.WrapAnywhere
            onTextChanged: outputField.text = textTool.convertToNato(text)
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
