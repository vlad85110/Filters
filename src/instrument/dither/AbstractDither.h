//
// Created by Влад Кирилов on 01.04.2023.
//

#ifndef FILTERS_ABSTRACTDITHER_H
#define FILTERS_ABSTRACTDITHER_H


#include "instrument/AbstractFilter.h"
#include "ui/config/dither/DitherForm.h"

class DitherForm;

class AbstractDither : public AbstractFilter {
protected:
    int redColorsCnt = 2;
    int greenColorsCnt = 2;
    int blueColorsCnt = 2;

    [[nodiscard]] static int findClosetColor(int color, int colorsCnt);

    std::shared_ptr<DitherForm> form;

public:
    AbstractDither();

    [[nodiscard]] int getRedColorsCnt() const;

    virtual void setRedColorsCnt(int redColorsCnt);

    [[nodiscard]] int getGreenColorsCnt() const;

    virtual void setGreenColorsCnt(int greenColorsCnt);

    [[nodiscard]] int getBlueColorsCnt() const;

    virtual void setBlueColorsCnt(int blueColorsCnt);

    [[nodiscard]] InstrumentForm *getForm() const override;
};


#endif //FILTERS_ABSTRACTDITHER_H
