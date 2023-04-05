//
// Created by Влад Кирилов on 21.03.2023.
//

#ifndef FILTERS_GRAYSCALEFILTERFORM_H
#define FILTERS_GRAYSCALEFILTERFORM_H


#include <QLineEdit>
#include "ui/config/InstrumentForm.h"
#include "instrument/single_pixel/gray_scale/GrayScaleFilter.h"
#include "ui/config/input/DoubleInputWithErrorLabel.h"

class GrayScaleFilter;

class GrayScaleFilterForm : public InstrumentForm {
    std::shared_ptr<DoubleInputWithErrorLabel> redWeightEdit;
    std::shared_ptr<DoubleInputWithErrorLabel> greenWeightEdit;
    std::shared_ptr<DoubleInputWithErrorLabel> blueWeightEdit;
    GrayScaleFilter &filter;

    bool verify() override;

public:
    explicit GrayScaleFilterForm(GrayScaleFilter &filter);

    void initInputs() override;
};


#endif //FILTERS_GRAYSCALEFILTERFORM_H
