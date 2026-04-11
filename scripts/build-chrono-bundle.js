const fs = require("fs");
const path = require("path");
const esbuild = require("esbuild");
const babel = require("@babel/core");

const repoRoot = path.resolve(__dirname, "..");
const buildRoot = "/tmp/codex-chrono-build";
const outputFile = path.join(repoRoot, "src/contents/ui/vendor/chrono-en.bundle.js");
const licenseNote = "// Bundled from chrono-node@2.9.0 (MIT). See third_party/chrono-node/LICENSE.txt.\n";

const entrySource = `
const chrono = require("chrono-node/en");
var root = Function("return this")();
root.ChronoBridge = {
  parseComponents: function(text, referenceEpochMs, timezoneOffsetMinutes) {
    var reference = {
      instant: new Date(referenceEpochMs),
      timezone: timezoneOffsetMinutes
    };

    var results = chrono.parse(text, reference);
    if (!results || results.length === 0) {
      return null;
    }

    var start = results[0].start;
    var fields = ["year", "month", "day", "hour", "minute", "second", "millisecond"];
    var out = { text: results[0].text };

    for (var i = 0; i < fields.length; i++) {
      var field = fields[i];
      var value = start.get(field);
      if (value !== null && value !== undefined) {
        out[field] = value;
      }
      out[field + "Certain"] = start.isCertain(field);
    }

    return out;
  }
};
`;

async function main() {
  const entryFile = path.join(buildRoot, "chrono-qml-entry.js");
  fs.mkdirSync(buildRoot, { recursive: true });
  fs.writeFileSync(entryFile, entrySource);

  const bundled = await esbuild.build({
    entryPoints: [entryFile],
    bundle: true,
    platform: "browser",
    format: "iife",
    target: ["es2015"],
    write: false,
    banner: { js: licenseNote.trimEnd() },
  });

  const transformed = babel.transformSync(bundled.outputFiles[0].text, {
    presets: [[require("@babel/preset-env"), { targets: { ie: "11" }, modules: false }]],
    sourceType: "script",
    plugins: [
      require("@babel/plugin-transform-arrow-functions"),
      require("@babel/plugin-transform-block-scoping"),
      require("@babel/plugin-transform-classes"),
      require("@babel/plugin-transform-computed-properties"),
      require("@babel/plugin-transform-destructuring"),
      require("@babel/plugin-transform-for-of"),
      require("@babel/plugin-transform-parameters"),
      require("@babel/plugin-transform-shorthand-properties"),
      require("@babel/plugin-transform-template-literals"),
    ],
    comments: true,
    compact: false,
    babelrc: false,
    configFile: false,
  });

  const promoted = transformed.code.replace(
    /require_chrono_qml_entry\(\);\s*\}\)\(\);?\s*$/,
    'var __chronoBridgeExports = require_chrono_qml_entry();\n  Function("return this")().ChronoBridge = __chronoBridgeExports.ChronoBridge;\n})();'
  );

  fs.writeFileSync(outputFile, promoted);
}

main().catch((error) => {
  console.error(error);
  process.exit(1);
});
