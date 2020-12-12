#ifndef TRANSFEROK_H
#define TRANSFEROK_H

#include <QWidget>

namespace Ui {
class TransferOK;
}

class TransferOK : public QWidget
{
    Q_OBJECT

public:
    explicit TransferOK(QWidget *parent = nullptr);
    ~TransferOK();

signals:
    void logoutClicked();
    void continueClicked();


private slots:
    void on_btnLogout_clicked();

    void on_btnContinue_clicked();

private:
    Ui::TransferOK *ui;
};

#endif // TRANSFEROK_H
