//
// Created by Влад Кирилов on 04.04.2023.
//

#ifndef FILTERS_VERTICALPHOTOFORM_H
#define FILTERS_VERTICALPHOTOFORM_H


#include "ui/config/InstrumentForm.h"
#include "ui/config/input/DoubleInputWithErrorLabel.h"
#include "instrument/vertical/VerticalPhotoFilter.h"

class VerticalPhotoFilter;

class VerticalPhotoForm : public InstrumentForm {
public:
    VerticalPhotoFilter& filter;

    explicit VerticalPhotoForm(VerticalPhotoFilter &filter);

    void initInputs() override;

protected:
    bool verify() override;

private:
    std::shared_ptr<DoubleInputWithErrorLabel> widthInput;

};


#endif //FILTERS_VERTICALPHOTOFORM_H
