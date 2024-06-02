//
// Created by Влад Кирилов on 01.04.2023.
//

#include "OrderedDither.h"

OrderedDither::OrderedDither() {
    redMatrix = OrderedDither::createMatrix(redColorsCnt);
    greenMatrix = OrderedDither::createMatrix(greenColorsCnt);
    blueMatrix = OrderedDither::createMatrix(blueColorsCnt);
}

QRgb OrderedDither::getNewPixelColor(int x, int y, QImage &image, int threadNum) {
    auto pixel = image.pixel(x, y);

    auto red = qRed(pixel);
    auto green = qGreen(pixel);
    auto blue = qBlue(pixel);

    auto red_interval_len = 255 / (redColorsCnt - 1);
    auto green_interval_len = 255 / (greenColorsCnt - 1);
    auto blue_interval_len = 255 / (blueColorsCnt - 1);

    auto redMatrixSize = (int) sqrt(redMatrix.size());
    auto greenMatrixSize = (int) sqrt(greenMatrix.size());
    auto blueMatrixSize = (int) sqrt(blueMatrix.size());

    auto redMatrixIndex = (y % redMatrixSize) * redMatrixSize + (x % redMatrixSize);
    auto greenMatrixIndex = (y % greenMatrixSize) * greenMatrixSize + (x % greenMatrixSize);
    auto blueMatrixIndex = (y % blueMatrixSize) * blueMatrixSize + (x % blueMatrixSize);

    auto redMatrixValue = (double) redMatrix[redMatrixIndex] / (double) redMatrix.size();
    auto greenMatrixValue = (double) greenMatrix[greenMatrixIndex] / (double) greenMatrix.size();
    auto blueMatrixValue = (double) blueMatrix[blueMatrixIndex] / (double) blueMatrix.size();

    auto newRed = findClosetColor((int) (red + red_interval_len * (redMatrixValue - 0.5)),
                                  redColorsCnt);

    auto newGreen = findClosetColor((int) (green + green_interval_len * (greenMatrixValue - 0.5)),
                                    greenColorsCnt);

    auto newBlue = findClosetColor((int) (blue + blue_interval_len * (blueMatrixValue - 0.5)),
                                   blueColorsCnt);

    return qRgb((int) newRed, (int) newGreen, (int) newBlue);
}

int getSizeByColorCnt(int colorCnt) {
    auto val = sqrt(256.0 / colorCnt);

    if (val > 8 && val <= 16) {
        return 16;
    }

    if (val > 4 && val <= 8) {
        return 8;
    }

    if (val > 2 && val <= 4) {
        return 4;
    }

    return 2;
}

void OrderedDither::setRedColorsCnt(int redColorsCnt) {
    AbstractDither::setRedColorsCnt(redColorsCnt);
    redMatrix = OrderedDither::createMatrix(getSizeByColorCnt(redColorsCnt));
}

void OrderedDither::setGreenColorsCnt(int greenColorsCnt) {
    AbstractDither::setGreenColorsCnt(greenColorsCnt);
    greenMatrix = OrderedDither::createMatrix(getSizeByColorCnt(greenColorsCnt));
}

void OrderedDither::setBlueColorsCnt(int blueColorsCnt) {
    AbstractDither::setBlueColorsCnt(blueColorsCnt);
    blueMatrix = OrderedDither::createMatrix(getSizeByColorCnt(blueColorsCnt));
}

Vector<int> OrderedDither::createMatrix(int size) {
    auto currentSize = 2;
    auto matrix = Vector<int>{
            0, 2,
            3, 1
    };
    Vector<int> newMatrix;

    while (currentSize < size) {
        auto newSize = currentSize * 2;
        newMatrix = Vector<int>(newSize * newSize, 0);

        for (int i = 0; i < newSize; ++i) {
            for (int j = 0; j < newSize; ++j) {
                if (j < newSize / 2) {
                    if (i < newSize / 2) {
                        newMatrix[i * newSize + j] = 4 * matrix[i * currentSize + j];
                    } else {
                        newMatrix[i * newSize + j] = 4 * matrix[(i % currentSize) * currentSize + j] + 3;
                    }
                } else {
                    if (i < newSize / 2) {
                        newMatrix[i * newSize + j] = 4 * matrix[i * currentSize + (j % currentSize)] + 2;
                    } else {
                        newMatrix[i * newSize + j] =
                                4 * matrix[(i % currentSize) * currentSize + (j % currentSize)] + 1;
                    }
                }

            }
        }

        currentSize *= 2;
        matrix = newMatrix;
    }

    return matrix;
}

OrderedDither::~OrderedDither() {
    cout << "OD" << endl;
}


