import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.ScrollablePage {
    id: dashboardPage
    objectName: "dashboard"
    title: "Dashboard"
    
    property var toolsModel: null
    
    ListModel {
        id: filteredModel
    }
    
    function refreshFilter() {
        filteredModel.clear();
        if (!toolsModel) return;
        var searchStr = dashboardSearch.text.toLowerCase();
        var matches = [];
        for (var i = 0; i < toolsModel.count; i++) {
            var item = toolsModel.get(i);
            if (searchStr === "" || 
                item.name.toLowerCase().indexOf(searchStr) !== -1 ||
                (item.keywords && item.keywords.toLowerCase().indexOf(searchStr) !== -1)) {
                matches.push(item);
            }
        }

        matches.sort(function(a, b) {
            return a.name.localeCompare(b.name);
        });

        for (var j = 0; j < matches.length; j++) {
            filteredModel.append(matches[j]);
        }
    }

    function categoryIcon(category) {
        switch (category) {
        case "Crypto":
            return "qrc:/contents/ui/icons/category-crypto-symbolic.svg";
        case "Converter":
            return "qrc:/contents/ui/icons/category-converter-symbolic.svg";
        case "Network":
            return "qrc:/contents/ui/icons/category-network-symbolic.svg";
        case "Web":
            return "qrc:/contents/ui/icons/category-web-symbolic.svg";
        case "Development":
            return "qrc:/contents/ui/icons/category-development-symbolic.svg";
        case "Text":
            return "qrc:/contents/ui/icons/category-text-symbolic.svg";
        default:
            return "qrc:/contents/ui/icons/tool-symbolic.svg";
        }
    }
    
    onToolsModelChanged: refreshFilter()
    
    Component.onCompleted: refreshFilter()

    ColumnLayout {
        spacing: 0
        
        Kirigami.SearchField {
            id: dashboardSearch
            placeholderText: "Search tools..."
            Layout.fillWidth: true
            Layout.margins: Kirigami.Units.largeSpacing
            focus: true
            onTextChanged: refreshFilter()
            onAccepted: {
                if (filteredModel.count === 1) {
                    applicationWindow().openTool(filteredModel.get(0).file);
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
        }
        
        GridView {
            id: toolsGridView
            Layout.fillWidth: true
            Layout.preferredHeight: contentHeight
            Layout.leftMargin: Kirigami.Units.largeSpacing
            Layout.rightMargin: Kirigami.Units.largeSpacing
            focus: false
            keyNavigationEnabled: false
            
            cellWidth: Kirigami.Units.gridUnit * 12
            cellHeight: Kirigami.Units.gridUnit * 6
            
            model: filteredModel
            interactive: false
            
            delegate: Kirigami.AbstractCard {
                width: toolsGridView.cellWidth - Kirigami.Units.smallSpacing
                height: toolsGridView.cellHeight - Kirigami.Units.smallSpacing
                focusPolicy: Qt.NoFocus
                
                contentItem: ColumnLayout {
                    spacing: Kirigami.Units.smallSpacing
                    Kirigami.Icon {
                        source: dashboardPage.categoryIcon(model.category)
                        isMask: true
                        Layout.alignment: Qt.AlignHCenter
                        Layout.preferredWidth: Kirigami.Units.iconSizes.medium
                        Layout.preferredHeight: Kirigami.Units.iconSizes.medium
                    }
                    
                    Label {
                        text: model.name
                        wrapMode: Text.WordWrap
                        horizontalAlignment: Text.AlignHCenter
                        Layout.fillWidth: true
                        font.bold: true
                        elide: Text.ElideRight
                        maximumLineCount: 2
                    }
                }
                
                onClicked: {
                    applicationWindow().openTool(model.file);
                }
            }
        }
    }
}
