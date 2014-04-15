#ifndef USERDATABASE_H
#define USERDATABASE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>
#include <QFile>
#include <QDir>
#include <QSqlQuery>
#include <QStandardPaths>
#include <QVariant>
#include <QDebug>

class UserDatabase : public QObject
{
    Q_OBJECT
public:
    explicit UserDatabase(QObject *parent = 0);
    ~UserDatabase();

    bool openDB();
    bool deleteDB();
    QSqlError lastError();
    void close();

    bool createDB();
    void setUpDB();

    bool createUserTable();
    bool insertUser(QString name, int age, QString gender, double height, double weight);

private:

    QSqlDatabase db;


};

#endif // USERDATABASE_H
