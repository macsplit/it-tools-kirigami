import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.Page {
    title: "URL Encoder/Decoder"
    ColumnLayout {
        anchors.fill: parent
        anchors.margins: Kirigami.Units.largeSpacing
        TextArea {
            id: urlInput
            placeholderText: "Input text..."
            Layout.fillWidth: true
            Layout.fillHeight: true
        }
        RowLayout {
            Button {
                text: "Encode"
                onClicked: urlInput.text = encodeURIComponent(urlInput.text)
            }
            Button {
                text: "Decode"
                onClicked: {
                    try {
                        urlInput.text = decodeURIComponent(urlInput.text)
                    } catch (e) {
                        root.showMessage("Invalid URL encoding")
                    }
                }
            }
        }
    }
}
