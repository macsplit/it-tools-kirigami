import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.ScrollablePage {
    title: "Text Diff"

    property var diffData: textTool.textDiff(leftInput.text,
                                             rightInput.text,
                                             ignoreWhitespace.checked,
                                             ignoreCase.checked)

    ColumnLayout {
        width: parent.width
        spacing: Kirigami.Units.largeSpacing

        RowLayout {
            Layout.fillWidth: true

            CheckBox {
                id: ignoreWhitespace
                text: "Ignore whitespace"
            }

            CheckBox {
                id: ignoreCase
                text: "Ignore case"
            }
        }

        Label {
            text: "Left text"
            font.bold: true
        }

        AppTextArea {
            id: leftInput
            Layout.fillWidth: true
            Layout.preferredHeight: 160
            font.family: "monospace"
            showPasteButton: true
            text: "alpha\nbeta\ngamma"
        }

        Label {
            text: "Right text"
            font.bold: true
        }

        AppTextArea {
            id: rightInput
            Layout.fillWidth: true
            Layout.preferredHeight: 160
            font.family: "monospace"
            showPasteButton: true
            text: "alpha\nbeta changed\ngamma\ndelta"
        }

        Kirigami.FormLayout {
            Layout.fillWidth: true
            wideMode: true

            OutputField {
                Kirigami.FormData.label: "Added:"
                Layout.fillWidth: true
                readOnly: true
                text: String(diffData.added || 0)
            }

            OutputField {
                Kirigami.FormData.label: "Removed:"
                Layout.fillWidth: true
                readOnly: true
                text: String(diffData.removed || 0)
            }

            OutputField {
                Kirigami.FormData.label: "Unchanged:"
                Layout.fillWidth: true
                readOnly: true
                text: String(diffData.unchanged || 0)
            }
        }

        Label {
            text: "Diff"
            font.bold: true
        }

        OutputArea {
            Layout.fillWidth: true
            Layout.preferredHeight: 220
            font.family: "monospace"
            wrapMode: TextEdit.WrapAnywhere
            text: diffData.diff || ""
        }
    }
}
