#include "parsersession.h"

ParserSession::ParserSession(QObject *parent) : QObject(parent)
{
    csv = new CSVObject(this);
    html = new HTMLObject(this);
    configuration = new Configuration(this);
}

ParserSession::ParserSession(QString csvDir, QString htmlDir, QObject *parent) {
    configuration = new Configuration(this);
    csv = new CSVObject(csvDir, configuration, this);
    html = new HTMLObject(htmlDir, this);
    html->setCSSString(configuration->getCSS());
}


bool ParserSession::start(){
    if (csv->getStringInterpretation() == NULL) {
        return false;
    }
    if (Parser::parse(csv, html, configuration)) {
        return true;
    }
    else {
        return false;
    }
}
