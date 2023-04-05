//
// Created by Влад Кирилов on 04.04.2023.
//

#ifndef FILTERS_RADIANBLUR_H
#define FILTERS_RADIANBLUR_H


#include "instrument/matrix/AbstractMatrixFilter.h"

class RadianBlur : public AbstractMatrixFilter {
public:
    RadianBlur();

    ~RadianBlur() override;
};


#endif //FILTERS_RADIANBLUR_H
