#ifndef BALANCE_H
#define BALANCE_H

#include <QWidget>

namespace Ui {
class Balance;
}

class Balance : public QWidget
{
    Q_OBJECT

public:
    explicit Balance(QWidget *parent = nullptr);
    ~Balance();

signals:
    void logoutClicked();
    void backClicked();

private slots:
    void on_btnLogout_clicked();

    void on_btnBack_clicked();

private:
    Ui::Balance *ui;
};

#endif // BALANCE_H
