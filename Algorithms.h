#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <vector>

// Функтор для умови: чи є число від'ємним
struct IsNegative {
    bool operator()(int x) const {
        return x < 0;
    }
};

// Функтор для заміни (додавання пів-суми)
struct AddValue {
    double value;
    AddValue(double v) : value(v) {}
    double operator()(double x) const {
        return x + value;
    }
};

// Аналог replace_copy: копіює всі елементи, замінюючи їх за допомогою функтора
template <typename T, typename Op>
void my_replace_copy(const T* source, int size, std::vector<double>& dest, Op op) {
    for (int i = 0; i < size; ++i) {
        dest.push_back(op(static_cast<double>(source[i])));
    }
}

// Аналог replace_copy_if: копіює та замінює лише ті, що відповідають умові
template <typename T, typename Predicate, typename Op>
void my_replace_copy_if(const T* source, int size, std::vector<double>& dest, Predicate pred, Op op) {
    for (int i = 0; i < size; ++i) {
        if (pred(source[i])) {
            dest.push_back(op(static_cast<double>(source[i])));
        } else {
            dest.push_back(static_cast<double>(source[i]));
        }
    }
}

#endif