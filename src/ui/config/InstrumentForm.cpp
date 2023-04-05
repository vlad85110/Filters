//
// Created by Влад Кирилов on 21.03.2023.
//

#include <QDialogButtonBox>
#include <QFormLayout>
#include "InstrumentForm.h"

InstrumentForm::InstrumentForm() {
    inputsLayout = std::make_shared<QFormLayout>();
}

void InstrumentForm::addInputs() {
    auto buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    buttonBox->setCenterButtons(true);

    connect(buttonBox, &QDialogButtonBox::accepted, this, &InstrumentForm::onOkClicked);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &InstrumentForm::onCancelClicked);

    auto inputsWidget = new QWidget();
    inputsWidget->setLayout(inputsLayout.get());

    for (auto &input: inputs) {
        inputsLayout->addWidget(input.second.get());
    }

    auto layout = new QFormLayout();
    layout->addWidget(inputsWidget);
    layout->addRow(buttonBox);
    setLayout(layout);
}

int InstrumentForm::exec() {
    initInputs();
    return QDialog::exec();
}

bool InstrumentForm::verify() {
    auto isValid = true;

    for (auto &input: inputs) {
        isValid &= input.second->verify();
    }

    return isValid;
}

void InstrumentForm::clear() {
    for (auto &input: inputs) {
        input.second->clear();
    }
}

void InstrumentForm::onOkClicked() {
    if (verify()) {
        accept();
    }
}

void InstrumentForm::onCancelClicked() {
    reject();
}

