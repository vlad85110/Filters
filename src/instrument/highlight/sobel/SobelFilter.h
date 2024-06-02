//
// Created by Влад Кирилов on 22.03.2023.
//

#ifndef FILTERS_SOBELFILTER_H
#define FILTERS_SOBELFILTER_H


#include "instrument/matrix/AbstractMatrixFilter.h"
#include "instrument/highlight/HighlightFilter.h"

class SobelFilter : public AbstractMatrixFilter, HighlightFilter {
private:
    Vector<double> matrix1;

public:
    SobelFilter();

    [[nodiscard]] InstrumentForm *getForm() const override;

    std::shared_ptr<QImage> run(QImage &image) override;

    ~SobelFilter() override;

protected:
    QRgb getNewPixelColor(int x, int y, QImage &image, int threadNum) override;
};


#endif //FILTERS_SOBELFILTER_H
