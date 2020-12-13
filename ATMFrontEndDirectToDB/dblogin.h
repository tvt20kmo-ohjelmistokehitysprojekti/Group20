#ifndef DBLOGIN_H
#define DBLOGIN_H

#include <QWidget>

namespace Ui {
class DBLogin;
}

class DBLogin : public QWidget
{
    Q_OBJECT

public:
    explicit DBLogin(QWidget *parent = nullptr);
    ~DBLogin();
    void clear();

private slots:
    void on_btnLogin_clicked();
    void on_btnCancel_clicked();

private:
    Ui::DBLogin *ui;

signals:
    void loginClicked(QString address, QString user, QString password);

};


#endif // DBLOGIN_H
