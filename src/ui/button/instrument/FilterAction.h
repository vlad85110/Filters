//
// Created by Влад Кирилов on 15.03.2023.
//

#ifndef FILTERS_FILTERACTION_H
#define FILTERS_FILTERACTION_H

#include <QPushButton>
#include "types.h"
#include "instrument/Instrument.h"
#include "ui/button/ToolBarAction.h"
#include "instrument/factory/InstrumentFactory.h"


class FilterAction : public ToolBarAction {
private:
    std::string name;
    Consumer<InstrumentPtr> setInstrument;
    InstrumentPtr instrument;

public:
    FilterAction(QString &iconPath, QString &name, String &&instrumentName, const InstrumentFactory &factory,
                 Consumer<InstrumentPtr> setInstrument);

    [[nodiscard]] virtual InstrumentPtr getInstrument() const;

    void onMouseClicked() override;
};


#endif //FILTERS_FILTERACTION_H
