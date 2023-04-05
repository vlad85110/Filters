//
// Created by Влад Кирилов on 30.03.2023.
//

#ifndef FILTERS_FLOYDSTEINBERGDITHER_H
#define FILTERS_FLOYDSTEINBERGDITHER_H


#include "instrument/AbstractFilter.h"
#include "AbstractDither.h"



class FloydSteinbergDither : public AbstractDither {
public:
    FloydSteinbergDither();

    QRgb getNewPixelColor(int x, int y, QImage &image, int threadNum) override;

    ~FloydSteinbergDither() override;
};


#endif //FILTERS_FLOYDSTEINBERGDITHER_H
