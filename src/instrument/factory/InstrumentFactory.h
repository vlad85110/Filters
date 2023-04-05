//
// Created by Влад Кирилов on 17.03.2023.
//

#ifndef FILTERS_INSTRUMENTFACTORY_H
#define FILTERS_INSTRUMENTFACTORY_H


#include "instrument/Instrument.h"
#include "InstrumentCreator.h"
#include "types.h"
#include "instrument/single_pixel/gray_scale/GrayScaleFilter.h"

#include <unordered_map>

class InstrumentFactory {
private:
    HashMap<String, AbstractInstrumentCreatorPtr> creators;
public:
    InstrumentFactory();
    [[nodiscard]] InstrumentPtr create(const std::string&& name) const;
};


#endif //FILTERS_INSTRUMENTFACTORY_H
