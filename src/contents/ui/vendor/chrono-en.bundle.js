function _typeof(o) { "@babel/helpers - typeof"; return _typeof = "function" == typeof Symbol && "symbol" == typeof Symbol.iterator ? function (o) { return typeof o; } : function (o) { return o && "function" == typeof Symbol && o.constructor === Symbol && o !== Symbol.prototype ? "symbol" : typeof o; }, _typeof(o); }
function _superPropGet(t, o, e, r) { var p = _get(_getPrototypeOf(1 & r ? t.prototype : t), o, e); return 2 & r && "function" == typeof p ? function (t) { return p.apply(e, t); } : p; }
function _get() { return _get = "undefined" != typeof Reflect && Reflect.get ? Reflect.get.bind() : function (e, t, r) { var p = _superPropBase(e, t); if (p) { var n = Object.getOwnPropertyDescriptor(p, t); return n.get ? n.get.call(arguments.length < 3 ? e : r) : n.value; } }, _get.apply(null, arguments); }
function _superPropBase(t, o) { for (; !{}.hasOwnProperty.call(t, o) && null !== (t = _getPrototypeOf(t));); return t; }
function _callSuper(t, o, e) { return o = _getPrototypeOf(o), _possibleConstructorReturn(t, _isNativeReflectConstruct() ? Reflect.construct(o, e || [], _getPrototypeOf(t).constructor) : o.apply(t, e)); }
function _possibleConstructorReturn(t, e) { if (e && ("object" == _typeof(e) || "function" == typeof e)) return e; if (void 0 !== e) throw new TypeError("Derived constructors may only return object or undefined"); return _assertThisInitialized(t); }
function _assertThisInitialized(e) { if (void 0 === e) throw new ReferenceError("this hasn't been initialised - super() hasn't been called"); return e; }
function _isNativeReflectConstruct() { try { var t = !Boolean.prototype.valueOf.call(Reflect.construct(Boolean, [], function () {})); } catch (t) {} return (_isNativeReflectConstruct = function _isNativeReflectConstruct() { return !!t; })(); }
function _getPrototypeOf(t) { return _getPrototypeOf = Object.setPrototypeOf ? Object.getPrototypeOf.bind() : function (t) { return t.__proto__ || Object.getPrototypeOf(t); }, _getPrototypeOf(t); }
function _inherits(t, e) { if ("function" != typeof e && null !== e) throw new TypeError("Super expression must either be null or a function"); t.prototype = Object.create(e && e.prototype, { constructor: { value: t, writable: !0, configurable: !0 } }), Object.defineProperty(t, "prototype", { writable: !1 }), e && _setPrototypeOf(t, e); }
function _setPrototypeOf(t, e) { return _setPrototypeOf = Object.setPrototypeOf ? Object.setPrototypeOf.bind() : function (t, e) { return t.__proto__ = e, t; }, _setPrototypeOf(t, e); }
function _toConsumableArray(r) { return _arrayWithoutHoles(r) || _iterableToArray(r) || _unsupportedIterableToArray(r) || _nonIterableSpread(); }
function _nonIterableSpread() { throw new TypeError("Invalid attempt to spread non-iterable instance.\nIn order to be iterable, non-array objects must have a [Symbol.iterator]() method."); }
function _iterableToArray(r) { if ("undefined" != typeof Symbol && null != r[Symbol.iterator] || null != r["@@iterator"]) return Array.from(r); }
function _arrayWithoutHoles(r) { if (Array.isArray(r)) return _arrayLikeToArray(r); }
function _readOnlyError(r) { throw new TypeError('"' + r + '" is read-only'); }
function _createForOfIteratorHelper(r, e) { var t = "undefined" != typeof Symbol && r[Symbol.iterator] || r["@@iterator"]; if (!t) { if (Array.isArray(r) || (t = _unsupportedIterableToArray(r)) || e && r && "number" == typeof r.length) { t && (r = t); var _n = 0, F = function F() {}; return { s: F, n: function n() { return _n >= r.length ? { done: !0 } : { done: !1, value: r[_n++] }; }, e: function e(r) { throw r; }, f: F }; } throw new TypeError("Invalid attempt to iterate non-iterable instance.\nIn order to be iterable, non-array objects must have a [Symbol.iterator]() method."); } var o, a = !0, u = !1; return { s: function s() { t = t.call(r); }, n: function n() { var r = t.next(); return a = r.done, r; }, e: function e(r) { u = !0, o = r; }, f: function f() { try { a || null == t.return || t.return(); } finally { if (u) throw o; } } }; }
function _unsupportedIterableToArray(r, a) { if (r) { if ("string" == typeof r) return _arrayLikeToArray(r, a); var t = {}.toString.call(r).slice(8, -1); return "Object" === t && r.constructor && (t = r.constructor.name), "Map" === t || "Set" === t ? Array.from(r) : "Arguments" === t || /^(?:Ui|I)nt(?:8|16|32)(?:Clamped)?Array$/.test(t) ? _arrayLikeToArray(r, a) : void 0; } }
function _arrayLikeToArray(r, a) { (null == a || a > r.length) && (a = r.length); for (var e = 0, n = Array(a); e < a; e++) n[e] = r[e]; return n; }
function _classCallCheck(a, n) { if (!(a instanceof n)) throw new TypeError("Cannot call a class as a function"); }
function _defineProperties(e, r) { for (var t = 0; t < r.length; t++) { var o = r[t]; o.enumerable = o.enumerable || !1, o.configurable = !0, "value" in o && (o.writable = !0), Object.defineProperty(e, _toPropertyKey(o.key), o); } }
function _createClass(e, r, t) { return r && _defineProperties(e.prototype, r), t && _defineProperties(e, t), Object.defineProperty(e, "prototype", { writable: !1 }), e; }
function _toPropertyKey(t) { var i = _toPrimitive(t, "string"); return "symbol" == _typeof(i) ? i : i + ""; }
function _toPrimitive(t, r) { if ("object" != _typeof(t) || !t) return t; var e = t[Symbol.toPrimitive]; if (void 0 !== e) { var i = e.call(t, r || "default"); if ("object" != _typeof(i)) return i; throw new TypeError("@@toPrimitive must return a primitive value."); } return ("string" === r ? String : Number)(t); }
// Bundled from chrono-node@2.9.0 (MIT). See third_party/chrono-node/LICENSE.txt.
(function () {
  var __getOwnPropNames = Object.getOwnPropertyNames;
  var __commonJS = function __commonJS(cb, mod) {
    return function __require() {
      return mod || (0, cb[__getOwnPropNames(cb)[0]])((mod = {
        exports: {}
      }).exports, mod), mod.exports;
    };
  };

  // ../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/types.js
  var require_types = __commonJS({
    "../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/types.js": function _____tmp_codexChronoBuild_node_modules_chronoNode_dist_cjs_typesJs(exports) {
      "use strict";

      Object.defineProperty(exports, "__esModule", {
        value: true
      });
      exports.Month = exports.Weekday = exports.Meridiem = void 0;
      var Meridiem;
      (function (Meridiem2) {
        Meridiem2[Meridiem2["AM"] = 0] = "AM";
        Meridiem2[Meridiem2["PM"] = 1] = "PM";
      })(Meridiem || (exports.Meridiem = Meridiem = {}));
      var Weekday;
      (function (Weekday2) {
        Weekday2[Weekday2["SUNDAY"] = 0] = "SUNDAY";
        Weekday2[Weekday2["MONDAY"] = 1] = "MONDAY";
        Weekday2[Weekday2["TUESDAY"] = 2] = "TUESDAY";
        Weekday2[Weekday2["WEDNESDAY"] = 3] = "WEDNESDAY";
        Weekday2[Weekday2["THURSDAY"] = 4] = "THURSDAY";
        Weekday2[Weekday2["FRIDAY"] = 5] = "FRIDAY";
        Weekday2[Weekday2["SATURDAY"] = 6] = "SATURDAY";
      })(Weekday || (exports.Weekday = Weekday = {}));
      var Month;
      (function (Month2) {
        Month2[Month2["JANUARY"] = 1] = "JANUARY";
        Month2[Month2["FEBRUARY"] = 2] = "FEBRUARY";
        Month2[Month2["MARCH"] = 3] = "MARCH";
        Month2[Month2["APRIL"] = 4] = "APRIL";
        Month2[Month2["MAY"] = 5] = "MAY";
        Month2[Month2["JUNE"] = 6] = "JUNE";
        Month2[Month2["JULY"] = 7] = "JULY";
        Month2[Month2["AUGUST"] = 8] = "AUGUST";
        Month2[Month2["SEPTEMBER"] = 9] = "SEPTEMBER";
        Month2[Month2["OCTOBER"] = 10] = "OCTOBER";
        Month2[Month2["NOVEMBER"] = 11] = "NOVEMBER";
        Month2[Month2["DECEMBER"] = 12] = "DECEMBER";
      })(Month || (exports.Month = Month = {}));
    }
  });

  // ../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/utils/dates.js
  var require_dates = __commonJS({
    "../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/utils/dates.js": function _____tmp_codexChronoBuild_node_modules_chronoNode_dist_cjs_utils_datesJs(exports) {
      "use strict";

      Object.defineProperty(exports, "__esModule", {
        value: true
      });
      exports.assignSimilarDate = assignSimilarDate;
      exports.assignSimilarTime = assignSimilarTime;
      exports.implySimilarDate = implySimilarDate;
      exports.implySimilarTime = implySimilarTime;
      var types_1 = require_types();
      function assignSimilarDate(component, target) {
        component.assign("day", target.getDate());
        component.assign("month", target.getMonth() + 1);
        component.assign("year", target.getFullYear());
      }
      function assignSimilarTime(component, target) {
        component.assign("hour", target.getHours());
        component.assign("minute", target.getMinutes());
        component.assign("second", target.getSeconds());
        component.assign("millisecond", target.getMilliseconds());
        component.assign("meridiem", target.getHours() < 12 ? types_1.Meridiem.AM : types_1.Meridiem.PM);
      }
      function implySimilarDate(component, target) {
        component.imply("day", target.getDate());
        component.imply("month", target.getMonth() + 1);
        component.imply("year", target.getFullYear());
      }
      function implySimilarTime(component, target) {
        component.imply("hour", target.getHours());
        component.imply("minute", target.getMinutes());
        component.imply("second", target.getSeconds());
        component.imply("millisecond", target.getMilliseconds());
        component.imply("meridiem", target.getHours() < 12 ? types_1.Meridiem.AM : types_1.Meridiem.PM);
      }
    }
  });

  // ../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/timezone.js
  var require_timezone = __commonJS({
    "../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/timezone.js": function _____tmp_codexChronoBuild_node_modules_chronoNode_dist_cjs_timezoneJs(exports) {
      "use strict";

      Object.defineProperty(exports, "__esModule", {
        value: true
      });
      exports.TIMEZONE_ABBR_MAP = void 0;
      exports.getNthWeekdayOfMonth = getNthWeekdayOfMonth;
      exports.getLastWeekdayOfMonth = getLastWeekdayOfMonth;
      exports.toTimezoneOffset = toTimezoneOffset;
      var types_1 = require_types();
      exports.TIMEZONE_ABBR_MAP = {
        ACDT: 630,
        ACST: 570,
        ADT: -180,
        AEDT: 660,
        AEST: 600,
        AFT: 270,
        AKDT: -480,
        AKST: -540,
        ALMT: 360,
        AMST: -180,
        AMT: -240,
        ANAST: 720,
        ANAT: 720,
        AQTT: 300,
        ART: -180,
        AST: -240,
        AWDT: 540,
        AWST: 480,
        AZOST: 0,
        AZOT: -60,
        AZST: 300,
        AZT: 240,
        BNT: 480,
        BOT: -240,
        BRST: -120,
        BRT: -180,
        BST: 60,
        BTT: 360,
        CAST: 480,
        CAT: 120,
        CCT: 390,
        CDT: -300,
        CEST: 120,
        CET: {
          timezoneOffsetDuringDst: 2 * 60,
          timezoneOffsetNonDst: 60,
          dstStart: function dstStart(year) {
            return getLastWeekdayOfMonth(year, types_1.Month.MARCH, types_1.Weekday.SUNDAY, 2);
          },
          dstEnd: function dstEnd(year) {
            return getLastWeekdayOfMonth(year, types_1.Month.OCTOBER, types_1.Weekday.SUNDAY, 3);
          }
        },
        CHADT: 825,
        CHAST: 765,
        CKT: -600,
        CLST: -180,
        CLT: -240,
        COT: -300,
        CST: -360,
        CT: {
          timezoneOffsetDuringDst: -5 * 60,
          timezoneOffsetNonDst: -6 * 60,
          dstStart: function dstStart(year) {
            return getNthWeekdayOfMonth(year, types_1.Month.MARCH, types_1.Weekday.SUNDAY, 2, 2);
          },
          dstEnd: function dstEnd(year) {
            return getNthWeekdayOfMonth(year, types_1.Month.NOVEMBER, types_1.Weekday.SUNDAY, 1, 2);
          }
        },
        CVT: -60,
        CXT: 420,
        ChST: 600,
        DAVT: 420,
        EASST: -300,
        EAST: -360,
        EAT: 180,
        ECT: -300,
        EDT: -240,
        EEST: 180,
        EET: 120,
        EGST: 0,
        EGT: -60,
        EST: -300,
        ET: {
          timezoneOffsetDuringDst: -4 * 60,
          timezoneOffsetNonDst: -5 * 60,
          dstStart: function dstStart(year) {
            return getNthWeekdayOfMonth(year, types_1.Month.MARCH, types_1.Weekday.SUNDAY, 2, 2);
          },
          dstEnd: function dstEnd(year) {
            return getNthWeekdayOfMonth(year, types_1.Month.NOVEMBER, types_1.Weekday.SUNDAY, 1, 2);
          }
        },
        FJST: 780,
        FJT: 720,
        FKST: -180,
        FKT: -240,
        FNT: -120,
        GALT: -360,
        GAMT: -540,
        GET: 240,
        GFT: -180,
        GILT: 720,
        GMT: 0,
        GST: 240,
        GYT: -240,
        HAA: -180,
        HAC: -300,
        HADT: -540,
        HAE: -240,
        HAP: -420,
        HAR: -360,
        HAST: -600,
        HAT: -90,
        HAY: -480,
        HKT: 480,
        HLV: -210,
        HNA: -240,
        HNC: -360,
        HNE: -300,
        HNP: -480,
        HNR: -420,
        HNT: -150,
        HNY: -540,
        HOVT: 420,
        ICT: 420,
        IDT: 180,
        IOT: 360,
        IRDT: 270,
        IRKST: 540,
        IRKT: 540,
        IRST: 210,
        IST: 330,
        JST: 540,
        KGT: 360,
        KRAST: 480,
        KRAT: 480,
        KST: 540,
        KUYT: 240,
        LHDT: 660,
        LHST: 630,
        LINT: 840,
        MAGST: 720,
        MAGT: 720,
        MART: -510,
        MAWT: 300,
        MDT: -360,
        MESZ: 120,
        MEZ: 60,
        MHT: 720,
        MMT: 390,
        MSD: 240,
        MSK: 180,
        MST: -420,
        MT: {
          timezoneOffsetDuringDst: -6 * 60,
          timezoneOffsetNonDst: -7 * 60,
          dstStart: function dstStart(year) {
            return getNthWeekdayOfMonth(year, types_1.Month.MARCH, types_1.Weekday.SUNDAY, 2, 2);
          },
          dstEnd: function dstEnd(year) {
            return getNthWeekdayOfMonth(year, types_1.Month.NOVEMBER, types_1.Weekday.SUNDAY, 1, 2);
          }
        },
        MUT: 240,
        MVT: 300,
        MYT: 480,
        NCT: 660,
        NDT: -90,
        NFT: 690,
        NOVST: 420,
        NOVT: 360,
        NPT: 345,
        NST: -150,
        NUT: -660,
        NZDT: 780,
        NZST: 720,
        OMSST: 420,
        OMST: 420,
        PDT: -420,
        PET: -300,
        PETST: 720,
        PETT: 720,
        PGT: 600,
        PHOT: 780,
        PHT: 480,
        PKT: 300,
        PMDT: -120,
        PMST: -180,
        PONT: 660,
        PST: -480,
        PT: {
          timezoneOffsetDuringDst: -7 * 60,
          timezoneOffsetNonDst: -8 * 60,
          dstStart: function dstStart(year) {
            return getNthWeekdayOfMonth(year, types_1.Month.MARCH, types_1.Weekday.SUNDAY, 2, 2);
          },
          dstEnd: function dstEnd(year) {
            return getNthWeekdayOfMonth(year, types_1.Month.NOVEMBER, types_1.Weekday.SUNDAY, 1, 2);
          }
        },
        PWT: 540,
        PYST: -180,
        PYT: -240,
        RET: 240,
        SAMT: 240,
        SAST: 120,
        SBT: 660,
        SCT: 240,
        SGT: 480,
        SRT: -180,
        SST: -660,
        TAHT: -600,
        TFT: 300,
        TJT: 300,
        TKT: 780,
        TLT: 540,
        TMT: 300,
        TVT: 720,
        ULAT: 480,
        UTC: 0,
        UYST: -120,
        UYT: -180,
        UZT: 300,
        VET: -210,
        VLAST: 660,
        VLAT: 660,
        VUT: 660,
        WAST: 120,
        WAT: 60,
        WEST: 60,
        WESZ: 60,
        WET: 0,
        WEZ: 0,
        WFT: 720,
        WGST: -120,
        WGT: -180,
        WIB: 420,
        WIT: 540,
        WITA: 480,
        WST: 780,
        WT: 0,
        YAKST: 600,
        YAKT: 600,
        YAPT: 600,
        YEKST: 360,
        YEKT: 360
      };
      function getNthWeekdayOfMonth(year, month, weekday, n) {
        var hour = arguments.length > 4 && arguments[4] !== undefined ? arguments[4] : 0;
        var dayOfMonth = 0;
        var i = 0;
        while (i < n) {
          dayOfMonth++;
          var date = new Date(year, month - 1, dayOfMonth);
          if (date.getDay() === weekday) i++;
        }
        return new Date(year, month - 1, dayOfMonth, hour);
      }
      function getLastWeekdayOfMonth(year, month, weekday) {
        var hour = arguments.length > 3 && arguments[3] !== undefined ? arguments[3] : 0;
        var oneIndexedWeekday = weekday === 0 ? 7 : weekday;
        var date = new Date(year, month - 1 + 1, 1, 12);
        var firstWeekdayNextMonth = date.getDay() === 0 ? 7 : date.getDay();
        var dayDiff;
        if (firstWeekdayNextMonth === oneIndexedWeekday) dayDiff = 7;else if (firstWeekdayNextMonth < oneIndexedWeekday) dayDiff = 7 + firstWeekdayNextMonth - oneIndexedWeekday;else dayDiff = firstWeekdayNextMonth - oneIndexedWeekday;
        date.setDate(date.getDate() - dayDiff);
        return new Date(year, month - 1, date.getDate(), hour);
      }
      function toTimezoneOffset(timezoneInput, date) {
        var timezoneOverrides = arguments.length > 2 && arguments[2] !== undefined ? arguments[2] : {};
        var _a;
        if (timezoneInput == null) {
          return null;
        }
        if (typeof timezoneInput === "number") {
          return timezoneInput;
        }
        var matchedTimezone = (_a = timezoneOverrides[timezoneInput]) !== null && _a !== void 0 ? _a : exports.TIMEZONE_ABBR_MAP[timezoneInput];
        if (matchedTimezone == null) {
          return null;
        }
        if (typeof matchedTimezone == "number") {
          return matchedTimezone;
        }
        if (date == null) {
          return null;
        }
        if (date > matchedTimezone.dstStart(date.getFullYear()) && !(date > matchedTimezone.dstEnd(date.getFullYear()))) {
          return matchedTimezone.timezoneOffsetDuringDst;
        }
        return matchedTimezone.timezoneOffsetNonDst;
      }
    }
  });

  // ../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/calculation/duration.js
  var require_duration = __commonJS({
    "../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/calculation/duration.js": function _____tmp_codexChronoBuild_node_modules_chronoNode_dist_cjs_calculation_durationJs(exports) {
      "use strict";

      Object.defineProperty(exports, "__esModule", {
        value: true
      });
      exports.EmptyDuration = void 0;
      exports.addDuration = addDuration;
      exports.reverseDuration = reverseDuration;
      exports.EmptyDuration = {
        day: 0,
        second: 0,
        millisecond: 0
      };
      function addDuration(ref, duration) {
        var _a, _b, _c, _d, _e, _f, _g;
        var date = new Date(ref);
        if (duration["y"]) {
          duration["year"] = duration["y"];
          delete duration["y"];
        }
        if (duration["mo"]) {
          duration["month"] = duration["mo"];
          delete duration["mo"];
        }
        if (duration["M"]) {
          duration["month"] = duration["M"];
          delete duration["M"];
        }
        if (duration["w"]) {
          duration["week"] = duration["w"];
          delete duration["w"];
        }
        if (duration["d"]) {
          duration["day"] = duration["d"];
          delete duration["d"];
        }
        if (duration["h"]) {
          duration["hour"] = duration["h"];
          delete duration["h"];
        }
        if (duration["m"]) {
          duration["minute"] = duration["m"];
          delete duration["m"];
        }
        if (duration["s"]) {
          duration["second"] = duration["s"];
          delete duration["s"];
        }
        if (duration["ms"]) {
          duration["millisecond"] = duration["ms"];
          delete duration["ms"];
        }
        if ("year" in duration) {
          var floor = Math.floor(duration["year"]);
          date.setFullYear(date.getFullYear() + floor);
          var remainingFraction = duration["year"] - floor;
          if (remainingFraction > 0) {
            duration.month = (_a = duration === null || duration === void 0 ? void 0 : duration.month) !== null && _a !== void 0 ? _a : 0;
            duration.month += remainingFraction * 12;
          }
        }
        if ("quarter" in duration) {
          var _floor = Math.floor(duration["quarter"]);
          date.setMonth(date.getMonth() + _floor * 3);
        }
        if ("month" in duration) {
          var _floor2 = Math.floor(duration["month"]);
          date.setMonth(date.getMonth() + _floor2);
          var _remainingFraction = duration["month"] - _floor2;
          if (_remainingFraction > 0) {
            duration.week = (_b = duration === null || duration === void 0 ? void 0 : duration.week) !== null && _b !== void 0 ? _b : 0;
            duration.week += _remainingFraction * 4;
          }
        }
        if ("week" in duration) {
          var _floor3 = Math.floor(duration["week"]);
          date.setDate(date.getDate() + _floor3 * 7);
          var _remainingFraction2 = duration["week"] - _floor3;
          if (_remainingFraction2 > 0) {
            duration.day = (_c = duration === null || duration === void 0 ? void 0 : duration.day) !== null && _c !== void 0 ? _c : 0;
            duration.day += Math.round(_remainingFraction2 * 7);
          }
        }
        if ("day" in duration) {
          var _floor4 = Math.floor(duration["day"]);
          date.setDate(date.getDate() + _floor4);
          var _remainingFraction3 = duration["day"] - _floor4;
          if (_remainingFraction3 > 0) {
            duration.hour = (_d = duration === null || duration === void 0 ? void 0 : duration.hour) !== null && _d !== void 0 ? _d : 0;
            duration.hour += Math.round(_remainingFraction3 * 24);
          }
        }
        if ("hour" in duration) {
          var _floor5 = Math.floor(duration["hour"]);
          date.setHours(date.getHours() + _floor5);
          var _remainingFraction4 = duration["hour"] - _floor5;
          if (_remainingFraction4 > 0) {
            duration.minute = (_e = duration === null || duration === void 0 ? void 0 : duration.minute) !== null && _e !== void 0 ? _e : 0;
            duration.minute += Math.round(_remainingFraction4 * 60);
          }
        }
        if ("minute" in duration) {
          var _floor6 = Math.floor(duration["minute"]);
          date.setMinutes(date.getMinutes() + _floor6);
          var _remainingFraction5 = duration["minute"] - _floor6;
          if (_remainingFraction5 > 0) {
            duration.second = (_f = duration === null || duration === void 0 ? void 0 : duration.second) !== null && _f !== void 0 ? _f : 0;
            duration.second += Math.round(_remainingFraction5 * 60);
          }
        }
        if ("second" in duration) {
          var _floor7 = Math.floor(duration["second"]);
          date.setSeconds(date.getSeconds() + _floor7);
          var _remainingFraction6 = duration["second"] - _floor7;
          if (_remainingFraction6 > 0) {
            duration.millisecond = (_g = duration === null || duration === void 0 ? void 0 : duration.millisecond) !== null && _g !== void 0 ? _g : 0;
            duration.millisecond += Math.round(_remainingFraction6 * 1e3);
          }
        }
        if ("millisecond" in duration) {
          var _floor8 = Math.floor(duration["millisecond"]);
          date.setMilliseconds(date.getMilliseconds() + _floor8);
        }
        return date;
      }
      function reverseDuration(duration) {
        var reversed = {};
        for (var key in duration) {
          reversed[key] = -duration[key];
        }
        return reversed;
      }
    }
  });

  // ../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/results.js
  var require_results = __commonJS({
    "../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/results.js": function _____tmp_codexChronoBuild_node_modules_chronoNode_dist_cjs_resultsJs(exports) {
      "use strict";

      Object.defineProperty(exports, "__esModule", {
        value: true
      });
      exports.ParsingResult = exports.ParsingComponents = exports.ReferenceWithTimezone = void 0;
      var dates_1 = require_dates();
      var timezone_1 = require_timezone();
      var duration_1 = require_duration();
      var ReferenceWithTimezone = /*#__PURE__*/function () {
        function _ReferenceWithTimezone(instant, timezoneOffset) {
          _classCallCheck(this, _ReferenceWithTimezone);
          this.instant = instant !== null && instant !== void 0 ? instant : /* @__PURE__ */new Date();
          this.timezoneOffset = timezoneOffset !== null && timezoneOffset !== void 0 ? timezoneOffset : null;
        }
        return _createClass(_ReferenceWithTimezone, [{
          key: "getDateWithAdjustedTimezone",
          value: function getDateWithAdjustedTimezone() {
            var date = new Date(this.instant);
            if (this.timezoneOffset !== null) {
              date.setMinutes(date.getMinutes() - this.getSystemTimezoneAdjustmentMinute(this.instant));
            }
            return date;
          }
        }, {
          key: "getSystemTimezoneAdjustmentMinute",
          value: function getSystemTimezoneAdjustmentMinute(date, overrideTimezoneOffset) {
            var _a;
            if (!date || date.getTime() < 0) {
              date = /* @__PURE__ */new Date();
            }
            var currentTimezoneOffset = -date.getTimezoneOffset();
            var targetTimezoneOffset = (_a = overrideTimezoneOffset !== null && overrideTimezoneOffset !== void 0 ? overrideTimezoneOffset : this.timezoneOffset) !== null && _a !== void 0 ? _a : currentTimezoneOffset;
            return currentTimezoneOffset - targetTimezoneOffset;
          }
        }, {
          key: "getTimezoneOffset",
          value: function getTimezoneOffset() {
            var _a;
            return (_a = this.timezoneOffset) !== null && _a !== void 0 ? _a : -this.instant.getTimezoneOffset();
          }
        }], [{
          key: "fromDate",
          value: function fromDate(date) {
            return new _ReferenceWithTimezone(date);
          }
        }, {
          key: "fromInput",
          value: function fromInput(input, timezoneOverrides) {
            var _a;
            if (input instanceof Date) {
              return _ReferenceWithTimezone.fromDate(input);
            }
            var instant = (_a = input === null || input === void 0 ? void 0 : input.instant) !== null && _a !== void 0 ? _a : /* @__PURE__ */new Date();
            var timezoneOffset = (0, timezone_1.toTimezoneOffset)(input === null || input === void 0 ? void 0 : input.timezone, instant, timezoneOverrides);
            return new _ReferenceWithTimezone(instant, timezoneOffset);
          }
        }]);
      }();
      exports.ReferenceWithTimezone = ReferenceWithTimezone;
      var ParsingComponents = /*#__PURE__*/function () {
        function _ParsingComponents(reference, knownComponents) {
          _classCallCheck(this, _ParsingComponents);
          this._tags = /* @__PURE__ */new Set();
          this.reference = reference;
          this.knownValues = {};
          this.impliedValues = {};
          if (knownComponents) {
            for (var key in knownComponents) {
              this.knownValues[key] = knownComponents[key];
            }
          }
          var date = reference.getDateWithAdjustedTimezone();
          this.imply("day", date.getDate());
          this.imply("month", date.getMonth() + 1);
          this.imply("year", date.getFullYear());
          this.imply("hour", 12);
          this.imply("minute", 0);
          this.imply("second", 0);
          this.imply("millisecond", 0);
        }
        return _createClass(_ParsingComponents, [{
          key: "get",
          value: function get(component) {
            if (component in this.knownValues) {
              return this.knownValues[component];
            }
            if (component in this.impliedValues) {
              return this.impliedValues[component];
            }
            return null;
          }
        }, {
          key: "isCertain",
          value: function isCertain(component) {
            return component in this.knownValues;
          }
        }, {
          key: "getCertainComponents",
          value: function getCertainComponents() {
            return Object.keys(this.knownValues);
          }
        }, {
          key: "imply",
          value: function imply(component, value) {
            if (component in this.knownValues) {
              return this;
            }
            this.impliedValues[component] = value;
            return this;
          }
        }, {
          key: "assign",
          value: function assign(component, value) {
            this.knownValues[component] = value;
            delete this.impliedValues[component];
            return this;
          }
        }, {
          key: "addDurationAsImplied",
          value: function addDurationAsImplied(duration) {
            var currentDate = this.dateWithoutTimezoneAdjustment();
            var date = (0, duration_1.addDuration)(currentDate, duration);
            if ("day" in duration || "week" in duration || "month" in duration || "year" in duration) {
              this.delete(["day", "weekday", "month", "year"]);
              this.imply("day", date.getDate());
              this.imply("weekday", date.getDay());
              this.imply("month", date.getMonth() + 1);
              this.imply("year", date.getFullYear());
            }
            if ("second" in duration || "minute" in duration || "hour" in duration) {
              this.delete(["second", "minute", "hour"]);
              this.imply("second", date.getSeconds());
              this.imply("minute", date.getMinutes());
              this.imply("hour", date.getHours());
            }
            return this;
          }
        }, {
          key: "delete",
          value: function _delete(components) {
            if (typeof components === "string") {
              components = [components];
            }
            var _iterator = _createForOfIteratorHelper(components),
              _step;
            try {
              for (_iterator.s(); !(_step = _iterator.n()).done;) {
                var component = _step.value;
                delete this.knownValues[component];
                delete this.impliedValues[component];
              }
            } catch (err) {
              _iterator.e(err);
            } finally {
              _iterator.f();
            }
          }
        }, {
          key: "clone",
          value: function clone() {
            var component = new _ParsingComponents(this.reference);
            component.knownValues = {};
            component.impliedValues = {};
            for (var key in this.knownValues) {
              component.knownValues[key] = this.knownValues[key];
            }
            for (var _key2 in this.impliedValues) {
              component.impliedValues[_key2] = this.impliedValues[_key2];
            }
            return component;
          }
        }, {
          key: "isOnlyDate",
          value: function isOnlyDate() {
            return !this.isCertain("hour") && !this.isCertain("minute") && !this.isCertain("second");
          }
        }, {
          key: "isOnlyTime",
          value: function isOnlyTime() {
            return !this.isCertain("weekday") && !this.isCertain("day") && !this.isCertain("month") && !this.isCertain("year");
          }
        }, {
          key: "isOnlyWeekdayComponent",
          value: function isOnlyWeekdayComponent() {
            return this.isCertain("weekday") && !this.isCertain("day") && !this.isCertain("month");
          }
        }, {
          key: "isDateWithUnknownYear",
          value: function isDateWithUnknownYear() {
            return this.isCertain("month") && !this.isCertain("year");
          }
        }, {
          key: "isValidDate",
          value: function isValidDate() {
            var date = this.dateWithoutTimezoneAdjustment();
            if (date.getFullYear() !== this.get("year")) return false;
            if (date.getMonth() !== this.get("month") - 1) return false;
            if (date.getDate() !== this.get("day")) return false;
            if (this.get("hour") != null && date.getHours() != this.get("hour")) return false;
            if (this.get("minute") != null && date.getMinutes() != this.get("minute")) return false;
            return true;
          }
        }, {
          key: "toString",
          value: function toString() {
            return "[ParsingComponents {\n            tags: ".concat(JSON.stringify(Array.from(this._tags).sort()), ", \n            knownValues: ").concat(JSON.stringify(this.knownValues), ", \n            impliedValues: ").concat(JSON.stringify(this.impliedValues), "}, \n            reference: ").concat(JSON.stringify(this.reference), "]");
          }
        }, {
          key: "date",
          value: function date() {
            var date = this.dateWithoutTimezoneAdjustment();
            var timezoneAdjustment = this.reference.getSystemTimezoneAdjustmentMinute(date, this.get("timezoneOffset"));
            return new Date(date.getTime() + timezoneAdjustment * 6e4);
          }
        }, {
          key: "addTag",
          value: function addTag(tag) {
            this._tags.add(tag);
            return this;
          }
        }, {
          key: "addTags",
          value: function addTags(tags) {
            var _iterator2 = _createForOfIteratorHelper(tags),
              _step2;
            try {
              for (_iterator2.s(); !(_step2 = _iterator2.n()).done;) {
                var tag = _step2.value;
                this._tags.add(tag);
              }
            } catch (err) {
              _iterator2.e(err);
            } finally {
              _iterator2.f();
            }
            return this;
          }
        }, {
          key: "tags",
          value: function tags() {
            return new Set(this._tags);
          }
        }, {
          key: "dateWithoutTimezoneAdjustment",
          value: function dateWithoutTimezoneAdjustment() {
            var date = new Date(this.get("year"), this.get("month") - 1, this.get("day"), this.get("hour"), this.get("minute"), this.get("second"), this.get("millisecond"));
            date.setFullYear(this.get("year"));
            return date;
          }
        }], [{
          key: "createRelativeFromReference",
          value: function createRelativeFromReference(reference) {
            var duration = arguments.length > 1 && arguments[1] !== undefined ? arguments[1] : duration_1.EmptyDuration;
            var date = (0, duration_1.addDuration)(reference.getDateWithAdjustedTimezone(), duration);
            var components = new _ParsingComponents(reference);
            components.addTag("result/relativeDate");
            if ("hour" in duration || "minute" in duration || "second" in duration || "millisecond" in duration) {
              components.addTag("result/relativeDateAndTime");
              (0, dates_1.assignSimilarTime)(components, date);
              (0, dates_1.assignSimilarDate)(components, date);
              components.assign("timezoneOffset", reference.getTimezoneOffset());
            } else {
              (0, dates_1.implySimilarTime)(components, date);
              components.imply("timezoneOffset", reference.getTimezoneOffset());
              if ("day" in duration) {
                components.assign("day", date.getDate());
                components.assign("month", date.getMonth() + 1);
                components.assign("year", date.getFullYear());
                components.assign("weekday", date.getDay());
              } else if ("week" in duration) {
                components.assign("day", date.getDate());
                components.assign("month", date.getMonth() + 1);
                components.assign("year", date.getFullYear());
                components.imply("weekday", date.getDay());
              } else {
                components.imply("day", date.getDate());
                if ("month" in duration) {
                  components.assign("month", date.getMonth() + 1);
                  components.assign("year", date.getFullYear());
                } else {
                  components.imply("month", date.getMonth() + 1);
                  if ("year" in duration) {
                    components.assign("year", date.getFullYear());
                  } else {
                    components.imply("year", date.getFullYear());
                  }
                }
              }
            }
            return components;
          }
        }]);
      }();
      exports.ParsingComponents = ParsingComponents;
      var ParsingResult = /*#__PURE__*/function () {
        function _ParsingResult(reference, index, text, start, end) {
          _classCallCheck(this, _ParsingResult);
          this.reference = reference;
          this.refDate = reference.instant;
          this.index = index;
          this.text = text;
          this.start = start || new ParsingComponents(reference);
          this.end = end;
        }
        return _createClass(_ParsingResult, [{
          key: "clone",
          value: function clone() {
            var result = new _ParsingResult(this.reference, this.index, this.text);
            result.start = this.start ? this.start.clone() : null;
            result.end = this.end ? this.end.clone() : null;
            return result;
          }
        }, {
          key: "date",
          value: function date() {
            return this.start.date();
          }
        }, {
          key: "addTag",
          value: function addTag(tag) {
            this.start.addTag(tag);
            if (this.end) {
              this.end.addTag(tag);
            }
            return this;
          }
        }, {
          key: "addTags",
          value: function addTags(tags) {
            this.start.addTags(tags);
            if (this.end) {
              this.end.addTags(tags);
            }
            return this;
          }
        }, {
          key: "tags",
          value: function tags() {
            var combinedTags = new Set(this.start.tags());
            if (this.end) {
              var _iterator3 = _createForOfIteratorHelper(this.end.tags()),
                _step3;
              try {
                for (_iterator3.s(); !(_step3 = _iterator3.n()).done;) {
                  var tag = _step3.value;
                  combinedTags.add(tag);
                }
              } catch (err) {
                _iterator3.e(err);
              } finally {
                _iterator3.f();
              }
            }
            return combinedTags;
          }
        }, {
          key: "toString",
          value: function toString() {
            var tags = Array.from(this.tags()).sort();
            return "[ParsingResult {index: ".concat(this.index, ", text: '").concat(this.text, "', tags: ").concat(JSON.stringify(tags), " ...}]");
          }
        }]);
      }();
      exports.ParsingResult = ParsingResult;
    }
  });

  // ../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/utils/pattern.js
  var require_pattern = __commonJS({
    "../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/utils/pattern.js": function _____tmp_codexChronoBuild_node_modules_chronoNode_dist_cjs_utils_patternJs(exports) {
      "use strict";

      Object.defineProperty(exports, "__esModule", {
        value: true
      });
      exports.repeatedTimeunitPattern = repeatedTimeunitPattern;
      exports.extractTerms = extractTerms;
      exports.matchAnyPattern = matchAnyPattern;
      function repeatedTimeunitPattern(prefix, singleTimeunitPattern) {
        var connectorPattern = arguments.length > 2 && arguments[2] !== undefined ? arguments[2] : "\\s{0,5},?\\s{0,5}";
        var singleTimeunitPatternNoCapture = singleTimeunitPattern.replace(/\((?!\?)/g, "(?:");
        return "".concat(prefix).concat(singleTimeunitPatternNoCapture, "(?:").concat(connectorPattern).concat(singleTimeunitPatternNoCapture, "){0,10}");
      }
      function extractTerms(dictionary) {
        var keys;
        if (dictionary instanceof Array) {
          keys = _toConsumableArray(dictionary);
        } else if (dictionary instanceof Map) {
          keys = Array.from(dictionary.keys());
        } else {
          keys = Object.keys(dictionary);
        }
        return keys;
      }
      function matchAnyPattern(dictionary) {
        var joinedTerms = extractTerms(dictionary).sort(function (a, b) {
          return b.length - a.length;
        }).join("|").replace(/\./g, "\\.");
        return "(?:".concat(joinedTerms, ")");
      }
    }
  });

  // ../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/calculation/years.js
  var require_years = __commonJS({
    "../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/calculation/years.js": function _____tmp_codexChronoBuild_node_modules_chronoNode_dist_cjs_calculation_yearsJs(exports) {
      "use strict";

      Object.defineProperty(exports, "__esModule", {
        value: true
      });
      exports.findMostLikelyADYear = findMostLikelyADYear;
      exports.findYearClosestToRef = findYearClosestToRef;
      var duration_1 = require_duration();
      function findMostLikelyADYear(yearNumber) {
        if (yearNumber < 100) {
          if (yearNumber > 50) {
            yearNumber = yearNumber + 1900;
          } else {
            yearNumber = yearNumber + 2e3;
          }
        }
        return yearNumber;
      }
      function findYearClosestToRef(refDate, day, month) {
        var date = new Date(refDate);
        date.setMonth(month - 1);
        date.setDate(day);
        var nextYear = (0, duration_1.addDuration)(date, {
          "year": 1
        });
        var lastYear = (0, duration_1.addDuration)(date, {
          "year": -1
        });
        if (Math.abs(nextYear.getTime() - refDate.getTime()) < Math.abs(date.getTime() - refDate.getTime())) {
          date = nextYear;
        } else if (Math.abs(lastYear.getTime() - refDate.getTime()) < Math.abs(date.getTime() - refDate.getTime())) {
          date = lastYear;
        }
        return date.getFullYear();
      }
    }
  });

  // ../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/locales/en/constants.js
  var require_constants = __commonJS({
    "../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/locales/en/constants.js": function _____tmp_codexChronoBuild_node_modules_chronoNode_dist_cjs_locales_en_constantsJs(exports) {
      "use strict";

      Object.defineProperty(exports, "__esModule", {
        value: true
      });
      exports.TIME_UNITS_NO_ABBR_PATTERN = exports.TIME_UNITS_PATTERN = exports.YEAR_PATTERN = exports.ORDINAL_NUMBER_PATTERN = exports.NUMBER_PATTERN = exports.TIME_UNIT_DICTIONARY = exports.TIME_UNIT_DICTIONARY_NO_ABBR = exports.ORDINAL_WORD_DICTIONARY = exports.INTEGER_WORD_DICTIONARY = exports.MONTH_DICTIONARY = exports.FULL_MONTH_NAME_DICTIONARY = exports.WEEKDAY_DICTIONARY = void 0;
      exports.parseNumberPattern = parseNumberPattern;
      exports.parseOrdinalNumberPattern = parseOrdinalNumberPattern;
      exports.parseYear = parseYear;
      exports.parseDuration = parseDuration;
      var pattern_1 = require_pattern();
      var years_1 = require_years();
      exports.WEEKDAY_DICTIONARY = {
        sunday: 0,
        sun: 0,
        "sun.": 0,
        monday: 1,
        mon: 1,
        "mon.": 1,
        tuesday: 2,
        tue: 2,
        "tue.": 2,
        wednesday: 3,
        wed: 3,
        "wed.": 3,
        thursday: 4,
        thurs: 4,
        "thurs.": 4,
        thur: 4,
        "thur.": 4,
        thu: 4,
        "thu.": 4,
        friday: 5,
        fri: 5,
        "fri.": 5,
        saturday: 6,
        sat: 6,
        "sat.": 6
      };
      exports.FULL_MONTH_NAME_DICTIONARY = {
        january: 1,
        february: 2,
        march: 3,
        april: 4,
        may: 5,
        june: 6,
        july: 7,
        august: 8,
        september: 9,
        october: 10,
        november: 11,
        december: 12
      };
      exports.MONTH_DICTIONARY = Object.assign(Object.assign({}, exports.FULL_MONTH_NAME_DICTIONARY), {
        jan: 1,
        "jan.": 1,
        feb: 2,
        "feb.": 2,
        mar: 3,
        "mar.": 3,
        apr: 4,
        "apr.": 4,
        jun: 6,
        "jun.": 6,
        jul: 7,
        "jul.": 7,
        aug: 8,
        "aug.": 8,
        sep: 9,
        "sep.": 9,
        sept: 9,
        "sept.": 9,
        oct: 10,
        "oct.": 10,
        nov: 11,
        "nov.": 11,
        dec: 12,
        "dec.": 12
      });
      exports.INTEGER_WORD_DICTIONARY = {
        one: 1,
        two: 2,
        three: 3,
        four: 4,
        five: 5,
        six: 6,
        seven: 7,
        eight: 8,
        nine: 9,
        ten: 10,
        eleven: 11,
        twelve: 12
      };
      exports.ORDINAL_WORD_DICTIONARY = {
        first: 1,
        second: 2,
        third: 3,
        fourth: 4,
        fifth: 5,
        sixth: 6,
        seventh: 7,
        eighth: 8,
        ninth: 9,
        tenth: 10,
        eleventh: 11,
        twelfth: 12,
        thirteenth: 13,
        fourteenth: 14,
        fifteenth: 15,
        sixteenth: 16,
        seventeenth: 17,
        eighteenth: 18,
        nineteenth: 19,
        twentieth: 20,
        "twenty first": 21,
        "twenty-first": 21,
        "twenty second": 22,
        "twenty-second": 22,
        "twenty third": 23,
        "twenty-third": 23,
        "twenty fourth": 24,
        "twenty-fourth": 24,
        "twenty fifth": 25,
        "twenty-fifth": 25,
        "twenty sixth": 26,
        "twenty-sixth": 26,
        "twenty seventh": 27,
        "twenty-seventh": 27,
        "twenty eighth": 28,
        "twenty-eighth": 28,
        "twenty ninth": 29,
        "twenty-ninth": 29,
        "thirtieth": 30,
        "thirty first": 31,
        "thirty-first": 31
      };
      exports.TIME_UNIT_DICTIONARY_NO_ABBR = {
        second: "second",
        seconds: "second",
        minute: "minute",
        minutes: "minute",
        hour: "hour",
        hours: "hour",
        day: "day",
        days: "day",
        week: "week",
        weeks: "week",
        month: "month",
        months: "month",
        quarter: "quarter",
        quarters: "quarter",
        year: "year",
        years: "year"
      };
      exports.TIME_UNIT_DICTIONARY = Object.assign({
        s: "second",
        sec: "second",
        second: "second",
        seconds: "second",
        m: "minute",
        min: "minute",
        mins: "minute",
        minute: "minute",
        minutes: "minute",
        h: "hour",
        hr: "hour",
        hrs: "hour",
        hour: "hour",
        hours: "hour",
        d: "day",
        day: "day",
        days: "day",
        w: "week",
        week: "week",
        weeks: "week",
        mo: "month",
        mon: "month",
        mos: "month",
        month: "month",
        months: "month",
        qtr: "quarter",
        quarter: "quarter",
        quarters: "quarter",
        y: "year",
        yr: "year",
        year: "year",
        years: "year"
      }, exports.TIME_UNIT_DICTIONARY_NO_ABBR);
      exports.NUMBER_PATTERN = "(?:".concat((0, pattern_1.matchAnyPattern)(exports.INTEGER_WORD_DICTIONARY), "|[0-9]+|[0-9]+\\.[0-9]+|half(?:\\s{0,2}an?)?|an?\\b(?:\\s{0,2}few)?|few|several|the|a?\\s{0,2}couple\\s{0,2}(?:of)?)");
      function parseNumberPattern(match) {
        var num = match.toLowerCase();
        if (exports.INTEGER_WORD_DICTIONARY[num] !== void 0) {
          return exports.INTEGER_WORD_DICTIONARY[num];
        } else if (num === "a" || num === "an" || num == "the") {
          return 1;
        } else if (num.match(/few/)) {
          return 3;
        } else if (num.match(/half/)) {
          return 0.5;
        } else if (num.match(/couple/)) {
          return 2;
        } else if (num.match(/several/)) {
          return 7;
        }
        return parseFloat(num);
      }
      exports.ORDINAL_NUMBER_PATTERN = "(?:".concat((0, pattern_1.matchAnyPattern)(exports.ORDINAL_WORD_DICTIONARY), "|[0-9]{1,2}(?:st|nd|rd|th)?)");
      function parseOrdinalNumberPattern(match) {
        var num = match.toLowerCase();
        if (exports.ORDINAL_WORD_DICTIONARY[num] !== void 0) {
          return exports.ORDINAL_WORD_DICTIONARY[num];
        }
        num = num.replace(/(?:st|nd|rd|th)$/i, "");
        return parseInt(num);
      }
      exports.YEAR_PATTERN = "(?:[1-9][0-9]{0,3}\\s{0,2}(?:BE|AD|BC|BCE|CE)|[1-2][0-9]{3}|[5-9][0-9]|2[0-5])";
      function parseYear(match) {
        if (/BE/i.test(match)) {
          match = match.replace(/BE/i, "");
          return parseInt(match) - 543;
        }
        if (/BCE?/i.test(match)) {
          match = match.replace(/BCE?/i, "");
          return -parseInt(match);
        }
        if (/(AD|CE)/i.test(match)) {
          match = match.replace(/(AD|CE)/i, "");
          return parseInt(match);
        }
        var rawYearNumber = parseInt(match);
        return (0, years_1.findMostLikelyADYear)(rawYearNumber);
      }
      var SINGLE_TIME_UNIT_PATTERN = "(".concat(exports.NUMBER_PATTERN, ")\\s{0,3}(").concat((0, pattern_1.matchAnyPattern)(exports.TIME_UNIT_DICTIONARY), ")");
      var SINGLE_TIME_UNIT_REGEX = new RegExp(SINGLE_TIME_UNIT_PATTERN, "i");
      var SINGLE_TIME_UNIT_NO_ABBR_PATTERN = "(".concat(exports.NUMBER_PATTERN, ")\\s{0,3}(").concat((0, pattern_1.matchAnyPattern)(exports.TIME_UNIT_DICTIONARY_NO_ABBR), ")");
      var TIME_UNIT_CONNECTOR_PATTERN = "\\s{0,5},?(?:\\s*and)?\\s{0,5}";
      exports.TIME_UNITS_PATTERN = (0, pattern_1.repeatedTimeunitPattern)("(?:(?:about|around)\\s{0,3})?", SINGLE_TIME_UNIT_PATTERN, TIME_UNIT_CONNECTOR_PATTERN);
      exports.TIME_UNITS_NO_ABBR_PATTERN = (0, pattern_1.repeatedTimeunitPattern)("(?:(?:about|around)\\s{0,3})?", SINGLE_TIME_UNIT_NO_ABBR_PATTERN, TIME_UNIT_CONNECTOR_PATTERN);
      function parseDuration(timeunitText) {
        var fragments = {};
        var remainingText = timeunitText;
        var match = SINGLE_TIME_UNIT_REGEX.exec(remainingText);
        while (match) {
          collectDateTimeFragment(fragments, match);
          remainingText = remainingText.substring(match[0].length).trim();
          match = SINGLE_TIME_UNIT_REGEX.exec(remainingText);
        }
        if (Object.keys(fragments).length == 0) {
          return null;
        }
        return fragments;
      }
      function collectDateTimeFragment(fragments, match) {
        if (match[0].match(/^[a-zA-Z]+$/)) {
          return;
        }
        var num = parseNumberPattern(match[1]);
        var unit = exports.TIME_UNIT_DICTIONARY[match[2].toLowerCase()];
        fragments[unit] = num;
      }
    }
  });

  // ../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/common/parsers/AbstractParserWithWordBoundary.js
  var require_AbstractParserWithWordBoundary = __commonJS({
    "../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/common/parsers/AbstractParserWithWordBoundary.js": function _____tmp_codexChronoBuild_node_modules_chronoNode_dist_cjs_common_parsers_AbstractParserWithWordBoundaryJs(exports) {
      "use strict";

      Object.defineProperty(exports, "__esModule", {
        value: true
      });
      exports.AbstractParserWithWordBoundaryChecking = void 0;
      var AbstractParserWithWordBoundaryChecking = /*#__PURE__*/function () {
        function AbstractParserWithWordBoundaryChecking() {
          _classCallCheck(this, AbstractParserWithWordBoundaryChecking);
          this.cachedInnerPattern = null;
          this.cachedPattern = null;
        }
        return _createClass(AbstractParserWithWordBoundaryChecking, [{
          key: "innerPatternHasChange",
          value: function innerPatternHasChange(context, currentInnerPattern) {
            return this.innerPattern(context) !== currentInnerPattern;
          }
        }, {
          key: "patternLeftBoundary",
          value: function patternLeftBoundary() {
            return "(\\W|^)";
          }
        }, {
          key: "pattern",
          value: function pattern(context) {
            if (this.cachedInnerPattern) {
              if (!this.innerPatternHasChange(context, this.cachedInnerPattern)) {
                return this.cachedPattern;
              }
            }
            this.cachedInnerPattern = this.innerPattern(context);
            this.cachedPattern = new RegExp("".concat(this.patternLeftBoundary()).concat(this.cachedInnerPattern.source), this.cachedInnerPattern.flags);
            return this.cachedPattern;
          }
        }, {
          key: "extract",
          value: function extract(context, match) {
            var _a;
            var header = (_a = match[1]) !== null && _a !== void 0 ? _a : "";
            match.index = match.index + header.length;
            match[0] = match[0].substring(header.length);
            for (var i = 2; i < match.length; i++) {
              match[i - 1] = match[i];
            }
            return this.innerExtract(context, match);
          }
        }]);
      }();
      exports.AbstractParserWithWordBoundaryChecking = AbstractParserWithWordBoundaryChecking;
    }
  });

  // ../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/locales/en/parsers/ENTimeUnitWithinFormatParser.js
  var require_ENTimeUnitWithinFormatParser = __commonJS({
    "../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/locales/en/parsers/ENTimeUnitWithinFormatParser.js": function _____tmp_codexChronoBuild_node_modules_chronoNode_dist_cjs_locales_en_parsers_ENTimeUnitWithinFormatParserJs(exports) {
      "use strict";

      Object.defineProperty(exports, "__esModule", {
        value: true
      });
      var constants_1 = require_constants();
      var results_1 = require_results();
      var AbstractParserWithWordBoundary_1 = require_AbstractParserWithWordBoundary();
      var PATTERN_WITH_OPTIONAL_PREFIX = new RegExp("(?:(?:within|in|for)\\s*)?(?:(?:about|around|roughly|approximately|just)\\s*(?:~\\s*)?)?(".concat(constants_1.TIME_UNITS_PATTERN, ")(?=\\W|$)"), "i");
      var PATTERN_WITH_PREFIX = new RegExp("(?:within|in|for)\\s*(?:(?:about|around|roughly|approximately|just)\\s*(?:~\\s*)?)?(".concat(constants_1.TIME_UNITS_PATTERN, ")(?=\\W|$)"), "i");
      var PATTERN_WITH_PREFIX_STRICT = new RegExp("(?:within|in|for)\\s*(?:(?:about|around|roughly|approximately|just)\\s*(?:~\\s*)?)?(".concat(constants_1.TIME_UNITS_NO_ABBR_PATTERN, ")(?=\\W|$)"), "i");
      var ENTimeUnitWithinFormatParser = /*#__PURE__*/function (_AbstractParserWithWo) {
        function ENTimeUnitWithinFormatParser(strictMode) {
          var _this;
          _classCallCheck(this, ENTimeUnitWithinFormatParser);
          _this = _callSuper(this, ENTimeUnitWithinFormatParser);
          _this.strictMode = strictMode;
          return _this;
        }
        _inherits(ENTimeUnitWithinFormatParser, _AbstractParserWithWo);
        return _createClass(ENTimeUnitWithinFormatParser, [{
          key: "innerPattern",
          value: function innerPattern(context) {
            if (this.strictMode) {
              return PATTERN_WITH_PREFIX_STRICT;
            }
            return context.option.forwardDate ? PATTERN_WITH_OPTIONAL_PREFIX : PATTERN_WITH_PREFIX;
          }
        }, {
          key: "innerExtract",
          value: function innerExtract(context, match) {
            if (match[0].match(/^for\s*the\s*\w+/)) {
              return null;
            }
            var timeUnits = (0, constants_1.parseDuration)(match[1]);
            if (!timeUnits) {
              return null;
            }
            return results_1.ParsingComponents.createRelativeFromReference(context.reference, timeUnits);
          }
        }]);
      }(AbstractParserWithWordBoundary_1.AbstractParserWithWordBoundaryChecking);
      exports.default = ENTimeUnitWithinFormatParser;
    }
  });

  // ../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/locales/en/parsers/ENMonthNameLittleEndianParser.js
  var require_ENMonthNameLittleEndianParser = __commonJS({
    "../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/locales/en/parsers/ENMonthNameLittleEndianParser.js": function _____tmp_codexChronoBuild_node_modules_chronoNode_dist_cjs_locales_en_parsers_ENMonthNameLittleEndianParserJs(exports) {
      "use strict";

      Object.defineProperty(exports, "__esModule", {
        value: true
      });
      var years_1 = require_years();
      var constants_1 = require_constants();
      var constants_2 = require_constants();
      var constants_3 = require_constants();
      var pattern_1 = require_pattern();
      var AbstractParserWithWordBoundary_1 = require_AbstractParserWithWordBoundary();
      var PATTERN = new RegExp("(?:on\\s{0,3})?(".concat(constants_3.ORDINAL_NUMBER_PATTERN, ")(?:\\s{0,3}(?:to|\\-|\\\u2013|until|through|till)?\\s{0,3}(").concat(constants_3.ORDINAL_NUMBER_PATTERN, "))?(?:-|/|\\s{0,3}(?:of)?\\s{0,3})(").concat((0, pattern_1.matchAnyPattern)(constants_1.MONTH_DICTIONARY), ")(?:(?:-|/|,?\\s{0,3})(").concat(constants_2.YEAR_PATTERN, "(?!\\w)))?(?=\\W|$)"), "i");
      var DATE_GROUP = 1;
      var DATE_TO_GROUP = 2;
      var MONTH_NAME_GROUP = 3;
      var YEAR_GROUP = 4;
      var ENMonthNameLittleEndianParser = /*#__PURE__*/function (_AbstractParserWithWo2) {
        function ENMonthNameLittleEndianParser() {
          _classCallCheck(this, ENMonthNameLittleEndianParser);
          return _callSuper(this, ENMonthNameLittleEndianParser, arguments);
        }
        _inherits(ENMonthNameLittleEndianParser, _AbstractParserWithWo2);
        return _createClass(ENMonthNameLittleEndianParser, [{
          key: "innerPattern",
          value: function innerPattern() {
            return PATTERN;
          }
        }, {
          key: "innerExtract",
          value: function innerExtract(context, match) {
            var result = context.createParsingResult(match.index, match[0]);
            var month = constants_1.MONTH_DICTIONARY[match[MONTH_NAME_GROUP].toLowerCase()];
            var day = (0, constants_3.parseOrdinalNumberPattern)(match[DATE_GROUP]);
            if (day > 31) {
              match.index = match.index + match[DATE_GROUP].length;
              return null;
            }
            result.start.assign("month", month);
            result.start.assign("day", day);
            if (match[YEAR_GROUP]) {
              var yearNumber = (0, constants_2.parseYear)(match[YEAR_GROUP]);
              result.start.assign("year", yearNumber);
            } else {
              var year = (0, years_1.findYearClosestToRef)(context.refDate, day, month);
              result.start.imply("year", year);
            }
            if (match[DATE_TO_GROUP]) {
              var endDate = (0, constants_3.parseOrdinalNumberPattern)(match[DATE_TO_GROUP]);
              result.end = result.start.clone();
              result.end.assign("day", endDate);
            }
            return result;
          }
        }]);
      }(AbstractParserWithWordBoundary_1.AbstractParserWithWordBoundaryChecking);
      exports.default = ENMonthNameLittleEndianParser;
    }
  });

  // ../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/locales/en/parsers/ENMonthNameMiddleEndianParser.js
  var require_ENMonthNameMiddleEndianParser = __commonJS({
    "../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/locales/en/parsers/ENMonthNameMiddleEndianParser.js": function _____tmp_codexChronoBuild_node_modules_chronoNode_dist_cjs_locales_en_parsers_ENMonthNameMiddleEndianParserJs(exports) {
      "use strict";

      Object.defineProperty(exports, "__esModule", {
        value: true
      });
      var years_1 = require_years();
      var constants_1 = require_constants();
      var constants_2 = require_constants();
      var constants_3 = require_constants();
      var pattern_1 = require_pattern();
      var AbstractParserWithWordBoundary_1 = require_AbstractParserWithWordBoundary();
      var PATTERN = new RegExp("(".concat((0, pattern_1.matchAnyPattern)(constants_1.MONTH_DICTIONARY), ")(?:-|/|\\s*,?\\s*)(").concat(constants_2.ORDINAL_NUMBER_PATTERN, ")(?!\\s*(?:am|pm))\\s*(?:(?:to|\\-)\\s*(").concat(constants_2.ORDINAL_NUMBER_PATTERN, ")\\s*)?(?:(?:-|/|\\s*,\\s*|\\s+)(").concat(constants_3.YEAR_PATTERN, "))?(?=\\W|$)(?!\\:\\d)"), "i");
      var MONTH_NAME_GROUP = 1;
      var DATE_GROUP = 2;
      var DATE_TO_GROUP = 3;
      var YEAR_GROUP = 4;
      var ENMonthNameMiddleEndianParser = /*#__PURE__*/function (_AbstractParserWithWo3) {
        function ENMonthNameMiddleEndianParser(shouldSkipYearLikeDate) {
          var _this2;
          _classCallCheck(this, ENMonthNameMiddleEndianParser);
          _this2 = _callSuper(this, ENMonthNameMiddleEndianParser);
          _this2.shouldSkipYearLikeDate = shouldSkipYearLikeDate;
          return _this2;
        }
        _inherits(ENMonthNameMiddleEndianParser, _AbstractParserWithWo3);
        return _createClass(ENMonthNameMiddleEndianParser, [{
          key: "innerPattern",
          value: function innerPattern() {
            return PATTERN;
          }
        }, {
          key: "innerExtract",
          value: function innerExtract(context, match) {
            var month = constants_1.MONTH_DICTIONARY[match[MONTH_NAME_GROUP].toLowerCase()];
            var day = (0, constants_2.parseOrdinalNumberPattern)(match[DATE_GROUP]);
            if (day > 31) {
              return null;
            }
            if (this.shouldSkipYearLikeDate) {
              if (!match[DATE_TO_GROUP] && !match[YEAR_GROUP] && match[DATE_GROUP].match(/^2[0-5]$/)) {
                return null;
              }
            }
            var components = context.createParsingComponents({
              day: day,
              month: month
            }).addTag("parser/ENMonthNameMiddleEndianParser");
            if (match[YEAR_GROUP]) {
              var year = (0, constants_3.parseYear)(match[YEAR_GROUP]);
              components.assign("year", year);
            } else {
              var _year = (0, years_1.findYearClosestToRef)(context.refDate, day, month);
              components.imply("year", _year);
            }
            if (!match[DATE_TO_GROUP]) {
              return components;
            }
            var endDate = (0, constants_2.parseOrdinalNumberPattern)(match[DATE_TO_GROUP]);
            var result = context.createParsingResult(match.index, match[0]);
            result.start = components;
            result.end = components.clone();
            result.end.assign("day", endDate);
            return result;
          }
        }]);
      }(AbstractParserWithWordBoundary_1.AbstractParserWithWordBoundaryChecking);
      exports.default = ENMonthNameMiddleEndianParser;
    }
  });

  // ../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/locales/en/parsers/ENMonthNameParser.js
  var require_ENMonthNameParser = __commonJS({
    "../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/locales/en/parsers/ENMonthNameParser.js": function _____tmp_codexChronoBuild_node_modules_chronoNode_dist_cjs_locales_en_parsers_ENMonthNameParserJs(exports) {
      "use strict";

      Object.defineProperty(exports, "__esModule", {
        value: true
      });
      var constants_1 = require_constants();
      var years_1 = require_years();
      var pattern_1 = require_pattern();
      var constants_2 = require_constants();
      var AbstractParserWithWordBoundary_1 = require_AbstractParserWithWordBoundary();
      var PATTERN = new RegExp("((?:in)\\s*)?(".concat((0, pattern_1.matchAnyPattern)(constants_1.MONTH_DICTIONARY), ")\\s*(?:(?:,|-|of)?\\s*(").concat(constants_2.YEAR_PATTERN, ")?)?(?=[^\\s\\w]|\\s+[^0-9]|\\s+$|$)"), "i");
      var PREFIX_GROUP = 1;
      var MONTH_NAME_GROUP = 2;
      var YEAR_GROUP = 3;
      var ENMonthNameParser = /*#__PURE__*/function (_AbstractParserWithWo4) {
        function ENMonthNameParser() {
          _classCallCheck(this, ENMonthNameParser);
          return _callSuper(this, ENMonthNameParser, arguments);
        }
        _inherits(ENMonthNameParser, _AbstractParserWithWo4);
        return _createClass(ENMonthNameParser, [{
          key: "innerPattern",
          value: function innerPattern() {
            return PATTERN;
          }
        }, {
          key: "innerExtract",
          value: function innerExtract(context, match) {
            var monthName = match[MONTH_NAME_GROUP].toLowerCase();
            if (match[0].length <= 3 && !constants_1.FULL_MONTH_NAME_DICTIONARY[monthName]) {
              return null;
            }
            var result = context.createParsingResult(match.index + (match[PREFIX_GROUP] || "").length, match.index + match[0].length);
            result.start.imply("day", 1);
            result.start.addTag("parser/ENMonthNameParser");
            var month = constants_1.MONTH_DICTIONARY[monthName];
            result.start.assign("month", month);
            if (match[YEAR_GROUP]) {
              var year = (0, constants_2.parseYear)(match[YEAR_GROUP]);
              result.start.assign("year", year);
            } else {
              var _year2 = (0, years_1.findYearClosestToRef)(context.refDate, 1, month);
              result.start.imply("year", _year2);
            }
            return result;
          }
        }]);
      }(AbstractParserWithWordBoundary_1.AbstractParserWithWordBoundaryChecking);
      exports.default = ENMonthNameParser;
    }
  });

  // ../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/locales/en/parsers/ENYearMonthDayParser.js
  var require_ENYearMonthDayParser = __commonJS({
    "../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/locales/en/parsers/ENYearMonthDayParser.js": function _____tmp_codexChronoBuild_node_modules_chronoNode_dist_cjs_locales_en_parsers_ENYearMonthDayParserJs(exports) {
      "use strict";

      Object.defineProperty(exports, "__esModule", {
        value: true
      });
      var constants_1 = require_constants();
      var pattern_1 = require_pattern();
      var AbstractParserWithWordBoundary_1 = require_AbstractParserWithWordBoundary();
      var PATTERN = new RegExp("([0-9]{4})[-\\.\\/\\s](?:(".concat((0, pattern_1.matchAnyPattern)(constants_1.MONTH_DICTIONARY), ")|([0-9]{1,2}))[-\\.\\/\\s]([0-9]{1,2})(?=\\W|$)"), "i");
      var YEAR_NUMBER_GROUP = 1;
      var MONTH_NAME_GROUP = 2;
      var MONTH_NUMBER_GROUP = 3;
      var DATE_NUMBER_GROUP = 4;
      var ENYearMonthDayParser = /*#__PURE__*/function (_AbstractParserWithWo5) {
        function ENYearMonthDayParser(strictMonthDateOrder) {
          var _this3;
          _classCallCheck(this, ENYearMonthDayParser);
          _this3 = _callSuper(this, ENYearMonthDayParser);
          _this3.strictMonthDateOrder = strictMonthDateOrder;
          return _this3;
        }
        _inherits(ENYearMonthDayParser, _AbstractParserWithWo5);
        return _createClass(ENYearMonthDayParser, [{
          key: "innerPattern",
          value: function innerPattern() {
            return PATTERN;
          }
        }, {
          key: "innerExtract",
          value: function innerExtract(context, match) {
            var year = parseInt(match[YEAR_NUMBER_GROUP]);
            var day = parseInt(match[DATE_NUMBER_GROUP]);
            var month = match[MONTH_NUMBER_GROUP] ? parseInt(match[MONTH_NUMBER_GROUP]) : constants_1.MONTH_DICTIONARY[match[MONTH_NAME_GROUP].toLowerCase()];
            if (month < 1 || month > 12) {
              if (this.strictMonthDateOrder) {
                return null;
              }
              if (day >= 1 && day <= 12) {
                var _ref = [day, month];
                month = _ref[0];
                day = _ref[1];
              }
            }
            if (day < 1 || day > 31) {
              return null;
            }
            return {
              day: day,
              month: month,
              year: year
            };
          }
        }]);
      }(AbstractParserWithWordBoundary_1.AbstractParserWithWordBoundaryChecking);
      exports.default = ENYearMonthDayParser;
    }
  });

  // ../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/locales/en/parsers/ENSlashMonthFormatParser.js
  var require_ENSlashMonthFormatParser = __commonJS({
    "../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/locales/en/parsers/ENSlashMonthFormatParser.js": function _____tmp_codexChronoBuild_node_modules_chronoNode_dist_cjs_locales_en_parsers_ENSlashMonthFormatParserJs(exports) {
      "use strict";

      Object.defineProperty(exports, "__esModule", {
        value: true
      });
      var AbstractParserWithWordBoundary_1 = require_AbstractParserWithWordBoundary();
      var PATTERN = new RegExp("([0-9]|0[1-9]|1[012])/([0-9]{4})", "i");
      var MONTH_GROUP = 1;
      var YEAR_GROUP = 2;
      var ENSlashMonthFormatParser = /*#__PURE__*/function (_AbstractParserWithWo6) {
        function ENSlashMonthFormatParser() {
          _classCallCheck(this, ENSlashMonthFormatParser);
          return _callSuper(this, ENSlashMonthFormatParser, arguments);
        }
        _inherits(ENSlashMonthFormatParser, _AbstractParserWithWo6);
        return _createClass(ENSlashMonthFormatParser, [{
          key: "innerPattern",
          value: function innerPattern() {
            return PATTERN;
          }
        }, {
          key: "innerExtract",
          value: function innerExtract(context, match) {
            var year = parseInt(match[YEAR_GROUP]);
            var month = parseInt(match[MONTH_GROUP]);
            return context.createParsingComponents().imply("day", 1).assign("month", month).assign("year", year);
          }
        }]);
      }(AbstractParserWithWordBoundary_1.AbstractParserWithWordBoundaryChecking);
      exports.default = ENSlashMonthFormatParser;
    }
  });

  // ../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/common/parsers/AbstractTimeExpressionParser.js
  var require_AbstractTimeExpressionParser = __commonJS({
    "../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/common/parsers/AbstractTimeExpressionParser.js": function _____tmp_codexChronoBuild_node_modules_chronoNode_dist_cjs_common_parsers_AbstractTimeExpressionParserJs(exports) {
      "use strict";

      Object.defineProperty(exports, "__esModule", {
        value: true
      });
      exports.AbstractTimeExpressionParser = void 0;
      var types_1 = require_types();
      function primaryTimePattern(leftBoundary, primaryPrefix, primarySuffix, flags) {
        return new RegExp("".concat(leftBoundary).concat(primaryPrefix, "(\\d{1,4})(?:(?:\\.|:|\uFF1A)(\\d{1,2})(?:(?::|\uFF1A)(\\d{2})(?:\\.(\\d{1,6}))?)?)?(?:\\s*(a\\.m\\.|p\\.m\\.|am?|pm?))?").concat(primarySuffix), flags);
      }
      function followingTimePatten(followingPhase, followingSuffix) {
        return new RegExp("^(".concat(followingPhase, ")(\\d{1,4})(?:(?:\\.|\\:|\\\uFF1A)(\\d{1,2})(?:(?:\\.|\\:|\\\uFF1A)(\\d{1,2})(?:\\.(\\d{1,6}))?)?)?(?:\\s*(a\\.m\\.|p\\.m\\.|am?|pm?))?").concat(followingSuffix), "i");
      }
      var HOUR_GROUP = 2;
      var MINUTE_GROUP = 3;
      var SECOND_GROUP = 4;
      var MILLI_SECOND_GROUP = 5;
      var AM_PM_HOUR_GROUP = 6;
      var AbstractTimeExpressionParser = /*#__PURE__*/function () {
        function AbstractTimeExpressionParser() {
          var strictMode = arguments.length > 0 && arguments[0] !== undefined ? arguments[0] : false;
          _classCallCheck(this, AbstractTimeExpressionParser);
          this.cachedPrimaryPrefix = null;
          this.cachedPrimarySuffix = null;
          this.cachedPrimaryTimePattern = null;
          this.cachedFollowingPhase = null;
          this.cachedFollowingSuffix = null;
          this.cachedFollowingTimePatten = null;
          this.strictMode = strictMode;
        }
        return _createClass(AbstractTimeExpressionParser, [{
          key: "patternFlags",
          value: function patternFlags() {
            return "i";
          }
        }, {
          key: "primaryPatternLeftBoundary",
          value: function primaryPatternLeftBoundary() {
            return "(^|\\s|T|\\b)";
          }
        }, {
          key: "primarySuffix",
          value: function primarySuffix() {
            return "(?!/)(?=\\W|$)";
          }
        }, {
          key: "followingSuffix",
          value: function followingSuffix() {
            return "(?!/)(?=\\W|$)";
          }
        }, {
          key: "pattern",
          value: function pattern(context) {
            return this.getPrimaryTimePatternThroughCache();
          }
        }, {
          key: "extract",
          value: function extract(context, match) {
            var startComponents = this.extractPrimaryTimeComponents(context, match);
            if (!startComponents) {
              if (match[0].match(/^\d{4}/)) {
                match.index += 4;
                return null;
              }
              match.index += match[0].length;
              return null;
            }
            var index = match.index + match[1].length;
            var text = match[0].substring(match[1].length);
            var result = context.createParsingResult(index, text, startComponents);
            match.index += match[0].length;
            var remainingText = context.text.substring(match.index);
            var followingPattern = this.getFollowingTimePatternThroughCache();
            var followingMatch = followingPattern.exec(remainingText);
            if (text.match(/^\d{3,4}/) && followingMatch) {
              if (followingMatch[0].match(/^\s*([+-])\s*\d{2,4}$/)) {
                return null;
              }
              if (followingMatch[0].match(/^\s*([+-])\s*\d{2}\W\d{2}/)) {
                return null;
              }
            }
            if (!followingMatch || followingMatch[0].match(/^\s*([+-])\s*\d{3,4}$/)) {
              return this.checkAndReturnWithoutFollowingPattern(result);
            }
            result.end = this.extractFollowingTimeComponents(context, followingMatch, result);
            if (result.end) {
              result.text += followingMatch[0];
            }
            return this.checkAndReturnWithFollowingPattern(result);
          }
        }, {
          key: "extractPrimaryTimeComponents",
          value: function extractPrimaryTimeComponents(context, match) {
            var strict = arguments.length > 2 && arguments[2] !== undefined ? arguments[2] : false;
            var components = context.createParsingComponents();
            var minute = 0;
            var meridiem = null;
            var hour = parseInt(match[HOUR_GROUP]);
            if (hour > 100) {
              if (match[HOUR_GROUP].length == 4 && match[MINUTE_GROUP] == null && !match[AM_PM_HOUR_GROUP]) {
                return null;
              }
              if (this.strictMode || match[MINUTE_GROUP] != null) {
                return null;
              }
              minute = hour % 100;
              hour = Math.floor(hour / 100);
            }
            if (hour > 24) {
              return null;
            }
            if (match[MINUTE_GROUP] != null) {
              if (match[MINUTE_GROUP].length == 1 && !match[AM_PM_HOUR_GROUP]) {
                return null;
              }
              minute = parseInt(match[MINUTE_GROUP]);
            }
            if (minute >= 60) {
              return null;
            }
            if (hour > 12) {
              meridiem = types_1.Meridiem.PM;
            }
            if (match[AM_PM_HOUR_GROUP] != null) {
              if (hour > 12) return null;
              var ampm = match[AM_PM_HOUR_GROUP][0].toLowerCase();
              if (ampm == "a") {
                meridiem = types_1.Meridiem.AM;
                if (hour == 12) {
                  hour = 0;
                }
              }
              if (ampm == "p") {
                meridiem = types_1.Meridiem.PM;
                if (hour != 12) {
                  hour += 12;
                }
              }
            }
            components.assign("hour", hour);
            components.assign("minute", minute);
            if (meridiem !== null) {
              components.assign("meridiem", meridiem);
            } else {
              if (hour < 12) {
                components.imply("meridiem", types_1.Meridiem.AM);
              } else {
                components.imply("meridiem", types_1.Meridiem.PM);
              }
            }
            if (match[MILLI_SECOND_GROUP] != null) {
              var millisecond = parseInt(match[MILLI_SECOND_GROUP].substring(0, 3));
              if (millisecond >= 1e3) return null;
              components.assign("millisecond", millisecond);
            }
            if (match[SECOND_GROUP] != null) {
              var second = parseInt(match[SECOND_GROUP]);
              if (second >= 60) return null;
              components.assign("second", second);
            }
            return components;
          }
        }, {
          key: "extractFollowingTimeComponents",
          value: function extractFollowingTimeComponents(context, match, result) {
            var components = context.createParsingComponents();
            if (match[MILLI_SECOND_GROUP] != null) {
              var millisecond = parseInt(match[MILLI_SECOND_GROUP].substring(0, 3));
              if (millisecond >= 1e3) return null;
              components.assign("millisecond", millisecond);
            }
            if (match[SECOND_GROUP] != null) {
              var second = parseInt(match[SECOND_GROUP]);
              if (second >= 60) return null;
              components.assign("second", second);
            }
            var hour = parseInt(match[HOUR_GROUP]);
            var minute = 0;
            var meridiem = -1;
            if (match[MINUTE_GROUP] != null) {
              minute = parseInt(match[MINUTE_GROUP]);
            } else if (hour > 100) {
              minute = hour % 100;
              hour = Math.floor(hour / 100);
            }
            if (minute >= 60 || hour > 24) {
              return null;
            }
            if (hour >= 12) {
              meridiem = types_1.Meridiem.PM;
            }
            if (match[AM_PM_HOUR_GROUP] != null) {
              if (hour > 12) {
                return null;
              }
              var ampm = match[AM_PM_HOUR_GROUP][0].toLowerCase();
              if (ampm == "a") {
                meridiem = types_1.Meridiem.AM;
                if (hour == 12) {
                  hour = 0;
                  if (!components.isCertain("day")) {
                    components.imply("day", components.get("day") + 1);
                  }
                }
              }
              if (ampm == "p") {
                meridiem = types_1.Meridiem.PM;
                if (hour != 12) hour += 12;
              }
              if (!result.start.isCertain("meridiem")) {
                if (meridiem == types_1.Meridiem.AM) {
                  result.start.imply("meridiem", types_1.Meridiem.AM);
                  if (result.start.get("hour") == 12) {
                    result.start.assign("hour", 0);
                  }
                } else {
                  result.start.imply("meridiem", types_1.Meridiem.PM);
                  if (result.start.get("hour") != 12) {
                    result.start.assign("hour", result.start.get("hour") + 12);
                  }
                }
              }
            }
            components.assign("hour", hour);
            components.assign("minute", minute);
            if (meridiem >= 0) {
              components.assign("meridiem", meridiem);
            } else {
              var startAtPM = result.start.isCertain("meridiem") && result.start.get("hour") > 12;
              if (startAtPM) {
                if (result.start.get("hour") - 12 > hour) {
                  components.imply("meridiem", types_1.Meridiem.AM);
                } else if (hour <= 12) {
                  components.assign("hour", hour + 12);
                  components.assign("meridiem", types_1.Meridiem.PM);
                }
              } else if (hour > 12) {
                components.imply("meridiem", types_1.Meridiem.PM);
              } else if (hour <= 12) {
                components.imply("meridiem", types_1.Meridiem.AM);
              }
            }
            if (components.date().getTime() < result.start.date().getTime()) {
              components.imply("day", components.get("day") + 1);
            }
            return components;
          }
        }, {
          key: "checkAndReturnWithoutFollowingPattern",
          value: function checkAndReturnWithoutFollowingPattern(result) {
            if (result.text.match(/^\d$/)) {
              return null;
            }
            if (result.text.match(/^\d\d\d+$/)) {
              return null;
            }
            if (result.text.match(/\d[apAP]$/)) {
              return null;
            }
            var endingWithNumbers = result.text.match(/[^\d:.](\d[\d.]+)$/);
            if (endingWithNumbers) {
              var endingNumbers = endingWithNumbers[1];
              if (this.strictMode) {
                return null;
              }
              if (endingNumbers.includes(".") && !endingNumbers.match(/\d(\.\d{2})+$/)) {
                return null;
              }
              var endingNumberVal = parseInt(endingNumbers);
              if (endingNumberVal > 24) {
                return null;
              }
            }
            return result;
          }
        }, {
          key: "checkAndReturnWithFollowingPattern",
          value: function checkAndReturnWithFollowingPattern(result) {
            if (result.text.match(/^\d+-\d+$/)) {
              return null;
            }
            var endingWithNumbers = result.text.match(/[^\d:.](\d[\d.]+)\s*-\s*(\d[\d.]+)$/);
            if (endingWithNumbers) {
              if (this.strictMode) {
                return null;
              }
              var startingNumbers = endingWithNumbers[1];
              var endingNumbers = endingWithNumbers[2];
              if (endingNumbers.includes(".") && !endingNumbers.match(/\d(\.\d{2})+$/)) {
                return null;
              }
              var endingNumberVal = parseInt(endingNumbers);
              var startingNumberVal = parseInt(startingNumbers);
              if (endingNumberVal > 24 || startingNumberVal > 24) {
                return null;
              }
            }
            return result;
          }
        }, {
          key: "getPrimaryTimePatternThroughCache",
          value: function getPrimaryTimePatternThroughCache() {
            var primaryPrefix = this.primaryPrefix();
            var primarySuffix = this.primarySuffix();
            if (this.cachedPrimaryPrefix === primaryPrefix && this.cachedPrimarySuffix === primarySuffix) {
              return this.cachedPrimaryTimePattern;
            }
            this.cachedPrimaryTimePattern = primaryTimePattern(this.primaryPatternLeftBoundary(), primaryPrefix, primarySuffix, this.patternFlags());
            this.cachedPrimaryPrefix = primaryPrefix;
            this.cachedPrimarySuffix = primarySuffix;
            return this.cachedPrimaryTimePattern;
          }
        }, {
          key: "getFollowingTimePatternThroughCache",
          value: function getFollowingTimePatternThroughCache() {
            var followingPhase = this.followingPhase();
            var followingSuffix = this.followingSuffix();
            if (this.cachedFollowingPhase === followingPhase && this.cachedFollowingSuffix === followingSuffix) {
              return this.cachedFollowingTimePatten;
            }
            this.cachedFollowingTimePatten = followingTimePatten(followingPhase, followingSuffix);
            this.cachedFollowingPhase = followingPhase;
            this.cachedFollowingSuffix = followingSuffix;
            return this.cachedFollowingTimePatten;
          }
        }]);
      }();
      exports.AbstractTimeExpressionParser = AbstractTimeExpressionParser;
    }
  });

  // ../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/locales/en/parsers/ENTimeExpressionParser.js
  var require_ENTimeExpressionParser = __commonJS({
    "../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/locales/en/parsers/ENTimeExpressionParser.js": function _____tmp_codexChronoBuild_node_modules_chronoNode_dist_cjs_locales_en_parsers_ENTimeExpressionParserJs(exports) {
      "use strict";

      Object.defineProperty(exports, "__esModule", {
        value: true
      });
      var types_1 = require_types();
      var AbstractTimeExpressionParser_1 = require_AbstractTimeExpressionParser();
      var ENTimeExpressionParser = /*#__PURE__*/function (_AbstractTimeExpressi) {
        function ENTimeExpressionParser(strictMode) {
          _classCallCheck(this, ENTimeExpressionParser);
          return _callSuper(this, ENTimeExpressionParser, [strictMode]);
        }
        _inherits(ENTimeExpressionParser, _AbstractTimeExpressi);
        return _createClass(ENTimeExpressionParser, [{
          key: "followingPhase",
          value: function followingPhase() {
            return "\\s*(?:\\-|\\\u2013|\\~|\\\u301C|to|until|through|till|\\?)\\s*";
          }
        }, {
          key: "primaryPrefix",
          value: function primaryPrefix() {
            return "(?:(?:at|from)\\s*)??";
          }
        }, {
          key: "primarySuffix",
          value: function primarySuffix() {
            return "(?:\\s*(?:o\\W*clock|at\\s*night|in\\s*the\\s*(?:morning|afternoon)))?(?!/)(?=\\W|$)";
          }
        }, {
          key: "extractPrimaryTimeComponents",
          value: function extractPrimaryTimeComponents(context, match) {
            var components = _superPropGet(ENTimeExpressionParser, "extractPrimaryTimeComponents", this, 3)([context, match]);
            if (!components) {
              return components;
            }
            if (match[0].endsWith("night")) {
              var hour = components.get("hour");
              if (hour >= 6 && hour < 12) {
                components.assign("hour", components.get("hour") + 12);
                components.assign("meridiem", types_1.Meridiem.PM);
              } else if (hour < 6) {
                components.assign("meridiem", types_1.Meridiem.AM);
              }
            }
            if (match[0].endsWith("afternoon")) {
              components.assign("meridiem", types_1.Meridiem.PM);
              var _hour = components.get("hour");
              if (_hour >= 0 && _hour <= 6) {
                components.assign("hour", components.get("hour") + 12);
              }
            }
            if (match[0].endsWith("morning")) {
              components.assign("meridiem", types_1.Meridiem.AM);
              var _hour2 = components.get("hour");
              if (_hour2 < 12) {
                components.assign("hour", components.get("hour"));
              }
            }
            return components.addTag("parser/ENTimeExpressionParser");
          }
        }, {
          key: "extractFollowingTimeComponents",
          value: function extractFollowingTimeComponents(context, match, result) {
            var followingComponents = _superPropGet(ENTimeExpressionParser, "extractFollowingTimeComponents", this, 3)([context, match, result]);
            if (followingComponents) {
              followingComponents.addTag("parser/ENTimeExpressionParser");
            }
            return followingComponents;
          }
        }]);
      }(AbstractTimeExpressionParser_1.AbstractTimeExpressionParser);
      exports.default = ENTimeExpressionParser;
    }
  });

  // ../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/locales/en/parsers/ENTimeUnitAgoFormatParser.js
  var require_ENTimeUnitAgoFormatParser = __commonJS({
    "../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/locales/en/parsers/ENTimeUnitAgoFormatParser.js": function _____tmp_codexChronoBuild_node_modules_chronoNode_dist_cjs_locales_en_parsers_ENTimeUnitAgoFormatParserJs(exports) {
      "use strict";

      Object.defineProperty(exports, "__esModule", {
        value: true
      });
      var constants_1 = require_constants();
      var results_1 = require_results();
      var AbstractParserWithWordBoundary_1 = require_AbstractParserWithWordBoundary();
      var duration_1 = require_duration();
      var PATTERN = new RegExp("(".concat(constants_1.TIME_UNITS_PATTERN, ")\\s{0,5}(?:ago|before|earlier)(?=\\W|$)"), "i");
      var STRICT_PATTERN = new RegExp("(".concat(constants_1.TIME_UNITS_NO_ABBR_PATTERN, ")\\s{0,5}(?:ago|before|earlier)(?=\\W|$)"), "i");
      var ENTimeUnitAgoFormatParser = /*#__PURE__*/function (_AbstractParserWithWo7) {
        function ENTimeUnitAgoFormatParser(strictMode) {
          var _this4;
          _classCallCheck(this, ENTimeUnitAgoFormatParser);
          _this4 = _callSuper(this, ENTimeUnitAgoFormatParser);
          _this4.strictMode = strictMode;
          return _this4;
        }
        _inherits(ENTimeUnitAgoFormatParser, _AbstractParserWithWo7);
        return _createClass(ENTimeUnitAgoFormatParser, [{
          key: "innerPattern",
          value: function innerPattern() {
            return this.strictMode ? STRICT_PATTERN : PATTERN;
          }
        }, {
          key: "innerExtract",
          value: function innerExtract(context, match) {
            var duration = (0, constants_1.parseDuration)(match[1]);
            if (!duration) {
              return null;
            }
            return results_1.ParsingComponents.createRelativeFromReference(context.reference, (0, duration_1.reverseDuration)(duration));
          }
        }]);
      }(AbstractParserWithWordBoundary_1.AbstractParserWithWordBoundaryChecking);
      exports.default = ENTimeUnitAgoFormatParser;
    }
  });

  // ../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/locales/en/parsers/ENTimeUnitLaterFormatParser.js
  var require_ENTimeUnitLaterFormatParser = __commonJS({
    "../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/locales/en/parsers/ENTimeUnitLaterFormatParser.js": function _____tmp_codexChronoBuild_node_modules_chronoNode_dist_cjs_locales_en_parsers_ENTimeUnitLaterFormatParserJs(exports) {
      "use strict";

      Object.defineProperty(exports, "__esModule", {
        value: true
      });
      var constants_1 = require_constants();
      var results_1 = require_results();
      var AbstractParserWithWordBoundary_1 = require_AbstractParserWithWordBoundary();
      var PATTERN = new RegExp("(".concat(constants_1.TIME_UNITS_PATTERN, ")\\s{0,5}(?:later|after|from now|henceforth|forward|out)(?=(?:\\W|$))"), "i");
      var STRICT_PATTERN = new RegExp("(".concat(constants_1.TIME_UNITS_NO_ABBR_PATTERN, ")\\s{0,5}(later|after|from now)(?=\\W|$)"), "i");
      var GROUP_NUM_TIMEUNITS = 1;
      var ENTimeUnitLaterFormatParser = /*#__PURE__*/function (_AbstractParserWithWo8) {
        function ENTimeUnitLaterFormatParser(strictMode) {
          var _this5;
          _classCallCheck(this, ENTimeUnitLaterFormatParser);
          _this5 = _callSuper(this, ENTimeUnitLaterFormatParser);
          _this5.strictMode = strictMode;
          return _this5;
        }
        _inherits(ENTimeUnitLaterFormatParser, _AbstractParserWithWo8);
        return _createClass(ENTimeUnitLaterFormatParser, [{
          key: "innerPattern",
          value: function innerPattern() {
            return this.strictMode ? STRICT_PATTERN : PATTERN;
          }
        }, {
          key: "innerExtract",
          value: function innerExtract(context, match) {
            var timeUnits = (0, constants_1.parseDuration)(match[GROUP_NUM_TIMEUNITS]);
            if (!timeUnits) {
              return null;
            }
            return results_1.ParsingComponents.createRelativeFromReference(context.reference, timeUnits);
          }
        }]);
      }(AbstractParserWithWordBoundary_1.AbstractParserWithWordBoundaryChecking);
      exports.default = ENTimeUnitLaterFormatParser;
    }
  });

  // ../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/common/abstractRefiners.js
  var require_abstractRefiners = __commonJS({
    "../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/common/abstractRefiners.js": function _____tmp_codexChronoBuild_node_modules_chronoNode_dist_cjs_common_abstractRefinersJs(exports) {
      "use strict";

      Object.defineProperty(exports, "__esModule", {
        value: true
      });
      exports.MergingRefiner = exports.Filter = void 0;
      var Filter = /*#__PURE__*/function () {
        function Filter() {
          _classCallCheck(this, Filter);
        }
        return _createClass(Filter, [{
          key: "refine",
          value: function refine(context, results) {
            var _this6 = this;
            return results.filter(function (r) {
              return _this6.isValid(context, r);
            });
          }
        }]);
      }();
      exports.Filter = Filter;
      var MergingRefiner = /*#__PURE__*/function () {
        function MergingRefiner() {
          _classCallCheck(this, MergingRefiner);
        }
        return _createClass(MergingRefiner, [{
          key: "refine",
          value: function refine(context, results) {
            var _this7 = this;
            if (results.length < 2) {
              return results;
            }
            var mergedResults = [];
            var curResult = results[0];
            var nextResult = null;
            var _loop = function _loop() {
              nextResult = results[i];
              var textBetween = context.text.substring(curResult.index + curResult.text.length, nextResult.index);
              if (!_this7.shouldMergeResults(textBetween, curResult, nextResult, context)) {
                mergedResults.push(curResult);
                curResult = nextResult;
              } else {
                var left = curResult;
                var right = nextResult;
                var mergedResult = _this7.mergeResults(textBetween, left, right, context);
                context.debug(function () {
                  console.log("".concat(_this7.constructor.name, " merged ").concat(left, " and ").concat(right, " into ").concat(mergedResult));
                });
                curResult = mergedResult;
              }
            };
            for (var i = 1; i < results.length; i++) {
              _loop();
            }
            if (curResult != null) {
              mergedResults.push(curResult);
            }
            return mergedResults;
          }
        }]);
      }();
      exports.MergingRefiner = MergingRefiner;
    }
  });

  // ../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/common/refiners/AbstractMergeDateRangeRefiner.js
  var require_AbstractMergeDateRangeRefiner = __commonJS({
    "../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/common/refiners/AbstractMergeDateRangeRefiner.js": function _____tmp_codexChronoBuild_node_modules_chronoNode_dist_cjs_common_refiners_AbstractMergeDateRangeRefinerJs(exports) {
      "use strict";

      Object.defineProperty(exports, "__esModule", {
        value: true
      });
      var abstractRefiners_1 = require_abstractRefiners();
      var duration_1 = require_duration();
      var AbstractMergeDateRangeRefiner = /*#__PURE__*/function (_abstractRefiners_1$M) {
        function AbstractMergeDateRangeRefiner() {
          _classCallCheck(this, AbstractMergeDateRangeRefiner);
          return _callSuper(this, AbstractMergeDateRangeRefiner, arguments);
        }
        _inherits(AbstractMergeDateRangeRefiner, _abstractRefiners_1$M);
        return _createClass(AbstractMergeDateRangeRefiner, [{
          key: "shouldMergeResults",
          value: function shouldMergeResults(textBetween, currentResult, nextResult) {
            return !currentResult.end && !nextResult.end && textBetween.match(this.patternBetween()) != null;
          }
        }, {
          key: "mergeResults",
          value: function mergeResults(textBetween, fromResult, toResult) {
            if (!fromResult.start.isOnlyWeekdayComponent() && !toResult.start.isOnlyWeekdayComponent()) {
              toResult.start.getCertainComponents().forEach(function (key) {
                if (!fromResult.start.isCertain(key)) {
                  fromResult.start.imply(key, toResult.start.get(key));
                }
              });
              fromResult.start.getCertainComponents().forEach(function (key) {
                if (!toResult.start.isCertain(key)) {
                  toResult.start.imply(key, fromResult.start.get(key));
                }
              });
            }
            if (fromResult.start.date() > toResult.start.date()) {
              var fromDate = fromResult.start.date();
              var toDate = toResult.start.date();
              if (toResult.start.isOnlyWeekdayComponent() && (0, duration_1.addDuration)(toDate, {
                day: 7
              }) > fromDate) {
                toDate = (0, duration_1.addDuration)(toDate, {
                  day: 7
                });
                toResult.start.imply("day", toDate.getDate());
                toResult.start.imply("month", toDate.getMonth() + 1);
                toResult.start.imply("year", toDate.getFullYear());
              } else if (fromResult.start.isOnlyWeekdayComponent() && (0, duration_1.addDuration)(fromDate, {
                day: -7
              }) < toDate) {
                fromDate = (0, duration_1.addDuration)(fromDate, {
                  day: -7
                });
                fromResult.start.imply("day", fromDate.getDate());
                fromResult.start.imply("month", fromDate.getMonth() + 1);
                fromResult.start.imply("year", fromDate.getFullYear());
              } else if (toResult.start.isDateWithUnknownYear() && (0, duration_1.addDuration)(toDate, {
                year: 1
              }) > fromDate) {
                toDate = (0, duration_1.addDuration)(toDate, {
                  year: 1
                });
                toResult.start.imply("year", toDate.getFullYear());
              } else if (fromResult.start.isDateWithUnknownYear() && (0, duration_1.addDuration)(fromDate, {
                year: -1
              }) < toDate) {
                fromDate = (0, duration_1.addDuration)(fromDate, {
                  year: -1
                });
                fromResult.start.imply("year", fromDate.getFullYear());
              } else {
                var _ref2 = [fromResult, toResult];
                toResult = _ref2[0];
                fromResult = _ref2[1];
              }
            }
            var result = fromResult.clone();
            result.start = fromResult.start;
            result.end = toResult.start;
            result.index = Math.min(fromResult.index, toResult.index);
            if (fromResult.index < toResult.index) {
              result.text = fromResult.text + textBetween + toResult.text;
            } else {
              result.text = toResult.text + textBetween + fromResult.text;
            }
            return result;
          }
        }]);
      }(abstractRefiners_1.MergingRefiner);
      exports.default = AbstractMergeDateRangeRefiner;
    }
  });

  // ../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/locales/en/refiners/ENMergeDateRangeRefiner.js
  var require_ENMergeDateRangeRefiner = __commonJS({
    "../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/locales/en/refiners/ENMergeDateRangeRefiner.js": function _____tmp_codexChronoBuild_node_modules_chronoNode_dist_cjs_locales_en_refiners_ENMergeDateRangeRefinerJs(exports) {
      "use strict";

      var __importDefault = exports && exports.__importDefault || function (mod) {
        return mod && mod.__esModule ? mod : {
          "default": mod
        };
      };
      Object.defineProperty(exports, "__esModule", {
        value: true
      });
      var AbstractMergeDateRangeRefiner_1 = __importDefault(require_AbstractMergeDateRangeRefiner());
      var ENMergeDateRangeRefiner = /*#__PURE__*/function (_AbstractMergeDateRan) {
        function ENMergeDateRangeRefiner() {
          _classCallCheck(this, ENMergeDateRangeRefiner);
          return _callSuper(this, ENMergeDateRangeRefiner, arguments);
        }
        _inherits(ENMergeDateRangeRefiner, _AbstractMergeDateRan);
        return _createClass(ENMergeDateRangeRefiner, [{
          key: "patternBetween",
          value: function patternBetween() {
            return /^\s*(to|-|–|until|through|till)\s*$/i;
          }
        }]);
      }(AbstractMergeDateRangeRefiner_1.default);
      exports.default = ENMergeDateRangeRefiner;
    }
  });

  // ../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/calculation/mergingCalculation.js
  var require_mergingCalculation = __commonJS({
    "../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/calculation/mergingCalculation.js": function _____tmp_codexChronoBuild_node_modules_chronoNode_dist_cjs_calculation_mergingCalculationJs(exports) {
      "use strict";

      Object.defineProperty(exports, "__esModule", {
        value: true
      });
      exports.mergeDateTimeResult = mergeDateTimeResult;
      exports.mergeDateTimeComponent = mergeDateTimeComponent;
      var types_1 = require_types();
      var dates_1 = require_dates();
      function mergeDateTimeResult(dateResult, timeResult) {
        var result = dateResult.clone();
        var beginDate = dateResult.start;
        var beginTime = timeResult.start;
        result.start = mergeDateTimeComponent(beginDate, beginTime);
        if (dateResult.end != null || timeResult.end != null) {
          var endDate = dateResult.end == null ? dateResult.start : dateResult.end;
          var endTime = timeResult.end == null ? timeResult.start : timeResult.end;
          var endDateTime = mergeDateTimeComponent(endDate, endTime);
          if (dateResult.end == null && endDateTime.date().getTime() < result.start.date().getTime()) {
            var nextDay = new Date(endDateTime.date().getTime());
            nextDay.setDate(nextDay.getDate() + 1);
            if (endDateTime.isCertain("day")) {
              (0, dates_1.assignSimilarDate)(endDateTime, nextDay);
            } else {
              (0, dates_1.implySimilarDate)(endDateTime, nextDay);
            }
          }
          result.end = endDateTime;
        }
        return result;
      }
      function mergeDateTimeComponent(dateComponent, timeComponent) {
        var dateTimeComponent = dateComponent.clone();
        if (timeComponent.isCertain("hour")) {
          dateTimeComponent.assign("hour", timeComponent.get("hour"));
          dateTimeComponent.assign("minute", timeComponent.get("minute"));
          if (timeComponent.isCertain("second")) {
            dateTimeComponent.assign("second", timeComponent.get("second"));
            if (timeComponent.isCertain("millisecond")) {
              dateTimeComponent.assign("millisecond", timeComponent.get("millisecond"));
            } else {
              dateTimeComponent.imply("millisecond", timeComponent.get("millisecond"));
            }
          } else {
            dateTimeComponent.imply("second", timeComponent.get("second"));
            dateTimeComponent.imply("millisecond", timeComponent.get("millisecond"));
          }
        } else {
          dateTimeComponent.imply("hour", timeComponent.get("hour"));
          dateTimeComponent.imply("minute", timeComponent.get("minute"));
          dateTimeComponent.imply("second", timeComponent.get("second"));
          dateTimeComponent.imply("millisecond", timeComponent.get("millisecond"));
        }
        if (timeComponent.isCertain("timezoneOffset")) {
          dateTimeComponent.assign("timezoneOffset", timeComponent.get("timezoneOffset"));
        }
        if (timeComponent.isCertain("meridiem")) {
          dateTimeComponent.assign("meridiem", timeComponent.get("meridiem"));
        } else if (timeComponent.get("meridiem") != null && dateTimeComponent.get("meridiem") == null) {
          dateTimeComponent.imply("meridiem", timeComponent.get("meridiem"));
        }
        if (dateTimeComponent.get("meridiem") == types_1.Meridiem.PM && dateTimeComponent.get("hour") < 12) {
          if (timeComponent.isCertain("hour")) {
            dateTimeComponent.assign("hour", dateTimeComponent.get("hour") + 12);
          } else {
            dateTimeComponent.imply("hour", dateTimeComponent.get("hour") + 12);
          }
        }
        dateTimeComponent.addTags(dateComponent.tags());
        dateTimeComponent.addTags(timeComponent.tags());
        return dateTimeComponent;
      }
    }
  });

  // ../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/common/refiners/AbstractMergeDateTimeRefiner.js
  var require_AbstractMergeDateTimeRefiner = __commonJS({
    "../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/common/refiners/AbstractMergeDateTimeRefiner.js": function _____tmp_codexChronoBuild_node_modules_chronoNode_dist_cjs_common_refiners_AbstractMergeDateTimeRefinerJs(exports) {
      "use strict";

      Object.defineProperty(exports, "__esModule", {
        value: true
      });
      var abstractRefiners_1 = require_abstractRefiners();
      var mergingCalculation_1 = require_mergingCalculation();
      var AbstractMergeDateTimeRefiner = /*#__PURE__*/function (_abstractRefiners_1$M2) {
        function AbstractMergeDateTimeRefiner() {
          _classCallCheck(this, AbstractMergeDateTimeRefiner);
          return _callSuper(this, AbstractMergeDateTimeRefiner, arguments);
        }
        _inherits(AbstractMergeDateTimeRefiner, _abstractRefiners_1$M2);
        return _createClass(AbstractMergeDateTimeRefiner, [{
          key: "shouldMergeResults",
          value: function shouldMergeResults(textBetween, currentResult, nextResult) {
            return (currentResult.start.isOnlyDate() && nextResult.start.isOnlyTime() || nextResult.start.isOnlyDate() && currentResult.start.isOnlyTime()) && textBetween.match(this.patternBetween()) != null;
          }
        }, {
          key: "mergeResults",
          value: function mergeResults(textBetween, currentResult, nextResult) {
            var result = currentResult.start.isOnlyDate() ? (0, mergingCalculation_1.mergeDateTimeResult)(currentResult, nextResult) : (0, mergingCalculation_1.mergeDateTimeResult)(nextResult, currentResult);
            result.index = currentResult.index;
            result.text = currentResult.text + textBetween + nextResult.text;
            return result;
          }
        }]);
      }(abstractRefiners_1.MergingRefiner);
      exports.default = AbstractMergeDateTimeRefiner;
    }
  });

  // ../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/locales/en/refiners/ENMergeDateTimeRefiner.js
  var require_ENMergeDateTimeRefiner = __commonJS({
    "../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/locales/en/refiners/ENMergeDateTimeRefiner.js": function _____tmp_codexChronoBuild_node_modules_chronoNode_dist_cjs_locales_en_refiners_ENMergeDateTimeRefinerJs(exports) {
      "use strict";

      var __importDefault = exports && exports.__importDefault || function (mod) {
        return mod && mod.__esModule ? mod : {
          "default": mod
        };
      };
      Object.defineProperty(exports, "__esModule", {
        value: true
      });
      var AbstractMergeDateTimeRefiner_1 = __importDefault(require_AbstractMergeDateTimeRefiner());
      var ENMergeDateTimeRefiner = /*#__PURE__*/function (_AbstractMergeDateTim) {
        function ENMergeDateTimeRefiner() {
          _classCallCheck(this, ENMergeDateTimeRefiner);
          return _callSuper(this, ENMergeDateTimeRefiner, arguments);
        }
        _inherits(ENMergeDateTimeRefiner, _AbstractMergeDateTim);
        return _createClass(ENMergeDateTimeRefiner, [{
          key: "patternBetween",
          value: function patternBetween() {
            return new RegExp("^\\s*(T|at|after|before|on|of|,|-|\\.|\u2219|:)?\\s*$");
          }
        }]);
      }(AbstractMergeDateTimeRefiner_1.default);
      exports.default = ENMergeDateTimeRefiner;
    }
  });

  // ../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/common/refiners/ExtractTimezoneAbbrRefiner.js
  var require_ExtractTimezoneAbbrRefiner = __commonJS({
    "../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/common/refiners/ExtractTimezoneAbbrRefiner.js": function _____tmp_codexChronoBuild_node_modules_chronoNode_dist_cjs_common_refiners_ExtractTimezoneAbbrRefinerJs(exports) {
      "use strict";

      Object.defineProperty(exports, "__esModule", {
        value: true
      });
      var timezone_1 = require_timezone();
      var TIMEZONE_NAME_PATTERN = new RegExp("^\\s*,?\\s*\\(?([A-Z]{2,4})\\)?(?=\\W|$)", "i");
      var ExtractTimezoneAbbrRefiner = /*#__PURE__*/function () {
        function ExtractTimezoneAbbrRefiner(timezoneOverrides) {
          _classCallCheck(this, ExtractTimezoneAbbrRefiner);
          this.timezoneOverrides = timezoneOverrides;
        }
        return _createClass(ExtractTimezoneAbbrRefiner, [{
          key: "refine",
          value: function refine(context, results) {
            var _this8 = this;
            var _a;
            var timezoneOverrides = (_a = context.option.timezones) !== null && _a !== void 0 ? _a : {};
            results.forEach(function (result) {
              var _a2, _b;
              var suffix = context.text.substring(result.index + result.text.length);
              var match = TIMEZONE_NAME_PATTERN.exec(suffix);
              if (!match) {
                return;
              }
              var timezoneAbbr = match[1].toUpperCase();
              var refDate = (_b = (_a2 = result.start.date()) !== null && _a2 !== void 0 ? _a2 : result.refDate) !== null && _b !== void 0 ? _b : /* @__PURE__ */new Date();
              var tzOverrides = Object.assign(Object.assign({}, _this8.timezoneOverrides), timezoneOverrides);
              var extractedTimezoneOffset = (0, timezone_1.toTimezoneOffset)(timezoneAbbr, refDate, tzOverrides);
              if (extractedTimezoneOffset == null) {
                return;
              }
              context.debug(function () {
                console.log("Extracting timezone: '".concat(timezoneAbbr, "' into: ").concat(extractedTimezoneOffset, " for: ").concat(result.start));
              });
              var currentTimezoneOffset = result.start.get("timezoneOffset");
              if (currentTimezoneOffset !== null && extractedTimezoneOffset != currentTimezoneOffset) {
                if (result.start.isCertain("timezoneOffset")) {
                  return;
                }
                if (timezoneAbbr != match[1]) {
                  return;
                }
              }
              if (result.start.isOnlyDate()) {
                if (timezoneAbbr != match[1]) {
                  return;
                }
              }
              result.text += match[0];
              if (!result.start.isCertain("timezoneOffset")) {
                result.start.assign("timezoneOffset", extractedTimezoneOffset);
              }
              if (result.end != null && !result.end.isCertain("timezoneOffset")) {
                result.end.assign("timezoneOffset", extractedTimezoneOffset);
              }
            });
            return results;
          }
        }]);
      }();
      exports.default = ExtractTimezoneAbbrRefiner;
    }
  });

  // ../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/common/refiners/ExtractTimezoneOffsetRefiner.js
  var require_ExtractTimezoneOffsetRefiner = __commonJS({
    "../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/common/refiners/ExtractTimezoneOffsetRefiner.js": function _____tmp_codexChronoBuild_node_modules_chronoNode_dist_cjs_common_refiners_ExtractTimezoneOffsetRefinerJs(exports) {
      "use strict";

      Object.defineProperty(exports, "__esModule", {
        value: true
      });
      var TIMEZONE_OFFSET_PATTERN = new RegExp("^\\s*(?:\\(?(?:GMT|UTC)\\s?)?([+-])(\\d{1,2})(?::?(\\d{2}))?\\)?", "i");
      var TIMEZONE_OFFSET_SIGN_GROUP = 1;
      var TIMEZONE_OFFSET_HOUR_OFFSET_GROUP = 2;
      var TIMEZONE_OFFSET_MINUTE_OFFSET_GROUP = 3;
      var ExtractTimezoneOffsetRefiner = /*#__PURE__*/function () {
        function ExtractTimezoneOffsetRefiner() {
          _classCallCheck(this, ExtractTimezoneOffsetRefiner);
        }
        return _createClass(ExtractTimezoneOffsetRefiner, [{
          key: "refine",
          value: function refine(context, results) {
            results.forEach(function (result) {
              if (result.start.isCertain("timezoneOffset")) {
                return;
              }
              var suffix = context.text.substring(result.index + result.text.length);
              var match = TIMEZONE_OFFSET_PATTERN.exec(suffix);
              if (!match) {
                return;
              }
              context.debug(function () {
                console.log("Extracting timezone: '".concat(match[0], "' into : ").concat(result));
              });
              var hourOffset = parseInt(match[TIMEZONE_OFFSET_HOUR_OFFSET_GROUP]);
              var minuteOffset = parseInt(match[TIMEZONE_OFFSET_MINUTE_OFFSET_GROUP] || "0");
              var timezoneOffset = hourOffset * 60 + minuteOffset;
              if (timezoneOffset > 14 * 60) {
                return;
              }
              if (match[TIMEZONE_OFFSET_SIGN_GROUP] === "-") {
                timezoneOffset = -timezoneOffset;
              }
              if (result.end != null) {
                result.end.assign("timezoneOffset", timezoneOffset);
              }
              result.start.assign("timezoneOffset", timezoneOffset);
              result.text += match[0];
            });
            return results;
          }
        }]);
      }();
      exports.default = ExtractTimezoneOffsetRefiner;
    }
  });

  // ../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/common/refiners/OverlapRemovalRefiner.js
  var require_OverlapRemovalRefiner = __commonJS({
    "../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/common/refiners/OverlapRemovalRefiner.js": function _____tmp_codexChronoBuild_node_modules_chronoNode_dist_cjs_common_refiners_OverlapRemovalRefinerJs(exports) {
      "use strict";

      Object.defineProperty(exports, "__esModule", {
        value: true
      });
      var OverlapRemovalRefiner = /*#__PURE__*/function () {
        function OverlapRemovalRefiner() {
          _classCallCheck(this, OverlapRemovalRefiner);
        }
        return _createClass(OverlapRemovalRefiner, [{
          key: "refine",
          value: function refine(context, results) {
            var _this9 = this;
            if (results.length < 2) {
              return results;
            }
            var filteredResults = [];
            var prevResult = results[0];
            var _loop2 = function _loop2() {
              var result = results[i];
              if (result.index >= prevResult.index + prevResult.text.length) {
                filteredResults.push(prevResult);
                prevResult = result;
                return 1; // continue
              }
              var kept = null;
              var removed = null;
              if (result.text.length > prevResult.text.length) {
                kept = result;
                removed = prevResult;
              } else {
                kept = prevResult;
                removed = result;
              }
              context.debug(function () {
                console.log("".concat(_this9.constructor.name, " remove ").concat(removed, " by ").concat(kept));
              });
              prevResult = kept;
            };
            for (var i = 1; i < results.length; i++) {
              if (_loop2()) continue;
            }
            if (prevResult != null) {
              filteredResults.push(prevResult);
            }
            return filteredResults;
          }
        }]);
      }();
      exports.default = OverlapRemovalRefiner;
    }
  });

  // ../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/common/refiners/ForwardDateRefiner.js
  var require_ForwardDateRefiner = __commonJS({
    "../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/common/refiners/ForwardDateRefiner.js": function _____tmp_codexChronoBuild_node_modules_chronoNode_dist_cjs_common_refiners_ForwardDateRefinerJs(exports) {
      "use strict";

      var __createBinding = exports && exports.__createBinding || (Object.create ? function (o, m, k, k2) {
        if (k2 === void 0) k2 = k;
        var desc = Object.getOwnPropertyDescriptor(m, k);
        if (!desc || ("get" in desc ? !m.__esModule : desc.writable || desc.configurable)) {
          desc = {
            enumerable: true,
            get: function get() {
              return m[k];
            }
          };
        }
        Object.defineProperty(o, k2, desc);
      } : function (o, m, k, k2) {
        if (k2 === void 0) k2 = k;
        o[k2] = m[k];
      });
      var __setModuleDefault = exports && exports.__setModuleDefault || (Object.create ? function (o, v) {
        Object.defineProperty(o, "default", {
          enumerable: true,
          value: v
        });
      } : function (o, v) {
        o["default"] = v;
      });
      var __importStar = exports && exports.__importStar || /* @__PURE__ */function () {
        var _ownKeys = function ownKeys(o) {
          _ownKeys = Object.getOwnPropertyNames || function (o2) {
            var ar = [];
            for (var k in o2) if (Object.prototype.hasOwnProperty.call(o2, k)) ar[ar.length] = k;
            return ar;
          };
          return _ownKeys(o);
        };
        return function (mod) {
          if (mod && mod.__esModule) return mod;
          var result = {};
          if (mod != null) {
            for (var k = _ownKeys(mod), i = 0; i < k.length; i++) if (k[i] !== "default") __createBinding(result, mod, k[i]);
          }
          __setModuleDefault(result, mod);
          return result;
        };
      }();
      Object.defineProperty(exports, "__esModule", {
        value: true
      });
      var dates = __importStar(require_dates());
      var dates_1 = require_dates();
      var duration_1 = require_duration();
      var ForwardDateRefiner = /*#__PURE__*/function () {
        function ForwardDateRefiner() {
          _classCallCheck(this, ForwardDateRefiner);
        }
        return _createClass(ForwardDateRefiner, [{
          key: "refine",
          value: function refine(context, results) {
            var _this0 = this;
            if (!context.option.forwardDate) {
              return results;
            }
            results.forEach(function (result) {
              var refDate = context.reference.getDateWithAdjustedTimezone();
              if (result.start.isOnlyTime() && context.reference.instant > result.start.date()) {
                var refDate2 = context.reference.getDateWithAdjustedTimezone();
                var refFollowingDay = new Date(refDate2);
                refFollowingDay.setDate(refFollowingDay.getDate() + 1);
                dates.implySimilarDate(result.start, refFollowingDay);
                context.debug(function () {
                  console.log("".concat(_this0.constructor.name, " adjusted ").concat(result, " time from the ref date (").concat(refDate2, ") to the following day (").concat(refFollowingDay, ")"));
                });
                if (result.end && result.end.isOnlyTime()) {
                  dates.implySimilarDate(result.end, refFollowingDay);
                  if (result.start.date() > result.end.date()) {
                    refFollowingDay.setDate(refFollowingDay.getDate() + 1);
                    dates.implySimilarDate(result.end, refFollowingDay);
                  }
                }
              }
              if (result.start.isOnlyWeekdayComponent() && refDate > result.start.date()) {
                var daysToAdd = result.start.get("weekday") - refDate.getDay();
                if (daysToAdd <= 0) {
                  daysToAdd += 7;
                }
                refDate = (0, duration_1.addDuration)(refDate, {
                  day: daysToAdd
                });
                (0, dates_1.implySimilarDate)(result.start, refDate);
                context.debug(function () {
                  console.log("".concat(_this0.constructor.name, " adjusted ").concat(result, " weekday (").concat(result.start, ")"));
                });
                if (result.end && result.end.isOnlyWeekdayComponent()) {
                  var daysToAdd2 = result.end.get("weekday") - refDate.getDay();
                  if (daysToAdd2 <= 0) {
                    daysToAdd2 += 7;
                  }
                  refDate = (0, duration_1.addDuration)(refDate, {
                    day: daysToAdd2
                  });
                  (0, dates_1.implySimilarDate)(result.end, refDate);
                  context.debug(function () {
                    console.log("".concat(_this0.constructor.name, " adjusted ").concat(result, " weekday (").concat(result.end, ")"));
                  });
                }
              }
              if (result.start.isDateWithUnknownYear() && refDate > result.start.date()) {
                for (var i = 0; i < 3 && refDate > result.start.date(); i++) {
                  result.start.imply("year", result.start.get("year") + 1);
                  context.debug(function () {
                    console.log("".concat(_this0.constructor.name, " adjusted ").concat(result, " year (").concat(result.start, ")"));
                  });
                  if (result.end && !result.end.isCertain("year")) {
                    result.end.imply("year", result.end.get("year") + 1);
                    context.debug(function () {
                      console.log("".concat(_this0.constructor.name, " adjusted ").concat(result, " month (").concat(result.start, ")"));
                    });
                  }
                }
              }
            });
            return results;
          }
        }]);
      }();
      exports.default = ForwardDateRefiner;
    }
  });

  // ../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/common/refiners/UnlikelyFormatFilter.js
  var require_UnlikelyFormatFilter = __commonJS({
    "../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/common/refiners/UnlikelyFormatFilter.js": function _____tmp_codexChronoBuild_node_modules_chronoNode_dist_cjs_common_refiners_UnlikelyFormatFilterJs(exports) {
      "use strict";

      Object.defineProperty(exports, "__esModule", {
        value: true
      });
      var abstractRefiners_1 = require_abstractRefiners();
      var UnlikelyFormatFilter = /*#__PURE__*/function (_abstractRefiners_1$F) {
        function UnlikelyFormatFilter(strictMode) {
          var _this1;
          _classCallCheck(this, UnlikelyFormatFilter);
          _this1 = _callSuper(this, UnlikelyFormatFilter);
          _this1.strictMode = strictMode;
          return _this1;
        }
        _inherits(UnlikelyFormatFilter, _abstractRefiners_1$F);
        return _createClass(UnlikelyFormatFilter, [{
          key: "isValid",
          value: function isValid(context, result) {
            if (result.text.replace(" ", "").match(/^\d*(\.\d*)?$/)) {
              context.debug(function () {
                console.log("Removing unlikely result '".concat(result.text, "'"));
              });
              return false;
            }
            if (!result.start.isValidDate()) {
              context.debug(function () {
                console.log("Removing invalid result: ".concat(result, " (").concat(result.start, ")"));
              });
              return false;
            }
            if (result.end && !result.end.isValidDate()) {
              context.debug(function () {
                console.log("Removing invalid result: ".concat(result, " (").concat(result.end, ")"));
              });
              return false;
            }
            if (this.strictMode) {
              return this.isStrictModeValid(context, result);
            }
            return true;
          }
        }, {
          key: "isStrictModeValid",
          value: function isStrictModeValid(context, result) {
            if (result.start.isOnlyWeekdayComponent()) {
              context.debug(function () {
                console.log("(Strict) Removing weekday only component: ".concat(result, " (").concat(result.end, ")"));
              });
              return false;
            }
            return true;
          }
        }]);
      }(abstractRefiners_1.Filter);
      exports.default = UnlikelyFormatFilter;
    }
  });

  // ../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/common/parsers/ISOFormatParser.js
  var require_ISOFormatParser = __commonJS({
    "../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/common/parsers/ISOFormatParser.js": function _____tmp_codexChronoBuild_node_modules_chronoNode_dist_cjs_common_parsers_ISOFormatParserJs(exports) {
      "use strict";

      Object.defineProperty(exports, "__esModule", {
        value: true
      });
      var AbstractParserWithWordBoundary_1 = require_AbstractParserWithWordBoundary();
      var PATTERN = new RegExp("([0-9]{4})\\-([0-9]{1,2})\\-([0-9]{1,2})(?:T([0-9]{1,2}):([0-9]{1,2})(?::([0-9]{1,2})(?:\\.(\\d{1,4}))?)?(Z|([+-]\\d{2}):?(\\d{2})?)?)?(?=\\W|$)", "i");
      var YEAR_NUMBER_GROUP = 1;
      var MONTH_NUMBER_GROUP = 2;
      var DATE_NUMBER_GROUP = 3;
      var HOUR_NUMBER_GROUP = 4;
      var MINUTE_NUMBER_GROUP = 5;
      var SECOND_NUMBER_GROUP = 6;
      var MILLISECOND_NUMBER_GROUP = 7;
      var TZD_GROUP = 8;
      var TZD_HOUR_OFFSET_GROUP = 9;
      var TZD_MINUTE_OFFSET_GROUP = 10;
      var ISOFormatParser = /*#__PURE__*/function (_AbstractParserWithWo9) {
        function ISOFormatParser() {
          _classCallCheck(this, ISOFormatParser);
          return _callSuper(this, ISOFormatParser, arguments);
        }
        _inherits(ISOFormatParser, _AbstractParserWithWo9);
        return _createClass(ISOFormatParser, [{
          key: "innerPattern",
          value: function innerPattern() {
            return PATTERN;
          }
        }, {
          key: "innerExtract",
          value: function innerExtract(context, match) {
            var components = context.createParsingComponents({
              "year": parseInt(match[YEAR_NUMBER_GROUP]),
              "month": parseInt(match[MONTH_NUMBER_GROUP]),
              "day": parseInt(match[DATE_NUMBER_GROUP])
            });
            if (match[HOUR_NUMBER_GROUP] != null) {
              components.assign("hour", parseInt(match[HOUR_NUMBER_GROUP]));
              components.assign("minute", parseInt(match[MINUTE_NUMBER_GROUP]));
              if (match[SECOND_NUMBER_GROUP] != null) {
                components.assign("second", parseInt(match[SECOND_NUMBER_GROUP]));
              }
              if (match[MILLISECOND_NUMBER_GROUP] != null) {
                components.assign("millisecond", parseInt(match[MILLISECOND_NUMBER_GROUP]));
              }
              if (match[TZD_GROUP] != null) {
                var offset = 0;
                if (match[TZD_HOUR_OFFSET_GROUP]) {
                  var hourOffset = parseInt(match[TZD_HOUR_OFFSET_GROUP]);
                  var minuteOffset = 0;
                  if (match[TZD_MINUTE_OFFSET_GROUP] != null) {
                    minuteOffset = parseInt(match[TZD_MINUTE_OFFSET_GROUP]);
                  }
                  offset = hourOffset * 60;
                  if (offset < 0) {
                    offset -= minuteOffset;
                  } else {
                    offset += minuteOffset;
                  }
                }
                components.assign("timezoneOffset", offset);
              }
            }
            return components.addTag("parser/ISOFormatParser");
          }
        }]);
      }(AbstractParserWithWordBoundary_1.AbstractParserWithWordBoundaryChecking);
      exports.default = ISOFormatParser;
    }
  });

  // ../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/common/refiners/MergeWeekdayComponentRefiner.js
  var require_MergeWeekdayComponentRefiner = __commonJS({
    "../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/common/refiners/MergeWeekdayComponentRefiner.js": function _____tmp_codexChronoBuild_node_modules_chronoNode_dist_cjs_common_refiners_MergeWeekdayComponentRefinerJs(exports) {
      "use strict";

      Object.defineProperty(exports, "__esModule", {
        value: true
      });
      var abstractRefiners_1 = require_abstractRefiners();
      var MergeWeekdayComponentRefiner = /*#__PURE__*/function (_abstractRefiners_1$M3) {
        function MergeWeekdayComponentRefiner() {
          _classCallCheck(this, MergeWeekdayComponentRefiner);
          return _callSuper(this, MergeWeekdayComponentRefiner, arguments);
        }
        _inherits(MergeWeekdayComponentRefiner, _abstractRefiners_1$M3);
        return _createClass(MergeWeekdayComponentRefiner, [{
          key: "mergeResults",
          value: function mergeResults(textBetween, currentResult, nextResult) {
            var newResult = nextResult.clone();
            newResult.index = currentResult.index;
            newResult.text = currentResult.text + textBetween + newResult.text;
            newResult.start.assign("weekday", currentResult.start.get("weekday"));
            if (newResult.end) {
              newResult.end.assign("weekday", currentResult.start.get("weekday"));
            }
            return newResult;
          }
        }, {
          key: "shouldMergeResults",
          value: function shouldMergeResults(textBetween, currentResult, nextResult) {
            var weekdayThenNormalDate = currentResult.start.isOnlyWeekdayComponent() && !currentResult.start.isCertain("hour") && nextResult.start.isCertain("day");
            return weekdayThenNormalDate && textBetween.match(/^,?\s*$/) != null;
          }
        }]);
      }(abstractRefiners_1.MergingRefiner);
      exports.default = MergeWeekdayComponentRefiner;
    }
  });

  // ../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/configurations.js
  var require_configurations = __commonJS({
    "../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/configurations.js": function _____tmp_codexChronoBuild_node_modules_chronoNode_dist_cjs_configurationsJs(exports) {
      "use strict";

      var __importDefault = exports && exports.__importDefault || function (mod) {
        return mod && mod.__esModule ? mod : {
          "default": mod
        };
      };
      Object.defineProperty(exports, "__esModule", {
        value: true
      });
      exports.includeCommonConfiguration = includeCommonConfiguration;
      var ExtractTimezoneAbbrRefiner_1 = __importDefault(require_ExtractTimezoneAbbrRefiner());
      var ExtractTimezoneOffsetRefiner_1 = __importDefault(require_ExtractTimezoneOffsetRefiner());
      var OverlapRemovalRefiner_1 = __importDefault(require_OverlapRemovalRefiner());
      var ForwardDateRefiner_1 = __importDefault(require_ForwardDateRefiner());
      var UnlikelyFormatFilter_1 = __importDefault(require_UnlikelyFormatFilter());
      var ISOFormatParser_1 = __importDefault(require_ISOFormatParser());
      var MergeWeekdayComponentRefiner_1 = __importDefault(require_MergeWeekdayComponentRefiner());
      function includeCommonConfiguration(configuration) {
        var strictMode = arguments.length > 1 && arguments[1] !== undefined ? arguments[1] : false;
        configuration.parsers.unshift(new ISOFormatParser_1.default());
        configuration.refiners.unshift(new MergeWeekdayComponentRefiner_1.default());
        configuration.refiners.unshift(new ExtractTimezoneOffsetRefiner_1.default());
        configuration.refiners.unshift(new OverlapRemovalRefiner_1.default());
        configuration.refiners.push(new ExtractTimezoneAbbrRefiner_1.default());
        configuration.refiners.push(new OverlapRemovalRefiner_1.default());
        configuration.refiners.push(new ForwardDateRefiner_1.default());
        configuration.refiners.push(new UnlikelyFormatFilter_1.default(strictMode));
        return configuration;
      }
    }
  });

  // ../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/common/casualReferences.js
  var require_casualReferences = __commonJS({
    "../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/common/casualReferences.js": function _____tmp_codexChronoBuild_node_modules_chronoNode_dist_cjs_common_casualReferencesJs(exports) {
      "use strict";

      Object.defineProperty(exports, "__esModule", {
        value: true
      });
      exports.now = now;
      exports.today = today;
      exports.yesterday = yesterday;
      exports.tomorrow = tomorrow;
      exports.theDayBefore = theDayBefore;
      exports.theDayAfter = theDayAfter;
      exports.tonight = tonight;
      exports.lastNight = lastNight;
      exports.evening = evening;
      exports.yesterdayEvening = yesterdayEvening;
      exports.midnight = midnight;
      exports.morning = morning;
      exports.afternoon = afternoon;
      exports.noon = noon;
      var results_1 = require_results();
      var dates_1 = require_dates();
      var types_1 = require_types();
      function now(reference) {
        var targetDate = reference.getDateWithAdjustedTimezone();
        var component = new results_1.ParsingComponents(reference, {});
        (0, dates_1.assignSimilarDate)(component, targetDate);
        (0, dates_1.assignSimilarTime)(component, targetDate);
        component.assign("timezoneOffset", reference.getTimezoneOffset());
        component.addTag("casualReference/now");
        return component;
      }
      function today(reference) {
        var targetDate = reference.getDateWithAdjustedTimezone();
        var component = new results_1.ParsingComponents(reference, {});
        (0, dates_1.assignSimilarDate)(component, targetDate);
        (0, dates_1.implySimilarTime)(component, targetDate);
        component.delete("meridiem");
        component.addTag("casualReference/today");
        return component;
      }
      function yesterday(reference) {
        return theDayBefore(reference, 1).addTag("casualReference/yesterday");
      }
      function tomorrow(reference) {
        return theDayAfter(reference, 1).addTag("casualReference/tomorrow");
      }
      function theDayBefore(reference, numDay) {
        return theDayAfter(reference, -numDay);
      }
      function theDayAfter(reference, nDays) {
        var targetDate = reference.getDateWithAdjustedTimezone();
        var component = new results_1.ParsingComponents(reference, {});
        var newDate = new Date(targetDate.getTime());
        newDate.setDate(newDate.getDate() + nDays);
        (0, dates_1.assignSimilarDate)(component, newDate);
        (0, dates_1.implySimilarTime)(component, newDate);
        component.delete("meridiem");
        return component;
      }
      function tonight(reference) {
        var implyHour = arguments.length > 1 && arguments[1] !== undefined ? arguments[1] : 22;
        var targetDate = reference.getDateWithAdjustedTimezone();
        var component = new results_1.ParsingComponents(reference, {});
        (0, dates_1.assignSimilarDate)(component, targetDate);
        component.imply("hour", implyHour);
        component.imply("meridiem", types_1.Meridiem.PM);
        component.addTag("casualReference/tonight");
        return component;
      }
      function lastNight(reference) {
        var implyHour = arguments.length > 1 && arguments[1] !== undefined ? arguments[1] : 0;
        var targetDate = reference.getDateWithAdjustedTimezone();
        var component = new results_1.ParsingComponents(reference, {});
        if (targetDate.getHours() < 6) {
          targetDate = new Date(targetDate.getTime() - 24 * 60 * 60 * 1e3);
        }
        (0, dates_1.assignSimilarDate)(component, targetDate);
        component.imply("hour", implyHour);
        return component;
      }
      function evening(reference) {
        var implyHour = arguments.length > 1 && arguments[1] !== undefined ? arguments[1] : 20;
        var component = new results_1.ParsingComponents(reference, {});
        component.imply("meridiem", types_1.Meridiem.PM);
        component.imply("hour", implyHour);
        component.addTag("casualReference/evening");
        return component;
      }
      function yesterdayEvening(reference) {
        var implyHour = arguments.length > 1 && arguments[1] !== undefined ? arguments[1] : 20;
        var targetDate = reference.getDateWithAdjustedTimezone();
        var component = new results_1.ParsingComponents(reference, {});
        targetDate = new Date(targetDate.getTime() - 24 * 60 * 60 * 1e3);
        (0, dates_1.assignSimilarDate)(component, targetDate);
        component.imply("hour", implyHour);
        component.imply("meridiem", types_1.Meridiem.PM);
        component.addTag("casualReference/yesterday");
        component.addTag("casualReference/evening");
        return component;
      }
      function midnight(reference) {
        var component = new results_1.ParsingComponents(reference, {});
        if (reference.getDateWithAdjustedTimezone().getHours() > 2) {
          component.addDurationAsImplied({
            day: 1
          });
        }
        component.assign("hour", 0);
        component.imply("minute", 0);
        component.imply("second", 0);
        component.imply("millisecond", 0);
        component.addTag("casualReference/midnight");
        return component;
      }
      function morning(reference) {
        var implyHour = arguments.length > 1 && arguments[1] !== undefined ? arguments[1] : 6;
        var component = new results_1.ParsingComponents(reference, {});
        component.imply("meridiem", types_1.Meridiem.AM);
        component.imply("hour", implyHour);
        component.imply("minute", 0);
        component.imply("second", 0);
        component.imply("millisecond", 0);
        component.addTag("casualReference/morning");
        return component;
      }
      function afternoon(reference) {
        var implyHour = arguments.length > 1 && arguments[1] !== undefined ? arguments[1] : 15;
        var component = new results_1.ParsingComponents(reference, {});
        component.imply("meridiem", types_1.Meridiem.PM);
        component.imply("hour", implyHour);
        component.imply("minute", 0);
        component.imply("second", 0);
        component.imply("millisecond", 0);
        component.addTag("casualReference/afternoon");
        return component;
      }
      function noon(reference) {
        var component = new results_1.ParsingComponents(reference, {});
        component.imply("meridiem", types_1.Meridiem.AM);
        component.assign("hour", 12);
        component.imply("minute", 0);
        component.imply("second", 0);
        component.imply("millisecond", 0);
        component.addTag("casualReference/noon");
        return component;
      }
    }
  });

  // ../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/locales/en/parsers/ENCasualDateParser.js
  var require_ENCasualDateParser = __commonJS({
    "../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/locales/en/parsers/ENCasualDateParser.js": function _____tmp_codexChronoBuild_node_modules_chronoNode_dist_cjs_locales_en_parsers_ENCasualDateParserJs(exports) {
      "use strict";

      var __createBinding = exports && exports.__createBinding || (Object.create ? function (o, m, k, k2) {
        if (k2 === void 0) k2 = k;
        var desc = Object.getOwnPropertyDescriptor(m, k);
        if (!desc || ("get" in desc ? !m.__esModule : desc.writable || desc.configurable)) {
          desc = {
            enumerable: true,
            get: function get() {
              return m[k];
            }
          };
        }
        Object.defineProperty(o, k2, desc);
      } : function (o, m, k, k2) {
        if (k2 === void 0) k2 = k;
        o[k2] = m[k];
      });
      var __setModuleDefault = exports && exports.__setModuleDefault || (Object.create ? function (o, v) {
        Object.defineProperty(o, "default", {
          enumerable: true,
          value: v
        });
      } : function (o, v) {
        o["default"] = v;
      });
      var __importStar = exports && exports.__importStar || /* @__PURE__ */function () {
        var _ownKeys2 = function ownKeys(o) {
          _ownKeys2 = Object.getOwnPropertyNames || function (o2) {
            var ar = [];
            for (var k in o2) if (Object.prototype.hasOwnProperty.call(o2, k)) ar[ar.length] = k;
            return ar;
          };
          return _ownKeys2(o);
        };
        return function (mod) {
          if (mod && mod.__esModule) return mod;
          var result = {};
          if (mod != null) {
            for (var k = _ownKeys2(mod), i = 0; i < k.length; i++) if (k[i] !== "default") __createBinding(result, mod, k[i]);
          }
          __setModuleDefault(result, mod);
          return result;
        };
      }();
      Object.defineProperty(exports, "__esModule", {
        value: true
      });
      var AbstractParserWithWordBoundary_1 = require_AbstractParserWithWordBoundary();
      var dates_1 = require_dates();
      var references = __importStar(require_casualReferences());
      var PATTERN = /(now|today|tonight|tomorrow|overmorrow|tmr|tmrw|yesterday|last\s*night)(?=\W|$)/i;
      var ENCasualDateParser = /*#__PURE__*/function (_AbstractParserWithWo0) {
        function ENCasualDateParser() {
          _classCallCheck(this, ENCasualDateParser);
          return _callSuper(this, ENCasualDateParser, arguments);
        }
        _inherits(ENCasualDateParser, _AbstractParserWithWo0);
        return _createClass(ENCasualDateParser, [{
          key: "innerPattern",
          value: function innerPattern(context) {
            return PATTERN;
          }
        }, {
          key: "innerExtract",
          value: function innerExtract(context, match) {
            var targetDate = context.refDate;
            var lowerText = match[0].toLowerCase();
            var component = context.createParsingComponents();
            switch (lowerText) {
              case "now":
                component = references.now(context.reference);
                break;
              case "today":
                component = references.today(context.reference);
                break;
              case "yesterday":
                component = references.yesterday(context.reference);
                break;
              case "tomorrow":
              case "tmr":
              case "tmrw":
                component = references.tomorrow(context.reference);
                break;
              case "tonight":
                component = references.tonight(context.reference);
                break;
              case "overmorrow":
                component = references.theDayAfter(context.reference, 2);
                break;
              default:
                if (lowerText.match(/last\s*night/)) {
                  if (targetDate.getHours() > 6) {
                    var previousDay = new Date(targetDate.getTime());
                    previousDay.setDate(previousDay.getDate() - 1);
                    targetDate = previousDay;
                  }
                  (0, dates_1.assignSimilarDate)(component, targetDate);
                  component.imply("hour", 0);
                }
                break;
            }
            component.addTag("parser/ENCasualDateParser");
            return component;
          }
        }]);
      }(AbstractParserWithWordBoundary_1.AbstractParserWithWordBoundaryChecking);
      exports.default = ENCasualDateParser;
    }
  });

  // ../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/locales/en/parsers/ENCasualTimeParser.js
  var require_ENCasualTimeParser = __commonJS({
    "../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/locales/en/parsers/ENCasualTimeParser.js": function _____tmp_codexChronoBuild_node_modules_chronoNode_dist_cjs_locales_en_parsers_ENCasualTimeParserJs(exports) {
      "use strict";

      var __createBinding = exports && exports.__createBinding || (Object.create ? function (o, m, k, k2) {
        if (k2 === void 0) k2 = k;
        var desc = Object.getOwnPropertyDescriptor(m, k);
        if (!desc || ("get" in desc ? !m.__esModule : desc.writable || desc.configurable)) {
          desc = {
            enumerable: true,
            get: function get() {
              return m[k];
            }
          };
        }
        Object.defineProperty(o, k2, desc);
      } : function (o, m, k, k2) {
        if (k2 === void 0) k2 = k;
        o[k2] = m[k];
      });
      var __setModuleDefault = exports && exports.__setModuleDefault || (Object.create ? function (o, v) {
        Object.defineProperty(o, "default", {
          enumerable: true,
          value: v
        });
      } : function (o, v) {
        o["default"] = v;
      });
      var __importStar = exports && exports.__importStar || /* @__PURE__ */function () {
        var _ownKeys3 = function ownKeys(o) {
          _ownKeys3 = Object.getOwnPropertyNames || function (o2) {
            var ar = [];
            for (var k in o2) if (Object.prototype.hasOwnProperty.call(o2, k)) ar[ar.length] = k;
            return ar;
          };
          return _ownKeys3(o);
        };
        return function (mod) {
          if (mod && mod.__esModule) return mod;
          var result = {};
          if (mod != null) {
            for (var k = _ownKeys3(mod), i = 0; i < k.length; i++) if (k[i] !== "default") __createBinding(result, mod, k[i]);
          }
          __setModuleDefault(result, mod);
          return result;
        };
      }();
      Object.defineProperty(exports, "__esModule", {
        value: true
      });
      var AbstractParserWithWordBoundary_1 = require_AbstractParserWithWordBoundary();
      var casualReferences = __importStar(require_casualReferences());
      var PATTERN = /(?:this)?\s{0,3}(morning|afternoon|evening|night|midnight|midday|noon)(?=\W|$)/i;
      var ENCasualTimeParser = /*#__PURE__*/function (_AbstractParserWithWo1) {
        function ENCasualTimeParser() {
          _classCallCheck(this, ENCasualTimeParser);
          return _callSuper(this, ENCasualTimeParser, arguments);
        }
        _inherits(ENCasualTimeParser, _AbstractParserWithWo1);
        return _createClass(ENCasualTimeParser, [{
          key: "innerPattern",
          value: function innerPattern() {
            return PATTERN;
          }
        }, {
          key: "innerExtract",
          value: function innerExtract(context, match) {
            var component = null;
            switch (match[1].toLowerCase()) {
              case "afternoon":
                component = casualReferences.afternoon(context.reference);
                break;
              case "evening":
              case "night":
                component = casualReferences.evening(context.reference);
                break;
              case "midnight":
                component = casualReferences.midnight(context.reference);
                break;
              case "morning":
                component = casualReferences.morning(context.reference);
                break;
              case "noon":
              case "midday":
                component = casualReferences.noon(context.reference);
                break;
            }
            if (component) {
              component.addTag("parser/ENCasualTimeParser");
            }
            return component;
          }
        }]);
      }(AbstractParserWithWordBoundary_1.AbstractParserWithWordBoundaryChecking);
      exports.default = ENCasualTimeParser;
    }
  });

  // ../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/calculation/weekdays.js
  var require_weekdays = __commonJS({
    "../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/calculation/weekdays.js": function _____tmp_codexChronoBuild_node_modules_chronoNode_dist_cjs_calculation_weekdaysJs(exports) {
      "use strict";

      Object.defineProperty(exports, "__esModule", {
        value: true
      });
      exports.createParsingComponentsAtWeekday = createParsingComponentsAtWeekday;
      exports.getDaysToWeekday = getDaysToWeekday;
      exports.getDaysToWeekdayClosest = getDaysToWeekdayClosest;
      exports.getDaysForwardToWeekday = getDaysForwardToWeekday;
      exports.getBackwardDaysToWeekday = getBackwardDaysToWeekday;
      var types_1 = require_types();
      var results_1 = require_results();
      function createParsingComponentsAtWeekday(reference, weekday, modifier) {
        var refDate = reference.getDateWithAdjustedTimezone();
        var daysToWeekday = getDaysToWeekday(refDate, weekday, modifier);
        var components = new results_1.ParsingComponents(reference);
        components = components.addDurationAsImplied({
          day: daysToWeekday
        });
        components.assign("weekday", weekday);
        return components;
      }
      function getDaysToWeekday(refDate, weekday, modifier) {
        var refWeekday = refDate.getDay();
        switch (modifier) {
          case "this":
            return getDaysForwardToWeekday(refDate, weekday);
          case "last":
            return getBackwardDaysToWeekday(refDate, weekday);
          case "next":
            if (refWeekday == types_1.Weekday.SUNDAY) {
              return weekday == types_1.Weekday.SUNDAY ? 7 : weekday;
            }
            if (refWeekday == types_1.Weekday.SATURDAY) {
              if (weekday == types_1.Weekday.SATURDAY) return 7;
              if (weekday == types_1.Weekday.SUNDAY) return 8;
              return 1 + weekday;
            }
            if (weekday < refWeekday && weekday != types_1.Weekday.SUNDAY) {
              return getDaysForwardToWeekday(refDate, weekday);
            } else {
              return getDaysForwardToWeekday(refDate, weekday) + 7;
            }
        }
        return getDaysToWeekdayClosest(refDate, weekday);
      }
      function getDaysToWeekdayClosest(refDate, weekday) {
        var backward = getBackwardDaysToWeekday(refDate, weekday);
        var forward = getDaysForwardToWeekday(refDate, weekday);
        return forward < -backward ? forward : backward;
      }
      function getDaysForwardToWeekday(refDate, weekday) {
        var refWeekday = refDate.getDay();
        var forwardCount = weekday - refWeekday;
        if (forwardCount < 0) {
          forwardCount += 7;
        }
        return forwardCount;
      }
      function getBackwardDaysToWeekday(refDate, weekday) {
        var refWeekday = refDate.getDay();
        var backwardCount = weekday - refWeekday;
        if (backwardCount >= 0) {
          backwardCount -= 7;
        }
        return backwardCount;
      }
    }
  });

  // ../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/locales/en/parsers/ENWeekdayParser.js
  var require_ENWeekdayParser = __commonJS({
    "../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/locales/en/parsers/ENWeekdayParser.js": function _____tmp_codexChronoBuild_node_modules_chronoNode_dist_cjs_locales_en_parsers_ENWeekdayParserJs(exports) {
      "use strict";

      Object.defineProperty(exports, "__esModule", {
        value: true
      });
      var constants_1 = require_constants();
      var pattern_1 = require_pattern();
      var AbstractParserWithWordBoundary_1 = require_AbstractParserWithWordBoundary();
      var weekdays_1 = require_weekdays();
      var types_1 = require_types();
      var PATTERN = new RegExp("(?:(?:\\,|\\(|\\\uFF08)\\s*)?(?:on\\s*?)?(?:(this|last|past|next)\\s*)?(".concat((0, pattern_1.matchAnyPattern)(constants_1.WEEKDAY_DICTIONARY), "|weekend|weekday)(?:\\s*(?:\\,|\\)|\\\uFF09))?(?:\\s*(this|last|past|next)\\s*week)?(?=\\W|$)"), "i");
      var PREFIX_GROUP = 1;
      var WEEKDAY_GROUP = 2;
      var POSTFIX_GROUP = 3;
      var ENWeekdayParser = /*#__PURE__*/function (_AbstractParserWithWo10) {
        function ENWeekdayParser() {
          _classCallCheck(this, ENWeekdayParser);
          return _callSuper(this, ENWeekdayParser, arguments);
        }
        _inherits(ENWeekdayParser, _AbstractParserWithWo10);
        return _createClass(ENWeekdayParser, [{
          key: "innerPattern",
          value: function innerPattern() {
            return PATTERN;
          }
        }, {
          key: "innerExtract",
          value: function innerExtract(context, match) {
            var prefix = match[PREFIX_GROUP];
            var postfix = match[POSTFIX_GROUP];
            var modifierWord = prefix || postfix;
            modifierWord = modifierWord || "";
            modifierWord = modifierWord.toLowerCase();
            var modifier = null;
            if (modifierWord == "last" || modifierWord == "past") {
              modifier = "last";
            } else if (modifierWord == "next") {
              modifier = "next";
            } else if (modifierWord == "this") {
              modifier = "this";
            }
            var weekday_word = match[WEEKDAY_GROUP].toLowerCase();
            var weekday;
            if (constants_1.WEEKDAY_DICTIONARY[weekday_word] !== void 0) {
              weekday = constants_1.WEEKDAY_DICTIONARY[weekday_word];
            } else if (weekday_word == "weekend") {
              weekday = modifier == "last" ? types_1.Weekday.SUNDAY : types_1.Weekday.SATURDAY;
            } else if (weekday_word == "weekday") {
              var refWeekday = context.reference.getDateWithAdjustedTimezone().getDay();
              if (refWeekday == types_1.Weekday.SUNDAY || refWeekday == types_1.Weekday.SATURDAY) {
                weekday = modifier == "last" ? types_1.Weekday.FRIDAY : types_1.Weekday.MONDAY;
              } else {
                weekday = refWeekday - 1;
                weekday = modifier == "last" ? weekday - 1 : weekday + 1;
                weekday = weekday % 5 + 1;
              }
            } else {
              return null;
            }
            return (0, weekdays_1.createParsingComponentsAtWeekday)(context.reference, weekday, modifier);
          }
        }]);
      }(AbstractParserWithWordBoundary_1.AbstractParserWithWordBoundaryChecking);
      exports.default = ENWeekdayParser;
    }
  });

  // ../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/locales/en/parsers/ENRelativeDateFormatParser.js
  var require_ENRelativeDateFormatParser = __commonJS({
    "../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/locales/en/parsers/ENRelativeDateFormatParser.js": function _____tmp_codexChronoBuild_node_modules_chronoNode_dist_cjs_locales_en_parsers_ENRelativeDateFormatParserJs(exports) {
      "use strict";

      Object.defineProperty(exports, "__esModule", {
        value: true
      });
      var constants_1 = require_constants();
      var results_1 = require_results();
      var AbstractParserWithWordBoundary_1 = require_AbstractParserWithWordBoundary();
      var pattern_1 = require_pattern();
      var PATTERN = new RegExp("(this|last|past|next|after\\s*this)\\s*(".concat((0, pattern_1.matchAnyPattern)(constants_1.TIME_UNIT_DICTIONARY), ")(?=\\s*)(?=\\W|$)"), "i");
      var MODIFIER_WORD_GROUP = 1;
      var RELATIVE_WORD_GROUP = 2;
      var ENRelativeDateFormatParser = /*#__PURE__*/function (_AbstractParserWithWo11) {
        function ENRelativeDateFormatParser() {
          _classCallCheck(this, ENRelativeDateFormatParser);
          return _callSuper(this, ENRelativeDateFormatParser, arguments);
        }
        _inherits(ENRelativeDateFormatParser, _AbstractParserWithWo11);
        return _createClass(ENRelativeDateFormatParser, [{
          key: "innerPattern",
          value: function innerPattern() {
            return PATTERN;
          }
        }, {
          key: "innerExtract",
          value: function innerExtract(context, match) {
            var modifier = match[MODIFIER_WORD_GROUP].toLowerCase();
            var unitWord = match[RELATIVE_WORD_GROUP].toLowerCase();
            var timeunit = constants_1.TIME_UNIT_DICTIONARY[unitWord];
            if (modifier == "next" || modifier.startsWith("after")) {
              var timeUnits = {};
              timeUnits[timeunit] = 1;
              return results_1.ParsingComponents.createRelativeFromReference(context.reference, timeUnits);
            }
            if (modifier == "last" || modifier == "past") {
              var _timeUnits = {};
              _timeUnits[timeunit] = -1;
              return results_1.ParsingComponents.createRelativeFromReference(context.reference, _timeUnits);
            }
            var components = context.createParsingComponents();
            var date = new Date(context.reference.instant.getTime());
            if (unitWord.match(/week/i)) {
              date.setDate(date.getDate() - date.getDay());
              components.imply("day", date.getDate());
              components.imply("month", date.getMonth() + 1);
              components.imply("year", date.getFullYear());
            } else if (unitWord.match(/month/i)) {
              date.setDate(1);
              components.imply("day", date.getDate());
              components.assign("year", date.getFullYear());
              components.assign("month", date.getMonth() + 1);
            } else if (unitWord.match(/year/i)) {
              date.setDate(1);
              date.setMonth(0);
              components.imply("day", date.getDate());
              components.imply("month", date.getMonth() + 1);
              components.assign("year", date.getFullYear());
            }
            return components;
          }
        }]);
      }(AbstractParserWithWordBoundary_1.AbstractParserWithWordBoundaryChecking);
      exports.default = ENRelativeDateFormatParser;
    }
  });

  // ../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/common/parsers/SlashDateFormatParser.js
  var require_SlashDateFormatParser = __commonJS({
    "../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/common/parsers/SlashDateFormatParser.js": function _____tmp_codexChronoBuild_node_modules_chronoNode_dist_cjs_common_parsers_SlashDateFormatParserJs(exports) {
      "use strict";

      Object.defineProperty(exports, "__esModule", {
        value: true
      });
      var years_1 = require_years();
      var PATTERN = new RegExp("([^\\d]|^)([0-3]{0,1}[0-9]{1})[\\/\\.\\-]([0-3]{0,1}[0-9]{1})(?:[\\/\\.\\-]([0-9]{4}|[0-9]{2}))?(\\W|$)", "i");
      var OPENING_GROUP = 1;
      var ENDING_GROUP = 5;
      var FIRST_NUMBERS_GROUP = 2;
      var SECOND_NUMBERS_GROUP = 3;
      var YEAR_GROUP = 4;
      var SlashDateFormatParser = /*#__PURE__*/function () {
        function SlashDateFormatParser(littleEndian) {
          _classCallCheck(this, SlashDateFormatParser);
          this.groupNumberMonth = littleEndian ? SECOND_NUMBERS_GROUP : FIRST_NUMBERS_GROUP;
          this.groupNumberDay = littleEndian ? FIRST_NUMBERS_GROUP : SECOND_NUMBERS_GROUP;
        }
        return _createClass(SlashDateFormatParser, [{
          key: "pattern",
          value: function pattern() {
            return PATTERN;
          }
        }, {
          key: "extract",
          value: function extract(context, match) {
            var index = match.index + match[OPENING_GROUP].length;
            var indexEnd = match.index + match[0].length - match[ENDING_GROUP].length;
            if (index > 0) {
              var textBefore = context.text.substring(0, index);
              if (textBefore.match("\\d/?$")) {
                return;
              }
            }
            if (indexEnd < context.text.length) {
              var textAfter = context.text.substring(indexEnd);
              if (textAfter.match("^/?\\d")) {
                return;
              }
            }
            var text = context.text.substring(index, indexEnd);
            if (text.match(/^\d\.\d$/) || text.match(/^\d\.\d{1,2}\.\d{1,2}\s*$/)) {
              return;
            }
            if (!match[YEAR_GROUP] && text.indexOf("/") < 0) {
              return;
            }
            var result = context.createParsingResult(index, text);
            var month = parseInt(match[this.groupNumberMonth]);
            var day = parseInt(match[this.groupNumberDay]);
            if (month < 1 || month > 12) {
              if (month > 12) {
                if (day >= 1 && day <= 12 && month <= 31) {
                  var _ref3 = [month, day];
                  day = _ref3[0];
                  month = _ref3[1];
                } else {
                  return null;
                }
              }
            }
            if (day < 1 || day > 31) {
              return null;
            }
            result.start.assign("day", day);
            result.start.assign("month", month);
            if (match[YEAR_GROUP]) {
              var rawYearNumber = parseInt(match[YEAR_GROUP]);
              var year = (0, years_1.findMostLikelyADYear)(rawYearNumber);
              result.start.assign("year", year);
            } else {
              var _year3 = (0, years_1.findYearClosestToRef)(context.refDate, day, month);
              result.start.imply("year", _year3);
            }
            return result.addTag("parser/SlashDateFormatParser");
          }
        }]);
      }();
      exports.default = SlashDateFormatParser;
    }
  });

  // ../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/locales/en/parsers/ENTimeUnitCasualRelativeFormatParser.js
  var require_ENTimeUnitCasualRelativeFormatParser = __commonJS({
    "../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/locales/en/parsers/ENTimeUnitCasualRelativeFormatParser.js": function _____tmp_codexChronoBuild_node_modules_chronoNode_dist_cjs_locales_en_parsers_ENTimeUnitCasualRelativeFormatParserJs(exports) {
      "use strict";

      Object.defineProperty(exports, "__esModule", {
        value: true
      });
      var constants_1 = require_constants();
      var results_1 = require_results();
      var AbstractParserWithWordBoundary_1 = require_AbstractParserWithWordBoundary();
      var duration_1 = require_duration();
      var PATTERN = new RegExp("(this|last|past|next|after|\\+|-)\\s*(".concat(constants_1.TIME_UNITS_PATTERN, ")(?=\\W|$)"), "i");
      var PATTERN_NO_ABBR = new RegExp("(this|last|past|next|after|\\+|-)\\s*(".concat(constants_1.TIME_UNITS_NO_ABBR_PATTERN, ")(?=\\W|$)"), "i");
      var ENTimeUnitCasualRelativeFormatParser = /*#__PURE__*/function (_AbstractParserWithWo12) {
        function ENTimeUnitCasualRelativeFormatParser() {
          var _this10;
          var allowAbbreviations = arguments.length > 0 && arguments[0] !== undefined ? arguments[0] : true;
          _classCallCheck(this, ENTimeUnitCasualRelativeFormatParser);
          _this10 = _callSuper(this, ENTimeUnitCasualRelativeFormatParser);
          _this10.allowAbbreviations = allowAbbreviations;
          return _this10;
        }
        _inherits(ENTimeUnitCasualRelativeFormatParser, _AbstractParserWithWo12);
        return _createClass(ENTimeUnitCasualRelativeFormatParser, [{
          key: "innerPattern",
          value: function innerPattern() {
            return this.allowAbbreviations ? PATTERN : PATTERN_NO_ABBR;
          }
        }, {
          key: "innerExtract",
          value: function innerExtract(context, match) {
            var prefix = match[1].toLowerCase();
            var duration = (0, constants_1.parseDuration)(match[2]);
            if (!duration) {
              return null;
            }
            switch (prefix) {
              case "last":
              case "past":
              case "-":
                duration = (0, duration_1.reverseDuration)(duration);
                break;
            }
            return results_1.ParsingComponents.createRelativeFromReference(context.reference, duration);
          }
        }]);
      }(AbstractParserWithWordBoundary_1.AbstractParserWithWordBoundaryChecking);
      exports.default = ENTimeUnitCasualRelativeFormatParser;
    }
  });

  // ../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/locales/en/refiners/ENMergeRelativeAfterDateRefiner.js
  var require_ENMergeRelativeAfterDateRefiner = __commonJS({
    "../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/locales/en/refiners/ENMergeRelativeAfterDateRefiner.js": function _____tmp_codexChronoBuild_node_modules_chronoNode_dist_cjs_locales_en_refiners_ENMergeRelativeAfterDateRefinerJs(exports) {
      "use strict";

      Object.defineProperty(exports, "__esModule", {
        value: true
      });
      var abstractRefiners_1 = require_abstractRefiners();
      var results_1 = require_results();
      var constants_1 = require_constants();
      var duration_1 = require_duration();
      function IsPositiveFollowingReference(result) {
        return result.text.match(/^[+-]/i) != null;
      }
      function IsNegativeFollowingReference(result) {
        return result.text.match(/^-/i) != null;
      }
      var ENMergeRelativeAfterDateRefiner = /*#__PURE__*/function (_abstractRefiners_1$M4) {
        function ENMergeRelativeAfterDateRefiner() {
          _classCallCheck(this, ENMergeRelativeAfterDateRefiner);
          return _callSuper(this, ENMergeRelativeAfterDateRefiner, arguments);
        }
        _inherits(ENMergeRelativeAfterDateRefiner, _abstractRefiners_1$M4);
        return _createClass(ENMergeRelativeAfterDateRefiner, [{
          key: "shouldMergeResults",
          value: function shouldMergeResults(textBetween, currentResult, nextResult) {
            if (!textBetween.match(/^\s*$/i)) {
              return false;
            }
            return IsPositiveFollowingReference(nextResult) || IsNegativeFollowingReference(nextResult);
          }
        }, {
          key: "mergeResults",
          value: function mergeResults(textBetween, currentResult, nextResult, context) {
            var timeUnits = (0, constants_1.parseDuration)(nextResult.text);
            if (IsNegativeFollowingReference(nextResult)) {
              timeUnits = (0, duration_1.reverseDuration)(timeUnits);
            }
            var components = results_1.ParsingComponents.createRelativeFromReference(results_1.ReferenceWithTimezone.fromDate(currentResult.start.date()), timeUnits);
            return new results_1.ParsingResult(currentResult.reference, currentResult.index, "".concat(currentResult.text).concat(textBetween).concat(nextResult.text), components);
          }
        }]);
      }(abstractRefiners_1.MergingRefiner);
      exports.default = ENMergeRelativeAfterDateRefiner;
    }
  });

  // ../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/locales/en/refiners/ENMergeRelativeFollowByDateRefiner.js
  var require_ENMergeRelativeFollowByDateRefiner = __commonJS({
    "../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/locales/en/refiners/ENMergeRelativeFollowByDateRefiner.js": function _____tmp_codexChronoBuild_node_modules_chronoNode_dist_cjs_locales_en_refiners_ENMergeRelativeFollowByDateRefinerJs(exports) {
      "use strict";

      Object.defineProperty(exports, "__esModule", {
        value: true
      });
      var abstractRefiners_1 = require_abstractRefiners();
      var results_1 = require_results();
      var constants_1 = require_constants();
      var duration_1 = require_duration();
      function hasImpliedEarlierReferenceDate(result) {
        return result.text.match(/\s+(before|from)$/i) != null;
      }
      function hasImpliedLaterReferenceDate(result) {
        return result.text.match(/\s+(after|since)$/i) != null;
      }
      var ENMergeRelativeFollowByDateRefiner = /*#__PURE__*/function (_abstractRefiners_1$M5) {
        function ENMergeRelativeFollowByDateRefiner() {
          _classCallCheck(this, ENMergeRelativeFollowByDateRefiner);
          return _callSuper(this, ENMergeRelativeFollowByDateRefiner, arguments);
        }
        _inherits(ENMergeRelativeFollowByDateRefiner, _abstractRefiners_1$M5);
        return _createClass(ENMergeRelativeFollowByDateRefiner, [{
          key: "patternBetween",
          value: function patternBetween() {
            return /^\s*$/i;
          }
        }, {
          key: "shouldMergeResults",
          value: function shouldMergeResults(textBetween, currentResult, nextResult) {
            if (!textBetween.match(this.patternBetween())) {
              return false;
            }
            if (!hasImpliedEarlierReferenceDate(currentResult) && !hasImpliedLaterReferenceDate(currentResult)) {
              return false;
            }
            return !!nextResult.start.get("day") && !!nextResult.start.get("month") && !!nextResult.start.get("year");
          }
        }, {
          key: "mergeResults",
          value: function mergeResults(textBetween, currentResult, nextResult) {
            var duration = (0, constants_1.parseDuration)(currentResult.text);
            if (hasImpliedEarlierReferenceDate(currentResult)) {
              duration = (0, duration_1.reverseDuration)(duration);
            }
            var components = results_1.ParsingComponents.createRelativeFromReference(results_1.ReferenceWithTimezone.fromDate(nextResult.start.date()), duration);
            return new results_1.ParsingResult(nextResult.reference, currentResult.index, "".concat(currentResult.text).concat(textBetween).concat(nextResult.text), components);
          }
        }]);
      }(abstractRefiners_1.MergingRefiner);
      exports.default = ENMergeRelativeFollowByDateRefiner;
    }
  });

  // ../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/locales/en/refiners/ENExtractYearSuffixRefiner.js
  var require_ENExtractYearSuffixRefiner = __commonJS({
    "../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/locales/en/refiners/ENExtractYearSuffixRefiner.js": function _____tmp_codexChronoBuild_node_modules_chronoNode_dist_cjs_locales_en_refiners_ENExtractYearSuffixRefinerJs(exports) {
      "use strict";

      Object.defineProperty(exports, "__esModule", {
        value: true
      });
      var constants_1 = require_constants();
      var YEAR_SUFFIX_PATTERN = new RegExp("^\\s*(".concat(constants_1.YEAR_PATTERN, ")"), "i");
      var YEAR_GROUP = 1;
      var ENExtractYearSuffixRefiner = /*#__PURE__*/function () {
        function ENExtractYearSuffixRefiner() {
          _classCallCheck(this, ENExtractYearSuffixRefiner);
        }
        return _createClass(ENExtractYearSuffixRefiner, [{
          key: "refine",
          value: function refine(context, results) {
            results.forEach(function (result) {
              if (!result.start.isDateWithUnknownYear()) {
                return;
              }
              var suffix = context.text.substring(result.index + result.text.length);
              var match = YEAR_SUFFIX_PATTERN.exec(suffix);
              if (!match) {
                return;
              }
              if (match[0].trim().length <= 3) {
                return;
              }
              context.debug(function () {
                console.log("Extracting year: '".concat(match[0], "' into : ").concat(result));
              });
              var year = (0, constants_1.parseYear)(match[YEAR_GROUP]);
              if (result.end != null) {
                result.end.assign("year", year);
              }
              result.start.assign("year", year);
              result.text += match[0];
            });
            return results;
          }
        }]);
      }();
      exports.default = ENExtractYearSuffixRefiner;
    }
  });

  // ../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/locales/en/refiners/ENUnlikelyFormatFilter.js
  var require_ENUnlikelyFormatFilter = __commonJS({
    "../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/locales/en/refiners/ENUnlikelyFormatFilter.js": function _____tmp_codexChronoBuild_node_modules_chronoNode_dist_cjs_locales_en_refiners_ENUnlikelyFormatFilterJs(exports) {
      "use strict";

      Object.defineProperty(exports, "__esModule", {
        value: true
      });
      var abstractRefiners_1 = require_abstractRefiners();
      var ENUnlikelyFormatFilter = /*#__PURE__*/function (_abstractRefiners_1$F2) {
        function ENUnlikelyFormatFilter() {
          _classCallCheck(this, ENUnlikelyFormatFilter);
          return _callSuper(this, ENUnlikelyFormatFilter);
        }
        _inherits(ENUnlikelyFormatFilter, _abstractRefiners_1$F2);
        return _createClass(ENUnlikelyFormatFilter, [{
          key: "isValid",
          value: function isValid(context, result) {
            var text = result.text.trim();
            if (text === context.text.trim()) {
              return true;
            }
            if (text.toLowerCase() === "may") {
              var textBefore = context.text.substring(0, result.index).trim();
              if (!textBefore.match(/\b(in)$/i)) {
                context.debug(function () {
                  console.log("Removing unlikely result: ".concat(result));
                });
                return false;
              }
            }
            if (text.toLowerCase().endsWith("the second")) {
              var textAfter = context.text.substring(result.index + result.text.length).trim();
              if (textAfter.length > 0) {
                context.debug(function () {
                  console.log("Removing unlikely result: ".concat(result));
                });
              }
              return false;
            }
            return true;
          }
        }]);
      }(abstractRefiners_1.Filter);
      exports.default = ENUnlikelyFormatFilter;
    }
  });

  // ../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/locales/en/configuration.js
  var require_configuration = __commonJS({
    "../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/locales/en/configuration.js": function _____tmp_codexChronoBuild_node_modules_chronoNode_dist_cjs_locales_en_configurationJs(exports) {
      "use strict";

      var __importDefault = exports && exports.__importDefault || function (mod) {
        return mod && mod.__esModule ? mod : {
          "default": mod
        };
      };
      Object.defineProperty(exports, "__esModule", {
        value: true
      });
      var ENTimeUnitWithinFormatParser_1 = __importDefault(require_ENTimeUnitWithinFormatParser());
      var ENMonthNameLittleEndianParser_1 = __importDefault(require_ENMonthNameLittleEndianParser());
      var ENMonthNameMiddleEndianParser_1 = __importDefault(require_ENMonthNameMiddleEndianParser());
      var ENMonthNameParser_1 = __importDefault(require_ENMonthNameParser());
      var ENYearMonthDayParser_1 = __importDefault(require_ENYearMonthDayParser());
      var ENSlashMonthFormatParser_1 = __importDefault(require_ENSlashMonthFormatParser());
      var ENTimeExpressionParser_1 = __importDefault(require_ENTimeExpressionParser());
      var ENTimeUnitAgoFormatParser_1 = __importDefault(require_ENTimeUnitAgoFormatParser());
      var ENTimeUnitLaterFormatParser_1 = __importDefault(require_ENTimeUnitLaterFormatParser());
      var ENMergeDateRangeRefiner_1 = __importDefault(require_ENMergeDateRangeRefiner());
      var ENMergeDateTimeRefiner_1 = __importDefault(require_ENMergeDateTimeRefiner());
      var configurations_1 = require_configurations();
      var ENCasualDateParser_1 = __importDefault(require_ENCasualDateParser());
      var ENCasualTimeParser_1 = __importDefault(require_ENCasualTimeParser());
      var ENWeekdayParser_1 = __importDefault(require_ENWeekdayParser());
      var ENRelativeDateFormatParser_1 = __importDefault(require_ENRelativeDateFormatParser());
      var SlashDateFormatParser_1 = __importDefault(require_SlashDateFormatParser());
      var ENTimeUnitCasualRelativeFormatParser_1 = __importDefault(require_ENTimeUnitCasualRelativeFormatParser());
      var ENMergeRelativeAfterDateRefiner_1 = __importDefault(require_ENMergeRelativeAfterDateRefiner());
      var ENMergeRelativeFollowByDateRefiner_1 = __importDefault(require_ENMergeRelativeFollowByDateRefiner());
      var OverlapRemovalRefiner_1 = __importDefault(require_OverlapRemovalRefiner());
      var ENExtractYearSuffixRefiner_1 = __importDefault(require_ENExtractYearSuffixRefiner());
      var ENUnlikelyFormatFilter_1 = __importDefault(require_ENUnlikelyFormatFilter());
      var ENDefaultConfiguration = /*#__PURE__*/function () {
        function ENDefaultConfiguration() {
          _classCallCheck(this, ENDefaultConfiguration);
        }
        return _createClass(ENDefaultConfiguration, [{
          key: "createCasualConfiguration",
          value: function createCasualConfiguration() {
            var littleEndian = arguments.length > 0 && arguments[0] !== undefined ? arguments[0] : false;
            var option = this.createConfiguration(false, littleEndian);
            option.parsers.push(new ENCasualDateParser_1.default());
            option.parsers.push(new ENCasualTimeParser_1.default());
            option.parsers.push(new ENMonthNameParser_1.default());
            option.parsers.push(new ENRelativeDateFormatParser_1.default());
            option.parsers.push(new ENTimeUnitCasualRelativeFormatParser_1.default());
            option.refiners.push(new ENUnlikelyFormatFilter_1.default());
            return option;
          }
        }, {
          key: "createConfiguration",
          value: function createConfiguration() {
            var strictMode = arguments.length > 0 && arguments[0] !== undefined ? arguments[0] : true;
            var littleEndian = arguments.length > 1 && arguments[1] !== undefined ? arguments[1] : false;
            var options = (0, configurations_1.includeCommonConfiguration)({
              parsers: [new SlashDateFormatParser_1.default(littleEndian), new ENTimeUnitWithinFormatParser_1.default(strictMode), new ENMonthNameLittleEndianParser_1.default(), new ENMonthNameMiddleEndianParser_1.default(littleEndian), new ENWeekdayParser_1.default(), new ENSlashMonthFormatParser_1.default(), new ENTimeExpressionParser_1.default(strictMode), new ENTimeUnitAgoFormatParser_1.default(strictMode), new ENTimeUnitLaterFormatParser_1.default(strictMode)],
              refiners: [new ENMergeDateTimeRefiner_1.default()]
            }, strictMode);
            options.parsers.unshift(new ENYearMonthDayParser_1.default(strictMode));
            options.refiners.unshift(new ENMergeRelativeFollowByDateRefiner_1.default());
            options.refiners.unshift(new ENMergeRelativeAfterDateRefiner_1.default());
            options.refiners.unshift(new OverlapRemovalRefiner_1.default());
            options.refiners.push(new ENMergeDateTimeRefiner_1.default());
            options.refiners.push(new ENExtractYearSuffixRefiner_1.default());
            options.refiners.push(new ENMergeDateRangeRefiner_1.default());
            return options;
          }
        }]);
      }();
      exports.default = ENDefaultConfiguration;
    }
  });

  // ../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/chrono.js
  var require_chrono = __commonJS({
    "../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/chrono.js": function _____tmp_codexChronoBuild_node_modules_chronoNode_dist_cjs_chronoJs(exports) {
      "use strict";

      var __importDefault = exports && exports.__importDefault || function (mod) {
        return mod && mod.__esModule ? mod : {
          "default": mod
        };
      };
      Object.defineProperty(exports, "__esModule", {
        value: true
      });
      exports.ParsingContext = exports.Chrono = void 0;
      var results_1 = require_results();
      var configuration_1 = __importDefault(require_configuration());
      var Chrono = /*#__PURE__*/function () {
        function _Chrono(configuration) {
          _classCallCheck(this, _Chrono);
          this.defaultConfig = new configuration_1.default();
          configuration = configuration || this.defaultConfig.createCasualConfiguration();
          this.parsers = _toConsumableArray(configuration.parsers);
          this.refiners = _toConsumableArray(configuration.refiners);
        }
        return _createClass(_Chrono, [{
          key: "clone",
          value: function clone() {
            return new _Chrono({
              parsers: _toConsumableArray(this.parsers),
              refiners: _toConsumableArray(this.refiners)
            });
          }
        }, {
          key: "parseDate",
          value: function parseDate(text, referenceDate, option) {
            var results = this.parse(text, referenceDate, option);
            return results.length > 0 ? results[0].start.date() : null;
          }
        }, {
          key: "parse",
          value: function parse(text, referenceDate, option) {
            var context = new ParsingContext(text, referenceDate, option);
            var results = [];
            this.parsers.forEach(function (parser) {
              var parsedResults = _Chrono.executeParser(context, parser);
              results = results.concat(parsedResults);
            });
            results.sort(function (a, b) {
              return a.index - b.index;
            });
            this.refiners.forEach(function (refiner) {
              results = refiner.refine(context, results);
            });
            return results;
          }
        }], [{
          key: "executeParser",
          value: function executeParser(context, parser) {
            var results = [];
            var pattern = parser.pattern(context);
            var originalText = context.text;
            var remainingText = context.text;
            var match = pattern.exec(remainingText);
            var _loop3 = function _loop3() {
              var index = match.index + originalText.length - remainingText.length;
              match.index = index;
              var result = parser.extract(context, match);
              if (!result) {
                remainingText = originalText.substring(match.index + 1);
                match = pattern.exec(remainingText);
                return 1; // continue
              }
              var parsedResult = null;
              if (result instanceof results_1.ParsingResult) {
                parsedResult = result;
              } else if (result instanceof results_1.ParsingComponents) {
                parsedResult = context.createParsingResult(match.index, match[0]);
                parsedResult.start = result;
              } else {
                parsedResult = context.createParsingResult(match.index, match[0], result);
              }
              var parsedIndex = parsedResult.index;
              var parsedText = parsedResult.text;
              context.debug(function () {
                return console.log("".concat(parser.constructor.name, " extracted (at index=").concat(parsedIndex, ") '").concat(parsedText, "'"));
              });
              results.push(parsedResult);
              remainingText = originalText.substring(parsedIndex + parsedText.length);
              match = pattern.exec(remainingText);
            };
            while (match) {
              if (_loop3()) continue;
            }
            return results;
          }
        }]);
      }();
      exports.Chrono = Chrono;
      var ParsingContext = /*#__PURE__*/function () {
        function ParsingContext(text, refDate, option) {
          _classCallCheck(this, ParsingContext);
          this.text = text;
          this.option = option !== null && option !== void 0 ? option : {};
          this.reference = results_1.ReferenceWithTimezone.fromInput(refDate, this.option.timezones);
          this.refDate = this.reference.instant;
        }
        return _createClass(ParsingContext, [{
          key: "createParsingComponents",
          value: function createParsingComponents(components) {
            if (components instanceof results_1.ParsingComponents) {
              return components;
            }
            return new results_1.ParsingComponents(this.reference, components);
          }
        }, {
          key: "createParsingResult",
          value: function createParsingResult(index, textOrEndIndex, startComponents, endComponents) {
            var text = typeof textOrEndIndex === "string" ? textOrEndIndex : this.text.substring(index, textOrEndIndex);
            var start = startComponents ? this.createParsingComponents(startComponents) : null;
            var end = endComponents ? this.createParsingComponents(endComponents) : null;
            return new results_1.ParsingResult(this.reference, index, text, start, end);
          }
        }, {
          key: "debug",
          value: function debug(block) {
            if (this.option.debug) {
              if (this.option.debug instanceof Function) {
                this.option.debug(block);
              } else {
                var handler = this.option.debug;
                handler.debug(block);
              }
            }
          }
        }]);
      }();
      exports.ParsingContext = ParsingContext;
    }
  });

  // ../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/locales/en/index.js
  var require_en = __commonJS({
    "../../../../../tmp/codex-chrono-build/node_modules/chrono-node/dist/cjs/locales/en/index.js": function _____tmp_codexChronoBuild_node_modules_chronoNode_dist_cjs_locales_en_indexJs(exports) {
      "use strict";

      var __importDefault = exports && exports.__importDefault || function (mod) {
        return mod && mod.__esModule ? mod : {
          "default": mod
        };
      };
      Object.defineProperty(exports, "__esModule", {
        value: true
      });
      exports.GB = exports.strict = exports.casual = exports.configuration = exports.Weekday = exports.Meridiem = exports.ReferenceWithTimezone = exports.ParsingComponents = exports.ParsingResult = exports.Chrono = void 0;
      exports.parse = parse;
      exports.parseDate = parseDate;
      var chrono_1 = require_chrono();
      Object.defineProperty(exports, "Chrono", {
        enumerable: true,
        get: function get() {
          return chrono_1.Chrono;
        }
      });
      var results_1 = require_results();
      Object.defineProperty(exports, "ParsingResult", {
        enumerable: true,
        get: function get() {
          return results_1.ParsingResult;
        }
      });
      Object.defineProperty(exports, "ParsingComponents", {
        enumerable: true,
        get: function get() {
          return results_1.ParsingComponents;
        }
      });
      Object.defineProperty(exports, "ReferenceWithTimezone", {
        enumerable: true,
        get: function get() {
          return results_1.ReferenceWithTimezone;
        }
      });
      var types_1 = require_types();
      Object.defineProperty(exports, "Meridiem", {
        enumerable: true,
        get: function get() {
          return types_1.Meridiem;
        }
      });
      Object.defineProperty(exports, "Weekday", {
        enumerable: true,
        get: function get() {
          return types_1.Weekday;
        }
      });
      var configuration_1 = __importDefault(require_configuration());
      exports.configuration = new configuration_1.default();
      exports.casual = new chrono_1.Chrono(exports.configuration.createCasualConfiguration(false));
      exports.strict = new chrono_1.Chrono(exports.configuration.createConfiguration(true, false));
      exports.GB = new chrono_1.Chrono(exports.configuration.createCasualConfiguration(true));
      function parse(text, ref, option) {
        return exports.casual.parse(text, ref, option);
      }
      function parseDate(text, ref, option) {
        return exports.casual.parseDate(text, ref, option);
      }
    }
  });

  // ../../../../../tmp/codex-chrono-build/chrono-qml-entry.js
  var chrono = require_en();
  var root = Function("return this")();
  root.ChronoBridge = {
    parseComponents: function parseComponents(text, referenceEpochMs, timezoneOffsetMinutes) {
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
      var out = {
        text: results[0].text
      };
      for (var i = 0; i < fields.length; i++) {
        var field = fields[i];
        var value = start.get(field);
        if (value !== null && value !== void 0) {
          out[field] = value;
        }
        out[field + "Certain"] = start.isCertain(field);
      }
      return out;
    }
  };
})();