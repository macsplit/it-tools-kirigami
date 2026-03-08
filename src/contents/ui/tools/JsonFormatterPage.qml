import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

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
