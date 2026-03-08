import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.ScrollablePage {
    title: "List Converter"

    ColumnLayout {
        width: parent.width
        spacing: Kirigami.Units.largeSpacing

        GridLayout {
            columns: 2
            Layout.fillWidth: true
            columnSpacing: Kirigami.Units.largeSpacing

            ColumnLayout {
                CheckBox { id: trimItems; text: "Trim list items"; checked: true }
                CheckBox { id: removeDuplicates; text: "Remove duplicates"; checked: true }
                CheckBox { id: lowerCase; text: "Convert to lowercase"; checked: false }
                CheckBox { id: reverseList; text: "Reverse list"; checked: false }
            }

            ColumnLayout {
                RowLayout {
                    Label { text: "Separator:" }
                    TextField { id: separator; text: ", "; Layout.preferredWidth: 50 }
                }
                RowLayout {
                    Label { text: "Item Wrap:" }
                    TextField { id: itemPrefix; placeholder: "Prefix"; Layout.preferredWidth: 80 }
                    TextField { id: itemSuffix; placeholder: "Suffix"; Layout.preferredWidth: 80 }
                }
                RowLayout {
                    Label { text: "List Wrap:" }
                    TextField { id: listPrefix; placeholder: "Prefix"; Layout.preferredWidth: 80 }
                    TextField { id: listSuffix; placeholder: "Suffix"; Layout.preferredWidth: 80 }
                }
            }
        }

        Label { text: "Input list (one item per line):"; font.bold: true }
        TextArea {
            id: listInput
            placeholderText: "Item 1\nItem 2\nItem 3"
            Layout.fillWidth: true
            Layout.preferredHeight: 150
        }

        Label { text: "Transformed list:"; font.bold: true }
        TextArea {
            readOnly: true
            Layout.fillWidth: true
            Layout.preferredHeight: 150
            text: transformList(listInput.text)
        }
    }

    function transformList(input) {
        if (!input) return "";
        var items = input.split(/\r\n|\r|\n/);
        
        if (trimItems.checked) items = items.map(function(i) { return i.trim(); });
        items = items.filter(function(i) { return i.length > 0; });
        if (lowerCase.checked) items = items.map(function(i) { return i.toLowerCase(); });
        if (removeDuplicates.checked) items = items.filter(function(item, pos) { return items.indexOf(item) === pos; });
        if (reverseList.checked) items.reverse();
        
        items = items.map(function(i) { return itemPrefix.text + i + itemSuffix.text; });
        
        return listPrefix.text + items.join(separator.text) + listSuffix.text;
    }
}
