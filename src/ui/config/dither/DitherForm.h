//
// Created by Влад Кирилов on 01.04.2023.
//

#ifndef FILTERS_DITHERFORM_H
#define FILTERS_DITHERFORM_H


#include "ui/config/InstrumentForm.h"
#include "ui/config/input/DoubleInputWithErrorLabel.h"
#include "instrument/dither/AbstractDither.h"

class AbstractDither;

class DitherForm : public InstrumentForm {
private:
    AbstractDither& filter;

    std::shared_ptr<DoubleInputWithErrorLabel> redColorsCnt;
    std::shared_ptr<DoubleInputWithErrorLabel> greenColorsCnt;
    std::shared_ptr<DoubleInputWithErrorLabel> blueColorsCnt;

public:
    explicit DitherForm(AbstractDither &filter);

    void initInputs() override;

protected:
    bool verify() override;
};


#endif //FILTERS_DITHERFORM_H
