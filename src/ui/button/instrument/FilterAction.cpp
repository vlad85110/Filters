//
// Created by Влад Кирилов on 15.03.2023.
//

#include <iostream>
#include "FilterAction.h"
#include "instrument/single_pixel/gray_scale/GrayScaleFilter.h"
#include "instrument/factory/InstrumentFactory.h"

FilterAction::FilterAction(QString &iconPath, QString &name, String &&instrumentName,
                           const InstrumentFactory &factory, Consumer<InstrumentPtr> setInstrument)
        : ToolBarAction(std::move(iconPath), std::move(name)), setInstrument(std::move(setInstrument)) {
    this->instrument = factory.create(std::move(instrumentName));
    setCheckable(true);
}

void FilterAction::onMouseClicked() {
    ToolBarAction::onMouseClicked();

    auto instrument = getInstrument();
    auto form = instrument->getForm();

    if (form != nullptr) {
        auto res = form->exec();
        if (res == QDialog::Rejected) return;
    }

    setInstrument(instrument);
}

std::shared_ptr<Instrument> FilterAction::getInstrument() const {
    return instrument;
}




