#include "patientview.h"
#include "ui_patientview.h"
#include "idatabase.h"

PatientView::PatientView(QWidget *parent, int index)
    : QWidget(parent)
    , ui(new Ui::PatientView)
{
    ui->setupUi(this);
    ui->tableView_2->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView_2->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView_2->setAlternatingRowColors(true);

    IDatabase &iDatabase = IDatabase::getInstance();
    if (iDatabase.initParentModel()) {
        ui->tableView_2->setModel(iDatabase.patientTabModel);
        ui->tableView_2->setSelectionModel(iDatabase.thePatientSelection);
    }
}

PatientView::~PatientView()
{
    delete ui;
}

void PatientView::on_btAdd_2_clicked()
{
    int currow=IDatabase::getInstance().addNewPatient();
    emit goPatientEditView(currow);
}


void PatientView::on_btSearch_2_clicked()
{
    QString filter=QString("name like '%%1%'").arg(ui->txtSearch_2->text());
    IDatabase::getInstance().searchPatient(filter);
}


void PatientView::on_btDelete_2_clicked()
{
    IDatabase::getInstance().deleteCurrentPatient();
}


void PatientView::on_btEdit_2_clicked()
{
    QModelIndex curIndex=IDatabase::getInstance().thePatientSelection->currentIndex();
    emit goPatientEditView(curIndex.row());
}

