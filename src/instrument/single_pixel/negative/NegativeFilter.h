//
// Created by Влад Кирилов on 18.03.2023.
//

#ifndef FILTERS_NEGATIVEFILTER_H
#define FILTERS_NEGATIVEFILTER_H


#include "instrument/single_pixel/SinglePixelFilter.h"

class NegativeFilter : public SinglePixelFilter {
protected:
    [[nodiscard]] QRgb handlePixel(QRgb pixel) const override;

public:
    ~NegativeFilter() override;
};


#endif //FILTERS_NEGATIVEFILTER_H
