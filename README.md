# Tools

A Kirigami-based Linux utility app for developer and IT support tasks.

Official website: https://pastetools.app

Application ID: `app.pastetools.Tools`

![Screenshot](screenshot.png)

## Flatpak

The project can be distributed as a self-hosted Flatpak.

Install from the hosted repository:

```bash
flatpak install https://pastetools.app/app.pastetools.Tools.flatpakref
```

Or add the repository first:

```bash
flatpak remote-add --if-not-exists pastetools https://pastetools.app/pastetools.flatpakrepo
flatpak install pastetools app.pastetools.Tools
```

To build and publish the Flatpak locally:

```bash
./scripts/release-flatpak.sh
./scripts/publish-web.sh
```

## Tools Included

- **Crypto**: Token Generator, Hash Text, HMAC Generator, Bcrypt Password Hash
- **Converter**: Base64 Converter, Integer Base Converter, Color Converter, JSON to YAML, JSON to XML, JSON to CSV, XML to JSON, CSV to JSON, Text to Binary, Epoch Converter, Date/Time Converter, Roman Numeral Converter, Temperature Converter, List Converter, Markdown to HTML
- **Network**: IPv4 Converter, IPv4 Subnet Calculator, WiFi QR Code Generator, MAC Address Generator, Random Port Generator
- **Web**: Basic Auth Generator, URL Encoder/Decoder, HTML Entities, JWT Parser, URL Parser, HTTP Status Codes
- **Development**: MIME Types, UUID Generator, ULID Generator, JSON Formatter, JSON Minify, XML Formatter, SQL Prettify, Chmod Calculator, Cron Expression Parser, Percentage Calculator
- **Text**: Case Converter, Text to NATO Alphabet, Numeronym Generator, Text to Unicode, Lorem Ipsum, Text Statistics, Slugify String, String Obfuscator

## Building and Running

### Prerequisites

- Qt 5.15+ (with Quick, Controls 2, Layouts, SVG)
- Kirigami 2.19+
- CMake
- A C++17 compiler

### Build Steps

```bash
mkdir build
cd build
cmake ..
cmake --build .
./app.pastetools.Tools
```

## Testing

The project includes automated backend and QML smoke tests.

```bash
cmake --build build --target tools_tests
./bin/tools_tests
ctest --output-on-failure
```

## Contributing

See [CONTRIBUTING.md](CONTRIBUTING.md) for the tool architecture, testing expectations, and contribution workflow.

## Third-Party Code

Bundled third-party components and their acknowledgements are listed in [THIRD_PARTY_NOTICES.md](THIRD_PARTY_NOTICES.md).

## License

Distributed under the GPL 3 License. See `LICENSE` for more information.
