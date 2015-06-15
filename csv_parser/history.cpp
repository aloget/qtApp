#include "history.h"
#include "ui_history.h"

History::History(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::History)
{
    ui->setupUi(this);
}

History::~History()
{
    delete ui;
}

void History::setDB(DBHelper* db_) {
    db = db_;
}

void History::appendString(QString string) {
    ui->textEdit->append(string);
}
