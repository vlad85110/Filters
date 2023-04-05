//
// Created by Влад Кирилов on 01.04.2023.
//

#include "AbstractDither.h"

AbstractDither::AbstractDither() {
    form = std::make_shared<DitherForm>(*this);
}

int AbstractDither::findClosetColor(int color, int colorsCnt) {
    auto interval_len = 255.0 / (colorsCnt - 1);
    auto closetColor = round(color / interval_len) * interval_len;
    return (int) closetColor;
}

int AbstractDither::getRedColorsCnt() const {
    return redColorsCnt;
}

InstrumentForm *AbstractDither::getForm() const {
    return form.get();
}

void AbstractDither::setRedColorsCnt(int redColorsCnt) {
    AbstractDither::redColorsCnt = redColorsCnt;
}

int AbstractDither::getGreenColorsCnt() const {
    return greenColorsCnt;
}

void AbstractDither::setGreenColorsCnt(int greenColorsCnt) {
    AbstractDither::greenColorsCnt = greenColorsCnt;
}

int AbstractDither::getBlueColorsCnt() const {
    return blueColorsCnt;
}

void AbstractDither::setBlueColorsCnt(int blueColorsCnt) {
    AbstractDither::blueColorsCnt = blueColorsCnt;
}
