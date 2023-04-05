//
// Created by Влад Кирилов on 27.03.2023.
//

#include <iostream>
#include <sys/time.h>
#include "WatercolorFilter.h"

std::shared_ptr<QImage> WatercolorFilter::run(QImage &image) {
    auto medianImage = medianFilter.run(image);
    auto watercolorImage = sharpnessFilter.run(*medianImage);
    return watercolorImage;
}

WatercolorFilter::~WatercolorFilter() {
    cout << "Watercolor" << endl;
}

