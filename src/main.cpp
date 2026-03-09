#include <QApplication>
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

int main(int argc, char *argv[])
{
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc, argv);
    app.setWindowIcon(QIcon(":/icon.svg"));

    qmlRegisterType<HashTool>("ittools.kirigami", 1, 0, "HashTool");
    qmlRegisterType<BaseTool>("ittools.kirigami", 1, 0, "BaseTool");
    qmlRegisterType<ConversionTool>("ittools.kirigami", 1, 0, "ConversionTool");
    qmlRegisterType<UrlTool>("ittools.kirigami", 1, 0, "UrlTool");
    qmlRegisterType<NetworkTool>("ittools.kirigami", 1, 0, "NetworkTool");

    QQmlApplicationEngine engine;
    engine.addImageProvider(QLatin1String("qrcode"), new QrCodeProvider);
    engine.load(QUrl(QStringLiteral("qrc:/contents/ui/main.qml")));

    if (engine.rootObjects().isEmpty()) {
        return -1;
    }

    return app.exec();
}
