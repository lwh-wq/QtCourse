#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QStack>
#include <QKeyEvent>
#include <QMap>
#include <QPushButton>
#include <QListWidget>
#include <QVBoxLayout>
#include <QDialog>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QActionGroup>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    // 主题枚举
    enum Theme {
        DarkTheme,
        LightTheme,
        BlueTheme
    };
    
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    
    // 主题相关
    void setTheme(Theme theme);
    
private slots:
    void btnNumClicked();
    void btnBinaryOperatorClicked();
    void btnUnaryOperatorClicked();
    void on_btnPeriod_clicked();

    void on_btnDel_clicked();
    void on_btnClear_clicked(); // 添加CE按钮的槽函数
    void on_btnClearAll_clicked();

    void on_btnEqual_clicked();
    void btnSignClicked();
    
    // 键盘事件处理
    virtual void keyPressEvent(QKeyEvent *event);
    
    // 菜单相关槽函数
    void on_actionHistory_triggered();
    void on_actionDarkTheme_triggered();
    void on_actionLightTheme_triggered();
    void on_actionBlueTheme_triggered();

private:
    Ui::MainWindow *ui;
    
    // 计算器核心数据
    QString operand;
    QString opcode;
    QStack<QString> operands;
    QStack<QString> opcodes;
    
    // 按钮映射
    QMap<int, QPushButton *> digitBTNs;
    QMap<int, QPushButton*> funcBTNs;
    
    // 历史记录相关
    QStringList history;
    QDialog *historyDialog;
    QListWidget *historyListWidget;
    
    // 主题相关
    Theme currentTheme;
    
    // 菜单相关
    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *viewMenu;
    QMenu *helpMenu;
    
    QAction *actionHistory;
    QAction *actionDarkTheme;
    QAction *actionLightTheme;
    QAction *actionBlueTheme;
    
    // 私有方法
    QString calculation(bool *ok=NULL);
    void addToHistory(const QString &expression, const QString &result);
    void showHistoryDialog();
    void createMenus();
};
#endif // MAINWINDOW_H
