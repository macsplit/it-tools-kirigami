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
*   Email Normalizer
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
*   JSON to TOML Converter
*   JSON to XML Converter
*   JSON to YAML Converter
*   JWT Decoder
*   List Converter
*   Lorem Ipsum Generator
*   MAC Address Generator
*   Math Evaluator
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
*   TOML to JSON Converter
*   ULID Generator
*   URL Encoder/Decoder
*   URL Parser
*   UUID Generator
*   Wifi QR Code Generator
*   IPv4 Range Expander
*   XML Formatter
*   XML to JSON Converter
*   YAML to JSON Converter

## Future Development

The following sections outline the planned future development for **Tools**.

Tool discovery by name and metadata is already in place in the current application, so this roadmap focuses only on work that remains ahead.

### Recent Progress

*   Replaced the temporary YAML and TOML conversion logic with vendored parser/formatter source.
*   Added `YAML to JSON`, `JSON to TOML`, and `TOML to JSON` to the shipped tool set.
*   Recorded the vendored parser dependencies in `THIRD_PARTY_NOTICES.md`.

### Current Correctness Audit

The following tools work, but their current implementations are narrower than their names suggest. These should either be made more spec-complete or renamed/constrained to match reality.

*   `SQL Prettify`: currently a keyword-based formatter, not a real SQL parser/formatter.
*   `Cron Expression Parser`: currently handles a limited 5-field cron subset with simple matching rules.
*   `XML to JSON` / `JSON to XML`: currently use a custom, lossy mapping convention rather than a general round-trip model.
*   `CSV to JSON` / `JSON to CSV`: currently support a simple comma-separated model, not broader CSV dialect handling.
*   `HTML Entities`: currently handles only a very small named-entity subset.
*   `Email Normalizer`: currently has meaningful provider-specific normalization only for Gmail/Googlemail.

### Next Fixes

This is the current order of work to tighten the tools above:

1. Replace the SQL keyword formatter with a real SQL formatter/parser or narrow the tool name.
2. Replace the cron implementation with a fuller parser/evaluator or rename it to reflect the supported subset.
3. Decide and document the exact XML/JSON mapping contract, then either harden it or narrow the naming.
4. Replace the simple CSV handling with a real CSV parser/writer that handles quoted fields and embedded newlines reliably.
5. Expand HTML entity coverage and decide whether email normalization should remain Gmail-focused or become explicitly multi-provider.

### New Tools to be Added

This list is based on an audit of the popular `it-tools` web application, and includes tools that are not yet implemented in **Tools**.

*   [ ] ASCII Text Drawer
*   [ ] Base64 File Converter
*   [ ] Benchmark Builder
*   [ ] BIP39 Generator
*   [ ] Camera Recorder
*   [ ] Chronometer
*   [ ] Device Information
*   [ ] Docker Run to Docker Compose Converter
*   [ ] Emoji Picker
*   [ ] Encryption (Generic)
*   [ ] ETA Calculator
*   [ ] Git Memo
*   [ ] HTML WYSIWYG Editor
*   [ ] IBAN Validator and Parser
*   [ ] IPv6 ULA Generator
*   [ ] JSON Diff
*   [ ] JSON Viewer
*   [ ] Keycode Info
*   [ ] MAC Address Lookup
*   [ ] Meta Tag Generator
*   [ ] OTP Code Generator and Validator
*   [ ] Password Strength Analyzer
*   [ ] PDF Signature Checker
*   [ ] Phone Parser and Formatter
*   [ ] Regex Memo
*   [ ] Regex Tester
*   [ ] RSA Key Pair Generator
*   [ ] Safelink Decoder
*   [ ] SVG Placeholder Generator
*   [ ] Text Diff
*   [ ] TOML to YAML
*   [ ] User Agent Parser
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
