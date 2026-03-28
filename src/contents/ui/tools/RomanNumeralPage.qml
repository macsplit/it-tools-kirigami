import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.Page {
    title: "Roman Numeral Converter"
    
    function arabicToRoman(num) {
        if (num < 1 || num > 3999) return "";
        var lookup = {
            M: 1000, CM: 900, D: 500, CD: 400,
            C: 100, XC: 90, L: 50, XL: 40,
            X: 10, IX: 9, V: 5, IV: 4, I: 1
        };
        var roman = '';
        for (var i in lookup) {
            while (num >= lookup[i]) {
                roman += i;
                num -= lookup[i];
            }
        }
        return roman;
    }
    
    function romanToArabic(s) {
        s = s.toUpperCase();
        var map = { I: 1, V: 5, X: 10, L: 50, C: 100, D: 500, M: 1000 };
        var res = 0;
        for (var i = 0; i < s.length; i++) {
            var s1 = map[s[i]];
            if (i + 1 < s.length) {
                var s2 = map[s[i+1]];
                if (s1 >= s2) {
                    res = res + s1;
                } else {
                    res = res + s2 - s1;
                    i++;
                }
            } else {
                res = res + s1;
            }
        }
        return res;
    }

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
                        romanInput.text = arabicToRoman(parseInt(text));
                    }
                }
            }
            AppTextField {
                id: romanInput
                Kirigami.FormData.label: "Roman Numeral:"
                placeholderText: "e.g. MMXXIV"
                onTextChanged: {
                    if (focus) {
                        var val = romanToArabic(text);
                        arabicInput.text = isNaN(val) ? "" : val.toString();
                    }
                }
            }
        }
        
        Item { Layout.fillHeight: true }
    }
}
