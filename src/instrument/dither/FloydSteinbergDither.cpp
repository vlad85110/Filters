//
// Created by Влад Кирилов on 30.03.2023.
//

#include "FloydSteinbergDither.h"

FloydSteinbergDither::FloydSteinbergDither() {
    taskCnt = 1;
}

QRgb FloydSteinbergDither::getNewPixelColor(int x, int y, QImage &image, int threadNum) {
    auto pixel = image.pixel(x, y);

    auto oldRed = qRed(pixel);
    auto oldGreen = qGreen(pixel);
    auto oldBlue = qBlue(pixel);

    auto newRed = findClosetColor(oldRed, redColorsCnt);
    auto newGreen = findClosetColor(oldGreen, greenColorsCnt);
    auto newBlue = findClosetColor(oldBlue, blueColorsCnt);

    auto redError = oldRed - newRed;
    auto greenError = oldGreen - newGreen;
    auto blueError = oldBlue - newBlue;

    double errors[4]{7.0 / 16, 3.0 / 16, 5.0 / 16, 1.0 / 16};

    if (x != image.width() - 1) {
        auto nextPixel = image.pixel(x + 1, y);
        auto errorK = errors[0];
        auto r = qBound(0.0, qRed(nextPixel) + redError * errorK, 255.0);
        auto g = qBound(0.0, qGreen(nextPixel) + greenError * errorK, 255.0);
        auto b = qBound(0.0, qBlue(nextPixel) + blueError * errorK, 255.0);
        image.setPixel(x + 1, y, qRgb((int) r, (int) g, (int) b));
    }

    if (y + 1 != image.height()) {
        for (int i = -1; i < 1; ++i) {
            if (x + i == image.width() - 1 || x + i == -1) {
                break;
            }

            auto nextPixel = image.pixel(x + i, y + 1);
            auto errorK = errors[i + 2];
            auto r = qBound(0.0, qRed(nextPixel) + redError * errorK, 255.0);
            auto g = qBound(0.0, qGreen(nextPixel) + greenError * errorK, 255.0);
            auto b = qBound(0.0, qBlue(nextPixel) + blueError * errorK, 255.0);
            image.setPixel(x + i, y + 1, qRgb((int) r, (int) g, (int) b));
        }
    }

    return qRgb(newRed, newGreen, newBlue);
}

FloydSteinbergDither::~FloydSteinbergDither() {
    cout << "FSD" << endl;
}


