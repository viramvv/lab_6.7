#include <gtest/gtest.h>
#include <vector>
#include "Algorithms.h"

// Приклад тесту для перевірки розрахунку пів-суми від'ємних чисел
TEST(ArrayProcessingTest, HandlesNegativeSum) {
    int arr[] = {-10, -20, 30}; // Сума від'ємних = -30, пів-сума = -15
    int n = 3;
    
    // Очікувані значення: 
    // -10 + (-15) = -25
    // -20 + (-15) = -35
    // 30 + (-15) = 15
    // Останні два елементи: сума (0) та сер. арифм. абс (0/3 = 0)
    
    std::vector<double> result;
    double halfSumNeg = -15.0;
    AddValue modifier(halfSumNeg);
    
    my_replace_copy(arr, n, result, modifier);
    
    ASSERT_EQ(result.size(), 3);
    EXPECT_DOUBLE_EQ(result[0], -25.0);
    EXPECT_DOUBLE_EQ(result[1], -35.0);
    EXPECT_DOUBLE_EQ(result[2], 15.0);
}

// Тест функтора умови
TEST(FunctorTest, IsNegativeCheck) {
    IsNegative isNeg;
    EXPECT_TRUE(isNeg(-5));
    EXPECT_FALSE(isNeg(0));
    EXPECT_FALSE(isNeg(10));
}