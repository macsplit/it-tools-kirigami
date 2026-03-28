import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.Page {
    title: "Integer Base Converter"
    ColumnLayout {
        anchors.fill: parent
        anchors.margins: Kirigami.Units.largeSpacing
        spacing: Kirigami.Units.smallSpacing

        Label { text: "Input number:"; font.bold: true }
        AppTextField {
            id: baseInput
            text: "42"
            Layout.fillWidth: true
        }
        Label { text: "Input base:"; font.bold: true }
        SpinBox {
            id: fromBase
            from: 2; to: 64; value: 10; editable: true
        }

        Label { text: "Binary (2):"; font.bold: true }
        OutputField { readOnly: true; Layout.fillWidth: true; text: baseTool.convert(baseInput.text, fromBase.value, 2) }
        Label { text: "Octal (8):"; font.bold: true }
        OutputField { readOnly: true; Layout.fillWidth: true; text: baseTool.convert(baseInput.text, fromBase.value, 8) }
        Label { text: "Decimal (10):"; font.bold: true }
        OutputField { readOnly: true; Layout.fillWidth: true; text: baseTool.convert(baseInput.text, fromBase.value, 10) }
        Label { text: "Hexadecimal (16):"; font.bold: true }
        OutputField { readOnly: true; Layout.fillWidth: true; text: baseTool.convert(baseInput.text, fromBase.value, 16) }
        
        Item { Layout.fillHeight: true }
    }
}
