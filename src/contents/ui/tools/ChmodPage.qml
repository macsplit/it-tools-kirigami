import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.Page {
    title: "Chmod Calculator"
    ColumnLayout {
        anchors.fill: parent
        anchors.margins: Kirigami.Units.largeSpacing
        spacing: Kirigami.Units.largeSpacing

        GridLayout {
            columns: 4
            Layout.fillWidth: true
            Label { text: "" }
            Label { text: "Owner"; font.bold: true; horizontalAlignment: Text.AlignHCenter; Layout.fillWidth: true }
            Label { text: "Group"; font.bold: true; horizontalAlignment: Text.AlignHCenter; Layout.fillWidth: true }
            Label { text: "Public"; font.bold: true; horizontalAlignment: Text.AlignHCenter; Layout.fillWidth: true }

            Label { text: "Read (4)"; font.bold: true }
            CheckBox { id: ownerRead; Layout.alignment: Qt.AlignHCenter }
            CheckBox { id: groupRead; Layout.alignment: Qt.AlignHCenter }
            CheckBox { id: publicRead; Layout.alignment: Qt.AlignHCenter }

            Label { text: "Write (2)"; font.bold: true }
            CheckBox { id: ownerWrite; Layout.alignment: Qt.AlignHCenter }
            CheckBox { id: groupWrite; Layout.alignment: Qt.AlignHCenter }
            CheckBox { id: publicWrite; Layout.alignment: Qt.AlignHCenter }

            Label { text: "Execute (1)"; font.bold: true }
            CheckBox { id: ownerExec; Layout.alignment: Qt.AlignHCenter }
            CheckBox { id: groupExec; Layout.alignment: Qt.AlignHCenter }
            CheckBox { id: publicExec; Layout.alignment: Qt.AlignHCenter }
        }

        Label {
            Layout.alignment: Qt.AlignHCenter
            text: textTool.chmodOctal(
                      ownerRead.checked, ownerWrite.checked, ownerExec.checked,
                      groupRead.checked, groupWrite.checked, groupExec.checked,
                      publicRead.checked, publicWrite.checked, publicExec.checked)
            font.pixelSize: 48
            font.family: "monospace"
        }

        Label {
            Layout.alignment: Qt.AlignHCenter
            text: textTool.chmodSymbolic(
                      ownerRead.checked, ownerWrite.checked, ownerExec.checked,
                      groupRead.checked, groupWrite.checked, groupExec.checked,
                      publicRead.checked, publicWrite.checked, publicExec.checked)
            font.pixelSize: 24
            font.family: "monospace"
        }

        OutputField {
            Layout.fillWidth: true
            readOnly: true
            text: "chmod " + textTool.chmodOctal(
                      ownerRead.checked, ownerWrite.checked, ownerExec.checked,
                      groupRead.checked, groupWrite.checked, groupExec.checked,
                      publicRead.checked, publicWrite.checked, publicExec.checked) + " path"
        }
        Item { Layout.fillHeight: true }
    }
}
