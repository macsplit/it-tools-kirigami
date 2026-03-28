import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.Page {
    title: "Case Converter"
    ColumnLayout {
        anchors.fill: parent
        anchors.margins: Kirigami.Units.largeSpacing
        AppTextArea {
            id: caseInputField
            placeholderText: "Input text..."
            Layout.fillWidth: true
            Layout.fillHeight: true
            showPasteButton: true
            showCopyButton: true
        }
        Flow {
            Layout.fillWidth: true
            spacing: Kirigami.Units.largeSpacing
            Button {
                text: "UPPERCASE"
                onClicked: caseInputField.text = caseInputField.text.toUpperCase()
            }
            Button {
                text: "lowercase"
                onClicked: caseInputField.text = caseInputField.text.toLowerCase()
            }
            Button {
                text: "camelCase"
                onClicked: {
                    var words = caseInputField.text.toLowerCase().split(/[\s_-]+/);
                    if (words.length === 0) return;
                    var res = words[0];
                    for (var i = 1; i < words.length; i++) {
                        if (words[i].length > 0)
                            res += words[i].charAt(0).toUpperCase() + words[i].slice(1);
                    }
                    caseInputField.text = res;
                }
            }
            Button {
                text: "PascalCase"
                onClicked: {
                    var words = caseInputField.text.toLowerCase().split(/[\s_-]+/);
                    var res = "";
                    for (var i = 0; i < words.length; i++) {
                        if (words[i].length > 0)
                            res += words[i].charAt(0).toUpperCase() + words[i].slice(1);
                    }
                    caseInputField.text = res;
                }
            }
            Button {
                text: "snake_case"
                onClicked: {
                    caseInputField.text = caseInputField.text.replace(/([a-z])([A-Z])/g, '$1_$2')
                                                              .replace(/[\s-]+/g, '_')
                                                              .toLowerCase();
                }
            }
            Button {
                text: "kebab-case"
                onClicked: {
                    caseInputField.text = caseInputField.text.replace(/([a-z])([A-Z])/g, '$1-$2')
                                                              .replace(/[\s_]+/g, '-')
                                                              .toLowerCase();
                }
            }
        }
    }
}
