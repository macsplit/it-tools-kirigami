import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.ScrollablePage {
    id: root
    title: "Date/Time Converter"

    property var formatOptions: [
        { name: "ISO 8601", placeholder: "e.g. 2026-04-19T14:30:00Z or 2026-04-19T14:30:00" },
        { name: "ISO 9075", placeholder: "e.g. 2026-04-19 14:30:00" },
        { name: "RFC 2822 / HTTP", placeholder: "e.g. Sun, 19 Apr 2026 14:30:00 GMT" },
        { name: "Date only", placeholder: "e.g. 2026-04-19" },
        { name: "Unix seconds", placeholder: "e.g. 1776609000" },
        { name: "Unix milliseconds", placeholder: "e.g. 1776609000000" },
        { name: "Mongo ObjectID", placeholder: "e.g. 507f1f77bcf86cd799439011" },
        { name: "Excel date/time", placeholder: "e.g. 46031.604167" }
    ]

    function currentPlaceholder() {
        if (formatSelector.currentIndex < 0 || formatSelector.currentIndex >= formatOptions.length) {
            return "Enter a date/time value";
        }

        return formatOptions[formatSelector.currentIndex].placeholder;
    }

    ColumnLayout {
        width: parent.width
        spacing: Kirigami.Units.largeSpacing

        Label {
            text: "Interpret input as"
            font.bold: true
        }

        ComboBox {
            id: formatSelector
            Layout.fillWidth: true
            textRole: "name"
            model: root.formatOptions
        }

        Label {
            text: "Timezone"
            font.bold: true
        }

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
        }

        Label {
            text: "Input value"
            font.bold: true
        }

        AppTextArea {
            id: inputField
            Layout.fillWidth: true
            Layout.preferredHeight: 100
            placeholderText: root.currentPlaceholder()
        }

        Label {
            text: "Converted values"
            font.bold: true
        }

        OutputArea {
            Layout.fillWidth: true
            Layout.preferredHeight: 220
            font.family: "monospace"
            wrapMode: TextEdit.NoWrap
            text: timeTool.convertDateTime(
                inputField.text,
                formatSelector.currentText,
                timezoneSelector.editText
            )
            placeholderText: "Converted values will appear here"
        }
    }
}
