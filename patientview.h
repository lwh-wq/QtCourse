#ifndef PATIENTVIEW_H
#define PATIENTVIEW_H

#include <QWidget>

namespace Ui {
class PatientView;
}

class PatientView : public QWidget
{
    Q_OBJECT

public:
    explicit PatientView(QWidget *parent = nullptr,int index=0);
    ~PatientView();

private slots:
    void on_btAdd_2_clicked();

    void on_btSearch_2_clicked();

    void on_btDelete_2_clicked();

    void on_btEdit_2_clicked();

signals:
    void goPatientEditView(int index);

private:
    Ui::PatientView *ui;
};

#endif // PATIENTVIEW_H
