import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.ScrollablePage {
    title: "ASCII Text Drawer"

    ColumnLayout {
        width: parent.width
        spacing: Kirigami.Units.largeSpacing

        Label {
            text: "Text"
            font.bold: true
        }

        AppTextField {
            id: asciiInput
            Layout.fillWidth: true
            text: "TOOLS 2026"
            placeholderText: "Enter uppercase text or digits"
        }

        Label {
            text: "ASCII output"
            font.bold: true
        }

        OutputArea {
            Layout.fillWidth: true
            Layout.preferredHeight: 180
            font.family: "monospace"
            wrapMode: TextEdit.NoWrap
            text: textTool.asciiTextDraw(asciiInput.text)
        }
    }
}
