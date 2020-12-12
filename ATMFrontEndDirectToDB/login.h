#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();
    void clear();
    QString getCardID();

private slots:
    void on_btnCancel_clicked();
    void on_btnLogin_clicked();

private:
    Ui::Login *ui;


signals:
    void loginClicked();


};

#endif // LOGIN_H
