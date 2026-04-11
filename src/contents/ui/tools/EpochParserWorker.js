var chronoReady = false;
var chronoLoadError = "";

function normalizeInput(input) {
    return input
        .replace(/\b(\d{1,2})(st|nd|rd|th)\b/gi, "$1")
        .replace(/\b(on|at)\b/gi, " ")
        .replace(/\s+/g, " ")
        .trim();
}

function ensureChronoLoaded() {
    if (chronoReady) {
        return true;
    }

    try {
        var result = Qt.include("../vendor/chrono-en.bundle.js");
        if (result.exception) {
            chronoLoadError = result.exception.toString();
            return false;
        }

        if (typeof ChronoBridge === "undefined" || !ChronoBridge.parseComponents) {
            chronoLoadError = "ChronoBridge global was not created";
            return false;
        }

        chronoReady = true;
        return true;
    } catch (error) {
        chronoLoadError = error.toString();
        return false;
    }
}

function sanitizeComponents(result) {
    if (!result) {
        return null;
    }

    var fields = [
        "year",
        "month",
        "day",
        "hour",
        "minute",
        "second",
        "millisecond",
        "hourCertain",
        "minuteCertain",
        "secondCertain",
        "millisecondCertain"
    ];
    var out = {};

    for (var i = 0; i < fields.length; i++) {
        var field = fields[i];
        if (result[field] !== undefined && result[field] !== null) {
            out[field] = result[field];
        }
    }

    return out;
}

WorkerScript.onMessage = function(message) {
    if (!message.text || !message.text.trim()) {
        WorkerScript.sendMessage({
            requestId: message.requestId,
            empty: true
        });
        return;
    }

    if (!ensureChronoLoaded()) {
        WorkerScript.sendMessage({
            requestId: message.requestId,
            error: chronoLoadError || "Failed to load bundled parser"
        });
        return;
    }

    try {
        var components = ChronoBridge.parseComponents(
            normalizeInput(message.text),
            message.referenceEpochMs,
            message.timezoneOffsetMinutes
        );

        WorkerScript.sendMessage({
            requestId: message.requestId,
            components: sanitizeComponents(components)
        });
    } catch (error) {
        WorkerScript.sendMessage({
            requestId: message.requestId,
            error: error.toString()
        });
    }
};
