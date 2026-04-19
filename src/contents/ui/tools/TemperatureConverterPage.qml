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
                    Component.onCompleted: text = conversionTool.temperatureFromKelvin(modelData.name, root.kelvin.toFixed(2))

                    Connections {
                        target: root
                        function onKelvinChanged() {
                            if (!tempInput.activeFocus) {
                                tempInput.text = conversionTool.temperatureFromKelvin(modelData.name, root.kelvin.toFixed(2))
                            }
                        }
                    }

                    onTextEdited: {
                        var kelvinText = conversionTool.temperatureToKelvin(modelData.name, text);
                        if (kelvinText.length) {
                            root.kelvin = parseFloat(kelvinText);
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
}
