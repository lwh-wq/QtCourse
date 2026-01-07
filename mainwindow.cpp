#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <math.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    
    // 初始化显示为0
    operand = "0";
    ui->display->setText(operand);
    
    // 初始化数字按钮映射
    digitBTNs = {
        {Qt::Key_0, ui->btnNum0},
        {Qt::Key_1, ui->btnNum1},
        {Qt::Key_2, ui->btnNum2},
        {Qt::Key_3, ui->btnNum3},
        {Qt::Key_4, ui->btnNum4},
        {Qt::Key_5, ui->btnNum5},
        {Qt::Key_6, ui->btnNum6},
        {Qt::Key_7, ui->btnNum7},
        {Qt::Key_8, ui->btnNum8},
        {Qt::Key_9, ui->btnNum9}
    };
    
    // 初始化功能按钮映射
    funcBTNs = {
        {Qt::Key_Plus, ui->btnPlus},        // 加号 +
        {Qt::Key_Minus, ui->btnMinus},      // 减号 -
        {Qt::Key_Asterisk, ui->btnMultiple},// 乘号 ×（键盘*键）
        {Qt::Key_Slash, ui->btnDivide},     // 除号 /
        {Qt::Key_Period, ui->btnPeriod},    // 小数点 .
        {Qt::Key_Backspace, ui->btnDel},    // 删除键 ←
        {Qt::Key_Escape, ui->btnClearAll},  // ESC键 清空
        {Qt::Key_Enter, ui->btnEqual},      // 回车键 =
        {Qt::Key_Return, ui->btnEqual}      // 小回车键 =
    };
    
    // 连接数字按钮信号槽
    foreach(auto btn, digitBTNs.values())
        connect(btn, SIGNAL(clicked()), this, SLOT(btnNumClicked()));
    
    // 确保0号按钮也被连接
    connect(ui->btnNum0, SIGNAL(clicked()), this, SLOT(btnNumClicked()));
    
    // 连接运算符按钮信号槽
    connect(ui->btnMultiple, SIGNAL(clicked()), this, SLOT(btnBinaryOperatorClicked()));
    connect(ui->btnMinus, SIGNAL(clicked()), this, SLOT(btnBinaryOperatorClicked()));
    connect(ui->btnPlus, SIGNAL(clicked()), this, SLOT(btnBinaryOperatorClicked()));
    connect(ui->btnDivide, SIGNAL(clicked()), this, SLOT(btnBinaryOperatorClicked()));
    
    // 连接单目运算符按钮信号槽
    connect(ui->btnInverse, SIGNAL(clicked()), this, SLOT(btnUnaryOperatorClicked()));
    connect(ui->btnPercentage, SIGNAL(clicked()), this, SLOT(btnUnaryOperatorClicked()));
    connect(ui->btnSqrt, SIGNAL(clicked()), this, SLOT(btnUnaryOperatorClicked()));
    connect(ui->btnSquare, SIGNAL(clicked()), this, SLOT(btnUnaryOperatorClicked()));
    connect(ui->btnSign, SIGNAL(clicked()), this, SLOT(btnSignClicked()));
    
    // 初始化历史记录对话框
    historyDialog = nullptr;
    historyListWidget = nullptr;
    
    // 创建菜单
    createMenus();
    
    // 初始化主题
    currentTheme = DarkTheme;
    setTheme(currentTheme);
}

// 创建菜单
void MainWindow::createMenus()
{
    // 创建文件菜单
    fileMenu = menuBar()->addMenu(tr("文件(&F)"));
    
    // 创建编辑菜单
    editMenu = menuBar()->addMenu(tr("编辑(&E)"));
    
    // 创建历史记录动作
    actionHistory = new QAction(tr("历史记录(&H)"), this);
    connect(actionHistory, SIGNAL(triggered()), this, SLOT(on_actionHistory_triggered()));
    editMenu->addAction(actionHistory);
    
    // 创建视图菜单
    viewMenu = menuBar()->addMenu(tr("视图(&V)"));
    
    // 创建主题子菜单
    QMenu *themeMenu = new QMenu(tr("主题(&T)"), this);
    viewMenu->addMenu(themeMenu);
    
    // 创建主题切换动作
    actionDarkTheme = new QAction(tr("深色主题"), this);
    actionDarkTheme->setCheckable(true);
    actionDarkTheme->setChecked(true);
    connect(actionDarkTheme, SIGNAL(triggered()), this, SLOT(on_actionDarkTheme_triggered()));
    themeMenu->addAction(actionDarkTheme);
    
    actionLightTheme = new QAction(tr("浅色主题"), this);
    actionLightTheme->setCheckable(true);
    connect(actionLightTheme, SIGNAL(triggered()), this, SLOT(on_actionLightTheme_triggered()));
    themeMenu->addAction(actionLightTheme);
    
    actionBlueTheme = new QAction(tr("蓝色主题"), this);
    actionBlueTheme->setCheckable(true);
    connect(actionBlueTheme, SIGNAL(triggered()), this, SLOT(on_actionBlueTheme_triggered()));
    themeMenu->addAction(actionBlueTheme);
    
    // 将主题动作添加到一个组，确保只有一个被选中
    QActionGroup *themeGroup = new QActionGroup(this);
    themeGroup->addAction(actionDarkTheme);
    themeGroup->addAction(actionLightTheme);
    themeGroup->addAction(actionBlueTheme);
    
    // 创建帮助菜单
    helpMenu = menuBar()->addMenu(tr("帮助(&H)"));
}

