//
// Created by Влад Кирилов on 24.03.2023.
//

#include "GammaFilterForm.h"

GammaFilterForm::GammaFilterForm(GammaFilter &filter) : filter(filter) {
    gammaInput = std::make_shared<DoubleInputWithErrorLabel>(0.1, 10, filter.getGamma(),
                                                             QString("Gamma"), 2);
    inputs["Gamma"] = gammaInput;
    addInputs();
}

bool GammaFilterForm::verify() {
    auto res = InstrumentForm::verify();

    auto gammaValue = gammaInput->getValue();
    filter.setGamma(gammaValue);

    return res;
}

void GammaFilterForm::initInputs() {
    gammaInput->setValue(filter.getGamma());
}
