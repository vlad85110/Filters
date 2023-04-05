//
// Created by Влад Кирилов on 22.03.2023.
//

#include "RobertsFilter.h"
#include "instrument/single_pixel/gray_scale/GrayScaleFilter.h"

int robertsOperator(int g1, int g2, int g3, int g4) {
    return abs(g1 - g4) + abs(g2 - g3);
}

QRgb RobertsFilter::getNewPixelColor(int x, int y, QImage &image, int threadNum) {
    auto height = image.height();
    auto width = image.width();

    if (x == width - 1 || y == height - 1) {
        return Qt::black;
    }

    QRgb c1, c2, c3, c4;

    c1 = grayScaleFilter.getNewPixelColor(x, y, image, threadNum);
    c2 = grayScaleFilter.getNewPixelColor(x + 1, y, image, threadNum);
    c3 = grayScaleFilter.getNewPixelColor(x, y + 1, image, threadNum);
    c4 = grayScaleFilter.getNewPixelColor(x + 1, y + 1, image, threadNum);

    auto newGray = robertsOperator(qBlue(c1), qBlue(c2), qBlue(c3), qBlue(c4));

    if (newGray > threshold) {
        newGray = 255;
    } else {
        newGray = 0;
    }

    return qRgb(newGray, newGray, newGray);
}

InstrumentForm *RobertsFilter::getForm() const {
    return form.get();
}

RobertsFilter::~RobertsFilter() {
    cout << "Roberts" << endl;
}


