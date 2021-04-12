#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QSystemTrayIcon>
#include "helpform.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void  activeTray(QSystemTrayIcon::ActivationReason reason);
    void  showMenu();
    void  actionWindow();
    void  showMessage();
private:
    Ui::MainWindow *ui;
    QSystemTrayIcon *m_systemTray;
    QMenu *m_menu;
    HelpForm helpform;

};

#endif // MAINWINDOW_H
