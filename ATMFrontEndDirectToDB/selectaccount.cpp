#include "selectaccount.h"
#include "ui_selectaccount.h"

SelectAccount::SelectAccount(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SelectAccount)
{
    ui->setupUi(this);
}

SelectAccount::~SelectAccount()
{
    delete ui;
}

void SelectAccount::on_btnSelect_clicked()
{
    emit selectClicked();
}

void SelectAccount::on_btnLogout_clicked()
{
    emit logoutClicked();
}