// 菜单相关槽函数
void MainWindow::on_actionHistory_triggered()
{
    showHistoryDialog();
}

void MainWindow::on_actionDarkTheme_triggered()
{
    setTheme(DarkTheme);
}

void MainWindow::on_actionLightTheme_triggered()
{
    setTheme(LightTheme);
}

void MainWindow::on_actionBlueTheme_triggered()
{
    setTheme(BlueTheme);
}

// 设置主题
void MainWindow::setTheme(Theme theme)
{
    // 简化主题切换，保留UI文件中的样式表
    // 只更新主题状态
    currentTheme = theme;
    
    // 可以在这里添加主题切换逻辑，如果需要的话
    // 目前保留UI文件中的样式表
}

MainWindow::~MainWindow()
{
    // 清理历史记录对话框
    if (historyDialog != nullptr) {
        delete historyDialog;
        historyDialog = nullptr;
    }
    
    delete ui;
}

// 历史记录相关方法
void MainWindow::addToHistory(const QString &expression, const QString &result)
{
    QString historyEntry = expression + " = " + result;
    history.prepend(historyEntry); // 添加到历史记录开头
    
    // 限制历史记录数量
    if (history.size() > 50) {
        history.removeLast();
    }
}

void MainWindow::showHistoryDialog()
{
    if (historyDialog == nullptr) {
        // 创建历史记录对话框
        historyDialog = new QDialog(this);
        historyDialog->setWindowTitle("历史记录");
        historyDialog->resize(400, 300);
        
        // 创建布局
        QVBoxLayout *layout = new QVBoxLayout(historyDialog);
        
        // 创建列表控件
        historyListWidget = new QListWidget(historyDialog);
        layout->addWidget(historyListWidget);
        
        // 设置对话框布局
        historyDialog->setLayout(layout);
    }
    
    // 更新历史记录列表
    historyListWidget->clear();
    foreach (const QString &entry, history) {
        historyListWidget->addItem(entry);
    }
    
    // 显示对话框
    historyDialog->exec();
}



// CE按钮的槽函数
void MainWindow::on_btnClear_clicked()
{
    operand = "0"; // CE按钮只清空当前输入的操作数
    ui->display->setText(operand);
    ui->statusbar->showMessage("Cleared current operand");
}

QString MainWindow::calculation(bool *ok)
{
    double result=0;
    if(operands.size()>=2&&!opcodes.isEmpty()){
        //取操作数（注意顺序：栈顶是第二个操作数）
        double operand2=operands.back().toDouble();
        operands.pop_back();
        double operand1=operands.back().toDouble();
        operands.pop_back();
        //取操作符
        QString op=opcodes.back();
        opcodes.pop_back();
        
        bool calculationOk = true;
        QString expression = QString::number(operand1) + " " + op + " " + QString::number(operand2);
        
        if(op=="+"){
            result=operand1+operand2;
        }
        else if(op=="-"){
            result=operand1-operand2;
        }
        else if(op=="×"){
            result=operand1*operand2;
        }
        else if(op=="/"){
            if(operand2==0){
                calculationOk = false;
                result = 0;
                ui->statusbar->showMessage("Error: Division by zero");
            } else {
                result=operand1/operand2;
            }
        }
        else if(op=="^"){
            result=pow(operand1, operand2);
        }
        
        if(ok != NULL) {
            *ok = calculationOk;
        }
        
        QString resultStr = QString::number(result, 'g', 15);
        
        // 将结果压回栈中，支持连续运算
        operands.push_back(resultStr);
        
        // 添加到历史记录
        addToHistory(expression, resultStr);
        
        ui->statusbar->showMessage(QString("Calculation: %1 = %2").arg(expression).arg(resultStr));
        
        return resultStr;
    }
    else if(operands.size()==1){
        // 只有一个操作数，直接返回
        result = operands.back().toDouble();
        return QString::number(result, 'g', 15);
    }
    else {
        ui->statusbar->showMessage(QString("Operand stack size: %1, Operator stack size: %2").arg(operands.size()).arg(opcodes.size()));
        return "0";
    }
}

