//
// Created by Влад Кирилов on 18.03.2023.
//

#include "NegativeFilter.h"

QRgb NegativeFilter::handlePixel(QRgb pixel) const {
    return qRgb(255 - qRed(pixel), 255 - qGreen(pixel), 255 - qBlue(pixel));
}

NegativeFilter::~NegativeFilter() {
    cout << "Negative" << endl;
}
