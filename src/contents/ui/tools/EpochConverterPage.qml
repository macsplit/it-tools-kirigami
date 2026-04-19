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

        parsedResultText = timeTool.parseNaturalDateCompact(trimmed, timezoneSelector.editText);
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

        Label { text: "Timestamp to date/time"; font.bold: true }
        AppTextField {
            id: epochInput
            Layout.fillWidth: true
            placeholderText: "Seconds or milliseconds since 1970-01-01"
        }

        OutputArea {
            Layout.fillWidth: true
            Layout.preferredHeight: 90
            font.family: "monospace"
            wrapMode: TextEdit.NoWrap
            text: timeTool.formatEpochCompact(epochInput.text, timezoneSelector.editText)
            placeholderText: "Converted date/time will appear here"
        }

        Label { text: "Date/time to timestamp"; font.bold: true }
        AppTextArea {
            id: dateInput
            Layout.fillWidth: true
            Layout.preferredHeight: 72
            placeholderText: "Examples: now, tomorrow 10pm, 2026-04-19 18:05"
            onTextChanged: parseDebounce.restart()
        }

        OutputArea {
            Layout.fillWidth: true
            Layout.preferredHeight: 90
            font.family: "monospace"
            wrapMode: TextEdit.NoWrap
            text: root.parsedResultText
            placeholderText: "Converted timestamp will appear here"
        }
    }
}
