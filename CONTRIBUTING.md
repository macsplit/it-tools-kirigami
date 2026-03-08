# Contributing to IT-Tools Kirigami

Thank you for your interest in adding more tools! This project is a modular Kirigami application designed to be easily extensible.

## Architecture Overview

The application is built using a combination of three technologies:

1.  **QML**: Defines the user interface using the Kirigami framework.
2.  **JavaScript (ES6)**: Handles simple UI logic and light transformations directly within QML files.
3.  **C++**: Provides high-performance backends for complex logic (hashing, arbitrary precision math, etc.).

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
        
        // ... tool logic ...
    }
}
```

### 2. Register the Resource
Add your new file to `src/resources.qrc` so the application can find it at runtime.

```xml
<file>contents/ui/tools/MyNewToolPage.qml</file>
```

### 3. Add to the Sidebar
Open `src/contents/ui/main.qml` and add a new `ListElement` to the `toolsModel`. Categorize it appropriately (Crypto, Converter, Web, Development, Network, or Text).

```qml
ListElement { 
    name: "My New Tool"; 
    category: "Development"; 
    file: "tools/MyNewToolPage.qml" 
}
```

## Adding C++ Logic (Optional)

If your tool requires heavy computation:

1.  **Create a Header**: Add a new header file in `src/` (e.g., `mytool.h`) inheriting from `QObject`.
2.  **Use Q_INVOKABLE**: Mark functions you want to call from QML with `Q_INVOKABLE`.
3.  **Register in main.cpp**: Use `qmlRegisterType<MyTool>("ittools.kirigami", 1, 0, "MyTool");`.
4.  **Update CMakeLists.txt**: Add the header file to the `add_executable` list.
5.  **Use in QML**: Instantiate your tool in `main.qml` (e.g., `MyTool { id: myTool }`) and call its functions from your tool's page.

## Best Practices

*   **No Icons**: We avoid 1:1 icon mapping for tools to keep the UI clean and avoid abstract/mismatched imagery.
*   **Responsive Layouts**: Use `Kirigami.Units.gridUnit` and `Kirigami.Units.largeSpacing` instead of fixed pixel values to ensure the app scales correctly on high-DPI screens.
*   **ES6 Compatibility**: JavaScript inside QML should target ES6 (use `var` instead of `let/const` if you encounter engine issues, and avoid modern methods like `padStart` without polyfills).
*   **C++ for Performance**: If a transformation takes more than a few milliseconds, it belongs in a C++ backend.
