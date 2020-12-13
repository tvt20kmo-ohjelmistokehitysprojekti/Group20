#include "withdrawalok.h"
#include "ui_withdrawalok.h"
#include <QPixmap>

WithdrawalOK::WithdrawalOK(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WithdrawalOK)
{
    ui->setupUi(this);
}

WithdrawalOK::~WithdrawalOK()
{
    delete ui;
}

void WithdrawalOK::setAmount(int amount)
{
    QString amountText;
    amountText.setNum(amount);
    amountText.append(" € please");
    ui->labelAmount->setText(amountText);
}


void WithdrawalOK::on_btnLogout_clicked()
{
    emit logoutClicked();
}

void WithdrawalOK::on_btnContinue_clicked()
{
    emit continueClicked();
}
