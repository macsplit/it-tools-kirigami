# Third-Party Notices

This project is primarily original code under the repository license, but it also includes a small number of bundled third-party components.

## Bundled Components

### QR Code generator library (Project Nayuki)

- Purpose: QR code generation backend used by the QR-related tools.
- Upstream: https://www.nayuki.io/page/qr-code-generator-library
- License: MIT
- Vendored files:
  - `src/qrcodegen.hpp`
  - `src/qrcodegen.cpp`
- Notes:
  - The upstream MIT license notice is preserved directly in the vendored source files.

### chrono-node (English locale bundle)

- Purpose: Natural-language date parsing for the Epoch Converter.
- Upstream: https://github.com/wanasit/chrono
- License: MIT
- Vendored files:
  - `src/contents/ui/vendor/chrono-en.bundle.js`
  - `third_party/chrono-node/LICENSE.txt`
- Notes:
  - The bundled JavaScript file includes a provenance comment pointing to the preserved license text.

## Policy For Future Vendored Code

Any newly vendored source should include all of the following:

- An explicit acknowledgement in this file.
- Preserved upstream license text, either inside the vendored files when appropriate or as a sibling license file.
- A short provenance note describing the upstream project and why it is bundled.
