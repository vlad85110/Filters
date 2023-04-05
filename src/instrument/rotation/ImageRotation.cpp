//
// Created by Влад Кирилов on 02.04.2023.
//

#include "ImageRotation.h"
#include <cmath>
#include <QPainter>

ImageRotation::ImageRotation() {
    form = std::make_shared<ImageRotationForm>(*this);
    angle = 0;
    matrix = createMatrix(angle);
}

std::shared_ptr<QImage> ImageRotation::run(QImage &image) {

    auto newWidth = (int) round(image.width() * abs(matrix[0]) + image.height() * abs(matrix[2]));
    auto newHeight = (int) round(image.height() * abs(matrix[0]) + image.width() * abs(matrix[2]));

    auto copy = std::make_shared<QImage>(QSize(newWidth, newHeight),
                                         QImage::Format_ARGB32);

    QPainter painter(copy.get());
    painter.fillRect(QRect(0, 0, copy->width(), copy->height()), Qt::white);
    painter.end();

    auto newCenterX = (copy->width() - 1) / 2;
    auto newCenterY = (copy->height() - 1) / 2;

    auto oldCenterX = (image.width() - 1) / 2;
    auto oldCenterY = (image.height() - 1) / 2;

    for (int i = 0; i < copy->height(); ++i) {
        for (int j = 0; j < copy->width(); ++j) {
            auto currenVectorX = j - newCenterX;
            auto currenVectorY = i - newCenterY;

            auto oldX = (int) round(currenVectorX * matrix[0] + currenVectorY * matrix[1] + oldCenterX);
            auto oldY = (int) round(currenVectorX * matrix[2] + currenVectorY * matrix[3] + oldCenterY);

            if (0 <= oldX && oldX < image.width() && 0 <= oldY && oldY < image.height()) {
                copy->setPixel(j, i, image.pixel(oldX, oldY));
            }
        }
    }

    return copy;
}

int ImageRotation::getAngle() const {
    return angle;
}

void ImageRotation::setAngle(int angle) {
    ImageRotation::angle = angle;
    matrix = createMatrix(angle);
}

Vector<double> ImageRotation::createMatrix(int angle) {
    auto angleRad = angle * (M_PI / 180);

    return Vector<double>{
            cos(-angleRad), -sin(-angleRad),
            sin(-angleRad), cos(-angleRad)
    };
}

InstrumentForm *ImageRotation::getForm() const {
    return form.get();
}

ImageRotation::~ImageRotation() {
    cout << "Rotation" << endl;
}
