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
#include "workoutmodel/exercisemodel.h"
#include "workoutmodel/workoutmodel.h"
#include "apireader.h"
#include "controller.h"

int main(int argc, char *argv[])
{
    QScopedPointer<QGuiApplication> app(SailfishApp::application(argc, argv));
    QScopedPointer<QQuickView> view(SailfishApp::createView());

    QScopedPointer<Controller> controller(new Controller);
    QQmlContext* context = view->rootContext();
    context->setContextProperty("controller", controller.data());

    qmlRegisterType<ExerciseModel>("harbour.salifish", 1, 0, "ExerciseModel");
    qmlRegisterType<WorkoutModel>("harbour.salifish", 1, 0, "WorkoutModel");
    qmlRegisterType<User>("harbour.salifish", 1, 0, "User");

    view->engine()->addImportPath(SailfishApp::pathTo("qml/components").toString());
    view->setSource(SailfishApp::pathTo("qml/main.qml"));

    view->showFullScreen();

    return app->exec();
}
