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
                    AppTextField { id: separator; text: ", "; Layout.preferredWidth: 50 }
                }
                RowLayout {
                    Label { text: "Item Wrap:" }
                    AppTextField { id: itemPrefix; placeholderText: "Prefix"; Layout.preferredWidth: 80 }
                    AppTextField { id: itemSuffix; placeholderText: "Suffix"; Layout.preferredWidth: 80 }
                }
                RowLayout {
                    Label { text: "List Wrap:" }
                    AppTextField { id: listPrefix; placeholderText: "Prefix"; Layout.preferredWidth: 80 }
                    AppTextField { id: listSuffix; placeholderText: "Suffix"; Layout.preferredWidth: 80 }
                }
            }
        }

        Label { text: "Input list (one item per line):"; font.bold: true }
        AppTextArea {
            id: listInput
            placeholderText: "Item 1\nItem 2\nItem 3"
            Layout.fillWidth: true
            Layout.preferredHeight: 150
        }

        Label { text: "Transformed list:"; font.bold: true }
        OutputArea {
            readOnly: true
            Layout.fillWidth: true
            Layout.preferredHeight: 150
            text: textTool.transformList(
                      listInput.text,
                      trimItems.checked,
                      removeDuplicates.checked,
                      lowerCase.checked,
                      reverseList.checked,
                      separator.text,
                      itemPrefix.text,
                      itemSuffix.text,
                      listPrefix.text,
                      listSuffix.text)
        }
    }
}
