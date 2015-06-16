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

void History::loadData() {

    QVector <QStringList> records = db->getData();
    for (int i = 0; i < records.count(); i++) {
        QStringList record = records.at(i);
        QString textEditItem;
        foreach (QString oneItem, record) {
            textEditItem.append(QString("%1   ").arg(oneItem));
            qDebug() << oneItem;//"1", "users/Anna/desktop/csvFile.csv", "users/Anna/desktop/htmlFile.html"
        }
        ui->textEdit->append(textEditItem);
    }
}

