import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.ScrollablePage {
    title: "Math Evaluator"

    ColumnLayout {
        width: parent.width
        spacing: Kirigami.Units.largeSpacing

        Label {
            text: "Expression"
            font.bold: true
        }

        AppTextField {
            id: expressionInput
            Layout.fillWidth: true
            text: "(2 + 3) * 4^2 - 5"
            placeholderText: "Use +, -, *, /, %, ^ and parentheses"
        }

        Label {
            text: "Result"
            font.bold: true
        }

        OutputField {
            Layout.fillWidth: true
            readOnly: true
            text: mathTool.evaluateExpression(expressionInput.text)
            placeholderText: "Calculated result"
        }
    }
}
