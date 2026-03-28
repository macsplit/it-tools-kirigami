import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.ScrollablePage {
    function showError(message) {
        var window = applicationWindow();
        if (window && window.showMessage) {
            window.showMessage(message);
        }
    }

    title: "JSON Formatter / Minifier"
    ColumnLayout {
        width: parent.width
        spacing: Kirigami.Units.largeSpacing
        AppTextArea {
            id: jsonInput
            placeholderText: "Paste JSON here..."
            Layout.fillWidth: true
            Layout.preferredHeight: 300
            font.family: "monospace"
            showPasteButton: true
            showCopyButton: true
        }
        RowLayout {
            Button {
                text: "Format"
                onClicked: {
                    try {
                        var obj = JSON.parse(jsonInput.text);
                        jsonInput.text = JSON.stringify(obj, null, 4);
                    } catch (e) {
                        showError("Invalid JSON format")
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
                        showError("Invalid JSON format")
                    }
                }
            }
        }
    }
}
