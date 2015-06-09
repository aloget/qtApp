#include "source.h"

Source::Source(SourceType type_, QVector<QStringList> *staticSetsOfFields_,
               int selectedSetOfFields)
{

}

QVector<QStringList>* Source::getStaticSetsOfFields() const {
    return staticSetsOfFields;
}

int Source::getSelectedSetOfFields() const {
    return selectedSetOfFields;
}
