import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.ScrollablePage {
    title: "Markdown to HTML"

    ColumnLayout {
        width: parent.width
        spacing: Kirigami.Units.largeSpacing

        Label { text: "Markdown Input:"; font.bold: true }
        TextArea {
            id: mdInput
            placeholderText: "# Hello World\n\nThis is **markdown** content."
            Layout.fillWidth: true
            Layout.preferredHeight: 200
            font.family: "monospace"
            text: "# Sample Heading\n\n- List item 1\n- List item 2\n\n**Bold text** and *italic*."
        }

        Label { text: "HTML Output:"; font.bold: true }
        TextArea {
            id: htmlOutput
            readOnly: true
            Layout.fillWidth: true
            Layout.preferredHeight: 200
            font.family: "monospace"
            text: conversionTool.markdownToHtml(mdInput.text)
        }

        Label { text: "Preview:"; font.bold: true }
        Rectangle {
            Layout.fillWidth: true
            Layout.preferredHeight: 200
            color: "white"
            border.color: Kirigami.Theme.highlightColor
            
            Flickable {
                anchors.fill: parent
                contentWidth: parent.width
                contentHeight: previewText.implicitHeight
                clip: true
                
                Text {
                    id: previewText
                    width: parent.width - 20
                    x: 10
                    y: 10
                    text: mdInput.text
                    textFormat: Text.MarkdownText
                    wrapMode: Text.WordWrap
                    color: "black"
                }
            }
        }
    }
}
