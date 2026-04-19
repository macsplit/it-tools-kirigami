#include <QApplication>
#include <QDir>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMetaObject>
#include <QQmlComponent>
#include <QQmlContext>
#include <QQmlEngine>
#include <QRegularExpression>
#include <QtTest>
#include <memory>

#include "basetool.h"
#include "conversiontool.h"
#include "hashtool.h"
#include "networktool.h"
#include "qrcodetool.h"
#include "timetool.h"
#include "mathtool.h"
#include "idtool.h"
#include "texttool.h"
#include "crontool.h"
#include "mimetool.h"
#include "toolmanager.h"
#include "urltool.h"

class ToolsTest : public QObject
{
    Q_OBJECT

private slots:
    void backendDatasets();
    void qmlFunctionDatasets();
    void qmlSmokeLoadsAllToolPages();

private:
    QString dataPath(const QString &fileName) const;
    QJsonObject loadJsonObject(const QString &fileName) const;
    QVariant invokeBackend(const QString &toolName,
                           const QString &methodName,
                           const QJsonArray &args) const;
    QVariant invokeQmlFunction(const QString &pagePath,
                               const QString &functionName,
                               const QJsonArray &args) const;
    QQmlEngine *createConfiguredEngine(QObject *parent) const;
    QString variantAsText(const QVariant &value) const;
    void assertVariantMatches(const QVariant &actual,
                              const QJsonObject &expectation,
                              const QString &caseName) const;
};

QString ToolsTest::dataPath(const QString &fileName) const {
    return QDir(QStringLiteral(TOOLS_TEST_SOURCE_DIR)).filePath(QStringLiteral("tests/data/") + fileName);
}

QJsonObject ToolsTest::loadJsonObject(const QString &fileName) const {
    QFile file(dataPath(fileName));
    if (!file.open(QIODevice::ReadOnly)) {
        QTest::qFail(qPrintable(QStringLiteral("Failed to open %1").arg(file.fileName())), __FILE__, __LINE__);
        return QJsonObject();
    }

    QJsonParseError error;
    const QJsonDocument document = QJsonDocument::fromJson(file.readAll(), &error);
    if (error.error != QJsonParseError::NoError) {
        QTest::qFail(qPrintable(error.errorString()), __FILE__, __LINE__);
        return QJsonObject();
    }
    if (!document.isObject()) {
        QTest::qFail("Expected JSON object", __FILE__, __LINE__);
        return QJsonObject();
    }
    return document.object();
}

