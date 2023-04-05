//
// Created by Влад Кирилов on 01.04.2023.
//

#include "DitherForm.h"

DitherForm::DitherForm(AbstractDither &filter) : filter(filter) {
    redColorsCnt = std::make_shared<DoubleInputWithErrorLabel>(2, 128, filter.getRedColorsCnt(),
                                                               QString("Red colors count"), 0);
    greenColorsCnt = std::make_shared<DoubleInputWithErrorLabel>(2, 128, filter.getGreenColorsCnt(),
                                                                 QString("Green colors count"), 0);
    blueColorsCnt = std::make_shared<DoubleInputWithErrorLabel>(2, 128, filter.getBlueColorsCnt(),
                                                                QString("Blue colors count"), 0);

    inputs["redCnt"] = redColorsCnt;
    inputs["greenCnt"] = greenColorsCnt;
    inputs["blue"] = blueColorsCnt;

    addInputs();
}

void DitherForm::initInputs() {
    redColorsCnt->setValue(filter.getRedColorsCnt());
    greenColorsCnt->setValue(filter.getGreenColorsCnt());
    blueColorsCnt->setValue(filter.getBlueColorsCnt());
}

bool DitherForm::verify() {
    auto res = InstrumentForm::verify();
    if (!res) return res;

    filter.setRedColorsCnt((int) redColorsCnt->getValue());
    filter.setGreenColorsCnt((int) greenColorsCnt->getValue());
    filter.setBlueColorsCnt((int) blueColorsCnt->getValue());

    return res;
}
