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
        TextField {
            id: hexInput
            text: "#1EA54C"
            Layout.fillWidth: true
            onTextChanged: if (activeFocus) updateFromHex(text)
        }
        Label { text: "RGB:"; font.bold: true }
        TextField {
            id: rgbInput
            Layout.fillWidth: true
            onTextChanged: if (activeFocus) updateFromRgb(text)
        }
        Label { text: "HSL:"; font.bold: true }
        TextField {
            id: hslInput
            Layout.fillWidth: true
            onTextChanged: if (activeFocus) updateFromHsl(text)
        }
        
        Rectangle {
            Layout.fillWidth: true
            height: 100
            color: hexInput.text.match(/^#[0-9a-fA-F]{6}$/) ? hexInput.text : "transparent"
            border.color: "black"
        }

        Item { Layout.fillHeight: true }
    }

    function pad2(n) {
        var s = n.toString(16);
        return s.length < 2 ? "0" + s : s;
    }

    function updateFromHex(hex) {
        if (!hex.match(/^#[0-9a-fA-F]{6}$/)) return;
        var r = parseInt(hex.slice(1, 3), 16);
        var g = parseInt(hex.slice(3, 5), 16);
        var b = parseInt(hex.slice(5, 7), 16);
        rgbInput.text = "rgb(" + r + ", " + g + ", " + b + ")";
        
        r /= 255; g /= 255; b /= 255;
        var max = Math.max(r, g, b), min = Math.min(r, g, b);
        var h, s, l = (max + min) / 2;
        if (max === min) { h = s = 0; }
        else {
            var d = max - min;
            s = l > 0.5 ? d / (2 - max - min) : d / (max + min);
            switch (max) {
                case r: h = (g - b) / d + (g < b ? 6 : 0); break;
                case g: h = (b - r) / d + 2; break;
                case b: h = (r - g) / d + 4; break;
            }
            h /= 6;
        }
        hslInput.text = "hsl(" + Math.round(h * 360) + ", " + Math.round(s * 100) + "%, " + Math.round(l * 100) + "%)";
    }

    function updateFromRgb(rgb) {
        var m = rgb.match(/rgb\((\d+),\s*(\d+),\s*(\d+)\)/);
        if (!m) return;
        var r = parseInt(m[1]), g = parseInt(m[2]), b = parseInt(m[3]);
        var hex = "#" + pad2(r) + pad2(g) + pad2(b);
        hexInput.text = hex.toUpperCase();
        
        r /= 255; g /= 255; b /= 255;
        var max = Math.max(r, g, b), min = Math.min(r, g, b);
        var h, s, l = (max + min) / 2;
        if (max === min) { h = s = 0; }
        else {
            var d = max - min;
            s = l > 0.5 ? d / (2 - max - min) : d / (max + min);
            switch (max) {
                case r: h = (g - b) / d + (g < b ? 6 : 0); break;
                case g: h = (b - r) / d + 2; break;
                case b: h = (r - g) / d + 4; break;
            }
            h /= 6;
        }
        hslInput.text = "hsl(" + Math.round(h * 360) + ", " + Math.round(s * 100) + "%, " + Math.round(l * 100) + "%)";
    }

    function updateFromHsl(hsl) {
        var m = hsl.match(/hsl\((\d+),\s*(\d+)%,\s*(\d+)%\)/);
        if (!m) return;
        var h = parseInt(m[1]) / 360;
        var s = parseInt(m[2]) / 100;
        var l = parseInt(m[3]) / 100;

        var r, g, b;
        if (s === 0) {
            r = g = b = l;
        } else {
            var hue2rgb = function(p, q, t) {
                if (t < 0) t += 1;
                if (t > 1) t -= 1;
                if (t < 1/6) return p + (q - p) * 6 * t;
                if (t < 1/2) return q;
                if (t < 2/3) return p + (q - p) * (2/3 - t) * 6;
                return p;
            };
            var q = l < 0.5 ? l * (1 + s) : l + s - l * s;
            var p = 2 * l - q;
            r = hue2rgb(p, q, h + 1/3);
            g = hue2rgb(p, q, h);
            b = hue2rgb(p, q, h - 1/3);
        }

        var ri = Math.round(r * 255), gi = Math.round(g * 255), bi = Math.round(b * 255);
        var hex = "#" + pad2(ri) + pad2(gi) + pad2(bi);
        hexInput.text = hex.toUpperCase();
        rgbInput.text = "rgb(" + ri + ", " + gi + ", " + bi + ")";
    }
    
    Component.onCompleted: updateFromHex(hexInput.text)
}
