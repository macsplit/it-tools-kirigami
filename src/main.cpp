#include <QApplication>
#include <QFile>
#include <QQmlApplicationEngine>
#include <QtQml>
#include <QUrl>
#include <QIcon>
#include "hashtool.h"
#include "basetool.h"
#include "conversiontool.h"
#include "qrcodetool.h"
#include "urltool.h"
#include "networktool.h"
#include "timetool.h"
#include "toolmanager.h"

int main(int argc, char *argv[])
{
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    // Flatpak sandboxes commonly inherit SESSION_MANAGER from the host, but
    // the XSMP socket is not reachable inside the sandbox. Clearing it avoids
    // Qt's startup warning about failing to open the session-management socket.
    if (QFile::exists(QStringLiteral("/.flatpak-info"))) {
        qunsetenv("SESSION_MANAGER");
    }

    QApplication app(argc, argv);
    QApplication::setApplicationName(QStringLiteral("Tools"));
    QApplication::setApplicationDisplayName(QStringLiteral("Tools"));
    QApplication::setDesktopFileName(QStringLiteral("app.pastetools.Tools"));
    QApplication::setOrganizationDomain(QStringLiteral("pastetools.app"));
    QApplication::setOrganizationName(QStringLiteral("pastetools"));
    app.setWindowIcon(QIcon(":/icon.svg"));

    qmlRegisterSingletonType<ToolManager>("ittools.kirigami", 1, 0, "ToolManager", [](QQmlEngine *engine, QJSEngine *scriptEngine) -> QObject * {
        Q_UNUSED(engine)
        Q_UNUSED(scriptEngine)
        return new ToolManager();
    });

    qmlRegisterType<HashTool>("ittools.kirigami", 1, 0, "HashTool");
    qmlRegisterType<BaseTool>("ittools.kirigami", 1, 0, "BaseTool");
    qmlRegisterType<ConversionTool>("ittools.kirigami", 1, 0, "ConversionTool");
    qmlRegisterType<UrlTool>("ittools.kirigami", 1, 0, "UrlTool");
    qmlRegisterType<NetworkTool>("ittools.kirigami", 1, 0, "NetworkTool");
    qmlRegisterType<TimeTool>("ittools.kirigami", 1, 0, "TimeTool");

    QQmlApplicationEngine engine;
    engine.addImageProvider(QLatin1String("qrcode"), new QrCodeProvider);
    engine.load(QUrl(QStringLiteral("qrc:/contents/ui/main.qml")));

    if (engine.rootObjects().isEmpty()) {
        return -1;
    }

    return app.exec();
}
