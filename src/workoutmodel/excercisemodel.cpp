#include "excercisemodel.h"
#include <QDebug>

ExcerciseModel::ExcerciseModel(QObject *parent) :
    QAbstractListModel(parent) {

    mydbmanager = new DatabaseManager(this);
    mydbmanager->setUpDB();

}

int ExcerciseModel::rowCount(const QModelIndex &index) const {
    Q_UNUSED(index)
    return myExcercises.size();
}

QHash<int, QByteArray> ExcerciseModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[IdRole] = "id";
    roles[NameRole] = "name";
    roles[DescriptionRole] = "description";
    roles[CategoryRole] = "category";
    return roles;
}

QVariant ExcerciseModel::data(const QModelIndex &index, int role) const {

    if(!index.isValid()) {
        return QVariant();
    }

    if(role == IdRole) {
        return myExcercises[index.row()]->getExcerciseId();
    } else if(role == NameRole) {
        return myExcercises[index.row()]->getExcerciseName();
    } else if(role == DescriptionRole) {
        return myExcercises[index.row()]->getExcerciseDescription();
    } else if(role == CategoryRole) {
        return myExcercises[index.row()]->getExcerciseCategory();
    }
    return QVariant();
}

void ExcerciseModel::populate(QString selectedMuscle) {

    QList<QMap<QString,QString> > excercises = mydbmanager->getExcercises(selectedMuscle);
    int size = excercises.size();
    for(int i = 0; i < size; ++i) {
        QMap<QString,QString> temp = excercises.at(i);
        beginInsertRows(QModelIndex(), 0, 0);
        ExcerciseData* data = new ExcerciseData(temp["id"].toInt(), temp["name"], temp["description"], temp["category"]);
        myExcercises.append(data);
        endInsertRows();
    }
}
