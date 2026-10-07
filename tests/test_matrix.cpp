#include "matrix_ops.h"
#include <gtest/gtest.h>

TEST(MatrixTest, CreateOneByOne) {
    int** matrix = matrix_create(1, 1);
    ASSERT_NE(matrix, nullptr);
    EXPECT_EQ(matrix[0][0], 0);
    matrix_delete(matrix, 1);
}

TEST(MatrixTest, CreateThreeByThree) {
    int** matrix = matrix_create(3, 3);
    ASSERT_NE(matrix, nullptr);
    EXPECT_EQ(matrix[2][2], 0);
    matrix_delete(matrix, 3);
}

TEST(MatrixTest, FillWithZero) {
    int** matrix = matrix_create(2, 2);
    matrix_fill(matrix, 2, 2, 0);
    EXPECT_EQ(matrix[0][0], 0);
    EXPECT_EQ(matrix[1][1], 0);
    matrix_delete(matrix, 2);
}

TEST(MatrixTest, FillWithNegativeValue) {
    int** matrix = matrix_create(2, 2);
    matrix_fill(matrix, 2, 2, -7);
    EXPECT_EQ(matrix[0][1], -7);
    EXPECT_EQ(matrix[1][0], -7);
    matrix_delete(matrix, 2);
}

TEST(MatrixTest, SymmetricMatrix) {
    int** matrix = matrix_create(2, 2);
    matrix[0][0] = 1;
    matrix[0][1] = 2;
    matrix[1][0] = 2;
    matrix[1][1] = 3;
    EXPECT_TRUE(matrix_is_symmetric(matrix, 2));
    matrix_delete(matrix, 2);
}

TEST(MatrixTest, NotSymmetricMatrix) {
    int** matrix = matrix_create(2, 2);
    matrix[0][1] = 2;
    matrix[1][0] = 3;
    EXPECT_FALSE(matrix_is_symmetric(matrix, 2));
    matrix_delete(matrix, 2);
}

TEST(MatrixTest, OneElementIsSymmetric) {
    int** matrix = matrix_create(1, 1);
    matrix[0][0] = 5;
    EXPECT_TRUE(matrix_is_symmetric(matrix, 1));
    matrix_delete(matrix, 1);
}

TEST(MatrixTest, ZeroMatrixHasZeroTrace) {
    int** matrix = matrix_create(3, 3);
    EXPECT_EQ(matrix_trace(matrix, 3), 0);
    matrix_delete(matrix, 3);
}

TEST(MatrixTest, TraceIsCalculated) {
    int** matrix = matrix_create(3, 3);
    matrix[0][0] = 1;
    matrix[1][1] = 5;
    matrix[2][2] = 9;
    EXPECT_EQ(matrix_trace(matrix, 3), 15);
    matrix_delete(matrix, 3);
}

TEST(MatrixTest, NegativeTraceIsCalculated) {
    int** matrix = matrix_create(2, 2);
    matrix[0][0] = -2;
    matrix[1][1] = -3;
    EXPECT_EQ(matrix_trace(matrix, 2), -5);
    matrix_delete(matrix, 2);
}

TEST(MatrixTest, NullMatrixIsSafe) {
    EXPECT_FALSE(matrix_is_symmetric(nullptr, 2));
    EXPECT_EQ(matrix_trace(nullptr, 2), 0);
    matrix_delete(nullptr, 2);
}