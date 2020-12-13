#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <amount.h>
#include <balance.h>
#include <dblogin.h>
#include <login.h>
#include <logout.h>
#include <mainmenu.h>
#include <amount.h>
#include <selectaccount.h>
#include <statement.h>
#include <transfer.h>
#include <withdrawal.h>
#include <withdrawalok.h>
#include <transferok.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Amount amount;
    Balance balance;
    DBLogin dbLogin;
    Login login;
    Logout logout;
    MainMenu mainMenu;
    SelectAccount selectAccount;
    Statement statement;
    Transfer transfer;
    Withdrawal withdrawal;
    WithdrawalOK withdrawalOK;
    TransferOK transferOK;

    void gotoLogin();
    void gotoMainMenu();
    void gotoAmount();
    void gotoWithdrawal();
    void clearAll();
    void gotoWithdrawalOK();
    void gotoBalanced();
    void gotoTransfer();
    void gotoTransferOK();


private slots:
    void selectAccount_selectClicked();
    void dbLogin_loginClicked();
    void login_loginClicked();
    void mainMenu_logoutClicked();
    void selectAccount_logoutClicked();
    void withdrawal_logoutClicked();
    void withdrawal_backClicked();
    void withdrawal_otherClicked();
    void withdrawal_clicked(int amount);
    void mainMenu_withdrawalClicked();
    void amount_logoutClicked();
    void amount_backClicked();
    void amount_okClicked();
    void withdrawalOK_continueClicked();
    void withdrawalOK_logoutClicked();
    void mainMenu_balanceClicked();
    void balance_logoutClicked();
    void balance_backClicked();
    void mainMenu_transferClicked();
    void transfer_logoutClicked();
    void transfer_backClicked();
    void transfer_okClicked();
    void transferOK_logoutClicked();
    void transferOK_continueClicked();

};
#endif // MAINWINDOW_H
