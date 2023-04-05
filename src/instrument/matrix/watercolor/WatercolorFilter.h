//
// Created by Влад Кирилов on 27.03.2023.
//

#ifndef FILTERS_WATERCOLORFILTER_H
#define FILTERS_WATERCOLORFILTER_H


#include "instrument/AbstractFilter.h"
#include "instrument/matrix/median/MedianFilter.h"
#include "instrument/matrix/sharpness/SharpnessFilter.h"

class WatercolorFilter : public Instrument {
private:
    MedianFilter medianFilter;
    SharpnessFilter sharpnessFilter;
public:
    std::shared_ptr<QImage> run(QImage &image) override;

    ~WatercolorFilter() override;
};


#endif //FILTERS_WATERCOLORFILTER_H
