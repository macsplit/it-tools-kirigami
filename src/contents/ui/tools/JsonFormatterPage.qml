import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.ScrollablePage {
    function applyJsonResult(result) {
        if (result === "Invalid JSON format") {
            var window = applicationWindow();
            if (window && window.showMessage) {
                window.showMessage(result);
            }
            return;
        }

        jsonInput.text = result;
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
                onClicked: applyJsonResult(conversionTool.jsonFormat(jsonInput.text, 4))
            }
            Button {
                text: "Minify"
                onClicked: applyJsonResult(conversionTool.jsonMinify(jsonInput.text))
            }
        }
    }
}
