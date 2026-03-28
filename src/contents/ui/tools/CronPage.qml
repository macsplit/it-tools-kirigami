import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.ScrollablePage {
    id: root
    title: "Cron Expression Parser"

    // --- State Variables ---
    property var searchState: ({
        "results": [],
        "currentDate": new Date(),
        "iterations": 0,
        "parts": []
    })

    ListModel { id: nextOccurrencesModel }

    // --- The Chunked Search Timer ---
    // Instead of one big loop, we run 1000 iterations at a time.
    Timer {
        id: searchTimer
        interval: 1
        repeat: true
        onTriggered: {
            var state = root.searchState;
            var chunkCount = 0;

            while (state.results.length < 5 && state.iterations < 100000 && chunkCount < 1000) {
                state.iterations++;
                chunkCount++;
                state.currentDate.setMinutes(state.currentDate.getMinutes() + 1);

                if (matchesCron(state.currentDate, state.parts)) {
                    var timeStr = state.currentDate.toLocaleString();
                    state.results.push(timeStr);
                    nextOccurrencesModel.append({"time": timeStr});
                }
            }

            if (state.results.length >= 5 || state.iterations >= 100000) {
                stop(); // Search finished or limit reached
            }
        }
    }

    Timer {
        id: debounceTimer
        interval: 500
        repeat: false
        onTriggered: {
            var input = cronInput.text.trim();
            var parts = input.split(/\s+/);

            // Reset state
            searchTimer.stop();
            nextOccurrencesModel.clear();
            humanLabel.text = parseCron(input);

            if (parts.length >= 5) {
                var start = new Date();
                start.setSeconds(0);
                start.setMilliseconds(0);

                root.searchState = {
                    "results": [],
                    "currentDate": start,
                    "iterations": 0,
                    "parts": parts
                };
                searchTimer.start();
            }
        }
    }

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
            text: parseCron(cronInput.text)
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
                text: searchTimer.running ? "Calculating..." : (nextOccurrencesModel.count === 0 ? "No results found" : "")
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

    // --- Logic Functions ---

    function matchesCron(date, parts) {
        return fieldMatches(date.getMinutes(), parts[0]) &&
               fieldMatches(date.getHours(), parts[1]) &&
               fieldMatches(date.getDate(), parts[2]) &&
               fieldMatches(date.getMonth() + 1, parts[3]) &&
               fieldMatches(date.getDay(), parts[4]);
    }

    function fieldMatches(val, pattern) {
        if (pattern === "*" || pattern === "?") return true;
        if (pattern.indexOf("/") !== -1) {
            var p = pattern.split("/");
            var start = p[0] === "*" ? 0 : parseInt(p[0]);
            return (val >= start) && (val - start) % parseInt(p[1]) === 0;
        }
        if (pattern.indexOf("-") !== -1) {
            var r = pattern.split("-");
            return val >= parseInt(r[0]) && val <= parseInt(r[1]);
        }
        if (pattern.indexOf(",") !== -1) {
            var list = pattern.split(",");
            for (var i = 0; i < list.length; i++) {
                if (parseInt(list[i]) === val) return true;
            }
            return false;
        }
        return parseInt(pattern) === val;
    }

    function parseCron(cron) {
        var parts = cron.trim().split(/\s+/);
        if (parts.length < 5) return "Invalid expression";
        var min = parts[0], hour = parts[1], dom = parts[2], month = parts[3], dow = parts[4];
        var desc = "At ";
        if (min === "*" && hour === "*") desc = "Every minute ";
        else if (min.indexOf("/") !== -1 && hour === "*") desc = "Every " + min.split("/")[1] + " minutes ";
        else {
            var hStr = (hour === "*" ? "every hour" : "hour " + hour);
            var mStr = (min === "*" ? "00" : (min.length < 2 ? "0" + min : min));
            desc += hStr + ":" + mStr + " ";
        }
        if (dom !== "*" || month !== "*" || dow !== "*") {
            desc += "on ";
            if (dom !== "*" && dom !== "?") desc += "day " + dom + " ";
            if (month !== "*" && month !== "?") desc += "of month " + month + " ";
            if (dow !== "*" && dow !== "?") {
                var days = ["Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"];
                desc += "on " + (days[parseInt(dow)] || dow);
            }
        } else { desc += "every day"; }
        return desc;
    }

    Component.onCompleted: debounceTimer.restart()
}
