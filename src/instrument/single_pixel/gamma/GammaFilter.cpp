//
// Created by Влад Кирилов on 22.03.2023.
//

#include "GammaFilter.h"

GammaFilter::GammaFilter() {
    gamma = 0.5;
    form = std::make_shared<GammaFilterForm>(*this);
}

QRgb GammaFilter::handlePixel(QRgb pixel) const {
    return qRgb(newGamma(qRed(pixel)),
                newGamma(qGreen(pixel)),
                newGamma(qBlue(pixel)));
}

int GammaFilter::newGamma(int prev) const {
    return (int) (pow((double) prev / 255, gamma) * 255);
}

double GammaFilter::getGamma() const {
    return gamma;
}

void GammaFilter::setGamma(double gamma) {
    this->gamma = gamma;
}

InstrumentForm *GammaFilter::getForm() const {
    return form.get();
}

GammaFilter::~GammaFilter() {
    cout << "Gamma" << endl;
}



