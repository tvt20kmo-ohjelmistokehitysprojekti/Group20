#ifndef AMOUNT_H
#define AMOUNT_H

#include <QWidget>

namespace Ui {
class Amount;
}

class Amount : public QWidget
{
    Q_OBJECT

public:
    explicit Amount(QWidget *parent = nullptr);
    ~Amount();
    void clear();
    int getAmount();

signals:
    void logoutClicked();
    void backClicked();
    void okClicked();

private slots:
    void on_btnLogout_clicked();
    void on_btnBack_clicked();

    void on_btnOK_clicked();

private:
    Ui::Amount *ui;
};

#endif // AMOUNT_H
