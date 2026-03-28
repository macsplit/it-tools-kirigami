import QtQuick 2.15
import QtQuick.Controls 2.15

TextArea {
    id: root
    clip: true

    property string copiedMessage: "Copied to clipboard"
    property bool showPasteButton: !readOnly
    property bool showCopyButton: readOnly

    readonly property bool hasActions: showPasteButton || showCopyButton

    rightPadding: hasActions ? actionButtons.width + 8 : 0

    function pasteReplace() {
        if (readOnly) {
            return;
        }

        selectAll();
        paste();

        if (typeof deselect === "function") {
            deselect();
        }
    }

    function copyAll() {
        if (!text.length) {
            return;
        }

        selectAll();
        copy();

        if (typeof deselect === "function") {
            deselect();
        }

        if (typeof applicationWindow === "function") {
            var window = applicationWindow();
            if (window && window.showMessage) {
                window.showMessage(copiedMessage);
            }
        }
    }

    Keys.onPressed: function(event) {
        if (event.key === Qt.Key_Menu || (event.key === Qt.Key_F10 && (event.modifiers & Qt.ShiftModifier))) {
            event.accepted = true;
        }
    }

    MouseArea {
        anchors.fill: parent
        acceptedButtons: Qt.RightButton
        cursorShape: Qt.ArrowCursor
        onPressed: function(mouse) {
            mouse.accepted = true;
        }
        onReleased: function(mouse) {
            mouse.accepted = true;
        }
        onClicked: function(mouse) {
            mouse.accepted = true;
        }
        onPressAndHold: function(mouse) {
            mouse.accepted = true;
        }
    }

    Column {
        id: actionButtons
        anchors.top: parent.top
        anchors.topMargin: 4
        anchors.right: parent.right
        anchors.rightMargin: 4
        spacing: 4
        visible: root.hasActions

        ToolButton {
            width: 28
            height: 28
            visible: root.showPasteButton
            focusPolicy: Qt.NoFocus
            display: AbstractButton.IconOnly
            icon.name: "edit-paste"
            text: "Paste"
            onClicked: root.pasteReplace()
        }

        ToolButton {
            width: 28
            height: 28
            visible: root.showCopyButton
            enabled: root.text.length > 0
            focusPolicy: Qt.NoFocus
            display: AbstractButton.IconOnly
            icon.name: "edit-copy"
            text: "Copy"
            onClicked: root.copyAll()
        }
    }
}
