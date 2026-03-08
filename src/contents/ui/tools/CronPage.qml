import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.ScrollablePage {
    title: "Cron Expression Parser"
    ColumnLayout {
        width: parent.width
        spacing: Kirigami.Units.largeSpacing

        TextField {
            id: cronInput
            placeholderText: "* * * * *"
            text: "40 * * * *"
            Layout.fillWidth: true
            font.pixelSize: 24
            horizontalAlignment: Text.AlignHCenter
        }

        Label {
            text: "Human Readable:"
            font.bold: true
        }
        
        Label {
            Layout.fillWidth: true
            wrapMode: Text.WordWrap
            text: parseCron(cronInput.text)
            font.pixelSize: 18
            color: Kirigami.Theme.highlightColor
        }

        Label {
            text: "Next 5 Executions:"
            font.bold: true
        }

        ListView {
            Layout.fillWidth: true
            height: contentHeight
            interactive: false
            model: getNextOccurrences(cronInput.text, 5)
            delegate: Label {
                text: "• " + modelData
                font.family: "monospace"
            }
        }

        Label {
            text: "Cron Reference Guide"
            font.bold: true
            font.pixelSize: 18
        }

        TextArea {
            readOnly: true
            Layout.fillWidth: true
            font.family: "monospace"
            text: "┌──────────── minute (0 - 59)\n" +
                  "│ ┌────────── hour (0 - 23)\n" +
                  "│ │ ┌──────── day of month (1 - 31)\n" +
                  "│ │ │ ┌────── month (1 - 12)\n" +
                  "│ │ │ │ ┌──── day of week (0 - 6, Sunday=0)\n" +
                  "│ │ │ │ │\n" +
                  "* * * * *"
        }
    }

    function parseCron(cron) {
        var parts = cron.trim().split(/\s+/);
        if (parts.length < 5) return "Invalid cron expression (need at least 5 parts)";
        
        var min = parts[0];
        var hour = parts[1];
        var dom = parts[2];
        var month = parts[3];
        var dow = parts[4];

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
        } else {
            desc += "every day";
        }

        return desc;
    }

    function getNextOccurrences(cron, count) {
        var parts = cron.trim().split(/\s+/);
        if (parts.length < 5) return [];
        
        var results = [];
        var current = new Date();
        current.setSeconds(0);
        current.setMilliseconds(0);

        var iterations = 0;
        while (results.length < count && iterations < 100000) {
            iterations++;
            current.setMinutes(current.getMinutes() + 1);
            if (matchesCron(current, parts)) {
                results.push(current.toLocaleString());
            }
        }
        return results;
    }

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
}
