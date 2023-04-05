//
// Created by Влад Кирилов on 22.03.2023.
//

#ifndef FILTERS_ROBERTSFILTER_H
#define FILTERS_ROBERTSFILTER_H


#include "instrument/AbstractFilter.h"
#include "instrument/matrix/AbstractMatrixFilter.h"
#include "instrument/single_pixel/gray_scale/GrayScaleFilter.h"
#include "instrument/highlight/HighlightFilter.h"

class RobertsFilter : public AbstractFilter, HighlightFilter {
public:
    [[nodiscard]] QRgb getNewPixelColor(int x, int y, QImage &image, int threadNum) override;

    [[nodiscard]] InstrumentForm *getForm() const override;

    ~RobertsFilter() override;
};


#endif //FILTERS_ROBERTSFILTER_H
