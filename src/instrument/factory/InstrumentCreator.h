//
// Created by Влад Кирилов on 18.03.2023.
//

#ifndef FILTERS_INSTRUMENTCREATOR_H
#define FILTERS_INSTRUMENTCREATOR_H

#include "instrument/Instrument.h"


class AbstractInstrumentCreator {
public:
    virtual InstrumentPtr create() = 0;
};

template<class T>
class InstrumentCreator : public AbstractInstrumentCreator {
public:
    InstrumentPtr create() override { return std::make_shared<T>(); }
};

using AbstractInstrumentCreatorPtr = std::shared_ptr<AbstractInstrumentCreator>;


#endif //FILTERS_INSTRUMENTCREATOR_H
