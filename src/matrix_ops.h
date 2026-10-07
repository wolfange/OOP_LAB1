#pragma once
#include <cstddef>

int** matrix_create(std::size_t rows, std::size_t cols);
void matrix_delete(int** matrix, std::size_t rows);
void matrix_fill(int** matrix, std::size_t rows, std::size_t cols, int value);
void matrix_print(int* const* matrix, std::size_t rows, std::size_t cols);
bool matrix_is_symmetric(int* const* matrix, std::size_t size);
int matrix_trace(int* const* matrix, std::size_t size);