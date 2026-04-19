import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.Page {
    title: "Color Converter"
    ColumnLayout {
        anchors.fill: parent
        anchors.margins: Kirigami.Units.largeSpacing
        spacing: Kirigami.Units.smallSpacing

        Label { text: "Hex Color:"; font.bold: true }
        AppTextField {
            id: hexInput
            text: "#1EA54C"
            Layout.fillWidth: true
            onTextChanged: if (activeFocus) applyColor(conversionTool.colorFromHex(text))
        }
        Label { text: "RGB:"; font.bold: true }
        AppTextField {
            id: rgbInput
            Layout.fillWidth: true
            onTextChanged: if (activeFocus) applyColor(conversionTool.colorFromRgb(text))
        }
        Label { text: "HSL:"; font.bold: true }
        AppTextField {
            id: hslInput
            Layout.fillWidth: true
            onTextChanged: if (activeFocus) applyColor(conversionTool.colorFromHsl(text))
        }
        
        Rectangle {
            Layout.fillWidth: true
            height: 100
            color: hexInput.text.match(/^#[0-9a-fA-F]{6}$/) ? hexInput.text : "transparent"
            border.color: "black"
        }

        Item { Layout.fillHeight: true }
    }

    function applyColor(result) {
        if (!result || !result.hex) {
            return;
        }

        hexInput.text = result.hex;
        rgbInput.text = result.rgb;
        hslInput.text = result.hsl;
    }

    Component.onCompleted: applyColor(conversionTool.colorFromHex(hexInput.text))
}
