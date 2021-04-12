#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //    const char * strCmd = "wmic diskdrive get serialnumber";
    //    FILE   *stream;
    //    char   buf[100]={0};
    //    stream = popen(strCmd, "r");
    //    QString serialbumber;
    //    while (fgets(buf,sizeof(buf),stream) != NULL)
    //    {
    //        QString str = QString(buf).trimmed();
    //        if(str!="SerialNumber"){
    //            serialbumber.append(str);
    //        }
    //    }
    //    qDebug()<<"serialbumber "<<serialbumber;
    //    pclose(stream);

    m_systemTray = new QSystemTrayIcon(this);
    m_menu = new QMenu(this);
    QAction *m_action;
    QStringList lits;
    lits<<"显示窗口"<<"产品注册"<<"关于"<<"退出";
    for (int i = 0; i < lits.length(); ++i) {
        m_action = new QAction(m_menu);
        m_action->setText(lits.at(i));
        m_menu->addAction(m_action);
        connect(m_action, &QAction::triggered, this, &MainWindow::actionWindow);

    }

    m_systemTray->setContextMenu(m_menu);
    m_systemTray->setIcon(QIcon(":/image/6.ico"));
    m_systemTray->setToolTip("盘古神速网盘");
    m_systemTray->show();
    connect(m_systemTray, &QSystemTrayIcon::activated, this, &MainWindow::activeTray);//点击托盘，执行相应的动作

}

void MainWindow::activeTray(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason)
    {
    case QSystemTrayIcon::Context:
        showMenu();
        break;
    case QSystemTrayIcon::DoubleClick:
        //showWindow();
        break;
    case QSystemTrayIcon::Trigger:
        showMessage();
        break;
    }
}

void MainWindow::showMenu()
{
    m_menu->show();
}

void MainWindow::actionWindow()
{
    QAction *act=(QAction*)sender();
    if(act->text()=="关于"){
        helpform.show();
    }

}

void MainWindow::showMessage()
{
    this->show();

}

MainWindow::~MainWindow()
{

    delete  m_menu;
    delete m_systemTray;
    delete ui;
}
