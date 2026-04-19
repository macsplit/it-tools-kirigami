import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.Page {
    title: "Lorem Ipsum"
    ColumnLayout {
        anchors.fill: parent
        anchors.margins: Kirigami.Units.largeSpacing
        OutputArea {
            id: loremOutput
            readOnly: true
            Layout.fillWidth: true
            Layout.fillHeight: true
            wrapMode: TextEdit.WordWrap
        }
        Button {
            text: "Generate Standard Paragraph"
            onClicked: loremOutput.text = textTool.loremIpsum()
        }
    }
}
