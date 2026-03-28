import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.Page {
    title: "HTML Entities"
    ColumnLayout {
        anchors.fill: parent
        anchors.margins: Kirigami.Units.largeSpacing
        AppTextArea {
            id: htmlInput
            placeholderText: "Input text..."
            Layout.fillWidth: true
            Layout.fillHeight: true
            showPasteButton: true
            showCopyButton: true
        }
        RowLayout {
            Button {
                text: "Encode"
                onClicked: {
                    var entities = {
                        '&': '&amp;',
                        '<': '&lt;',
                        '>': '&gt;',
                        '"': '&quot;',
                        "'": '&#39;'
                    };
                    htmlInput.text = htmlInput.text.replace(/[&<>"']/g, function(m) {
                        return entities[m];
                    });
                }
            }
            Button {
                text: "Decode"
                onClicked: {
                    var entities = {
                        '&amp;': '&',
                        '&lt;': '<',
                        '&gt;': '>',
                        '&quot;': '"',
                        '&#39;': "'",
                        '&apos;': "'"
                    };
                    htmlInput.text = htmlInput.text.replace(/&amp;|&lt;|&gt;|&quot;|&#39;|&apos;/g, function(m) {
                        return entities[m];
                    });
                }
            }
        }
    }
}