QVariant ToolsTest::invokeBackend(const QString &toolName,
                                  const QString &methodName,
                                  const QJsonArray &args) const {
    static HashTool hashTool;
    static BaseTool baseTool;
    static UrlTool urlTool;
    static NetworkTool networkTool;
    static TimeTool timeTool;
    static MathTool mathTool;
    static IdTool idTool;
    static TextTool textTool;
    static CronTool cronTool;
    static MimeTool mimeTool;
    static ConversionTool conversionTool;

    if (toolName == QStringLiteral("HashTool")) {
        if (methodName == QStringLiteral("md5")) return HashTool::md5(args.at(0).toString());
        if (methodName == QStringLiteral("sha1")) return HashTool::sha1(args.at(0).toString());
        if (methodName == QStringLiteral("sha256")) return HashTool::sha256(args.at(0).toString());
        if (methodName == QStringLiteral("hmac")) {
            return hashTool.hmac(args.at(0).toString(), args.at(1).toString(), args.at(2).toString());
        }
    }

    if (toolName == QStringLiteral("BaseTool") && methodName == QStringLiteral("convert")) {
        return baseTool.convert(args.at(0).toString(), args.at(1).toInt(), args.at(2).toInt());
    }

    if (toolName == QStringLiteral("UrlTool") && methodName == QStringLiteral("parse")) {
        return urlTool.parse(args.at(0).toString());
    }

    if (toolName == QStringLiteral("UrlTool")) {
        if (methodName == QStringLiteral("encode")) return urlTool.encode(args.at(0).toString());
        if (methodName == QStringLiteral("decode")) return urlTool.decode(args.at(0).toString());
        if (methodName == QStringLiteral("parseJwtPart")) return urlTool.parseJwtPart(args.at(0).toString(), args.at(1).toInt());
        if (methodName == QStringLiteral("base64Encode")) return urlTool.base64Encode(args.at(0).toString());
        if (methodName == QStringLiteral("base64Decode")) return urlTool.base64Decode(args.at(0).toString());
        if (methodName == QStringLiteral("basicAuthHeader")) return urlTool.basicAuthHeader(args.at(0).toString(), args.at(1).toString());
    }

    if (toolName == QStringLiteral("NetworkTool")) {
        if (methodName == QStringLiteral("ipv4Convert")) return networkTool.ipv4Convert(args.at(0).toString());
        if (methodName == QStringLiteral("ipv4Subnet")) return networkTool.ipv4Subnet(args.at(0).toString());
        if (methodName == QStringLiteral("expandIpv4Range")) return networkTool.expandIpv4Range(args.at(0).toString());
    }

    if (toolName == QStringLiteral("TimeTool")) {
        if (methodName == QStringLiteral("formatEpoch")) {
            return timeTool.formatEpoch(args.at(0).toString(), args.at(1).toString());
        }
        if (methodName == QStringLiteral("convertDateTime")) {
            return timeTool.convertDateTime(args.at(0).toString(),
                                            args.at(1).toString(),
                                            args.at(2).toString());
        }
        if (methodName == QStringLiteral("parseNaturalDateWithReference")) {
            return timeTool.parseNaturalDateWithReference(args.at(0).toString(),
                                                          args.at(1).toString(),
                                                          args.at(2).toString());
        }
    }

    if (toolName == QStringLiteral("MathTool")) {
        if (methodName == QStringLiteral("percentOf")) return mathTool.percentOf(args.at(0).toString(), args.at(1).toString());
        if (methodName == QStringLiteral("whatPercent")) return mathTool.whatPercent(args.at(0).toString(), args.at(1).toString());
        if (methodName == QStringLiteral("percentageChange")) return mathTool.percentageChange(args.at(0).toString(), args.at(1).toString());
        if (methodName == QStringLiteral("evaluateExpression")) return mathTool.evaluateExpression(args.at(0).toString());
    }

    if (toolName == QStringLiteral("TextTool")) {
        if (methodName == QStringLiteral("textToUnicode")) return textTool.textToUnicode(args.at(0).toString());
        if (methodName == QStringLiteral("unicodeToText")) return textTool.unicodeToText(args.at(0).toString());
        if (methodName == QStringLiteral("numeronymizeText")) return textTool.numeronymizeText(args.at(0).toString());
        if (methodName == QStringLiteral("convertCase")) return textTool.convertCase(args.at(0).toString(), args.at(1).toString());
        if (methodName == QStringLiteral("convertToNato")) return textTool.convertToNato(args.at(0).toString());
        if (methodName == QStringLiteral("htmlEntitiesEncode")) return textTool.htmlEntitiesEncode(args.at(0).toString());
        if (methodName == QStringLiteral("htmlEntitiesDecode")) return textTool.htmlEntitiesDecode(args.at(0).toString());
        if (methodName == QStringLiteral("slugify")) return textTool.slugify(args.at(0).toString());
        if (methodName == QStringLiteral("normalizeEmail")) return textTool.normalizeEmail(args.at(0).toString());
        if (methodName == QStringLiteral("textStatistics")) return textTool.textStatistics(args.at(0).toString());
        if (methodName == QStringLiteral("loremIpsum")) return textTool.loremIpsum();
        if (methodName == QStringLiteral("obfuscate")) return textTool.obfuscate(args.at(0).toString(), args.at(1).toInt(), args.at(2).toInt(), args.at(3).toBool());
        if (methodName == QStringLiteral("transformList")) return textTool.transformList(args.at(0).toString(), args.at(1).toBool(), args.at(2).toBool(), args.at(3).toBool(), args.at(4).toBool(), args.at(5).toString(), args.at(6).toString(), args.at(7).toString(), args.at(8).toString(), args.at(9).toString());
        if (methodName == QStringLiteral("chmodOctal")) return textTool.chmodOctal(args.at(0).toBool(), args.at(1).toBool(), args.at(2).toBool(), args.at(3).toBool(), args.at(4).toBool(), args.at(5).toBool(), args.at(6).toBool(), args.at(7).toBool(), args.at(8).toBool());
        if (methodName == QStringLiteral("chmodSymbolic")) return textTool.chmodSymbolic(args.at(0).toBool(), args.at(1).toBool(), args.at(2).toBool(), args.at(3).toBool(), args.at(4).toBool(), args.at(5).toBool(), args.at(6).toBool(), args.at(7).toBool(), args.at(8).toBool());
        if (methodName == QStringLiteral("textToBinary")) return textTool.textToBinary(args.at(0).toString());
        if (methodName == QStringLiteral("binaryToText")) return textTool.binaryToText(args.at(0).toString());
        if (methodName == QStringLiteral("arabicToRoman")) return textTool.arabicToRoman(args.at(0).toString());
        if (methodName == QStringLiteral("romanToArabic")) return textTool.romanToArabic(args.at(0).toString());
    }

    if (toolName == QStringLiteral("IdTool")) {
        if (methodName == QStringLiteral("generateUuid")) return idTool.generateUuid();
        if (methodName == QStringLiteral("generateUlid")) return idTool.generateUlid();
        if (methodName == QStringLiteral("generateUlids")) return idTool.generateUlids(args.at(0).toInt(), args.at(1).toString());
        if (methodName == QStringLiteral("generateToken")) return idTool.generateToken(args.at(0).toInt());
        if (methodName == QStringLiteral("generateMacAddress")) return idTool.generateMacAddress();
        if (methodName == QStringLiteral("generatePort")) return idTool.generatePort();
        if (methodName == QStringLiteral("wifiQrPayload")) return idTool.wifiQrPayload(args.at(0).toString(), args.at(1).toString(), args.at(2).toString());
    }

    if (toolName == QStringLiteral("CronTool")) {
        if (methodName == QStringLiteral("describe")) return cronTool.describe(args.at(0).toString());
        if (methodName == QStringLiteral("nextOccurrences")) return cronTool.nextOccurrences(args.at(0).toString(), args.at(1).toInt());
    }

    if (toolName == QStringLiteral("MimeTool")) {
        if (methodName == QStringLiteral("search")) return mimeTool.search(args.at(0).toString());
    }

    if (toolName == QStringLiteral("ConversionTool")) {
        if (methodName == QStringLiteral("jsonToYaml")) return conversionTool.jsonToYaml(args.at(0).toString());
        if (methodName == QStringLiteral("jsonToXml")) return conversionTool.jsonToXml(args.at(0).toString());
        if (methodName == QStringLiteral("jsonToCsv")) return conversionTool.jsonToCsv(args.at(0).toString());
        if (methodName == QStringLiteral("csvToJson")) return conversionTool.csvToJson(args.at(0).toString());
        if (methodName == QStringLiteral("xmlToJson")) return conversionTool.xmlToJson(args.at(0).toString());
        if (methodName == QStringLiteral("markdownToHtml")) return conversionTool.markdownToHtml(args.at(0).toString());
        if (methodName == QStringLiteral("jsonMinify")) return conversionTool.jsonMinify(args.at(0).toString());
        if (methodName == QStringLiteral("jsonFormat")) return conversionTool.jsonFormat(args.at(0).toString(), args.at(1).toInt());
        if (methodName == QStringLiteral("colorFromHex")) return conversionTool.colorFromHex(args.at(0).toString());
        if (methodName == QStringLiteral("colorFromRgb")) return conversionTool.colorFromRgb(args.at(0).toString());
        if (methodName == QStringLiteral("colorFromHsl")) return conversionTool.colorFromHsl(args.at(0).toString());
        if (methodName == QStringLiteral("temperatureToKelvin")) return conversionTool.temperatureToKelvin(args.at(0).toString(), args.at(1).toString());
        if (methodName == QStringLiteral("temperatureFromKelvin")) return conversionTool.temperatureFromKelvin(args.at(0).toString(), args.at(1).toString());
    }

    QTest::qFail(qPrintable(QStringLiteral("Unsupported backend invocation: %1.%2").arg(toolName, methodName)),
                 __FILE__,
                 __LINE__);
    return QVariant();
}

