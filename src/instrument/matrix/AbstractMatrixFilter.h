//
// Created by Влад Кирилов on 20.03.2023.
//

#ifndef FILTERS_ABSTRACTMATRIXFILTER_H
#define FILTERS_ABSTRACTMATRIXFILTER_H


#include "instrument/Instrument.h"
#include "types.h"
#include "instrument/AbstractFilter.h"

class AbstractMatrixFilter : public AbstractFilter {
protected:
    int n;
    int size;
    int mSum;
    Vector<double> matrix;

    [[nodiscard]] QRgb getNewPixelColor(int x, int y, QImage &image, int threadNum) override;
};


#endif //FILTERS_ABSTRACTMATRIXFILTER_H
