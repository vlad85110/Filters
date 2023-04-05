//
// Created by Влад Кирилов on 04.04.2023.
//

#include "VerticalPhotoForm.h"

VerticalPhotoForm::VerticalPhotoForm(VerticalPhotoFilter &filter) : filter(filter) {
    widthInput = std::make_shared<DoubleInputWithErrorLabel>(1, 50, filter.getPercents(),
                                                             "width", 0);
    inputs["width"] = widthInput;

    addInputs();
}

bool VerticalPhotoForm::verify() {
    auto res = InstrumentForm::verify();

    filter.setPercents((int) widthInput->getValue());

    return res;
}

void VerticalPhotoForm::initInputs() {
    widthInput->setValue(filter.getPercents());
}
