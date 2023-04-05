//
// Created by Влад Кирилов on 01.04.2023.
//

#include "EmbossingFilterForm.h"

EmbossingFilterForm::EmbossingFilterForm(EmbossingFilter &filter) : filter(filter), comboBox() {
    auto label = new QLabel("Orientation");

    comboBox.addItem("Right");
    comboBox.addItem("Left");

    inputsLayout->addRow(label, &comboBox);

    addInputs();
}

bool EmbossingFilterForm::verify() {
    auto res = InstrumentForm::verify();

    auto orientation = comboBox.currentIndex();
    filter.setOrientation(static_cast<EmbossingOrientation>(orientation));

    return res;
}

void EmbossingFilterForm::initInputs() {}
