#include "idatabase.h"
#include <QUuid>
void IDatabase::initnDatabase()
{
    // 数据库初始化逻辑
    database=QSqlDatabase::addDatabase("QSQLITE");
    QString aFile="../../../Lab.db";
    database.setDatabaseName(aFile);
    if(!database.open()){
        qDebug()<<"failed to open database";
    }
    else qDebug()<<"open database is ok";
}

bool IDatabase::initParentModel()
{
    patientTabModel = new QSqlTableModel(this, database);
    patientTabModel->setTable("Patient");
    patientTabModel->setEditStrategy(QSqlTableModel::OnManualSubmit); //数据保存方式，OnManualSubmit ，OnRowChange
    patientTabModel->setSort(patientTabModel->fieldIndex("name"), Qt::AscendingOrder); //排序
    if (!(patientTabModel->select()))//查询数据
        return false;

    thePatientSelection = new QItemSelectionModel(patientTabModel);
    return true;
}

int IDatabase::addNewPatient()
{
    patientTabModel->insertRow(patientTabModel->rowCount(),QModelIndex());
    QModelIndex curIndex=patientTabModel->index(patientTabModel->rowCount()-1,1);
    int curRecNo=curIndex.row();
    QSqlRecord curRec=patientTabModel->record(curRecNo);//获取当前记录
    curRec.setValue("CREATETIMESTAMP",QDateTime::currentDateTime().toString("yyyy-MM-dd"));
    curRec.setValue("ID",QUuid::createUuid().toString(QUuid::WithoutBraces));
    patientTabModel->setRecord(curRecNo,curRec);
    return curIndex.row();
}

bool IDatabase::searchPatient(QString filter)
{
    patientTabModel->setFilter(filter);
    return patientTabModel->select();
}

bool IDatabase::deleteCurrentPatient()
{
    QModelIndex curIndex = thePatientSelection->currentIndex();
    patientTabModel->removeRow(curIndex.row());
    patientTabModel->submitAll();
    patientTabModel->select();
    return true;
}



bool IDatabase::submitPatientEdit()
{
    return patientTabModel->submitAll();
}

void IDatabase::revertPatientEdit()
{
    patientTabModel->revertAll();
}

QString IDatabase::userLogin(QString userName, QString password)
{
    QSqlQuery query;
    query.prepare("select USERNAME,PASSWORD from User where USERNAME=:USER ");
    query.bindValue(":USER",userName);
    query.exec();
    if(query.first()&&query.value("USERNAME").isValid()){
        QString passwd =query.value("PASSWORD").toString();
        if(passwd==password){
            return "loginOk";
        }
        else{
            qDebug()<<"wrong password";
            return "wrongPassword";
        }
    }
    else{
        qDebug()<<"no such user";
        return "wrongUsername";
    }
}

IDatabase::IDatabase(QObject *parent)
    : QObject(parent)
{
    initnDatabase();
}