void MainWindow::btnNumClicked()
{
    QString digit=qobject_cast<QPushButton*>(sender())->text();
    
    // 处理初始状态
    if(operand.isEmpty() || operand == "0"){
        if(digit == "0") {
            operand = "0"; // 保留单个0
        } else {
            operand = digit; // 替换初始0
        }
    } else {
        operand += digit; // 追加数字
    }
    
    ui->display->setText(operand);
}

void MainWindow::on_btnPeriod_clicked()
{
    if(operand.isEmpty()) {
        operand = "0."; // 空输入时添加小数点，自动补0
    } else if(!operand.contains(".")) {
        operand += ".";
    }
    ui->display->setText(operand);
}

void MainWindow::on_btnDel_clicked()
{
    if(!operand.isEmpty()) {
        operand = operand.left(operand.length()-1);
        // 如果删除后为空，显示0
        if(operand.isEmpty()) {
            operand = "0";
        }
        ui->display->setText(operand);
    }
}

void MainWindow::on_btnClearAll_clicked()
{
    // 清空所有状态
    operand.clear();
    operands.clear();
    opcodes.clear();
    operand = "0"; // 显示0
    ui->display->setText(operand);
    ui->statusbar->showMessage("All cleared");
}

void MainWindow::btnBinaryOperatorClicked()
{
    QString clickedOp=qobject_cast<QPushButton*>(sender())->text();
    ui->statusbar->showMessage("Operator clicked: " + clickedOp);
    
    if(operand!=""){
        // 如果当前有输入的操作数，将其压入栈中
        operands.push_back(operand);
        operand="";
    }
    
    // 如果操作符栈不为空，先计算之前的运算
    if(!opcodes.isEmpty() && operands.size()>=2){
        bool ok;
        QString result=calculation(&ok);
        if(ok) {
            ui->display->setText(result);
        }
    }
    
    // 将当前操作符压入栈中
    opcodes.push_back(clickedOp);
}

void MainWindow::btnUnaryOperatorClicked()
{
    if(operand!=""){
        double result=operand.toDouble();
        bool calculationOk = true;
        
        QString op=qobject_cast<QPushButton*>(sender())->text();
        if(op=="%") {
            result/=100.0;
        } else if(op=="1/x") {
            if(result==0) {
                calculationOk = false;
                ui->statusbar->showMessage("Error: Division by zero");
            } else {
                result =1/result;
            }
        } else if(op=="x^2") {
            result *=result;
        } else if(op=="√") {
            if(result<0) {
                calculationOk = false;
                ui->statusbar->showMessage("Error: Square root of negative number");
            } else {
                result =sqrt(result);
            }
        }
        
        if(calculationOk) {
            operand=QString::number(result, 'g', 15);
            ui->display->setText(operand);
        }
    }
}

void MainWindow::on_btnEqual_clicked()
{
    QString originalOperand = operand;
    
    if(operand!=""){
        // 如果当前有输入的操作数，将其压入栈中
        operands.push_back(operand);
        operand="";
    }
    
    // 构建完整的表达式用于历史记录
    QString expression;
    if(operands.size() == 1 && opcodes.isEmpty()) {
        // 只有一个操作数，直接返回
        expression = originalOperand;
    } else {
        // 构建表达式
        QList<QString> tempOperands = operands;
        QList<QString> tempOpcodes = opcodes;
        
        if(tempOperands.size() > 0) {
            expression = tempOperands.takeFirst();
            
            while(!tempOperands.isEmpty() && !tempOpcodes.isEmpty()) {
                expression += " " + tempOpcodes.takeFirst() + " " + tempOperands.takeFirst();
            }
        }
    }
    
    // 计算所有剩余的运算
    while(!opcodes.isEmpty() && operands.size()>=2){
        bool ok;
        QString result=calculation(&ok);
        if(ok) {
            ui->display->setText(result);
        } else {
            break;
        }
    }
    
    // 如果计算完成后栈中还有结果，将其作为当前操作数
    if(!operands.isEmpty()){
        operand = operands.back();
        operands.clear();
        opcodes.clear();
        
        // 添加到历史记录（如果表达式有效）
        if(!expression.isEmpty() && expression != operand) {
            addToHistory(expression, operand);
        }
    }
}

void MainWindow::btnSignClicked()
{
    if (operand!="") { // 确保当前有输入的数字
        bool isNegative = (operand.startsWith("-"));
        if (isNegative) {
            operand.remove(0, 1); // 移除负号，转为正数
        } else {
            operand = "-" + operand; // 添加负号，转为负数
        }
        ui->display->setText(operand); // 更新显示
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    foreach(auto btnKey,digitBTNs.keys()){
        if(event->key()==btnKey)
            digitBTNs[btnKey]->animateClick();
    }
    foreach(auto btnKey, funcBTNs.keys()){
        if(event->key() == btnKey)
            funcBTNs[btnKey]->animateClick();
    }
}
