# IT-Tools Kirigami

A Kirigami-based version of the popular `it-tools` collection. This application provides a set of handy developer tools in a convergent, cross-platform interface.

## Tools Included

- UUID Generator
- Base64 Converter (Encode/Decode)
- Case Converter (Uppercase/Lowercase)
- JSON Formatter (Format/Minify)
- Token Generator
- Lorem Ipsum Generator

## Building and Running

### Prerequisites

- CMake
- Qt 5.15
- KF5 (Kirigami2, I18n, CoreAddons)
- Extra CMake Modules (ECM)

### Build

```bash
mkdir build
cd build
cmake ..
make
```

### Run

```bash
./bin/it-tools-kirigami
```

## Cross-Platform

Since it's built with Kirigami and Qt, it can be compiled for:
- Linux (Desktop and Mobile)
- Android
- Windows
- macOS
