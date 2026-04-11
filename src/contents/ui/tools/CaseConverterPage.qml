import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.Page {
    title: "Case Converter"

    function extractWords(segment) {
        var words = [];
        var parts = segment.split(/[\s_-]+/);

        for (var i = 0; i < parts.length; i++) {
            var part = parts[i];
            if (!part.length) {
                continue;
            }

            var matches = part.match(/[A-Z]+(?![a-z])|[A-Z]?[a-z]+|[0-9]+/g);
            if (matches) {
                for (var j = 0; j < matches.length; j++) {
                    words.push(matches[j].toLowerCase());
                }
            } else {
                words.push(part.toLowerCase());
            }
        }

        return words;
    }

    function transformSegment(segment, mode) {
        var words = extractWords(segment);
        if (!words.length) {
            return segment;
        }

        if (mode === "camel") {
            var camel = words[0];
            for (var i = 1; i < words.length; i++) {
                camel += words[i].charAt(0).toUpperCase() + words[i].slice(1);
            }
            return camel;
        }

        if (mode === "pascal") {
            var pascal = "";
            for (var j = 0; j < words.length; j++) {
                pascal += words[j].charAt(0).toUpperCase() + words[j].slice(1);
            }
            return pascal;
        }

        if (mode === "snake") {
            return words.join("_");
        }

        if (mode === "kebab") {
            return words.join("-");
        }

        return segment;
    }

    function convertPreservingSymbols(text, mode) {
        var result = "";
        var segment = "";

        for (var i = 0; i < text.length; i++) {
            var ch = text.charAt(i);
            if (/[A-Za-z0-9\s_-]/.test(ch)) {
                segment += ch;
            } else {
                result += transformSegment(segment, mode);
                result += ch;
                segment = "";
            }
        }

        result += transformSegment(segment, mode);
        return result;
    }

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: Kirigami.Units.largeSpacing
        AppTextArea {
            id: caseInputField
            placeholderText: "Input text..."
            Layout.fillWidth: true
            Layout.fillHeight: true
            showPasteButton: true
            showCopyButton: true
        }
        Flow {
            Layout.fillWidth: true
            spacing: Kirigami.Units.largeSpacing
            Button {
                text: "UPPERCASE"
                onClicked: caseInputField.text = caseInputField.text.toUpperCase()
            }
            Button {
                text: "lowercase"
                onClicked: caseInputField.text = caseInputField.text.toLowerCase()
            }
            Button {
                text: "camelCase"
                onClicked: caseInputField.text = convertPreservingSymbols(caseInputField.text, "camel")
            }
            Button {
                text: "PascalCase"
                onClicked: caseInputField.text = convertPreservingSymbols(caseInputField.text, "pascal")
            }
            Button {
                text: "snake_case"
                onClicked: caseInputField.text = convertPreservingSymbols(caseInputField.text, "snake")
            }
            Button {
                text: "kebab-case"
                onClicked: caseInputField.text = convertPreservingSymbols(caseInputField.text, "kebab")
            }
        }
    }
}
