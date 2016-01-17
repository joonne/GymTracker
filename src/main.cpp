#ifdef QT_QML_DEBUG
#include <QtQuick>
#endif

#include <sailfishapp.h>
#include <QScopedPointer>
#include <QQuickView>
#include <QQmlEngine>
#include <QGuiApplication>
#include <QQmlContext>
#include <QStandardPaths>
#include <QDebug>

#include "gymmodel.h"
#include "user.h"
#include "databasemanager.h"
#include "workoutmodel/excercisemodel.h"
#include "apireader.h"
#include "controller.h"

int main(int argc, char *argv[])
{
    // For this example, wizard-generates single line code would be good enough,
    // but very soon it won't be enough for you anyway, so use this more detailed example from start
    QScopedPointer<QGuiApplication> app(SailfishApp::application(argc, argv));
    QScopedPointer<QQuickView> view(SailfishApp::createView());

    QScopedPointer<Controller> controller(new Controller);
    QQmlContext* context = view->rootContext();
    context->setContextProperty("controller", controller.data());

    qmlRegisterType<ExcerciseModel>("harbour.salifish", 1, 0, "ExcerciseModel");

    //    Here's how you will add QML components whenever you start using them
    //    Check https://github.com/amarchen/Wikipedia for a more full example
    //    view->engine()->addImportPath(SailfishApp::pathTo("qml/components").toString());
    view->setSource(SailfishApp::pathTo("qml/main.qml"));

    view->showFullScreen();

    return app->exec();

}
