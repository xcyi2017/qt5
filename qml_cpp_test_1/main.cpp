//#include <QGuiApplication>
//#include <QQmlApplicationEngine>
//#include "gemini.h"
//#include <QtQml>
//#include <QQuickView>

//int main(int argc, char *argv[])
//{
//    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

//    QGuiApplication app(argc, argv);

//    qmlRegisterType<Gemini>("an.qt.Gemini", 1., 0, "Gemini");

//    QQmlApplicationEngine engine;
//    const QUrl url(QStringLiteral("qrc:/main.qml"));

//    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
//                     &app, [url](QObject *obj, const QUrl &objUrl) {
//        if (!obj && url == objUrl)
//            QCoreApplication::exit(-1);
//    }, Qt::QueuedConnection);
//    engine.load(url);

//    return app.exec();
//}

//int main(int argc, char *argv[]) {
//    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

//    QGuiApplication app(argc, argv);

//    QQmlApplicationEngine engine;
//    engine.rootContext()->setContextProperty("gemini", new Gemini);
//    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
//    return app.exec();
//}


#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "gemini.h"
#include <QtQml>
#include <QQuickView>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<Gemini>("an.qt.Gemini", 1., 0, "Gemini");

    QQmlEngine engine;
    QQmlComponent compent(&engine, QUrl(QStringLiteral("qrc:/main.qml")));
    QObject *object = compent.create();
    qDebug() << "width value is" << object->property("width").toInt();
    object->setProperty("width", 500);
    qDebug() << "height value is " << QQmlProperty::read(object, "height").toInt();
    object->setProperty("height", 500);
    QObject *rect = object->findChild<QObject*>("rect");
    if (rect) {
        rect->setProperty("color", "black");
    }

    QVariant returnedValue;
    QVariant message = "Hello from C++";
    QMetaObject::invokeMethod(object, "qmlFunction", Q_RETURN_ARG(QVariant, returnedValue), Q_ARG(QVariant, message));
    qDebug() << "returnedValue is " << returnedValue;
    Gemini test;
    QObject::connect(object, SIGNAL(qmlSignal(QString)), &test, SLOT(cppSlot(QString)));

    return app.exec();
}
