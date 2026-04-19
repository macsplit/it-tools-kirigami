import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.ScrollablePage {
    id: root
    title: "Cron Expression Parser"

    Timer {
        id: debounceTimer
        interval: 500
        repeat: false
        onTriggered: {
            var input = cronInput.text.trim();
            nextOccurrencesModel.clear();
            humanLabel.text = cronTool.describe(input);

            var occurrences = cronTool.nextOccurrences(input, 5);
            for (var i = 0; i < occurrences.length; i++) {
                nextOccurrencesModel.append({"time": occurrences[i]});
            }
        }
    }

    ListModel { id: nextOccurrencesModel }

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: Kirigami.Units.gridUnit
        spacing: Kirigami.Units.largeSpacing

        AppTextField {
            id: cronInput
            placeholderText: "* * * * *"
            text: "40 * * * *"
            Layout.fillWidth: true
            font.pixelSize: 24
            horizontalAlignment: Text.AlignHCenter
            onTextChanged: debounceTimer.restart()
        }

        Label {
            text: "Human Readable:"
            font.bold: true
            color: Kirigami.Theme.disabledTextColor
        }

        Label {
            id: humanLabel
            Layout.fillWidth: true
            wrapMode: Text.WordWrap
            font.pixelSize: 18
            color: Kirigami.Theme.highlightColor
            text: cronTool.describe(cronInput.text)
        }

        Label {
            text: "Next 5 Executions:"
            font.bold: true
            color: Kirigami.Theme.disabledTextColor
            Layout.topMargin: Kirigami.Units.largeSpacing
        }

        ColumnLayout {
            Layout.fillWidth: true
            spacing: Kirigami.Units.smallSpacing

            Repeater {
                model: nextOccurrencesModel
                delegate: Label {
                    Layout.fillWidth: true
                    text: "• " + model.time
                    font.family: "monospace"
                }
            }

            Label {
                text: nextOccurrencesModel.count === 0 ? "No results found" : ""
                visible: nextOccurrencesModel.count < 5
                font.italic: true
                opacity: 0.5
            }
        }

        Label {
            text: "Cron Reference Guide"
            font.bold: true
            font.pixelSize: 18
            Layout.topMargin: Kirigami.Units.gridUnit
        }

        OutputArea {
            readOnly: true
            Layout.fillWidth: true
            font.family: "monospace"
            background: Rectangle {
                color: Kirigami.Theme.alternateBackgroundColor
                radius: Kirigami.Units.smallSpacing
            }
            text: "┌──────────── minute (0 - 59)\n" +
                  "│ ┌────────── hour (0 - 23)\n" +
                  "│ │ ┌──────── day of month (1 - 31)\n" +
                  "│ │ │ ┌────── month (1 - 12)\n" +
                  "│ │ │ │ ┌──── day of week (0 - 6, Sunday=0)\n" +
                  "│ │ │ │ │\n" +
                  "* * * * *"
        }

        Item { Layout.fillHeight: true }
    }

    Component.onCompleted: debounceTimer.restart()
}
