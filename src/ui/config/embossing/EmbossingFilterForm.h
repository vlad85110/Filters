//
// Created by Влад Кирилов on 01.04.2023.
//

#ifndef FILTERS_EMBOSSINGFILTERFORM_H
#define FILTERS_EMBOSSINGFILTERFORM_H


#include <QComboBox>
#include "ui/config/InstrumentForm.h"
#include "instrument/matrix/embossing/EmbossingFilter.h"

class EmbossingFilter;

class EmbossingFilterForm : public InstrumentForm {
    EmbossingFilter& filter;
    QComboBox comboBox;
public:
    explicit EmbossingFilterForm(EmbossingFilter &filter);

    void initInputs() override;

protected:
    bool verify() override;
};


#endif //FILTERS_EMBOSSINGFILTERFORM_H
