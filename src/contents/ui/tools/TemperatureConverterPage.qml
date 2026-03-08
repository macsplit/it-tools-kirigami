import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.ScrollablePage {
    title: "Temperature Converter"

    ColumnLayout {
        width: parent.width
        spacing: Kirigami.Units.largeSpacing

        Repeater {
            model: [
                { name: "celsius", title: "Celsius", unit: "°C" },
                { name: "fahrenheit", title: "Fahrenheit", unit: "°F" },
                { name: "kelvin", title: "Kelvin", unit: "K" },
                { name: "rankine", title: "Rankine", unit: "°R" }
            ]
            delegate: RowLayout {
                Layout.fillWidth: true
                Label {
                    text: modelData.title
                    Layout.preferredWidth: 100
                    font.bold: true
                }
                TextField {
                    id: tempInput
                    text: getTemp(modelData.name)
                    Layout.fillWidth: true
                    onTextChanged: if (activeFocus) updateTemps(modelData.name, text)
                }
                Label {
                    text: modelData.unit
                    Layout.preferredWidth: 50
                }
            }
        }
    }

    property double kelvin: 273.15

    function getTemp(name) {
        switch(name) {
            case "celsius": return (kelvin - 273.15).toFixed(2);
            case "fahrenheit": return ((kelvin - 273.15) * 9/5 + 32).toFixed(2);
            case "kelvin": return kelvin.toFixed(2);
            case "rankine": return (kelvin * 1.8).toFixed(2);
        }
        return "0";
    }

    function updateTemps(name, value) {
        var val = parseFloat(value);
        if (isNaN(val)) return;
        
        switch(name) {
            case "celsius": kelvin = val + 273.15; break;
            case "fahrenheit": kelvin = (val - 32) * 5/9 + 273.15; break;
            case "kelvin": kelvin = val; break;
            case "rankine": kelvin = val / 1.8; break;
        }
    }
}
