//
// Created by Влад Кирилов on 18.03.2023.
//

#ifndef FILTERS_TYPES_H
#define FILTERS_TYPES_H

#include <functional>
#include "unordered_map"

template <typename T>
using Consumer = std::function<void(T)>;
using String = std::string;

template<typename K, typename V>
using HashMap = std::unordered_map<K, V>;

template<class T1, class T2>
using Pair = std::pair<T1, T2>;

template<class T>
using Vector = std::vector<T>;

using Runnable = std::function<void(void)>;

#include <iostream>
using std::cout;
using std::endl;

#endif //FILTERS_TYPES_H
