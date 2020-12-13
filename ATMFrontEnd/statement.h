#ifndef STATEMENT_H
#define STATEMENT_H

#include <QWidget>

namespace Ui {
class Statement;
}

class Statement : public QWidget
{
    Q_OBJECT

public:
    explicit Statement(QWidget *parent = nullptr);
    ~Statement();

private:
    Ui::Statement *ui;
};

#endif // STATEMENT_H
