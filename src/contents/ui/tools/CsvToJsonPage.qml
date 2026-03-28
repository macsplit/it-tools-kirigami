import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.ScrollablePage {
    title: "CSV to JSON"

    ColumnLayout {
        width: parent.width
        spacing: Kirigami.Units.largeSpacing

        Label { text: "CSV Input (first line as header):"; font.bold: true }
        AppTextArea {
            id: csvInput
            placeholderText: "id,name,email\n1,John,john@example.com\n2,Jane,jane@example.com"
            Layout.fillWidth: true
            Layout.preferredHeight: 200
            font.family: "monospace"
            text: "id,name,email\n1,John,john@example.com\n2,Jane,jane@example.com"
        }

        Label { text: "JSON Output:"; font.bold: true }
        OutputArea {
            id: jsonOutput
            readOnly: true
            Layout.fillWidth: true
            Layout.preferredHeight: 200
            font.family: "monospace"
            text: csvToJson(csvInput.text)
        }
    }

    function csvToJson(csv) {
        if (!csv) return "";
        try {
            var lines = csv.trim().split(/\r\n|\r|\n/);
            if (lines.length < 2) return "[]";
            
            var headers = lines[0].split(",");
            var results = [];
            
            for (var i = 1; i < lines.length; i++) {
                var obj = {};
                var currentline = lines[i].split(",");
                for (var j = 0; j < headers.length; j++) {
                    obj[headers[j].trim()] = currentline[j] ? currentline[j].trim() : "";
                }
                results.push(obj);
            }
            return JSON.stringify(results, null, 4);
        } catch (e) {
            return "Error parsing CSV";
        }
    }
}
