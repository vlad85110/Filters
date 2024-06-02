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

    matrix1 = Vector<double>{
            -1, -2, -1,
            0, 0, 0,
            1, 2, 1
    };

    mSum = 0.25;

    for (int i = 0; i < matrix.size(); ++i) {
        matrix1[i] /= 4;
        matrix[i] /= 4;
    }

    n = 1;
    size = (int) sqrt(matrix.size());
}

InstrumentForm *SobelFilter::getForm() const {
    return form.get();
}

std::shared_ptr<QImage> SobelFilter::run(QImage &image) {
    auto grayScaled = grayScaleFilter.run(image);
    return AbstractMatrixFilter::run(image);
}


QRgb SobelFilter::getNewPixelColor(int x, int y, QImage &image, int threadNum) {
    double rSum = 0.0;
    double rSum1 = 0.0;

    for (int u = -n; u <= n; ++u) {
        for (int v = -n; v <= n; ++v) {
            auto matrixValue = matrix[((u + n) * size) + (v + n)];
            auto matrixValue1 = matrix1[((u + n) * size) + (v + n)];

            auto nx = qBound(0, x + u, image.width() - 1);
            auto ny = qBound(0, y + v, image.height() - 1);

            auto pixel = image.pixel(nx, ny);

            rSum += qRed(pixel) * matrixValue;
            rSum1 += qRed(pixel) * matrixValue1;
        }
    }

    auto color = sqrt(pow(rSum, 2) + pow(rSum1, 2));
//    auto color = (abs(rSum) + abs(rSum1));

    if (color > threshold) {
        color = 255;
    } else {
        color = 0;
    }

    return qRgb((int) color, (int) color, (int) color);
}

SobelFilter::~SobelFilter() {
    cout << "Sobel" << endl;
}
