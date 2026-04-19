import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.ScrollablePage {
    title: "TOML to JSON"

    ColumnLayout {
        width: parent.width
        spacing: Kirigami.Units.largeSpacing

        Label { text: "Your TOML content:"; font.bold: true }
        AppTextArea {
            id: tomlInput
            placeholderText: "Paste your TOML here..."
            Layout.fillWidth: true
            Layout.preferredHeight: 200
            font.family: "monospace"
            text: 'name = "Tools"\nfeatures = ["offline", "local"]\n\n[owner]\nname = "macsplit"'
        }

        Label { text: "Converted JSON:"; font.bold: true }
        OutputArea {
            readOnly: true
            Layout.fillWidth: true
            Layout.preferredHeight: 220
            font.family: "monospace"
            text: conversionTool.tomlToJson(tomlInput.text)
        }
    }
}
