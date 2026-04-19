import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.Page {
    title: "Case Converter"

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: Kirigami.Units.largeSpacing
        AppTextArea {
            id: caseInputField
            placeholderText: "Input text..."
            Layout.fillWidth: true
            Layout.fillHeight: true
            showPasteButton: true
            showCopyButton: true
        }
        Flow {
            Layout.fillWidth: true
            spacing: Kirigami.Units.largeSpacing
            Button {
                text: "UPPERCASE"
                onClicked: caseInputField.text = textTool.convertCase(caseInputField.text, "upper")
            }
            Button {
                text: "lowercase"
                onClicked: caseInputField.text = textTool.convertCase(caseInputField.text, "lower")
            }
            Button {
                text: "camelCase"
                onClicked: caseInputField.text = textTool.convertCase(caseInputField.text, "camel")
            }
            Button {
                text: "PascalCase"
                onClicked: caseInputField.text = textTool.convertCase(caseInputField.text, "pascal")
            }
            Button {
                text: "snake_case"
                onClicked: caseInputField.text = textTool.convertCase(caseInputField.text, "snake")
            }
            Button {
                text: "kebab-case"
                onClicked: caseInputField.text = textTool.convertCase(caseInputField.text, "kebab")
            }
        }
    }
}