QQmlEngine *ToolsTest::createConfiguredEngine(QObject *parent) const {
    auto *engine = new QQmlEngine(parent);

    auto *hashTool = new HashTool(engine);
    auto *baseTool = new BaseTool(engine);
    auto *conversionTool = new ConversionTool(engine);
    auto *urlTool = new UrlTool(engine);
    auto *networkTool = new NetworkTool(engine);
    auto *timeTool = new TimeTool(engine);
    auto *mathTool = new MathTool(engine);
    auto *idTool = new IdTool(engine);
    auto *textTool = new TextTool(engine);
    auto *cronTool = new CronTool(engine);
    auto *mimeTool = new MimeTool(engine);
    auto *toolManager = new ToolManager(engine);

    engine->rootContext()->setContextProperty(QStringLiteral("hashTool"), hashTool);
    engine->rootContext()->setContextProperty(QStringLiteral("baseTool"), baseTool);
    engine->rootContext()->setContextProperty(QStringLiteral("conversionTool"), conversionTool);
    engine->rootContext()->setContextProperty(QStringLiteral("urlTool"), urlTool);
    engine->rootContext()->setContextProperty(QStringLiteral("networkTool"), networkTool);
    engine->rootContext()->setContextProperty(QStringLiteral("timeTool"), timeTool);
    engine->rootContext()->setContextProperty(QStringLiteral("mathTool"), mathTool);
    engine->rootContext()->setContextProperty(QStringLiteral("idTool"), idTool);
    engine->rootContext()->setContextProperty(QStringLiteral("textTool"), textTool);
    engine->rootContext()->setContextProperty(QStringLiteral("cronTool"), cronTool);
    engine->rootContext()->setContextProperty(QStringLiteral("mimeTool"), mimeTool);
    engine->rootContext()->setContextProperty(QStringLiteral("ToolManager"), toolManager);
    engine->addImageProvider(QLatin1String("qrcode"), new QrCodeProvider);

    return engine;
}

