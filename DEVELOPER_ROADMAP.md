# Developer Roadmap: Tools

This document outlines the developer roadmap for "Tools", a desktop-based Swiss Army knife for developers, hackers, and sysadmins.

## Official Name

To avoid confusion and any suggestion of endorsement, the official name of this project is **Tools**.

## Current State

The application is currently in a stable and minimally viable state. The core architecture is in place, and a good number of tools are already implemented.

### Implemented Tools

*   Base64 Encoder/Decoder
*   Base Converter
*   Basic Auth Generator
*   Bcrypt Password Hash
*   Case Converter
*   Chmod Calculator
*   Color Converter
*   Cron Job Editor
*   CSV to JSON Converter
*   Epoch Converter
*   Date/Time Converter
*   Hash Calculator
*   HMAC Generator
*   HTML Entities Encoder/Decoder
*   HTTP Status Codes
*   IPv4 Converter
*   IPv4 Subnet Calculator
*   JSON Formatter
*   JSON Minify
*   JSON to CSV Converter
*   JSON to XML Converter
*   JSON to YAML Converter
*   JWT Decoder
*   List Converter
*   Lorem Ipsum Generator
*   MAC Address Generator
*   MIME Types
*   Markdown Preview
*   Numeronym Generator
*   Percentage Calculator
*   Port Generator
*   Roman Numeral Converter
*   Slugify
*   SQL Formatter
*   String Obfuscator
*   Temperature Converter
*   Text Statistics
*   Text to Binary Converter
*   Text to NATO Alphabet
*   Text to Unicode
*   Token Generator
*   ULID Generator
*   URL Encoder/Decoder
*   URL Parser
*   UUID Generator
*   Wifi QR Code Generator
*   XML Formatter
*   XML to JSON Converter

## Future Development

The following sections outline the planned future development for **Tools**.

### New Tools to be Added

This list is based on an audit of the popular `it-tools` web application, and includes tools that are not yet implemented in **Tools**.

*   [ ] ASCII Text Drawer
*   [ ] Base64 File Converter
*   [x] Basic Auth Generator
*   [x] Bcrypt
*   [ ] Benchmark Builder
*   [ ] BIP39 Generator
*   [ ] Camera Recorder
*   [ ] Chronometer
*   [x] Date/Time Converter
*   [ ] Device Information
*   [ ] Docker Run to Docker Compose Converter
*   [ ] Email Normalizer
*   [ ] Emoji Picker
*   [ ] Encryption (Generic)
*   [ ] ETA Calculator
*   [ ] Git Memo
*   [ ] HTML WYSIWYG Editor
*   [ ] IBAN Validator and Parser
*   [ ] IPv4 Range Expander
*   [ ] IPv6 ULA Generator
*   [ ] JSON Diff
*   [x] JSON Minify
*   [ ] JSON to TOML
*   [ ] JSON Viewer
*   [ ] Keycode Info
*   [ ] MAC Address Lookup
*   [x] Markdown to HTML
*   [ ] Math Evaluator
*   [ ] Meta Tag Generator
*   [x] MIME Types
*   [x] Numeronym Generator
*   [ ] OTP Code Generator and Validator
*   [ ] Password Strength Analyzer
*   [ ] PDF Signature Checker
*   [x] Percentage Calculator
*   [ ] Phone Parser and Formatter
*   [ ] Regex Memo
*   [ ] Regex Tester
*   [x] Roman Numeral Converter
*   [ ] RSA Key Pair Generator
*   [ ] Safelink Decoder
*   [ ] SVG Placeholder Generator
*   [ ] Text Diff
*   [x] Text to NATO Alphabet
*   [x] Text to Unicode
*   [ ] TOML to JSON
*   [ ] TOML to YAML
*   [x] ULID Generator
*   [ ] User Agent Parser
*   [ ] YAML to JSON Converter
*   [ ] YAML to TOML
*   [ ] YAML Viewer

### Brainstormed Tool Ideas

This is a list of potential new tools that are not present in `it-tools`, but would be a good fit for **Tools**.

*   [ ] Morse Code Converter
*   [ ] Binary/Hex/Octal Converter
*   [ ] ROT13/ROT47 Encoder/Decoder
*   [ ] Leet Speak Converter
*   [ ] Reverse String
*   [ ] Word/Line Count
*   [ ] Character Code (ASCII/Unicode) Finder
*   [ ] Figlet/ASCII Art Text Generator
*   [ ] Simple Cryptography Playground (Caesar, Atbash, etc.)
*   [ ] Data Size Converter
*   [ ] Time Zone Converter

### Enhancements

These are planned enhancements to the core application.

#### Tool Discovery

* [x] **Searchable Tool List:** Implement a search bar in the left pane to allow users to quickly find tools by name.
* [x] **Metadata-based Search:** Associate metadata and keywords with each tool. This will allow the search to return relevant tools even if the search term doesn't exactly match the tool's name. For example, searching for "hash" should also bring up "HMAC" and "Bcrypt".

##### Implementation suggestions

*   Create a JSON or XML file that stores the metadata for each tool. This file would include the tool's name, a description, and a list of keywords.
*   The search functionality would then parse this file and use it to provide more relevant search results.

## Technical Guidelines & Future-Proofing

To ensure "Tools" remains compatible with sandboxed environments (like Flatpak) and maintains its high performance and security, developers should adhere to the following guidelines:

### Sandboxing & Isolation

*   **Internal Resources:** Always prefer bundling data and assets within the Qt Resource System (`qrc:/`). This ensures the application remains self-contained and avoids the need for external filesystem permissions.
*   **Avoid Direct Filesystem Access:** Do not use direct file paths (e.g., `/home/user/...`) to access data. If a tool needs to interact with the user's files, use standard Qt/Kirigami dialogs (e.g., `FileDialog`), which automatically leverage XDG Portals in sandboxed environments.
*   **Environment Isolation:** Avoid dependencies on global system environment variables or external configuration files outside the application's own internal storage.

### Offline-First Development

*   **No Web Dependencies:** All tools must function entirely offline. Do not use external APIs, web-based fonts, or remote scripts. If a tool requires external data (like the MIME types list), bundle it as a local JSON file within the resources.
*   **Local C++ Libraries:** For complex processing (like ASCII art generation or encryption), use local C++ libraries or built-in Qt functionality rather than web services.

### QML & C++ Integration

*   **Prefer C++ for Heavy Lifting:** While QML is excellent for UI, complex logic and data processing should be implemented in C++ to maintain performance and take advantage of strong typing.
*   **Avoid `XMLHttpRequest` for Local Files:** For reading internal JSON resources, prefer loading the data in C++ and exposing it to QML as a property. This avoids security warnings and potential future deprecations in the Qt runtime.

## Conclusion

This roadmap provides a high-level overview of the future development of **Tools**. The focus is on adding more useful tools, keeping the application stable, and improving the day-to-day user experience in concrete, incremental steps.
