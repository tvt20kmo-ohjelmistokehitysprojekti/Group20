#include "transferok.h"
#include "ui_transferok.h"

TransferOK::TransferOK(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TransferOK)
{
    ui->setupUi(this);
}

TransferOK::~TransferOK()
{
    delete ui;
}

void TransferOK::on_btnLogout_clicked()
{
    emit logoutClicked();
}

void TransferOK::on_btnContinue_clicked()
{
    emit continueClicked();
}
