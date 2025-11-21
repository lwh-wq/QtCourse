#include "searchdialog.h"
#include "ui_searchdialog.h"
#include <QMessageBox>
SearchDialog::SearchDialog(QWidget *parent,QPlainTextEdit *textEdit)
    : QDialog(parent)
    , ui(new Ui::SearchDialog)
{
    ui->setupUi(this);
    PTextEdit=textEdit;
    ui->rbDown->setChecked(true);
}

SearchDialog::~SearchDialog()
{
    delete ui;
}

void SearchDialog::on_btFindNext_clicked()
{
    QString target=ui->searchText->text();

    if(target==""||PTextEdit==nullptr)
        return ;

    QString text=PTextEdit->toPlainText();
    QTextCursor c=PTextEdit->textCursor();
    int index=-1;

    if(ui->rbDown->isChecked()){
        index=text.indexOf(target,c.position(),ui->cbCaseSensitive->isChecked()?Qt::CaseSensitive:Qt::CaseInsensitive);
        if(index>=0){
            c.setPosition(index);
            c.setPosition(index+target.length(),QTextCursor::KeepAnchor);
            PTextEdit->setTextCursor(c);

        }
    }
    else if(ui->rbUp->isChecked()){
        index=text.lastIndexOf(target,c.position()-text.length()-1);
        if(index>=0){
            c.setPosition(index+target.length());
            c.setPosition(index,QTextCursor::KeepAnchor);
            PTextEdit->setTextCursor(c);

        }
    }
    if(index<0){
        QMessageBox msg(this);
        msg.setWindowTitle("waring");
        msg.setText(QString("找不到")+target);
        msg.setWindowFlag(Qt::Drawer);
        msg.setIcon(QMessageBox::Information);
        msg.setStandardButtons(QMessageBox::Ok);
        msg.exec();
    }
}


void SearchDialog::on_btCancel_clicked()
{
    accept();
}

