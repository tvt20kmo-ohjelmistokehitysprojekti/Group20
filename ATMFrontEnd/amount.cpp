#include "amount.h"
#include "ui_amount.h"

Amount::Amount(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Amount)
{
    ui->setupUi(this);
}

Amount::~Amount()
{
    delete ui;
}

void Amount::clear()
{
    ui->lineAmount->clear();
}

int Amount::getAmount()
{
    bool ok;
    int amount = ui->lineAmount->text().toInt(&ok);
    if (!ok) amount = -666;
    return amount;
}


void Amount::on_btnLogout_clicked()
{
    emit logoutClicked();
}

void Amount::on_btnBack_clicked()
{
    emit backClicked();
}


void Amount::on_btnOK_clicked()
{
    emit okClicked();
}
