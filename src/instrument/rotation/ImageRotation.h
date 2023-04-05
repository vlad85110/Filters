//
// Created by Влад Кирилов on 02.04.2023.
//

#ifndef FILTERS_IMAGEROTATION_H
#define FILTERS_IMAGEROTATION_H


#include "instrument/Instrument.h"
#include "ui/config/rotation/ImageRotationForm.h"

class ImageRotationForm;

class ImageRotation : public Instrument {
private:
    int angle;
    Vector<double> matrix;
    std::shared_ptr<ImageRotationForm> form;

    static Vector<double> createMatrix(int angle);

public:
    ImageRotation();

public:
    std::shared_ptr<QImage> run(QImage &image) override;

    [[nodiscard]] int getAngle() const;

    void setAngle(int angle);

    [[nodiscard]] InstrumentForm *getForm() const override;

    ~ImageRotation() override;
};


#endif //FILTERS_IMAGEROTATION_H
