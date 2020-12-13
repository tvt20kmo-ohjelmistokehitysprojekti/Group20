#ifndef TRANSFER_H
#define TRANSFER_H

#include <QWidget>

namespace Ui {
class Transfer;
}

class Transfer : public QWidget
{
    Q_OBJECT

public:
    explicit Transfer(QWidget *parent = nullptr);
    ~Transfer();

signals:
    void logoutClicked();
    void backClicked();
    void okClicked();

private slots:
    void on_btnLogout_clicked();

    void on_btnBack_clicked();

    void on_btnOK_clicked();

private:
    Ui::Transfer *ui;
};

#endif // TRANSFER_H
