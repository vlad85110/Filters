//
// Created by Влад Кирилов on 24.03.2023.
//

#ifndef FILTERS_GAMMAFILTERFORM_H
#define FILTERS_GAMMAFILTERFORM_H


#include "ui/config/InstrumentForm.h"
#include "ui/config/input/DoubleInputWithErrorLabel.h"
#include "instrument/single_pixel/gamma/GammaFilter.h"

class GammaFilter;

class GammaFilterForm : public InstrumentForm {
private:
    GammaFilter &filter;
    std::shared_ptr<DoubleInputWithErrorLabel> gammaInput;
public:
    void initInputs() override;

public:
    explicit GammaFilterForm(GammaFilter &filter);

private:
    bool verify() override;
};


#endif //FILTERS_GAMMAFILTERFORM_H
