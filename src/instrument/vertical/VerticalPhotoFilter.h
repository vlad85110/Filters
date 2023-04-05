//
// Created by Влад Кирилов on 03.04.2023.
//

#ifndef FILTERS_VERTICALPHOTOFILTER_H
#define FILTERS_VERTICALPHOTOFILTER_H


#include "instrument/Instrument.h"
#include "instrument/matrix/smoothing/SmoothingFilter.h"
#include "instrument/single_pixel/gamma/GammaFilter.h"
#include "instrument/matrix/radian_blur/RadianBlur.h"
#include "ui/config/vertical/VerticalPhotoForm.h"

class VerticalPhotoForm;

class VerticalPhotoFilter : public Instrument {
private:
    std::shared_ptr<VerticalPhotoForm> form;

    RadianBlur filter;
    GammaFilter gammaFilter;
    int percents = 25;
public:
    VerticalPhotoFilter();

    std::shared_ptr<QImage> run(QImage &image) override;

    [[nodiscard]] InstrumentForm *getForm() const override;

    [[nodiscard]] int getPercents() const;

    void setPercents(int percents);

    ~VerticalPhotoFilter() override;
};


#endif //FILTERS_VERTICALPHOTOFILTER_H
