#include "matrix_ops.h"
#include <iostream>

int** matrix_create(std::size_t rows, std::size_t cols) {
    int** matrix = new int*[rows];

    for (std::size_t i = 0; i < rows; ++i) {
        matrix[i] = new int[cols]{};
    }

    return matrix;
}

void matrix_delete(int** matrix, std::size_t rows) {
    if (matrix == nullptr) {
        return;
    }

    for (std::size_t i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }

    delete[] matrix;
}

void matrix_fill(int** matrix, std::size_t rows, std::size_t cols, int value) {
    if (matrix == nullptr) {
        return;
    }

    for (std::size_t i = 0; i < rows; ++i) {
        for (std::size_t j = 0; j < cols; ++j) {
            matrix[i][j] = value;
        }
    }
}

void matrix_print(int* const* matrix, std::size_t rows, std::size_t cols) {
    if (matrix == nullptr) {
        std::cout << "Матрица не создана\n";
        return;
    }
    std::cout << "\nМатрица:\n";
    for (std::size_t i = 0; i < rows; ++i) {
        for (std::size_t j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

bool matrix_is_symmetric(int* const* matrix, std::size_t size) {
    if (matrix == nullptr) {
        return false;
    }

    for (std::size_t i = 0; i < size; ++i) {
        for (std::size_t j = i + 1; j < size; ++j) {
            if (matrix[i][j] != matrix[j][i]) {
                return false;
            }
        }
    }

    return true;
}

int matrix_trace(int* const* matrix, std::size_t size) {
    if (matrix == nullptr) {
        return 0;
    }

    int result = 0;
    for (std::size_t i = 0; i < size; ++i) {
        result += matrix[i][i];
    }

    return result;
}