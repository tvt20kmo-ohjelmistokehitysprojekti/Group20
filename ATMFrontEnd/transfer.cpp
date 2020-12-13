#include "transfer.h"
#include "ui_transfer.h"

Transfer::Transfer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Transfer)
{
    ui->setupUi(this);
}

Transfer::~Transfer()
{
    delete ui;
}

void Transfer::on_btnLogout_clicked()
{
    emit logoutClicked();
}

void Transfer::on_btnBack_clicked()
{
    emit backClicked();
}

void Transfer::on_btnOK_clicked()
{
    emit okClicked();
}
