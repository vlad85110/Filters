//
// Created by Влад Кирилов on 01.04.2023.
//

#include <QComboBox>
#include <QLabel>
#include "SmoothingFilterForm.h"

SmoothingFilterForm::SmoothingFilterForm(SmoothingFilter &filter) : filter(filter), comboBox() {
    auto label = new QLabel("Matrix size");

    comboBox.addItem("3");
    comboBox.addItem("5");
    comboBox.addItem("7");
    comboBox.addItem("9");
    comboBox.addItem("11");

    inputsLayout->addRow(label, &comboBox);

    addInputs();
}

void SmoothingFilterForm::initInputs() {}

bool SmoothingFilterForm::verify() {
    auto res = InstrumentForm::verify();

    auto matrixSize = comboBox.itemText(comboBox.currentIndex()).toInt();
    filter.setMatrixSize(matrixSize);

    return res;
}


