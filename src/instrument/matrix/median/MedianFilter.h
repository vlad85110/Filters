//
// Created by Влад Кирилов on 27.03.2023.
//

#ifndef FILTERS_MEDIANFILTER_H
#define FILTERS_MEDIANFILTER_H

#include "instrument/matrix/AbstractMatrixFilter.h"

struct ThreadBuffer {
private:
    Vector<int> rBuffer;
    Vector<int> gBuffer;
    Vector<int> bBuffer;
public:
    [[nodiscard]] Vector<int> &getRBuffer();

    [[nodiscard]] Vector<int> &getGBuffer();

    [[nodiscard]] Vector<int> &getBBuffer();

    ThreadBuffer();
};

class MedianFilter : public AbstractFilter {
private:
    Vector<ThreadBuffer> threadBuffers;

public:
    MedianFilter();

    ~MedianFilter() override;

private:
    QRgb getNewPixelColor(int x, int y, QImage &image, int threadNum) override;
};


#endif //FILTERS_MEDIANFILTER_H
