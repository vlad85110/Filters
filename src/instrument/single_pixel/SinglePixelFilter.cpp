//
// Created by Влад Кирилов on 18.03.2023.
//

#include <iostream>
#include "SinglePixelFilter.h"

QRgb SinglePixelFilter::getNewPixelColor(int x, int y, QImage &image, int threadNum) {
    auto pixel = image.pixel(x, y);
    return handlePixel(pixel);
}