QVariant ToolsTest::invokeQmlFunction(const QString &pagePath,
                                      const QString &functionName,
                                      const QJsonArray &args) const {
    QObject engineOwner;
    std::unique_ptr<QQmlEngine> engine(createConfiguredEngine(&engineOwner));
    QQmlComponent component(engine.get(), QUrl(QStringLiteral("qrc:/contents/ui/") + pagePath));
    if (!component.isReady()) {
        QTest::qFail(qPrintable(component.errorString()), __FILE__, __LINE__);
        return QVariant();
    }

    std::unique_ptr<QObject> object(component.create());
    if (!object) {
        QTest::qFail(qPrintable(component.errorString()), __FILE__, __LINE__);
        return QVariant();
    }

    QVariant result;
    const QByteArray method = functionName.toUtf8();

    if (args.size() == 0) {
        if (!QMetaObject::invokeMethod(object.get(), method.constData(), Q_RETURN_ARG(QVariant, result))) {
            QTest::qFail(qPrintable(QStringLiteral("Failed to invoke %1 on %2").arg(functionName, pagePath)),
                         __FILE__,
                         __LINE__);
            return QVariant();
        }
    } else if (args.size() == 1) {
        const QVariant arg0 = args.at(0).toVariant();
        if (!QMetaObject::invokeMethod(object.get(),
                                       method.constData(),
                                       Q_RETURN_ARG(QVariant, result),
                                       Q_ARG(QVariant, arg0))) {
            QTest::qFail(qPrintable(QStringLiteral("Failed to invoke %1 on %2").arg(functionName, pagePath)),
                         __FILE__,
                         __LINE__);
            return QVariant();
        }
    } else if (args.size() == 2) {
        const QVariant arg0 = args.at(0).toVariant();
        const QVariant arg1 = args.at(1).toVariant();
        if (!QMetaObject::invokeMethod(object.get(),
                                       method.constData(),
                                       Q_RETURN_ARG(QVariant, result),
                                       Q_ARG(QVariant, arg0),
                                       Q_ARG(QVariant, arg1))) {
            QTest::qFail(qPrintable(QStringLiteral("Failed to invoke %1 on %2").arg(functionName, pagePath)),
                         __FILE__,
                         __LINE__);
            return QVariant();
        }
    } else if (args.size() == 3) {
        const QVariant arg0 = args.at(0).toVariant();
        const QVariant arg1 = args.at(1).toVariant();
        const QVariant arg2 = args.at(2).toVariant();
        if (!QMetaObject::invokeMethod(object.get(),
                                       method.constData(),
                                       Q_RETURN_ARG(QVariant, result),
                                       Q_ARG(QVariant, arg0),
                                       Q_ARG(QVariant, arg1),
                                       Q_ARG(QVariant, arg2))) {
            QTest::qFail(qPrintable(QStringLiteral("Failed to invoke %1 on %2").arg(functionName, pagePath)),
                         __FILE__,
                         __LINE__);
            return QVariant();
        }
    } else {
        QTest::qFail("Too many QML function arguments for test harness", __FILE__, __LINE__);
        return QVariant();
    }

    return result;
}

