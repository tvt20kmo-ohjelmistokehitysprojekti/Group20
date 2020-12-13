#include "database.h"

Database::Database()
{
}

bool Database::open(QString host, QString database, QString user, QString password)
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    //db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName(host);
    db.setDatabaseName(database);
    db.setUserName(user);
    db.setPassword(password);
    bool ok = db.open();
    return ok;
}
