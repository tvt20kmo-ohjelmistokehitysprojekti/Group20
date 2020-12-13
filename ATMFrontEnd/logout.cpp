#include "logout.h"
#include "ui_logout.h"

Logout::Logout(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Logout)
{
    ui->setupUi(this);
}

Logout::~Logout()
{
    delete ui;
}
