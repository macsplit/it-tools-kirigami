import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Window 2.15
import org.kde.kirigami 2.19 as Kirigami
import ittools.kirigami 1.0

Kirigami.ApplicationWindow {
    id: root

    title: "IT-Tools Kirigami"
    
    // Use grid units for scaling-aware sizing
    width: Kirigami.Units.gridUnit * 45
    height: Kirigami.Units.gridUnit * 30
    
    HashTool { id: hashTool }
    BaseTool { id: baseTool }
    ConversionTool { id: conversionTool }
    UrlTool { id: urlTool }

    // Logic for filtering categories
    function isCategoryVisible(cat, filter) {
        if (!filter) return true;
        for (var i = 0; i < toolsModel.count; i++) {
            var item = toolsModel.get(i);
            if (item.category === cat && item.name.toLowerCase().indexOf(filter.toLowerCase()) !== -1) {
                return true;
            }
        }
        return false;
    }

    ListModel {
        id: toolsModel
        ListElement { name: "Token Generator"; category: "Crypto"; file: "tools/TokenGeneratorPage.qml" }
        ListElement { name: "Hash Text"; category: "Crypto"; file: "tools/HashPage.qml" }
        ListElement { name: "Base64 Converter"; category: "Converter"; file: "tools/Base64Page.qml" }
        ListElement { name: "Integer Base Converter"; category: "Converter"; file: "tools/BaseConverterPage.qml" }
        ListElement { name: "Color Converter"; category: "Converter"; file: "tools/ColorConverterPage.qml" }
        ListElement { name: "JSON to YAML"; category: "Converter"; file: "tools/JsonYamlPage.qml" }
        ListElement { name: "XML to JSON"; category: "Converter"; file: "tools/XmlToJsonPage.qml" }
        ListElement { name: "URL Encoder/Decoder"; category: "Web"; file: "tools/UrlEncoderPage.qml" }
        ListElement { name: "HTML Entities"; category: "Web"; file: "tools/HtmlEntitiesPage.qml" }
        ListElement { name: "JWT Parser"; category: "Web"; file: "tools/JwtPage.qml" }
        ListElement { name: "URL Parser"; category: "Web"; file: "tools/UrlParserPage.qml" }
        ListElement { name: "UUID Generator"; category: "Development"; file: "tools/UuidPage.qml" }
        ListElement { name: "JSON Formatter"; category: "Development"; file: "tools/JsonFormatterPage.qml" }
        ListElement { name: "XML Formatter"; category: "Development"; file: "tools/XmlFormatterPage.qml" }
        ListElement { name: "Chmod Calculator"; category: "Development"; file: "tools/ChmodPage.qml" }
        ListElement { name: "Cron Expression Parser"; category: "Development"; file: "tools/CronPage.qml" }
        ListElement { name: "MAC Address Generator"; category: "Network"; file: "tools/MacGeneratorPage.qml" }
        ListElement { name: "Random Port Generator"; category: "Network"; file: "tools/PortGeneratorPage.qml" }
        ListElement { name: "WiFi QR Code Generator"; category: "Network"; file: "tools/WifiPage.qml" }
        ListElement { name: "Case Converter"; category: "Text"; file: "tools/CaseConverterPage.qml" }
        ListElement { name: "Lorem Ipsum"; category: "Text"; file: "tools/LoremIpsumPage.qml" }
        ListElement { name: "Text Statistics"; category: "Text"; file: "tools/TextStatisticsPage.qml" }
        ListElement { name: "Slugify String"; category: "Text"; file: "tools/SlugifyPage.qml" }
        ListElement { name: "String Obfuscator"; category: "Text"; file: "tools/StringObfuscatorPage.qml" }
    }

    globalDrawer: Kirigami.GlobalDrawer {
        id: drawer
        isMenu: false
        collapsible: true
        modal: false
        width: Kirigami.Units.gridUnit * 12
        handleVisible: true
        
        header: Kirigami.SearchField {
            id: searchField
            placeholderText: "Search..."
            Layout.fillWidth: true
            Layout.margins: Kirigami.Units.smallSpacing
        }

        contentItem: ListView {
            id: toolsList
            model: toolsModel
            clip: true
            topMargin: Kirigami.Units.gridUnit
            bottomMargin: Kirigami.Units.gridUnit * 2
            
            section.property: "category"
            section.delegate: Kirigami.ListSectionHeader {
                width: toolsList.width
                text: section
                visible: root.isCategoryVisible(section, searchField.text)
                height: visible ? implicitHeight : 0
            }

            delegate: Kirigami.BasicListItem {
                width: toolsList.width
                text: model.name
                visible: model.name.toLowerCase().indexOf(searchField.text.toLowerCase()) !== -1
                height: visible ? implicitHeight : 0
                onClicked: {
                    root.pageStack.replace(Qt.resolvedUrl(model.file));
                    if (drawer.modal) {
                        drawer.close();
                    }
                }
            }
        }
    }

    pageStack.initialPage: Kirigami.Page {
        title: "Welcome"
        Kirigami.PlaceholderMessage {
            anchors.centerIn: parent
            width: parent.width - (Kirigami.Units.largeSpacing * 4)
            text: "Welcome to IT-Tools"
            explanation: "Select a tool from the sidebar to get started."
        }
    }

    function showMessage(msg) {
        root.showPassiveNotification(msg)
    }
}
