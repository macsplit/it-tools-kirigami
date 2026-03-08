import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.ScrollablePage {
    title: "JSON Formatter / Minifier"
    ColumnLayout {
        width: parent.width
        spacing: Kirigami.Units.largeSpacing
        TextArea {
            id: jsonInput
            placeholderText: "Paste JSON here..."
            Layout.fillWidth: true
            Layout.preferredHeight: 300
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
