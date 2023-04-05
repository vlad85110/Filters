//
// Created by Влад Кирилов on 20.03.2023.
//

#ifndef FILTERS_SHARPNESSFILTER_H
#define FILTERS_SHARPNESSFILTER_H


#include "instrument/matrix/AbstractMatrixFilter.h"

class SharpnessFilter : public AbstractMatrixFilter {
public:
    SharpnessFilter();

    ~SharpnessFilter() override;
};


#endif //FILTERS_SHARPNESSFILTER_H
