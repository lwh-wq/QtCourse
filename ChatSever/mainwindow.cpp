#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_chatServer=new ChatServer(this);
    connect(m_chatServer,&ChatServer::logMessage,this,&MainWindow::logMessage);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startStopButton_clicked()
{
    static bool started = false;
    started = !started;
    if (started) {
        ui->startStopButton->setText("停止服务器");
        logMessage("服务器已经启动");
    } else {
        ui->startStopButton->setText("启动服务器");
        logMessage("服务器已经停止");
    }
}

void MainWindow::logMessage(const QString &msg)
{
    ui->logEidtor->appendPlainText(msg);
}

