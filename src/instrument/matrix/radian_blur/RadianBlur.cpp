//
// Created by Влад Кирилов on 04.04.2023.
//

#include "RadianBlur.h"

RadianBlur::RadianBlur() {
    matrix = Vector<double> {
            0, 0, 0, 1, 0, 0, 0,
            0, 0, 1, 1, 1, 0, 0,
            0, 1, 1, 1, 1, 1, 0,
            1, 1, 1, 1, 1, 1, 1,
            0, 1, 1, 1, 1, 1, 0,
            0, 0, 1, 1, 1, 0, 0,
            0, 0, 0, 1, 0, 0, 0
    };

    mSum = 0;

    for (auto &el: matrix) {
         mSum += (int)el;
    }

    n = 3;
    size = (int) sqrt(matrix.size());
}

RadianBlur::~RadianBlur() {
    cout << "Radian" << endl;
}
