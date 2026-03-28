import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.Page {
    title: "JSON to YAML"
    ColumnLayout {
        anchors.fill: parent
        anchors.margins: Kirigami.Units.largeSpacing
        AppTextArea {
            id: jsonYamlInput
            placeholderText: "Paste JSON here..."
            Layout.fillWidth: true
            Layout.fillHeight: true
            font.family: "monospace"
        }
        OutputArea {
            placeholderText: "YAML output will appear here..."
            readOnly: true
            Layout.fillWidth: true
            Layout.fillHeight: true
            font.family: "monospace"
            text: conversionTool.jsonToYaml(jsonYamlInput.text)
        }
    }
}
