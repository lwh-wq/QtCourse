#include "patientview.h"
#include "ui_patientview.h"

PatientView::PatientView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PatientView)
{
    ui->setupUi(this);
}

PatientView::~PatientView()
{
    delete ui;
}

void PatientView::on_btAdd_2_clicked()
{
    emit goPatientEditView();
}

