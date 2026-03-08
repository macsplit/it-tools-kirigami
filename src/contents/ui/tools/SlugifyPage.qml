import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.Page {
    title: "Slugify String"
    ColumnLayout {
        anchors.fill: parent
        anchors.margins: Kirigami.Units.largeSpacing
        spacing: Kirigami.Units.smallSpacing

        Label { text: "Input string:"; font.bold: true }
        TextField {
            id: slugInput
            placeholderText: "Type something..."
            Layout.fillWidth: true
        }
        Label { text: "Slug:"; font.bold: true }
        TextField {
            readOnly: true
            Layout.fillWidth: true
            text: slugInput.text.toLowerCase()
                            .trim()
                            .replace(/[^\w\s-]/g, '')
                            .replace(/[\s_-]+/g, '-')
                            .replace(/^-+|-+$/g, '')
        }
        Item { Layout.fillHeight: true }
    }
}
