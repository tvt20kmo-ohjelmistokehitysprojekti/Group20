#include "withdrawal.h"
#include "ui_withdrawal.h"

Withdrawal::Withdrawal(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Withdrawal)
{
    ui->setupUi(this);
}

Withdrawal::~Withdrawal()
{
    delete ui;
}

void Withdrawal::on_btnLogout_clicked()
{
    emit logoutClicked();
}

void Withdrawal::on_btnBack_clicked()
{
    emit backClicked();
}

void Withdrawal::on_btnOther_clicked()
{
    emit otherClicked();
}

void Withdrawal::on_btn20_clicked()
{
    emit clicked(20);
}

void Withdrawal::on_btn40_clicked()
{
    emit clicked(40);
}

void Withdrawal::on_btn60_clicked()
{
    emit clicked(60);
}

void Withdrawal::on_btn90_clicked()
{
    emit clicked(90);
}

void Withdrawal::on_btn140_clicked()
{
    emit clicked(140);
}

void Withdrawal::on_btn240_clicked()
{
    emit clicked(240);
}
