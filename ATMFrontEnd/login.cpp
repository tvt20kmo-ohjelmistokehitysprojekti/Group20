#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_btnCancel_clicked()
{
    clear();
}

void Login::clear()
{
    ui->lineCardID->clear();
    ui->linePassword->clear();
}

void Login::on_btnLogin_clicked()
{
    emit loginClicked();
}

QString Login::getCardID()
{
    return ui->lineCardID->text();
}
