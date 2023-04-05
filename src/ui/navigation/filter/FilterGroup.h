//
// Created by Влад Кирилов on 21.03.2023.
//

#ifndef FILTERS_FILTERGROUP_H
#define FILTERS_FILTERGROUP_H

#include <QActionGroup>
#include "instrument/Instrument.h"
#include "ui/button/instrument/FilterAction.h"
#include "ui/navigation/AbstractActionGroup.h"

class FilterGroup : public AbstractActionGroup {
public:
    FilterGroup(QObject *parent, const Consumer<InstrumentPtr> &setInstrument);
};


#endif //FILTERS_FILTERGROUP_H
