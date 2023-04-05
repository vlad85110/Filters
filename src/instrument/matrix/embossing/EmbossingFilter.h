//
// Created by Влад Кирилов on 22.03.2023.
//

#ifndef FILTERS_EMBOSSINGFILTER_H
#define FILTERS_EMBOSSINGFILTER_H


#include "instrument/matrix/AbstractMatrixFilter.h"
#include "instrument/single_pixel/gray_scale/GrayScaleFilter.h"
#include "ui/config/embossing/EmbossingFilterForm.h"

class EmbossingFilterForm;

enum EmbossingOrientation {
    RIGHT,
    LEFT
};

class EmbossingFilter : public AbstractMatrixFilter {
public:
    EmbossingFilter();

    std::shared_ptr<QImage> run(QImage &image) override;

    void setOrientation(EmbossingOrientation orientation);

    [[nodiscard]] InstrumentForm *getForm() const override;

    ~EmbossingFilter() override;

protected:
    QRgb getNewPixelColor(int x, int y, QImage &image, int threadNum) override;

private:
    std::shared_ptr<EmbossingFilterForm> form;
    GrayScaleFilter grayScaleFilter;
};


#endif //FILTERS_EMBOSSINGFILTER_H
