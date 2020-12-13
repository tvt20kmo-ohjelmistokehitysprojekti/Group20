#ifndef WITHDRAWALOK_H
#define WITHDRAWALOK_H

#include <QWidget>

namespace Ui {
class WithdrawalOK;
}

class WithdrawalOK : public QWidget
{
    Q_OBJECT

public:
    explicit WithdrawalOK(QWidget *parent = nullptr);
    ~WithdrawalOK();
    void setAmount(int amount);

signals:
    void logoutClicked();
    void continueClicked();

private slots:
    void on_btnLogout_clicked();

    void on_btnContinue_clicked();

private:
    Ui::WithdrawalOK *ui;
};

#endif // WITHDRAWALOK_H
