# Third-Party Notices

This project is primarily original code under the repository license, but it also includes bundled third-party code where noted below.

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

### toml++ (Mark Gillard / marzer)

- Purpose: TOML parsing and serialization backend used by the TOML conversion tools.
- Upstream: https://github.com/marzer/tomlplusplus
- License: MIT
- Vendored files:
  - `third_party/tomlplusplus/toml.hpp`
- Notes:
  - The upstream MIT license notice is embedded in the vendored single-header source.
  - Vendored version: `v3.4.0`

### yaml-cpp (Jesse Beder and contributors)

- Purpose: YAML parsing and emitting backend used by the YAML conversion tools.
- Upstream: https://github.com/jbeder/yaml-cpp
- License: MIT
- Vendored files:
  - `third_party/yaml-cpp/include/`
  - `third_party/yaml-cpp/src/`
  - `third_party/yaml-cpp/LICENSE`
  - `third_party/yaml-cpp/README.md`
- Notes:
  - Vendored version: `0.8.0`

## Policy For Future Vendored Code

Any newly vendored source should include all of the following:

- An explicit acknowledgement in this file.
- Preserved upstream license text, either inside the vendored files when appropriate or as a sibling license file.
- A short provenance note describing the upstream project and why it is bundled.
