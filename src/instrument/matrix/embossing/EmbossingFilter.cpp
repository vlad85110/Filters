//
// Created by Влад Кирилов on 22.03.2023.
//

#include "EmbossingFilter.h"

EmbossingFilter::EmbossingFilter() {
    setOrientation(RIGHT);

    form = std::make_shared<EmbossingFilterForm>(*this);

    mSum = 1;
    n = 1;
    size = (int) sqrt(matrix.size());
}

InstrumentForm *EmbossingFilter::getForm() const {
    return form.get();
}

void EmbossingFilter::setOrientation(EmbossingOrientation orientation) {
    if (orientation == RIGHT) {
        matrix = Vector<double>{
                0, -1, 0,
                1, 0, -1,
                0, 1, 0
        };
    } else if (orientation == LEFT) {
        matrix = Vector<double>{
                0, 1, 0,
                -1, 0, 1,
                0, -1, 0
        };
    }
}

QRgb EmbossingFilter::getNewPixelColor(int x, int y, QImage &image, int threadNum) {
    auto res = AbstractMatrixFilter::getNewPixelColor(x, y, image, 0);

    double newRed = qRed(res) + 128;
    double newGreen = qGreen(res) + 128;
    double newBlue = qBlue(res) + 128;

    newRed = qBound(0.0, newRed, 255.0);
    newGreen = qBound(0.0, newGreen, 255.0);
    newBlue = qBound(0.0, newBlue, 255.0);

    return qRgb((int) newRed, (int) newGreen, (int) newBlue);
}

std::shared_ptr<QImage> EmbossingFilter::run(QImage &image) {
    auto grayScaled = grayScaleFilter.run(image);
    return AbstractMatrixFilter::run(*grayScaled);
}

EmbossingFilter::~EmbossingFilter() {
    cout << "Embossing" << endl;
}
