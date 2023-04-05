//
// Created by Влад Кирилов on 03.04.2023.
//

#include "VerticalPhotoFilter.h"
#include <QPainter>

VerticalPhotoFilter::VerticalPhotoFilter() {
    form = std::make_shared<VerticalPhotoForm>(*this);
    gammaFilter.setGamma(5);
}

InstrumentForm *VerticalPhotoFilter::getForm() const {
    return form.get();
}

std::shared_ptr<QImage> VerticalPhotoFilter::run(QImage &image) {
    auto sideWidth = image.width() * percents / 100;
    auto newWidth = image.width() + 2 * sideWidth;

    auto copy = std::make_shared<QImage>(QSize(newWidth, image.height()),
                                         QImage::Format_ARGB32);

    auto leftMirror = std::make_shared<QImage>(QSize(sideWidth, image.height()),
                                             QImage::Format_ARGB32);

    for (int i = 0; i < leftMirror->height(); ++i) {
        for (int j = 0; j < leftMirror->width(); ++j) {
            auto newX = j;
//            auto newX = leftMirror->width() - 1 - j;

            leftMirror->setPixel(j, i, image.pixel( newX, i));
        }
    }
    leftMirror = filter.run(*leftMirror);
    leftMirror = gammaFilter.run(*leftMirror);

    auto rightMirror =  std::make_shared<QImage>(QSize(sideWidth, image.height()),
                                                 QImage::Format_ARGB32);

    for (int i = 0; i < rightMirror->height(); ++i) {
        for (int j = 0; j < rightMirror->width(); ++j) {
            auto newX = image.width() - rightMirror->width() - 1 + j;
//            auto newX = image.width() - 1 - j;

            rightMirror->setPixel(j, i, image.pixel(newX, i));
        }
    }

    rightMirror = filter.run(*rightMirror);
    rightMirror = gammaFilter.run(*rightMirror);

    QPainter painter(copy.get());
    painter.drawImage(leftMirror->rect(), *leftMirror, leftMirror->rect());
    auto centralRect = QRect(sideWidth, 0, image.width(),
                             image.height());
    painter.drawImage(centralRect, image, image.rect());

    auto rightRect = QRect(image.width() + sideWidth, 0,  sideWidth, image.height());
    painter.drawImage(rightRect, *rightMirror, rightMirror->rect());
    painter.end();

    return copy;
}

int VerticalPhotoFilter::getPercents() const {
    return percents;
}

void VerticalPhotoFilter::setPercents(int percents) {
    VerticalPhotoFilter::percents = percents;
}

VerticalPhotoFilter::~VerticalPhotoFilter() {
    cout << "Vertical" << endl;
}
