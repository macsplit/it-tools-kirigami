import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.ScrollablePage {
    title: "ULID Generator"

    ColumnLayout {
        width: parent.width
        spacing: Kirigami.Units.largeSpacing

        Label {
            text: "Quantity:"
            font.bold: true
        }

        SpinBox {
            id: quantityInput
            from: 1
            to: 100
            value: 1
            editable: true
        }

        Label {
            text: "Format:"
            font.bold: true
        }

        ComboBox {
            id: formatInput
            model: ["Raw", "JSON"]
        }

        Label {
            text: "Generated ULIDs:"
            font.bold: true
        }

        OutputArea {
            id: outputField
            Layout.fillWidth: true
            Layout.preferredHeight: 220
            font.family: "monospace"
            placeholderText: "Generated ULIDs will appear here"
        }

        Button {
            text: "Generate"
            Layout.alignment: Qt.AlignLeft
            onClicked: outputField.text = idTool.generateUlids(quantityInput.value, formatInput.currentText)
        }
    }

    Component.onCompleted: outputField.text = idTool.generateUlids(quantityInput.value, formatInput.currentText)
}
