import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.ScrollablePage {
    title: "JSON Minify"

    ColumnLayout {
        width: parent.width
        spacing: Kirigami.Units.largeSpacing

        Label {
            text: "JSON to minify:"
            font.bold: true
        }

        AppTextArea {
            id: jsonInput
            Layout.fillWidth: true
            Layout.preferredHeight: 180
            font.family: "monospace"
            placeholderText: "Paste JSON here..."
            showPasteButton: true
        }

        Label {
            text: "Minified JSON:"
            font.bold: true
        }

        OutputArea {
            Layout.fillWidth: true
            Layout.preferredHeight: 180
            font.family: "monospace"
            wrapMode: TextEdit.WrapAnywhere
            text: conversionTool.jsonMinify(jsonInput.text)
            placeholderText: "Minified JSON will appear here..."
        }
    }
}
