//
// Created by Влад Кирилов on 22.03.2023.
//

#include "SobelFilter.h"

SobelFilter::SobelFilter() {
    matrix = Vector<double>{
            -1, 0, 1,
            -2, 0, 2,
            -1, 0, 1
    };

    mSum = 1;

    n = 1;
    size = (int) sqrt(matrix.size());
}

InstrumentForm *SobelFilter::getForm() const {
    return form.get();
}

std::shared_ptr<QImage> SobelFilter::run(QImage &image) {
    auto grayScaled = grayScaleFilter.run(image);
    return AbstractMatrixFilter::run(*grayScaled);
}

QRgb SobelFilter::getNewPixelColor(int x, int y, QImage &image, int threadNum) {
    auto pixel = AbstractMatrixFilter::getNewPixelColor(x, y, image, threadNum);
    auto color = qRed(pixel);

    if (color > threshold) {
        color = 255;
    } else {
        color = 0;
    }

    return qRgb(color, color, color);
}

SobelFilter::~SobelFilter() {
    cout << "Sobel" << endl;
}
