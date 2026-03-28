import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.ScrollablePage {
    title: "SQL Prettify"

    ColumnLayout {
        width: parent.width
        spacing: Kirigami.Units.largeSpacing

        Label { text: "Your SQL query:"; font.bold: true }
        AppTextArea {
            id: sqlInput
            placeholderText: "Paste your SQL query here..."
            Layout.fillWidth: true
            Layout.preferredHeight: 200
            font.family: "monospace"
            text: "select field1,field2,field3 from my_table where my_condition;"
        }

        Label { text: "Prettified version:"; font.bold: true }
        OutputArea {
            id: sqlOutput
            readOnly: true
            Layout.fillWidth: true
            Layout.preferredHeight: 200
            font.family: "monospace"
            text: conversionTool.formatSql(sqlInput.text)
        }
    }
}
