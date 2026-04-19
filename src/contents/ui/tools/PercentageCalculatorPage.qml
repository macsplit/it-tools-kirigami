import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.ScrollablePage {
    title: "Percentage Calculator"

    ColumnLayout {
        width: parent.width
        spacing: Kirigami.Units.largeSpacing

        GroupBox {
            title: "What is X% of Y?"
            Layout.fillWidth: true

            ColumnLayout {
                anchors.fill: parent

                Label {
                    text: "X"
                    font.bold: true
                }

                AppTextField {
                    id: percentInput
                    Layout.fillWidth: true
                    placeholderText: "e.g. 15"
                    inputMethodHints: Qt.ImhFormattedNumbersOnly
                }

                Label {
                    text: "Y"
                    font.bold: true
                }

                AppTextField {
                    id: valueInput
                    Layout.fillWidth: true
                    placeholderText: "e.g. 240"
                    inputMethodHints: Qt.ImhFormattedNumbersOnly
                }

                Label {
                    text: "Result"
                    font.bold: true
                }

                OutputField {
                    Layout.fillWidth: true
                    text: mathTool.percentOf(percentInput.text, valueInput.text)
                    placeholderText: "Calculated value"
                }
            }
        }

        GroupBox {
            title: "X is what percent of Y?"
            Layout.fillWidth: true

            ColumnLayout {
                anchors.fill: parent

                Label {
                    text: "X"
                    font.bold: true
                }

                AppTextField {
                    id: partInput
                    Layout.fillWidth: true
                    placeholderText: "e.g. 48"
                    inputMethodHints: Qt.ImhFormattedNumbersOnly
                }

                Label {
                    text: "Y"
                    font.bold: true
                }

                AppTextField {
                    id: wholeInput
                    Layout.fillWidth: true
                    placeholderText: "e.g. 240"
                    inputMethodHints: Qt.ImhFormattedNumbersOnly
                }

                Label {
                    text: "Result"
                    font.bold: true
                }

                OutputField {
                    Layout.fillWidth: true
                    text: mathTool.whatPercent(partInput.text, wholeInput.text)
                    placeholderText: "Calculated percentage"
                }
            }
        }

        GroupBox {
            title: "Percentage increase or decrease"
            Layout.fillWidth: true

            ColumnLayout {
                anchors.fill: parent

                Label {
                    text: "From"
                    font.bold: true
                }

                AppTextField {
                    id: fromInput
                    Layout.fillWidth: true
                    placeholderText: "e.g. 80"
                    inputMethodHints: Qt.ImhFormattedNumbersOnly
                }

                Label {
                    text: "To"
                    font.bold: true
                }

                AppTextField {
                    id: toInput
                    Layout.fillWidth: true
                    placeholderText: "e.g. 100"
                    inputMethodHints: Qt.ImhFormattedNumbersOnly
                }

                Label {
                    text: "Result"
                    font.bold: true
                }

                OutputField {
                    Layout.fillWidth: true
                    text: mathTool.percentageChange(fromInput.text, toInput.text)
                    placeholderText: "Percentage change"
                }
            }
        }
    }
}
