#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
#include <iomanip>
#include "Algorithms.h"

std::vector<double> processArray(int* arr, int n) {
    double sumNeg = 0;
    double totalSum = 0;

    // Знаходимо суму від'ємних чисел та загальну суму для подальших розрахунків
    for (int i = 0; i < n; ++i) {
        if (arr[i] < 0) sumNeg += arr[i];
        totalSum += arr[i];
    }

    double halfSumNeg = sumNeg / 2.0;
    double avgAbs = std::abs(totalSum) / n;

    // Створюємо динамічний масив (vector)
    std::vector<double> result;
    result.reserve(n + 2); // Резервуємо місце для основних елементів + суми + сер. арифм.

    // Використовуємо наш шаблон replace_copy з функтором AddValue
    // Додаємо до кожного числа пів-суму від'ємних
    AddValue modifier(halfSumNeg);
    my_replace_copy(arr, n, result, modifier);

    // Дописуємо суму та середнє арифметичне за абсолютною величиною
    result.push_back(totalSum);
    result.push_back(avgAbs);

    return result;
}

int main() {
    srand(static_cast<unsigned>(time(0)));

    int n;
    std::cout << "Enter array size: ";
    std::cin >> n;

    int* sourceArray = new int[n];
    std::cout << "Source array: " << std::endl;
    for (int i = 0; i < n; ++i) {
        sourceArray[i] = rand() % 101 - 50; // від -50 до +50
        std::cout << std::setw(5) << sourceArray[i];
    }
    std::cout << std::endl;

    std::vector<double> dynamicResult = processArray(sourceArray, n);

    std::cout << "Result array (modified elements + sum + avg_abs): " << std::endl;
    for (double val : dynamicResult) {
        std::cout << std::fixed << std::setprecision(2) << std::setw(8) << val;
    }
    std::cout << std::endl;

    delete[] sourceArray;
    return 0;
}