#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>

namespace Ui {
class MainMenu;
}

class MainMenu : public QWidget
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = nullptr);
    ~MainMenu();

private:
    Ui::MainMenu *ui;

signals:
    void logoutClicked();
    void withdrawalClicked();
    void balanceClicked();
    void transferClicked();

private slots:
    void on_btnLogout_clicked();
    void on_btnWithdrawal_clicked();
    void on_btnBalance_clicked();
    void on_btnTransfer_clicked();
};

#endif // MAINMENU_H
