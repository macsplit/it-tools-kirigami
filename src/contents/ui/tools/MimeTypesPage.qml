import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.ScrollablePage {
    id: root
    title: "MIME Types"

    function matchingEntries(queryText) {
        var query = queryText.trim().toLowerCase();
        var matches = [];

        for (var i = 0; i < mimeModel.count; i++) {
            var item = mimeModel.get(i);
            if (!query || item.mime.toLowerCase().indexOf(query) !== -1 ||
                    item.extensions.toLowerCase().indexOf(query) !== -1) {
                matches.push(item);
            }
        }

        return matches;
    }

    function updateResults() {
        var matches = matchingEntries(mimeSearch.text);
        resultsField.text = matches.length ? matches.map(function(item) {
            return item.mime + "\nExtensions: " + item.extensions;
        }).join("\n\n") : "No matching MIME types found.";
    }
    
    ListModel {
        id: mimeModel
    }
    
    Component.onCompleted: {
        var data = ToolManager.loadJson("mimetypes.json");
        for (var i = 0; i < data.length; i++) {
            mimeModel.append({
                "mime": data[i].mime,
                "extensions": data[i].ext.join(", ")
            });
        }

        updateResults();
    }

    ColumnLayout {
        width: parent.width
        spacing: Kirigami.Units.largeSpacing
        
        Kirigami.SearchField {
            id: mimeSearch
            placeholderText: "Search MIME type or extension..."
            Layout.fillWidth: true
            onTextChanged: root.updateResults()
        }

        Label {
            text: "Matches"
            font.bold: true
        }

        OutputArea {
            id: resultsField
            Layout.fillWidth: true
            Layout.preferredHeight: 420
            placeholderText: "Search results will appear here..."
            wrapMode: TextEdit.WrapAnywhere
        }
    }
}
