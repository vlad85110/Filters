//
// Created by Влад Кирилов on 20.03.2023.
//

#include "SmoothingFilter.h"

SmoothingFilter::SmoothingFilter() {
    form = std::make_shared<SmoothingFilterForm>(*this);
    setMatrixSize(3);
}

InstrumentForm *SmoothingFilter::getForm() const {
    return form.get();
}

int SmoothingFilter::getMatrixSize() const {
    return matrixSize;
}

void SmoothingFilter::setMatrixSize(int matrixSize) {
    if (matrixSize % 2 == 0) {
        return;
    }

    this->matrixSize = matrixSize;

    if (matrixSize == 3) {
        matrix = Vector<double>{
                1, 2, 1,
                2, 4, 2,
                1, 2, 1
        };

        mSum = 16;


    } else if (matrixSize == 5) {
        matrix = Vector<double>{
                1, 2, 3, 2, 1,
                2, 4, 5, 4, 2,
                3, 5, 6, 5, 3,
                1, 2, 3, 2, 1,
                2, 4, 5, 4, 2,
        };

        mSum = 74;

    } else {
        matrix.clear();

        for (int i = 0; i < matrixSize * matrixSize; ++i) {
            matrix.emplace_back(1);
        }

        mSum = matrixSize * matrixSize;
    }

    n = matrixSize / 2;
    size = matrixSize;
}

SmoothingFilter::~SmoothingFilter() {
    cout << "Smoothing" << endl;
}
