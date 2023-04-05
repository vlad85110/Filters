//
// Created by Влад Кирилов on 20.03.2023.
//

#ifndef FILTERS_SMOOTHINGFILTER_H
#define FILTERS_SMOOTHINGFILTER_H


#include "instrument/matrix/AbstractMatrixFilter.h"
#include "ui/config/smoothing/SmoothingFilterForm.h"

class SmoothingFilterForm;

class SmoothingFilter : public AbstractMatrixFilter {
private:
    int matrixSize = 3;
    std::shared_ptr<SmoothingFilterForm> form;
public:
    [[nodiscard]] int getMatrixSize() const;

    void setMatrixSize(int matrixSize);

public:
    SmoothingFilter();

    [[nodiscard]] InstrumentForm *getForm() const override;

    ~SmoothingFilter() override;
};


#endif //FILTERS_SMOOTHINGFILTER_H
