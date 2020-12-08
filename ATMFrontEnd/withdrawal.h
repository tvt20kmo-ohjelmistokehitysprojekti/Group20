#ifndef WITHDRAWAL_H
#define WITHDRAWAL_H

#include <QWidget>

namespace Ui {
class Withdrawal;
}

class Withdrawal : public QWidget
{
    Q_OBJECT

public:
    explicit Withdrawal(QWidget *parent = nullptr);
    ~Withdrawal();

private slots:
    void on_btnLogout_clicked();

    void on_btnBack_clicked();

    void on_btnOther_clicked();

    void on_btn20_clicked();

    void on_btn60_clicked();

    void on_btn40_clicked();

    void on_btn90_clicked();

    void on_btn140_clicked();

    void on_btn240_clicked();

signals:
    void logoutClicked();
    void backClicked();
    void otherClicked();
    void clicked(int amount);

private:
    Ui::Withdrawal *ui;
};

#endif // WITHDRAWAL_H
