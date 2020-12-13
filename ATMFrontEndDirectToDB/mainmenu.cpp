#include "mainmenu.h"
#include "ui_mainmenu.h"

MainMenu::MainMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_btnLogout_clicked()
{
    emit logoutClicked();
}

void MainMenu::on_btnWithdrawal_clicked()
{
    emit withdrawalClicked();
}

void MainMenu::on_btnBalance_clicked()
{
    emit balanceClicked();
}

void MainMenu::on_btnTransfer_clicked()
{
    emit transferClicked();
}

