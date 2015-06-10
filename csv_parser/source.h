#ifndef SOURCE_H
#define SOURCE_H

#include <QObject>
#include <QStringList>

class Source
{

public:
    enum SourceType {
        BOOK, ARTICLE, WEB
    };

    Source();
    Source(SourceType type_);

//    QVector<QStringList>* getStaticSetsOfFields() const;
//    int getSelectedSetOfFields() const;

    int getMinNumberOfFields() const;
    void setMinNumberOfFields(int);

private:
    SourceType type;
    int minNumberOfFields;//static


//    QVector<QStringList> *staticSetsOfFields;
//    int selectedSetOfFields;
//    int selectedOrder;


};

#endif // SOURCE_H
