import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.ScrollablePage {
    id: root
    title: "Temperature Converter"

    property double kelvin: 273.15

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

                AppTextField {
                    id: tempInput
                    Layout.fillWidth: true
                    inputMethodHints: Qt.ImhFormattedNumbersOnly

                    // Remove the direct 'text: getTemp()' binding here.
                    // Instead, we use a Connection to update the text
                    // only when the field is NOT being edited.

                    Component.onCompleted: text = getTemp(modelData.name)

                    Connections {
                        target: root
                        function onKelvinChanged() {
                            if (!tempInput.activeFocus) {
                                tempInput.text = getTemp(modelData.name)
                            }
                        }
                    }

                    onTextEdited: {
                        let val = parseFloat(text);
                        if (!isNaN(val)) {
                            root.updateTemps(modelData.name, val);
                        }
                    }
                }

                Label {
                    text: modelData.unit
                    Layout.preferredWidth: 50
                }
            }
        }
    }

    function getTemp(name) {
        switch(name) {
            case "celsius": return (kelvin - 273.15).toFixed(2);
            case "fahrenheit": return ((kelvin - 273.15) * 9/5 + 32).toFixed(2);
            case "kelvin": return kelvin.toFixed(2);
            case "rankine": return (kelvin * 1.8).toFixed(2);
        }
        return "0.00";
    }

    function updateTemps(name, val) {
        // Validation check for Absolute Zero
        // This is a safety precaution to ensure physical accuracy.
        let targetKelvin = 0;
        switch(name) {
            case "celsius": targetKelvin = val + 273.15; break;
            case "fahrenheit": targetKelvin = (val - 32) * 5/9 + 273.15; break;
            case "kelvin": targetKelvin = val; break;
            case "rankine": targetKelvin = val / 1.8; break;
        }

        // Prevent values below absolute zero
        if (targetKelvin < 0) {
            kelvin = 0;
        } else {
            kelvin = targetKelvin;
        }
    }
}
