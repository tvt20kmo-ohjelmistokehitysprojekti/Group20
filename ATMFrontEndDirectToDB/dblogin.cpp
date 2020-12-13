#include "dblogin.h"
#include "ui_dblogin.h"

DBLogin::DBLogin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DBLogin)
{
    ui->setupUi(this);
}

DBLogin::~DBLogin()
{
    delete ui;
}

void DBLogin::clear()
{
    ui->lineAddress->clear();
    ui->lineUsername->clear();
    ui->linePassword->clear();
}

void DBLogin::on_btnLogin_clicked()
{
    emit loginClicked(ui->lineAddress->text(), ui->lineUsername->text(), ui->linePassword->text());
}

void DBLogin::on_btnCancel_clicked()
{
    clear();
}
