#ifndef SELECTACCOUNT_H
#define SELECTACCOUNT_H

#include <QWidget>

namespace Ui {
class SelectAccount;
}

class SelectAccount : public QWidget
{
    Q_OBJECT

public:
    explicit SelectAccount(QWidget *parent = nullptr);
    ~SelectAccount();

private:
    Ui::SelectAccount *ui;

signals:
    void selectClicked();
    void logoutClicked();

private slots:
    void on_btnSelect_clicked();
    void on_btnLogout_clicked();
};

#endif // SELECTACCOUNT_H
