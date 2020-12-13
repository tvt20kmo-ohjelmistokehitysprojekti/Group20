#include "statement.h"
#include "ui_statement.h"

Statement::Statement(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Statement)
{
    ui->setupUi(this);
}

Statement::~Statement()
{
    delete ui;
}
