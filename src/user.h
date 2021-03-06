#ifndef USER_H
#define USER_H

#include <QObject>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QString>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlDriver>
#include <QDir>
#include <QStandardPaths>

#include "databasemanager.h"

class User : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(int age READ getAge WRITE setAge NOTIFY ageChanged)
    Q_PROPERTY(QString gender READ getGender WRITE setGender NOTIFY genderChanged)
    Q_PROPERTY(double height READ getHeight WRITE setHeight NOTIFY heightChanged)
    Q_PROPERTY(double weight READ getWeight WRITE setWeight NOTIFY weightChanged)
    Q_PROPERTY(double BMI READ getBMI NOTIFY BMIChanged)
    Q_PROPERTY(QString BMIdescription READ getBMIdescription NOTIFY BMIdescriptionChanged)
    Q_PROPERTY(double BMR READ getBMR NOTIFY BMRChanged)
    Q_PROPERTY(int pause READ getPause WRITE setPause NOTIFY pauseChanged)

public:
    User(QObject *parent = 0, DatabaseManager* dbmanager = 0);
    ~User();
    Q_INVOKABLE void clean();

    QString getName();
    int getAge();
    QString getGender();
    double getHeight();
    double getWeight();
    double getBMI();
    double getBMR();
    int getPause();

    QString getBMIdescription();
    void calculateBMI();
    void calculateBMR();

    double calculateBurntCalories(int time);

    void setName(QString name);
    void setAge(int age);
    void setGender(QString gender);
    void setHeight(double height);
    void setWeight(double weight);
    void setPause(int pause);

    bool getUser();
    bool insertUser(QString name, int age, QString gender, double height, double weight);
    bool updateName(QString name);
    bool updateAge(int age);
    bool updateGender(QString gender);
    bool updateHeight(double height);
    bool updateWeight(double weight);
    bool openDB();
    void closeDB();

signals:
    void nameChanged();
    void ageChanged();
    void genderChanged();
    void heightChanged();
    void weightChanged();
    void BMIChanged();
    void BMIdescriptionChanged();
    void BMRChanged();
    void pauseChanged();


private:
    QString myName;
    int myAge;
    QString myGender;
    double myHeight;
    double myWeight;
    double myBMI;
    QString myBMIdescription;
    double myBMR;
    int myPause;
    DatabaseManager* mydbmanager;

};

#endif // USER_H
