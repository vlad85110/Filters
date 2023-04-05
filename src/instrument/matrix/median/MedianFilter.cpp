//
// Created by Влад Кирилов on 27.03.2023.
//

#include <iostream>
#include "MedianFilter.h"

ThreadBuffer::ThreadBuffer() : rBuffer(25), gBuffer(25), bBuffer(25) {}

Vector<int> &ThreadBuffer::getRBuffer() {
    return rBuffer;
}

Vector<int> &ThreadBuffer::getGBuffer() {
    return gBuffer;
}

Vector<int> &ThreadBuffer::getBBuffer() {
    return bBuffer;
}

MedianFilter::MedianFilter() : threadBuffers(taskCnt) {}

QRgb MedianFilter::getNewPixelColor(int x, int y, QImage &image, int threadNum) {
    auto &rVector = threadBuffers[threadNum].getRBuffer();
    auto &gVector = threadBuffers[threadNum].getGBuffer();
    auto &bVector = threadBuffers[threadNum].getBBuffer();

    for (int i = -2; i <= 2; ++i) {
        for (int j = -2; j <= 2; ++j) {
            auto nx = qBound(0, x + j, image.width() - 1);
            auto ny = qBound(0, y + i, image.height() - 1);

            auto pixel = image.pixel(nx, ny);

            rVector[(i + 2) * 5 + (j + 2)] = qRed(pixel);
            gVector[(i + 2) * 5 + (j + 2)] = qGreen(pixel);
            bVector[(i + 2) * 5 + (j + 4)] = qBlue(pixel);
        }
    }

    std::sort(rVector.begin(), rVector.end());
    std::sort(gVector.begin(), gVector.end());
    std::sort(bVector.begin(), bVector.end());

    return qRgb(rVector[12], gVector[12], bVector[12]);
}

MedianFilter::~MedianFilter() {
    cout << "Median" << endl;
}

