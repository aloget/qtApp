#include "parsersession.h"

ParserSession::ParserSession(QObject *parent) : QObject(parent)
{
    csv = new CSVObject(this);
    html = new HTMLObject(this);
    configuration = new Configuration(this);
}

ParserSession::ParserSession(QString csvDir, QString htmlDir, QObject *parent) {
    csv = new CSVObject(csvDir, this);
    html = new HTMLObject(htmlDir, this);
    configuration = new Configuration(this);
}


bool ParserSession::start(){
    if (Parser::parse(csv, html, configuration)) {
        return true;
    }
    else {
        return false;
    }
}