void ToolsTest::assertVariantMatches(const QVariant &actual,
                                     const QJsonObject &expectation,
                                     const QString &caseName) const {
    const QString actualText = variantAsText(actual);

    if (expectation.contains(QStringLiteral("equals"))) {
        QCOMPARE(actualText, expectation.value(QStringLiteral("equals")).toString());
    }

    if (expectation.contains(QStringLiteral("contains"))) {
        const QString text = actualText;
        const QJsonArray needles = expectation.value(QStringLiteral("contains")).toArray();
        for (const QJsonValue &needle : needles) {
            QVERIFY2(text.contains(needle.toString()),
                     qPrintable(QStringLiteral("%1 missing substring: %2\nActual:\n%3")
                                    .arg(caseName, needle.toString(), text)));
        }
    }

    if (expectation.contains(QStringLiteral("matches"))) {
        const QRegularExpression regex(expectation.value(QStringLiteral("matches")).toString());
        QVERIFY2(regex.isValid(), qPrintable(regex.errorString()));
        QVERIFY2(regex.match(actualText).hasMatch(),
                 qPrintable(QStringLiteral("%1 did not match regex %2\nActual:\n%3")
                                .arg(caseName, regex.pattern(), actualText)));
    }

    if (expectation.contains(QStringLiteral("mapEquals"))) {
        const QVariantMap actualMap = actual.toMap();
        const QJsonObject expectedMap = expectation.value(QStringLiteral("mapEquals")).toObject();
        for (auto it = expectedMap.begin(); it != expectedMap.end(); ++it) {
            QCOMPARE(actualMap.value(it.key()).toString(), it.value().toString());
        }
    }
}

QString ToolsTest::variantAsText(const QVariant &value) const {
    if (value.type() == QVariant::Map || value.type() == QVariant::List) {
        return QString::fromUtf8(QJsonDocument::fromVariant(value).toJson(QJsonDocument::Compact));
    }
    return value.toString();
}

