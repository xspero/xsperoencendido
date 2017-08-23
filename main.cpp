#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <QQmlContext>
#include <QQmlEngine>
#include <QtQml>
#include <serialisimo.h>
#include "clock.h"
#include "backlightcontroller.h"
//#include <QtQml/QQmlContext>




int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);


    QScopedPointer<Serialisimo> serialon(new Serialisimo);



    QQmlApplicationEngine engine;

    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    Serialisimo miSerial;
    engine.rootContext()->setContextProperty("serialito",&miSerial);


    QObject *rootObject = engine.rootObjects().first();
    qDebug() << "root: " << rootObject;


    //holi
    Clock clock(&engine);
    engine.rootContext()->setContextProperty("clock", &clock);

    BacklightController blCtrl(&engine);

    engine.connect(&clock, &Clock::nowChanged,
                   &blCtrl, &BacklightController::backlightCountdown);

    engine.connect(rootObject, SIGNAL(activateScreen()),
                   &blCtrl, SLOT(backlightOn()));

    //holi




    return app.exec();
}
