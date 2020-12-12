#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->windowStack->addWidget(&amount);
    ui->windowStack->addWidget(&balance);
    ui->windowStack->addWidget(&dbLogin);
    ui->windowStack->addWidget(&login);
    ui->windowStack->addWidget(&logout);
    ui->windowStack->addWidget(&mainMenu);
    ui->windowStack->addWidget(&amount);
    ui->windowStack->addWidget(&selectAccount);
    ui->windowStack->addWidget(&statement);
    ui->windowStack->addWidget(&transfer);
    ui->windowStack->addWidget(&withdrawal);
    ui->windowStack->addWidget(&withdrawalOK);
    ui->windowStack->addWidget(&transferOK);

    ui->windowStack->setCurrentWidget(&dbLogin);

    connect(&selectAccount, SIGNAL(selectClicked()), this, SLOT(selectAccount_selectClicked()));
    connect(&dbLogin, SIGNAL(loginClicked()), this, SLOT(dbLogin_loginClicked()));
    connect(&login, SIGNAL(loginClicked()), this, SLOT(login_loginClicked()));
    connect(&mainMenu, SIGNAL(logoutClicked()), this, SLOT(mainMenu_logoutClicked()));
    connect(&selectAccount, SIGNAL(logoutClicked()), this, SLOT(selectAccount_logoutClicked()));
    connect(&withdrawal, SIGNAL(logoutClicked()), this, SLOT(withdrawal_logoutClicked()));
    connect(&mainMenu, SIGNAL(withdrawalClicked()), this, SLOT(mainMenu_withdrawalClicked()));
    connect(&withdrawal, SIGNAL(backClicked()), this, SLOT(withdrawal_backClicked()));
    connect(&withdrawal, SIGNAL(otherClicked()), this, SLOT(withdrawal_otherClicked()));
    connect(&withdrawal, SIGNAL(clicked(int)), this, SLOT(withdrawal_clicked(int)));
    connect(&amount, SIGNAL(logoutClicked()), this, SLOT(amount_logoutClicked()));
    connect(&amount, SIGNAL(backClicked()), this, SLOT(amount_backClicked()));
    connect(&amount, SIGNAL(okClicked()), this, SLOT(amount_okClicked()));
    connect(&withdrawalOK, SIGNAL(logoutClicked()), this,SLOT(withdrawalOK_logoutClicked()));
    connect(&withdrawalOK, SIGNAL(continueClicked()), this, SLOT(withdrawalOK_continueClicked()));
    connect(&mainMenu, SIGNAL(balanceClicked()), this, SLOT(mainMenu_balanceClicked()));
    connect(&mainMenu, SIGNAL(transferClicked()), this, SLOT(mainMenu_transferClicked()));
    connect(&balance, SIGNAL(logoutClicked()), this, SLOT(balance_logoutClicked()));
    connect(&balance, SIGNAL(backClicked()), this, SLOT(balance_backClicked()));
    connect(&transfer, SIGNAL(logoutClicked()), this, SLOT(transfer_logoutClicked()));
    connect(&transfer, SIGNAL(backClicked()), this, SLOT(transfer_backClicked()));
    connect(&transfer, SIGNAL(okClicked()), this, SLOT(transfer_okClicked()));
    connect(&transferOK, SIGNAL(logoutClicked()), this, SLOT(transferOK_logoutClicked()));
    connect(&transferOK, SIGNAL(continueClicked()), this, SLOT(transferOK_continueClicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::selectAccount_selectClicked()
{
    ui->windowStack->setCurrentWidget(&mainMenu);
}

void MainWindow::dbLogin_loginClicked()
{
    ui->windowStack->setCurrentWidget(&login);
}

void MainWindow::login_loginClicked()
{
    ui->windowStack->setCurrentWidget(&selectAccount);
}

void MainWindow::mainMenu_logoutClicked()
{
    clearAll();
    gotoLogin();
}

void MainWindow::selectAccount_logoutClicked()
{
    clearAll();
    gotoLogin();
}

void MainWindow::gotoLogin()
{
    clearAll();
    ui->windowStack->setCurrentWidget(&login);
    //login.clear();
}

void MainWindow::clearAll()
{
    login.clear();
    amount.clear();
    //balance.clear();
    //selectAccount.clear();
    //statement.clear();
    //transfer.clear();
}

void MainWindow::gotoMainMenu()
{
    clearAll();
    ui->windowStack->setCurrentWidget(&mainMenu);
}

void MainWindow::gotoAmount()
{
    clearAll();
    ui->windowStack->setCurrentWidget(&amount);
    //amount.clear();
}

void MainWindow::gotoWithdrawal()
{
    clearAll();
    ui->windowStack->setCurrentWidget(&withdrawal);
}

void MainWindow::gotoWithdrawalOK()
{
    clearAll();
    ui->windowStack->setCurrentWidget(&withdrawalOK);
}

void MainWindow::gotoBalanced()
{
    clearAll();
    ui->windowStack->setCurrentWidget(&balance);
}

void MainWindow::gotoTransfer()
{
    clearAll();
    ui->windowStack->setCurrentWidget(&transfer);
}

void MainWindow::gotoTransferOK()
{
    clearAll();
    ui->windowStack->setCurrentWidget(&transferOK);
}

void MainWindow::withdrawal_logoutClicked()
{
    gotoLogin();
}

void MainWindow::withdrawal_backClicked()
{
    gotoMainMenu();
}

void MainWindow::withdrawal_otherClicked()
{
    gotoAmount();
}

void MainWindow::mainMenu_withdrawalClicked()
{
    gotoWithdrawal();
}

void MainWindow::amount_logoutClicked()
{
    gotoLogin();
}

void MainWindow::amount_backClicked()
{
    gotoMainMenu();
}

void MainWindow::amount_okClicked()
{
    withdrawalOK.setAmount(amount.getAmount());
    gotoWithdrawalOK();
}

void MainWindow::withdrawalOK_continueClicked()
{
    gotoMainMenu();
}

void MainWindow::withdrawalOK_logoutClicked()
{
    gotoLogin();
}

void MainWindow::mainMenu_balanceClicked()
{
    gotoBalanced();
}

void MainWindow::balance_logoutClicked()
{
    gotoLogin();
}

void MainWindow::balance_backClicked()
{
    gotoMainMenu();
}

void MainWindow::mainMenu_transferClicked()
{
    gotoTransfer();
}

void MainWindow::transfer_logoutClicked()
{
    gotoLogin();
}

void MainWindow::transfer_backClicked()
{
    gotoMainMenu();
}

void MainWindow::transfer_okClicked()
{
    gotoTransferOK();
}

void MainWindow::transferOK_logoutClicked()
{
    gotoLogin();
}

void MainWindow::transferOK_continueClicked()
{
    gotoMainMenu();
}

void MainWindow::withdrawal_clicked(int amount)
{
    withdrawalOK.setAmount(amount);
    gotoWithdrawalOK();
}



