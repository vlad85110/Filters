//
// Created by Влад Кирилов on 01.04.2023.
//

#include "HighlightFilterForm.h"


HighlightFilterForm::HighlightFilterForm(HighlightFilter &filter) : filter(filter) {
    thresholdInput = std::make_shared<DoubleInputWithErrorLabel>(1, 255, filter.getThreshold(),
                                                                 QString("Threshold"), 0);

    inputs["Threshold"] = thresholdInput;
    addInputs();
}

bool HighlightFilterForm::verify() {
    auto res = InstrumentForm::verify();
    if (!res) return res;

    filter.setThreshold((int) thresholdInput->getValue());

    return res;
}

void HighlightFilterForm::initInputs() {
    thresholdInput->setValue(filter.getThreshold());
}
