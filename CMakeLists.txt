cmake_minimum_required(VERSION 3.20)
project(Lab_6_Templates)

set(CMAKE_CXX_STANDARD 17)

# Додаємо Google Test через FetchContent (найпростіший спосіб для CLion)
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
# Для Windows/macOS іноді потрібно вимкнути застереження
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# 1. Основна програма
add_executable(Lab_Main main.cpp Algorithms.h)

# 2. Тестова програма
add_executable(UnitTest UnitTest.cpp Algorithms.h)
target_link_libraries(UnitTest GTest::gtest GTest::gtest_main)

# Додаємо можливість запуску тестів через вкладку "Run" у CLion
enable_testing()
include(GoogleTest)
gtest_discover_tests(UnitTest)