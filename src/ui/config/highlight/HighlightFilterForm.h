//
// Created by Влад Кирилов on 01.04.2023.
//

#ifndef FILTERS_HIGHLIGHTFILTERFORM_H
#define FILTERS_HIGHLIGHTFILTERFORM_H


#include "ui/config/InstrumentForm.h"
#include "ui/config/input/DoubleInputWithErrorLabel.h"
#include "instrument/highlight/HighlightFilter.h"

class HighlightFilter;

class HighlightFilterForm : public InstrumentForm {
private:
    std::shared_ptr<DoubleInputWithErrorLabel> thresholdInput;
    HighlightFilter& filter;
public:
    explicit HighlightFilterForm(HighlightFilter &filter);

    void initInputs() override;

protected:
    bool verify() override;
};


#endif //FILTERS_HIGHLIGHTFILTERFORM_H
