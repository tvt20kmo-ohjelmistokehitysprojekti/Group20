#include "balance.h"
#include "ui_balance.h"

Balance::Balance(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Balance)
{
    ui->setupUi(this);
}

Balance::~Balance()
{
    delete ui;
}

void Balance::on_btnLogout_clicked()
{
    emit logoutClicked();
}

void Balance::on_btnBack_clicked()
{
    emit backClicked();
}
