#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "colorMaker.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<ColorMaker>("an.qt.ColorMaker", 1, 0, "ColorMaker");
//    QtQuick2ApplicationViewer viewer;
//    viewer.setMainQmlFile(QStringLiteral("main.qml"));
//    viewer.showExpanded();

    QQmlApplicationEngine engine;
//    QQmlContext *rootContext = engine.rootContext();
//    rootContext->setContextProperty("ColorMaker", new ColorMaker);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
