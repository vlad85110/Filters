//
// Created by Влад Кирилов on 21.03.2023.
//

#include "GrayScaleFilterForm.h"

#include <QFormLayout>
#include <QDoubleValidator>
#include <iostream>


GrayScaleFilterForm::GrayScaleFilterForm(GrayScaleFilter &filter) : filter(filter) {
    redWeightEdit = std::make_shared<DoubleInputWithErrorLabel>(0, 1, filter.getRWeight(),
                                                                QString("Red weight"), 2);
    greenWeightEdit = std::make_shared<DoubleInputWithErrorLabel>(0, 1, filter.getGWeight(),
                                                                  QString("Green weight"), 2);
    blueWeightEdit = std::make_shared<DoubleInputWithErrorLabel>(0, 1, filter.getBWeight(),
                                                                 QString("Blue weight"), 2);
    inputs["Red"] = redWeightEdit;
    inputs["Green"] = greenWeightEdit;
    inputs["Blue"] = blueWeightEdit;

    addInputs();
}

bool GrayScaleFilterForm::verify() {
    auto isValid = InstrumentForm::verify();
    if (!isValid) return isValid;

    auto redWeight = redWeightEdit->getValue();
    auto greenWeight = greenWeightEdit->getValue();
    auto blueWeight = blueWeightEdit->getValue();
    auto sum = redWeight + blueWeight + greenWeight;

    if (sum != 1) {
        redWeight /= sum;
        greenWeight /= sum;
        blueWeight /= sum;
    }

    filter.setRWeight(redWeight);
    filter.setBWeight(blueWeight);
    filter.setGWeight(greenWeight);

    return isValid;
}

void GrayScaleFilterForm::initInputs() {
    redWeightEdit->setValue(filter.getRWeight());
    greenWeightEdit->setValue(filter.getGWeight());
    blueWeightEdit->setValue(filter.getBWeight());
}
