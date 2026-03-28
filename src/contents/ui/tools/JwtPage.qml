import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.Page {
    title: "JWT Parser"
    ColumnLayout {
        anchors.fill: parent
        anchors.margins: Kirigami.Units.largeSpacing
        AppTextArea {
            id: jwtInput
            placeholderText: "Paste JWT here..."
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.preferredHeight: 100
            wrapMode: TextEdit.WrapAnywhere
        }
        OutputArea {
            id: jwtHeaderOutput
            placeholderText: "Header"
            readOnly: true
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.preferredHeight: 100
            font.family: "monospace"
            text: parseJwt(jwtInput.text, 0)
        }
        OutputArea {
            id: jwtPayloadOutput
            placeholderText: "Payload"
            readOnly: true
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.preferredHeight: 200
            font.family: "monospace"
            text: parseJwt(jwtInput.text, 1)
        }
    }

    function parseJwt(token, part) {
        try {
            var parts = token.split('.');
            if (parts.length < 2) return "";
            var base64Url = parts[part];
            var base64 = base64Url.replace(/-/g, '+').replace(/_/g, '/');
            while (base64.length % 4) base64 += '=';
            var jsonPayload = Qt.atob(base64);
            return JSON.stringify(JSON.parse(jsonPayload), null, 4);
        } catch (e) {
            return "";
        }
    }
}
