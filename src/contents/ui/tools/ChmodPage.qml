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
            text: calculateOctal()
            font.pixelSize: 48
            font.family: "monospace"
        }

        Label {
            Layout.alignment: Qt.AlignHCenter
            text: calculateSymbolic()
            font.pixelSize: 24
            font.family: "monospace"
        }

        TextField {
            Layout.fillWidth: true
            readOnly: true
            text: "chmod " + calculateOctal() + " path"
        }
        Item { Layout.fillHeight: true }
    }

    function calculateOctal() {
        var o = (ownerRead.checked ? 4 : 0) + (ownerWrite.checked ? 2 : 0) + (ownerExec.checked ? 1 : 0);
        var g = (groupRead.checked ? 4 : 0) + (groupWrite.checked ? 2 : 0) + (groupExec.checked ? 1 : 0);
        var p = (publicRead.checked ? 4 : 0) + (publicWrite.checked ? 2 : 0) + (publicExec.checked ? 1 : 0);
        return "" + o + g + p;
    }

    function calculateSymbolic() {
        var s = "";
        s += (ownerRead.checked ? "r" : "-");
        s += (ownerWrite.checked ? "w" : "-");
        s += (ownerExec.checked ? "x" : "-");
        s += (groupRead.checked ? "r" : "-");
        s += (groupWrite.checked ? "w" : "-");
        s += (groupExec.checked ? "x" : "-");
        s += (publicRead.checked ? "r" : "-");
        s += (publicWrite.checked ? "w" : "-");
        s += (publicExec.checked ? "x" : "-");
        return s;
    }
}
