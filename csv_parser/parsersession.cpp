#include "parsersession.h"
#include <QDebug>
#include <QVector>
#include <QStringList>

ParserSession::ParserSession(QObject *parent) : QObject(parent)
{
    csv = new CSVObject(this);
    html = new HTMLObject(this);
    configuration = new Configuration(this);
}

ParserSession::ParserSession(QString csvDir, QString htmlDir, QObject *parent) {
    configuration = new Configuration(this);
    db = new DBHelper(this);
    csv = new CSVObject(csvDir, configuration, this);
    html = new HTMLObject(htmlDir, this);
    html->setCSSString(configuration->getCSS());
}


bool ParserSession::start(){
    QVector <QStringList> data = db->getData();
    for (int i = 0; i < data.count(); i++) {
        QStringList sourceInfo = data.at(i);
        foreach (QString str, sourceInfo) {
            qDebug() << str;
        }
    }


    if (csv->getStringInterpretation() == NULL) {
        return false;
    }
    if (Parser::parse(csv, html, configuration)) {
        db->insertValues(csv->getDirectory(), html->getHTMLDirectory());
        return true;
    }
    else {
        return false;
    }
}
