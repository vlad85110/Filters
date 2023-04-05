//
// Created by Влад Кирилов on 20.03.2023.
//

#include <QPainter>
#include <iostream>
#include <sys/time.h>
#include "AbstractMatrixFilter.h"

QRgb AbstractMatrixFilter::getNewPixelColor(int x, int y, QImage &image, int threadNum) {
    double rSum = 0.0;
    double gSum = 0.0;
    double bSum = 0.0;

    for (int u = -n; u <= n; ++u) {
        for (int v = -n; v <= n; ++v) {
            auto matrixValue = matrix[((u + n) * size) + (v + n)];

            auto nx = qBound(0, x + u, image.width() - 1);
            auto ny = qBound(0, y + v, image.height() - 1);

            auto pixel = image.pixel(nx, ny);

            rSum += qRed(pixel) * matrixValue;
            gSum += qGreen(pixel) * matrixValue;
            bSum += qBlue(pixel) * matrixValue;
        }
    }

    rSum /= mSum;
    gSum /= mSum;
    bSum /= mSum;

    rSum = qBound(0.0, rSum, 255.0);
    gSum = qBound(0.0, gSum, 255.0);
    bSum = qBound(0.0, bSum, 255.0);

    return qRgb((int) rSum, (int) gSum, (int) bSum);
}


