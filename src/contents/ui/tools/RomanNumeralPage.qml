import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.Page {
    title: "Roman Numeral Converter"

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: Kirigami.Units.largeSpacing
        
        Kirigami.FormLayout {
            AppTextField {
                id: arabicInput
                Kirigami.FormData.label: "Arabic Number:"
                placeholderText: "e.g. 2024"
                inputMethodHints: Qt.ImhDigitsOnly
                onTextChanged: {
                    if (focus) {
                        romanInput.text = textTool.arabicToRoman(text);
                    }
                }
            }
            AppTextField {
                id: romanInput
                Kirigami.FormData.label: "Roman Numeral:"
                placeholderText: "e.g. MMXXIV"
                onTextChanged: {
                    if (focus) {
                        arabicInput.text = textTool.romanToArabic(text);
                    }
                }
            }
        }
        
        Item { Layout.fillHeight: true }
    }
}
