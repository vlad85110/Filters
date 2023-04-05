//
// Created by Влад Кирилов on 01.04.2023.
//

#include "HighlightFilter.h"

int HighlightFilter::getThreshold() const {
    return threshold;
}

void HighlightFilter::setThreshold(int threshold) {
    this->threshold = threshold;
}

HighlightFilter::HighlightFilter() {
    form = std::make_shared<HighlightFilterForm>(*this);
}
