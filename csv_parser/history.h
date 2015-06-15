#ifndef HISTORY_H
#define HISTORY_H

#include <QDialog>
#include "dbhelper.h"

namespace Ui {
class History;
}

class History : public QDialog
{
    Q_OBJECT

public:
    explicit History(QWidget *parent = 0);
    ~History();

    void setDB(DBHelper* db_);

private:
    void appendString(QString string);

    Ui::History *ui;
    DBHelper* db;
};

#endif // HISTORY_H
