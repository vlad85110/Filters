//
// Created by Влад Кирилов on 03.04.2023.
//

#ifndef FILTERS_IMAGEROTATIONFORM_H
#define FILTERS_IMAGEROTATIONFORM_H


#include "ui/config/InstrumentForm.h"
#include "ui/config/input/DoubleInputWithErrorLabel.h"
#include "instrument/rotation/ImageRotation.h"

class ImageRotation;

class ImageRotationForm : public InstrumentForm {
private:
    ImageRotation& filter;
    std::shared_ptr<DoubleInputWithErrorLabel> angleInput;
public:
    explicit ImageRotationForm(ImageRotation &filter);

    void initInputs() override;

protected:
    bool verify() override;


};


#endif //FILTERS_IMAGEROTATIONFORM_H
