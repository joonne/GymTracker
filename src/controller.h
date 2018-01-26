#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QSortFilterProxyModel>

#include "workoutmodel/exercisemodel.h"
#include "workoutmodel/workoutmodel.h"
#include "apireader.h"
#include "databasemanager.h"
#include "user.h"

class Controller : public QObject
{
    Q_OBJECT
    Q_PROPERTY(ExerciseModel* exerciseModel READ getExerciseModel CONSTANT)
    Q_PROPERTY(WorkoutModel* workoutModel READ getWorkoutModel CONSTANT)
    Q_PROPERTY(User* user READ getUser CONSTANT)

public:
    explicit Controller(QObject *parent = 0);

    ExerciseModel* getExerciseModel();
    Q_INVOKABLE void sortExercises(QString name);

    WorkoutModel* getWorkoutModel();
    User* getUser();

    Q_INVOKABLE QVariantList getMuscleModel();
    Q_INVOKABLE QVariantList getCategoryModel();

signals:

public slots:

private:
    ExerciseModel* myExerciseModel;
    QSortFilterProxyModel* myExerciseProxyModel;
    WorkoutModel* myWorkoutModel;
    DatabaseManager* mydbmanager;
    APIReader* myapireader;
    User* myUser;

};

#endif // CONTROLLER_H
