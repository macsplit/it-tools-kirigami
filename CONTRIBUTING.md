# Contributing to Tools

Thank you for your interest in adding more tools! This project is a modular Kirigami application designed to be easily extensible.

## Architecture Overview

The project has a simple split of responsibilities:

1.  **QML**: page layout, bindings, and small UI glue.
2.  **C++**: parsing, formatting, validation, conversion, generation, and other reusable tool logic.

Treat page-local JavaScript as a last resort. If a tool has real behavior rather than simple bindings, put that behavior in a C++ helper and keep the QML page focused on UI.

## How to Add a New Tool

### 1. Create the UI Component
Create a new `.qml` file in `src/contents/ui/tools/`. Every tool should use `Kirigami.ScrollablePage` as the root element to ensure it works well on all screen sizes and with UI scaling.

```qml
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.19 as Kirigami

Kirigami.ScrollablePage {
    title: "My New Tool"

    ColumnLayout {
        width: parent.width
        spacing: Kirigami.Units.largeSpacing

        Label {
            text: "Input:"
            font.bold: true
        }
        TextField {
            id: inputField
            Layout.fillWidth: true
        }
        
        // Bind UI controls to backend helpers here.
    }
}
```

Prefer the existing shared controls where they fit:

*   `AppTextArea.qml`
*   `AppTextField.qml`
*   `OutputArea.qml`
*   `OutputField.qml`

These already handle common behavior such as copy/paste actions and passive notifications.

### 2. Register the Resource
Add your new file to `src/resources.qrc` so the application can find it at runtime.

```xml
<file>contents/ui/tools/MyNewToolPage.qml</file>
```

### 3. Register the Tool Metadata
Open `src/contents/ui/tools.json` and add a new object. This file drives both the dashboard and the drawer. Categorize the tool appropriately (`Crypto`, `Converter`, `Web`, `Development`, `Network`, or `Text`) and include useful search keywords.

```json
{
    "name": "My New Tool",
    "category": "Development",
    "file": "tools/MyNewToolPage.qml",
    "keywords": "search terms aliases related concepts"
}
```

The application loads `tools.json` through `ToolManager` and sorts it at startup, so there is no manual tool list to keep in sync in `main.qml`.

## Adding C++ Logic

If your tool parses, formats, validates, transforms, or generates data, add or extend a backend helper in `src/`:

1.  **Create a Header**: Add a new header file in `src/` (e.g., `mytool.h`) inheriting from `QObject`.
2.  **Use Q_INVOKABLE**: Mark functions you want to call from QML with `Q_INVOKABLE`.
3.  **Register in main.cpp**: Use `qmlRegisterType<MyTool>("ittools.kirigami", 1, 0, "MyTool");`.
4.  **Update CMakeLists.txt**: Add the header file to the `add_executable` list.
5.  **Use in QML**: Instantiate your tool in `main.qml` only if the page needs a shared object instance (for example, `MyTool { id: myTool }`) and call its functions from your tool page.

Good candidates for shared helpers are:

*   `TextTool`
*   `ConversionTool`
*   `TimeTool`
*   `IdTool`
*   `MathTool`
*   `UrlTool`
*   `NetworkTool`
*   `CronTool`
*   `MimeTool`

## Verifying the Change

After adding or modifying a tool, rebuild the project and run the automated tests:

```bash
cmake --build build
./bin/tools_tests
ctest --output-on-failure
```

Also verify the page opens from both the dashboard and the drawer.

## Adding Tests

Tool changes should include automated coverage.

1.  Add backend-focused dataset cases under `tests/data/`.
2.  Extend `tests/tools_test.cpp` only when a new backend method needs dispatch wiring.
3.  Prefer dataset-driven backend assertions over GUI interaction tests.
4.  Keep QML tests focused on smoke loading and thin integration behavior.

The current test harness loads QML directly with a headless `QQmlEngine`; it does not use a web view or browser-style runtime.

## Best Practices

*   **No Icons**: We avoid 1:1 icon mapping for tools to keep the UI clean and avoid abstract/mismatched imagery.
*   **Responsive Layouts**: Use `Kirigami.Units.gridUnit` and `Kirigami.Units.largeSpacing` instead of fixed pixel values to ensure the app scales correctly on high-DPI screens.
*   **Backend-Led Logic**: Keep major logic in C++. QML should describe the interface, not become a second implementation layer.
*   **Local-Only Behavior**: Prefer tools that run entirely on the local machine and avoid network-dependent processing.
*   **Keep Metadata Useful**: Tool names, categories, and keywords in `tools.json` are part of the user-facing search experience, so treat them as product behavior rather than bookkeeping.

## Vendored Code

If a new tool needs vendored third-party code or data:

1.  Preserve the upstream license text in the repository.
2.  Add or update an acknowledgement entry in `THIRD_PARTY_NOTICES.md`.
3.  Keep a short provenance note near the vendored source when practical.
4.  Avoid partial or ad-hoc parser copies when a dependency is complex enough that a real upstream library should be carried intact.
