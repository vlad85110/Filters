//
// Created by Влад Кирилов on 03.04.2023.
//

#include "ImageRotationForm.h"

ImageRotationForm::ImageRotationForm(ImageRotation &filter) : filter(filter) {
    angleInput = std::make_shared<DoubleInputWithErrorLabel>(-180, 180, filter.getAngle(),
                                                             QString("Angle"),
                                                             0);
    inputs["Angle"] = angleInput;
    addInputs();
}

bool ImageRotationForm::verify() {
    auto res = InstrumentForm::verify();

    filter.setAngle((int) angleInput->getValue());

    return res;
}

void ImageRotationForm::initInputs() {
    angleInput->setValue(filter.getAngle());
}
