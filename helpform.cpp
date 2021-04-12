#include "helpform.h"
#include "ui_helpform.h"
#include <QDate>
#include "qicon.h"
HelpForm::HelpForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HelpForm)
{
    ui->setupUi(this);
    this->setWindowTitle("帮助");
    this->setWindowIcon(QIcon(":/image/6.ico"));
    setWindowFlags (Qt::WindowTitleHint | Qt::WindowSystemMenuHint | Qt::WindowCloseButtonHint);
    this->setWindowModality(Qt::ApplicationModal);
}

HelpForm::~HelpForm()
{
    delete ui;
}
