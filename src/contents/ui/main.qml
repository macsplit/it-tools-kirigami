import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Window 2.15
import org.kde.kirigami 2.19 as Kirigami
import ittools.kirigami 1.0

Kirigami.ApplicationWindow {
    id: root

    title: "Tools"
    
    // Force single column view even on wide screens
    wideScreen: false
    
    width: Kirigami.Units.gridUnit * 45
    height: Kirigami.Units.gridUnit * 25
    
    HashTool { id: hashTool }
    BaseTool { id: baseTool }
    ConversionTool { id: conversionTool }
    UrlTool { id: urlTool }
    NetworkTool { id: networkTool }
    TimeTool { id: timeTool }

    ListModel {
        id: toolsModel
    }

    ListModel {
        id: filteredToolsModel
    }

    // Navigation logic
    function goToDashboard() {
        while (pageStack.depth > 1) {
            pageStack.pop();
        }
        if (pageStack.currentItem && pageStack.currentItem.objectName === "dashboard") {
            pageStack.currentItem.toolsModel = toolsModel;
        }
    }

    function openTool(file) {
        var resolvedFile = Qt.resolvedUrl(file);
        if (pageStack.currentItem && pageStack.currentItem.objectName === "dashboard") {
            pageStack.push(resolvedFile);
            return;
        }

        if (pageStack.depth > 1) {
            pageStack.replace(resolvedFile);
            return;
        }

        pageStack.push(resolvedFile);
    }

    function matchesSearch(item, filter) {
        if (!filter) return true;
        var searchStr = filter.toLowerCase();
        if (item.name.toLowerCase().indexOf(searchStr) !== -1) return true;
        if (item.keywords && item.keywords.toLowerCase().indexOf(searchStr) !== -1) return true;
        return false;
    }

    function refreshDrawerFilter() {
        filteredToolsModel.clear();
        for (var i = 0; i < toolsModel.count; i++) {
            var item = toolsModel.get(i);
            if (matchesSearch(item, searchField.text)) {
                filteredToolsModel.append(item);
            }
        }
    }

    Component.onCompleted: {
        var data = ToolManager.tools.slice(0);
        data.sort(function(a, b) {
            var categoryCompare = a.category.localeCompare(b.category);
            if (categoryCompare !== 0) {
                return categoryCompare;
            }

            return a.name.localeCompare(b.name);
        });

        for (var i = 0; i < data.length; i++) {
            toolsModel.append(data[i]);
        }
        
        // Ensure single column view for consistent layout
        if (pageStack.hasOwnProperty("columnDisplayMode")) {
            pageStack.columnDisplayMode = Kirigami.ColumnView.SingleColumn; // 0
        } else if (pageStack.columnView && pageStack.columnView.hasOwnProperty("columnDisplayMode")) {
            pageStack.columnView.columnDisplayMode = Kirigami.ColumnView.SingleColumn;
        }

        if (pageStack.currentItem && pageStack.currentItem.objectName === "dashboard") {
            pageStack.currentItem.toolsModel = toolsModel;
        }

        refreshDrawerFilter();
    }

    globalDrawer: Kirigami.GlobalDrawer {
        id: drawer
        collapsible: true
        collapsed: false
        modal: true // Set modal to true to force single column behavior
        width: Kirigami.Units.gridUnit * 15
        handleVisible: true

        contentItem: ColumnLayout {
            spacing: 0
            
            Kirigami.BasicListItem {
                text: "Home / Dashboard"
                icon: "go-home-symbolic"
                Layout.fillWidth: true
                focusPolicy: Qt.NoFocus
                onClicked: {
                    root.goToDashboard();
                    if (drawer.modal) drawer.close();
                }
            }

            Kirigami.SearchField {
                id: searchField
                placeholderText: "Search tools..."
                Layout.fillWidth: true
                Layout.margins: Kirigami.Units.smallSpacing
                onTextChanged: root.refreshDrawerFilter()

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
            }

            ListView {
                id: toolsList
                Layout.fillWidth: true
                Layout.fillHeight: true
                model: filteredToolsModel
                clip: true
                focus: false
                keyNavigationEnabled: false
                
                section.property: "category"
                section.delegate: Kirigami.ListSectionHeader {
                    width: toolsList.width
                    text: section
                }

                delegate: Kirigami.BasicListItem {
                    width: toolsList.width
                    text: model.name
                    focusPolicy: Qt.NoFocus
                    onClicked: {
                        root.openTool(model.file);
                        if (drawer.modal) drawer.close();
                    }
                }
            }
        }
    }

    pageStack.defaultColumnWidth: width
    pageStack.globalToolBar.style: Kirigami.ApplicationHeaderStyle.ToolBar
    pageStack.globalToolBar.showNavigationButtons: Kirigami.ApplicationHeaderStyle.ShowBackButton | Kirigami.ApplicationHeaderStyle.ShowForwardButton
    pageStack.initialPage: Qt.resolvedUrl("Dashboard.qml")

    function showMessage(msg) {
        root.showPassiveNotification(msg, 1200)
    }
}
