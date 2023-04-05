//
// Created by Влад Кирилов on 16.03.2023.
//

#ifndef FILTERS_GRAYSCALEFILTER_H
#define FILTERS_GRAYSCALEFILTER_H


#include "instrument/Instrument.h"
#include "instrument/single_pixel/SinglePixelFilter.h"
#include "ui/config/gray_scale/GrayScaleFilterForm.h"

class GrayScaleFilterForm;

class GrayScaleFilter : public SinglePixelFilter {
private:
    std::shared_ptr<GrayScaleFilterForm> form;

    double rWeight = 0.3;
    double gWeight = 0.59;
    double bWeight = 0.11;

protected:
    [[nodiscard]] QRgb handlePixel(QRgb pixel) const override;
public:
    [[nodiscard]] int toGrayScale(int red, int green, int blue) const;

    GrayScaleFilter();

    [[nodiscard]] InstrumentForm *getForm() const override;

    [[nodiscard]] double getRWeight() const;

    [[nodiscard]] double getGWeight() const;

    [[nodiscard]] double getBWeight() const;

    void setRWeight(double rWeight);

    void setGWeight(double gWeight);

    void setBWeight(double bWeight);

    ~GrayScaleFilter() override;
};

#endif //FILTERS_GRAYSCALEFILTER_H