void ToolsTest::backendDatasets() {
    const QDir dataDir(QDir(QStringLiteral(TOOLS_TEST_SOURCE_DIR)).filePath(QStringLiteral("tests/data")));
    const QStringList files = dataDir.entryList(QStringList() << QStringLiteral("*_cases.json"), QDir::Files, QDir::Name);

    for (const QString &fileName : files) {
        const QJsonObject spec = loadJsonObject(fileName);
        if (spec.value(QStringLiteral("kind")).toString() != QStringLiteral("backend")) {
            continue;
        }

        const QString toolName = spec.value(QStringLiteral("tool")).toString();
        const QJsonArray cases = spec.value(QStringLiteral("cases")).toArray();

        for (const QJsonValue &caseValue : cases) {
            const QJsonObject testCase = caseValue.toObject();
            const QString caseName = testCase.value(QStringLiteral("name")).toString(fileName);
            const QVariant actual = invokeBackend(toolName,
                                                  testCase.value(QStringLiteral("method")).toString(),
                                                  testCase.value(QStringLiteral("args")).toArray());
            assertVariantMatches(actual, testCase, caseName);
        }
    }
}

void ToolsTest::qmlFunctionDatasets() {
    const QDir dataDir(QDir(QStringLiteral(TOOLS_TEST_SOURCE_DIR)).filePath(QStringLiteral("tests/data")));
    const QStringList files = dataDir.entryList(QStringList() << QStringLiteral("*_cases.json"), QDir::Files, QDir::Name);

    for (const QString &fileName : files) {
        const QJsonObject spec = loadJsonObject(fileName);
        if (spec.value(QStringLiteral("kind")).toString() != QStringLiteral("qml-function")) {
            continue;
        }

        const QString pagePath = spec.value(QStringLiteral("page")).toString();
        const QString functionName = spec.value(QStringLiteral("function")).toString();
        const QJsonArray cases = spec.value(QStringLiteral("cases")).toArray();

        for (const QJsonValue &caseValue : cases) {
            const QJsonObject testCase = caseValue.toObject();
            const QString caseName = testCase.value(QStringLiteral("name")).toString(fileName);
            const QVariant actual = invokeQmlFunction(pagePath, functionName, testCase.value(QStringLiteral("args")).toArray());
            assertVariantMatches(actual, testCase, caseName);
        }
    }
}

void ToolsTest::qmlSmokeLoadsAllToolPages() {
    QFile file(QStringLiteral(":/contents/ui/tools.json"));
    QVERIFY(file.open(QIODevice::ReadOnly));

    const QJsonDocument document = QJsonDocument::fromJson(file.readAll());
    QVERIFY(document.isArray());

    QObject engineOwner;
    std::unique_ptr<QQmlEngine> engine(createConfiguredEngine(&engineOwner));

    const QJsonArray tools = document.array();
    for (const QJsonValue &toolValue : tools) {
        const QJsonObject tool = toolValue.toObject();
        const QString pagePath = tool.value(QStringLiteral("file")).toString();
        QQmlComponent component(engine.get(), QUrl(QStringLiteral("qrc:/contents/ui/") + pagePath));
        QVERIFY2(component.isReady(),
                 qPrintable(QStringLiteral("Failed to load %1\n%2")
                                .arg(pagePath, component.errorString())));

        std::unique_ptr<QObject> object(component.create());
        QVERIFY2(object != nullptr,
                 qPrintable(QStringLiteral("Failed to instantiate %1\n%2")
                                .arg(pagePath, component.errorString())));
    }
}

int main(int argc, char **argv) {
    qputenv("QT_QPA_PLATFORM", qEnvironmentVariableIsSet("QT_QPA_PLATFORM")
                                  ? qgetenv("QT_QPA_PLATFORM")
                                  : QByteArrayLiteral("offscreen"));

    QApplication app(argc, argv);
    ToolsTest test;
    return QTest::qExec(&test, argc, argv);
}

#include "tools_test.moc"
