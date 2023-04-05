//
// Created by Влад Кирилов on 01.04.2023.
//

#ifndef FILTERS_SMOOTHINGFILTERFORM_H
#define FILTERS_SMOOTHINGFILTERFORM_H


#include "ui/config/InstrumentForm.h"
#include "instrument/matrix/smoothing/SmoothingFilter.h"
#include <QComboBox>

class SmoothingFilter;

class SmoothingFilterForm : public InstrumentForm {
private:
    SmoothingFilter &filter;
    QComboBox comboBox;

public:
    explicit SmoothingFilterForm(SmoothingFilter &filter);

    void initInputs() override;

protected:
    bool verify() override;

};


#endif //FILTERS_SMOOTHINGFILTERFORM_H
