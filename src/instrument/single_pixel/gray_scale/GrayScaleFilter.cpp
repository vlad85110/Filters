//
// Created by Влад Кирилов on 16.03.2023.
//

#include <iostream>
#include "GrayScaleFilter.h"

GrayScaleFilter::GrayScaleFilter() {
    form = std::make_shared<GrayScaleFilterForm>(*this);
}

int GrayScaleFilter::toGrayScale(int red, int green, int blue) const {
    return (int) (red * rWeight + green * gWeight + blue * bWeight);
}

QRgb GrayScaleFilter::handlePixel(QRgb pixel) const {
    auto grayScale = toGrayScale(qRed(pixel), qGreen(pixel), qBlue(pixel));
    return qRgb(grayScale, grayScale, grayScale);
}

InstrumentForm* GrayScaleFilter::getForm() const {
    return form.get();
}

double GrayScaleFilter::getRWeight() const {
    return rWeight;
}

double GrayScaleFilter::getGWeight() const {
    return gWeight;
}

double GrayScaleFilter::getBWeight() const {
    return bWeight;
}

void GrayScaleFilter::setRWeight(double rWeight) {
    GrayScaleFilter::rWeight = rWeight;
}

void GrayScaleFilter::setGWeight(double gWeight) {
    GrayScaleFilter::gWeight = gWeight;
}

void GrayScaleFilter::setBWeight(double bWeight) {
    GrayScaleFilter::bWeight = bWeight;
}

GrayScaleFilter::~GrayScaleFilter() {
    cout << "Gray scale" << endl;
}
