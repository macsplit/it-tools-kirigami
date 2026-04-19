import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.ScrollablePage {
    title: "MIME Types"

    ColumnLayout {
        width: parent.width
        spacing: Kirigami.Units.largeSpacing
        
        Kirigami.SearchField {
            id: mimeSearch
            placeholderText: "Search MIME type or extension..."
            Layout.fillWidth: true
            onTextChanged: resultsField.text = mimeTool.search(text)
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
            Component.onCompleted: text = mimeTool.search("")
        }
    }
}
