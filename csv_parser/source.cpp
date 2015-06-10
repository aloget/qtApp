#include "source.h"

Source::Source() {

}


Source::Source(SourceType type_)
{
    type = type_;
}

//QVector<QStringList>* Source::getStaticSetsOfFields() const {
//    return staticSetsOfFields;
//}

//int Source::getSelectedSetOfFields() const {
//    return selectedSetOfFields;
//}

int Source::getMinNumberOfFields() const {
    return minNumberOfFields;
}

void Source::setMinNumberOfFields(int num) {
    minNumberOfFields = num;
}
