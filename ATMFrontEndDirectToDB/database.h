#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>
#include <QSqlDatabase>


class Database
{
public:
    Database();
    bool open(QString host, QString database, QString user, QString password);


private:
    QSqlDatabase db;
};

#endif // DATABASE_H
