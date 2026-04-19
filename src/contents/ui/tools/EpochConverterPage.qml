import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.ScrollablePage {
    id: root
    title: "Epoch Converter"

    property string parsedResultText: ""

    function requestParse() {
        var trimmed = dateInput.text.trim();
        if (!trimmed.length) {
            parsedResultText = "";
            return;
        }

        parsedResultText = timeTool.parseNaturalDate(trimmed, timezoneSelector.editText);
    }

    Timer {
        id: parseDebounce
        interval: 150
        repeat: false
        onTriggered: root.requestParse()
    }

    ColumnLayout {
        width: parent.width
        spacing: Kirigami.Units.largeSpacing

        Label { text: "Timezone"; font.bold: true }
        ComboBox {
            id: timezoneSelector
            Layout.fillWidth: true
            editable: true
            model: [
                "Local",
                "UTC",
                "Europe/London",
                "Europe/Berlin",
                "America/New_York",
                "America/Chicago",
                "America/Denver",
                "America/Los_Angeles",
                "Asia/Tokyo",
                "Australia/Sydney"
            ]

            Component.onCompleted: editText = "UTC"
            onEditTextChanged: parseDebounce.restart()
        }

        Label { text: "Unix timestamp"; font.bold: true }
        AppTextField {
            id: epochInput
            Layout.fillWidth: true
            placeholderText: "Seconds or milliseconds since 1970-01-01"
        }

        Label { text: "Timestamp result"; font.bold: true }
        OutputArea {
            Layout.fillWidth: true
            Layout.preferredHeight: 140
            font.family: "monospace"
            wrapMode: TextEdit.NoWrap
            text: timeTool.formatEpoch(epochInput.text, timezoneSelector.editText)
        }

        Label { text: "Date string"; font.bold: true }
        AppTextArea {
            id: dateInput
            Layout.fillWidth: true
            Layout.preferredHeight: 100
            placeholderText: "Examples: today, next Wednesday, 10pm on 13 October 2023"
            onTextChanged: parseDebounce.restart()
        }

        Label { text: "Parsed result"; font.bold: true }
        OutputArea {
            Layout.fillWidth: true
            Layout.preferredHeight: 120
            font.family: "monospace"
            wrapMode: TextEdit.NoWrap
            text: root.parsedResultText
        }
    }
}
