//
// Created by Влад Кирилов on 22.03.2023.
//

#ifndef FILTERS_GAMMAFILTER_H
#define FILTERS_GAMMAFILTER_H


#include "instrument/single_pixel/SinglePixelFilter.h"
#include "ui/config/gamma/GammaFilterForm.h"

class GammaFilterForm;

class GammaFilter : public SinglePixelFilter {
private:
    double gamma;
    std::shared_ptr<GammaFilterForm> form;

    [[nodiscard]] int newGamma(int prev) const;

protected:
    [[nodiscard]] QRgb handlePixel(QRgb pixel) const override;

public:
    GammaFilter();

    [[nodiscard]] double getGamma() const;

    void setGamma(double gamma);

    [[nodiscard]] InstrumentForm *getForm() const override;

    ~GammaFilter() override;
};


#endif //FILTERS_GAMMAFILTER_H
