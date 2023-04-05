//
// Created by Влад Кирилов on 01.04.2023.
//

#ifndef FILTERS_HIGHLIGHTFILTER_H
#define FILTERS_HIGHLIGHTFILTER_H


#include "ui/config/highlight/HighlightFilterForm.h"
#include "instrument/single_pixel/gray_scale/GrayScaleFilter.h"

class HighlightFilterForm;

class HighlightFilter {
protected:
    GrayScaleFilter grayScaleFilter;
    int threshold = 128;

    std::shared_ptr<HighlightFilterForm> form;
public:
    HighlightFilter();

    [[nodiscard]] int getThreshold() const;

    void setThreshold(int threshold);
};

#endif //FILTERS_HIGHLIGHTFILTER_H
