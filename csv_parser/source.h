#ifndef SOURCE_H
#define SOURCE_H

#include <QObject>

class Source
{

public:
    enum SourceType {
        BOOK, MULTIPART_BOOK, ARTICLE, WEB
    };

    Source(SourceType type_, QVector<QStringList> *staticSetsOfFields_,
           int selectedSetOfFields);

    QVector<QStringList>* getStaticSetsOfFields() const;
    int getSelectedSetOfFields() const;

private:
    SourceType type;
    QVector<QStringList> *staticSetsOfFields;
    int selectedSetOfFields;

    //need to implement ordering as well



};

#endif // SOURCE_H
