//
// Created by Влад Кирилов on 21.03.2023.
//

#ifndef FILTERS_INSTRUMENTFORM_H
#define FILTERS_INSTRUMENTFORM_H

#include <QDialog>
#include <QFormLayout>
#include <unordered_map>
#include "ui/config/input/InputWithErrorLabel.h"

class InstrumentForm : public QDialog {
Q_OBJECT

protected:
    std::unordered_map<std::string, std::shared_ptr<InputWithErrorLabel>> inputs;
    std::shared_ptr<QFormLayout> inputsLayout;

    virtual bool verify();

public:
    InstrumentForm();

    void addInputs();

    virtual void initInputs() = 0;

    int exec() override;

    void clear();

protected slots:

    void onOkClicked();

    void onCancelClicked();
};


#endif //FILTERS_INSTRUMENTFORM_H
