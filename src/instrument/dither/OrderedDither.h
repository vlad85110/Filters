//
// Created by Влад Кирилов on 01.04.2023.
//

#ifndef FILTERS_ORDEREDDITHER_H
#define FILTERS_ORDEREDDITHER_H


#include "AbstractDither.h"

Vector<int> createMatrix(int size);

class OrderedDither : public AbstractDither {
private:
    Vector<int> redMatrix;
    Vector<int> greenMatrix;
    Vector<int> blueMatrix;

    static Vector<int> createMatrix(int size);
public:
    OrderedDither();

    QRgb getNewPixelColor(int x, int y, QImage &image, int threadNum) override;

    void setRedColorsCnt(int redColorsCnt) override;

    void setGreenColorsCnt(int greenColorsCnt) override;

    void setBlueColorsCnt(int blueColorsCnt) override;

    ~OrderedDither() override;
};


#endif //FILTERS_ORDEREDDITHER_H
