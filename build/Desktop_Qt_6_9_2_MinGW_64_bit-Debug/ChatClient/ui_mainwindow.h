/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QStackedWidget *stackedWidget;
    QWidget *loginPage;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_2;
    QFrame *loginFram;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *serverEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *usernameEdit;
    QSpacerItem *verticalSpacer;
    QPushButton *loginButton;
    QWidget *chatPage;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QTextEdit *roomTextEdit;
    QListWidget *userListWidget;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *sayLineEdit;
    QPushButton *sayButton;
    QPushButton *logoutButton;
    QLabel *titleLabel;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(500, 400);
        MainWindow->setMinimumSize(QSize(500, 400));
        MainWindow->setStyleSheet(QString::fromUtf8("/* \346\240\207\351\242\230\346\240\267\345\274\217\357\274\232Qt\345\205\274\345\256\271\347\211\210\357\274\214\346\233\264\351\206\222\347\233\256\344\270\224\346\234\211\345\261\202\346\254\241\346\204\237 */\n"
"#titleLabel {\n"
"    background: #f8f9fa; /* \346\265\205\347\201\260\350\203\214\346\231\257\346\233\264\346\237\224\345\222\214 */\n"
"    color: #2c3e50; /* \346\267\261\347\201\260\346\226\207\345\255\227\346\233\264\351\253\230\347\272\247 */\n"
"    font-size: 22px;\n"
"    font-weight: 600; /* \345\212\240\347\262\227\347\252\201\345\207\272\346\240\207\351\242\230 */\n"
"    border: none;\n"
"    border-bottom: 2px solid #3498db; /* \350\223\235\350\211\262\344\270\213\350\276\271\346\241\206\346\233\264\344\272\256\347\234\274 */\n"
"    padding: 8px 12px;\n"
"    border-radius: 4px 4px 0 0; /* \351\241\266\351\203\250\345\234\206\350\247\222 */\n"
"}\n"
"\n"
"/* \344\270\273\346\241\206\346\236\266\357\274\232Qt\345\205\274\345\256\271\347\211\210\357\274\214\347\256\200\346\264\201\350"
                        "\210\222\351\200\202 */\n"
"#mainFrame {\n"
"    border: none;\n"
"    background: #f5f7fa; /* \346\267\241\350\223\235\347\201\260\350\203\214\346\231\257\346\233\264\350\210\222\351\200\202 */\n"
"    padding: 10px; /* \345\206\205\350\276\271\350\267\235\351\201\277\345\205\215\345\206\205\345\256\271\350\264\264\350\276\271 */\n"
"    border-radius: 6px; /* \346\225\264\344\275\223\345\234\206\350\247\222 */\n"
"}\n"
"\n"
"/* \347\231\273\345\275\225\346\241\206\357\274\232Qt\345\205\274\345\256\271\347\211\210\357\274\214\346\270\220\345\217\230+\347\262\276\350\207\264\350\276\271\346\241\206 */\n"
"#loginFram {\n"
"    /* Qt\346\224\257\346\214\201\347\232\204\347\272\277\346\200\247\346\270\220\345\217\230\357\274\214\346\233\264\346\270\205\346\226\260\347\232\204\346\265\205\350\223\235\350\260\203 */\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #e3f2fd, stop:1 #bbdefb);\n"
"    /* \345\217\214\345\261\202\350\276\271\346\241\206\346\250\241\346\213\237\351\230\264\345\275\261\346"
                        "\225\210\346\236\234\357\274\214Qt\345\205\274\345\256\271 */\n"
"    border: 1px solid #90caf9; \n"
"    border-top: 1px solid #e8f4f8;\n"
"    border-left: 1px solid #e8f4f8;\n"
"    padding: 15px 20px; /* \345\242\236\345\212\240\345\206\205\350\276\271\350\267\235\346\233\264\345\256\275\346\235\276 */\n"
"    border-radius: 12px; /* \346\233\264\345\234\206\346\266\246\347\232\204\350\276\271\350\247\222 */\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName("gridLayout_2");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        loginPage = new QWidget();
        loginPage->setObjectName("loginPage");
        gridLayout = new QGridLayout(loginPage);
        gridLayout->setObjectName("gridLayout");
        verticalSpacer_3 = new QSpacerItem(20, 14, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 2, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(31, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 14, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(30, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        loginFram = new QFrame(loginPage);
        loginFram->setObjectName("loginFram");
        loginFram->setMinimumSize(QSize(0, 0));
        loginFram->setFrameShape(QFrame::Shape::StyledPanel);
        loginFram->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_3 = new QVBoxLayout(loginFram);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_2 = new QLabel(loginFram);
        label_2->setObjectName("label_2");

        horizontalLayout->addWidget(label_2);

        serverEdit = new QLineEdit(loginFram);
        serverEdit->setObjectName("serverEdit");
        serverEdit->setMinimumSize(QSize(140, 0));
        serverEdit->setMaximumSize(QSize(140, 16777215));

        horizontalLayout->addWidget(serverEdit);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_3 = new QLabel(loginFram);
        label_3->setObjectName("label_3");

        horizontalLayout_2->addWidget(label_3);

        usernameEdit = new QLineEdit(loginFram);
        usernameEdit->setObjectName("usernameEdit");
        usernameEdit->setMinimumSize(QSize(140, 0));
        usernameEdit->setMaximumSize(QSize(140, 16777215));

        horizontalLayout_2->addWidget(usernameEdit);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout_3->addLayout(verticalLayout_2);

        verticalSpacer = new QSpacerItem(10, 19, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        loginButton = new QPushButton(loginFram);
        loginButton->setObjectName("loginButton");

        verticalLayout_3->addWidget(loginButton);


        gridLayout->addWidget(loginFram, 1, 1, 1, 1);

        stackedWidget->addWidget(loginPage);
        chatPage = new QWidget();
        chatPage->setObjectName("chatPage");
        verticalLayout = new QVBoxLayout(chatPage);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        roomTextEdit = new QTextEdit(chatPage);
        roomTextEdit->setObjectName("roomTextEdit");

        horizontalLayout_3->addWidget(roomTextEdit);

        userListWidget = new QListWidget(chatPage);
        userListWidget->setObjectName("userListWidget");
        userListWidget->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_3->addWidget(userListWidget);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        sayLineEdit = new QLineEdit(chatPage);
        sayLineEdit->setObjectName("sayLineEdit");

        horizontalLayout_4->addWidget(sayLineEdit);

        sayButton = new QPushButton(chatPage);
        sayButton->setObjectName("sayButton");

        horizontalLayout_4->addWidget(sayButton);

        logoutButton = new QPushButton(chatPage);
        logoutButton->setObjectName("logoutButton");

        horizontalLayout_4->addWidget(logoutButton);


        verticalLayout->addLayout(horizontalLayout_4);

        stackedWidget->addWidget(chatPage);

        gridLayout_2->addWidget(stackedWidget, 1, 0, 1, 1);

        titleLabel = new QLabel(centralwidget);
        titleLabel->setObjectName("titleLabel");

        gridLayout_2->addWidget(titleLabel, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\350\201\212\345\244\251\345\256\244\345\256\242\346\210\267\347\253\257", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\346\234\215\345\212\241\345\231\250\345\234\260\345\235\200\357\274\232", nullptr));
        serverEdit->setText(QCoreApplication::translate("MainWindow", "127.0.0.1", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\346\230\265\347\247\260\357\274\232", nullptr));
        usernameEdit->setText(QCoreApplication::translate("MainWindow", "lwh", nullptr));
        loginButton->setText(QCoreApplication::translate("MainWindow", "\347\231\273\345\275\225\350\201\212\345\244\251\345\256\244", nullptr));
        sayButton->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
        logoutButton->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        titleLabel->setText(QCoreApplication::translate("MainWindow", "\345\210\230\344\274\237\345\215\216\347\232\204\350\201\212\345\244\251\345\256\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
