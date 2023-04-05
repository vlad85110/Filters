//
// Created by Влад Кирилов on 18.03.2023.
//

#ifndef FILTERS_SINGLEPIXELFILTER_H
#define FILTERS_SINGLEPIXELFILTER_H


#include "instrument/Instrument.h"
#include "instrument/AbstractFilter.h"
#include <qrgb.h>

class SinglePixelFilter : public AbstractFilter {
public:
    [[nodiscard]] QRgb getNewPixelColor(int x, int y, QImage &image, int threadNum) override;

protected:
    [[nodiscard]] virtual QRgb handlePixel(QRgb pixel) const = 0;
};


#endif //FILTERS_SINGLEPIXELFILTER_H
