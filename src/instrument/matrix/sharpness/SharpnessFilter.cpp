//
// Created by Влад Кирилов on 20.03.2023.
//

#include "SharpnessFilter.h"

SharpnessFilter::SharpnessFilter() {
    matrix = Vector<double>{
            0, -1, 0,
            -1, 5, -1,
            0, -1, 0
    };

    mSum = 1;
    n = 1;
    size = (int) sqrt(matrix.size());
}

SharpnessFilter::~SharpnessFilter() {
    cout << "Sharpness" << endl;
}
