cmake_minimum_required(VERSION 3.16)

project(lab1_matrix LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(matrix_ops src/matrix_ops.cpp)
target_include_directories(matrix_ops PUBLIC src)
target_compile_options(matrix_ops PRIVATE -Wall -Wextra -Wpedantic)

add_executable(lab1_main main.cpp)
target_link_libraries(lab1_main PRIVATE matrix_ops)
target_compile_options(lab1_main PRIVATE -Wall -Wextra -Wpedantic)

enable_testing()

find_package(GTest QUIET)

if (NOT GTest_FOUND)
    include(FetchContent)
    FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
        DOWNLOAD_EXTRACT_TIMESTAMP TRUE
    )
    FetchContent_MakeAvailable(googletest)
endif()

if (GTest_FOUND OR TARGET GTest::gtest_main)
    add_executable(matrix_tests tests/test_matrix.cpp)
    target_link_libraries(matrix_tests PRIVATE matrix_ops GTest::gtest_main)
    target_compile_options(matrix_tests PRIVATE -Wall -Wextra -Wpedantic)

    include(GoogleTest)
    gtest_discover_tests(matrix_tests)
else()
    message(WARNING "Google Test не найден, тесты пропущены.")
endif()