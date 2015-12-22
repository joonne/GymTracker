#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>
#include <QFile>
#include <QDir>
#include <QSqlQuery>
#include <QTextStream>
#include <QStandardPaths>
#include <QVariant>

class DatabaseManager : public QObject
{
    Q_OBJECT
public:
    explicit DatabaseManager(QObject *parent = 0);
    ~DatabaseManager();

    void setUpDB();

    bool openDB();
    bool deleteDB();
    QSqlError lastError();
    void close();
    bool createDB();
    bool updateDB();

    bool initializeInfoTable();
    bool createInfoTable();
    bool updateInfoTable(double version);

    bool createCategoryTable();
    bool insertCategory(QString name);
    int findCategory(QString category);

    bool createExcerciseTable();
    bool insertExcercise(QString name, QString description, QString category);

    bool createExcerciseMuscleTable();
    bool insertExcerciseMuscle(int muscle, int excercise);

    bool createMuscleTable();
    bool insertMuscle(QString name);

    bool createWorkoutTable();
    bool insertWorkout(QString name, double calories);

    bool createWorkoutEntryTable();
    bool insertWorkoutEntry(int excercise, int user, int  workout, QString date, int repeats, double weights, int equipment);

    bool createEquipmentTable();
    bool insertEquipment(QString name);

    bool createUserTable();
    bool insertUser(QString name, int age, QString gender, double height, double weight);

    QMap<QString, QString> getUser();
    bool updateName(QString name);
    bool updateAge(int age);
    bool updateGender(QString gender);
    bool updateHeight(double height);
    bool updateWeight(double weight);

private:
    QSqlDatabase db;
};

#endif // DATABASEMANAGER_H