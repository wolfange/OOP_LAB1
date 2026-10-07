#include "matrix_ops.h"
#include <iostream>

void clear_input() {
    std::cin.clear();
    std::cin.ignore(10000, '\n');
}

int main() {
    int** matrix = nullptr;
    std::size_t size = 0;
    int command = -1;

    while (command != 0) {
        std::cout << "\n1. Создать матрицу\n"
                  << "2. Заполнить значением\n"
                  << "3. Напечатать\n"
                  << "4. Алгоритм варианта\n"
                  << "0. Выход\n"
                  << "\nВаш выбор: ";

        if (!(std::cin >> command)) {
            clear_input();
            std::cout << "Ошибка ввода\n";
            continue;
        }

        if (command == 1) {
            std::size_t new_size = 0;
            std::cout << "Размер матрицы: ";
            if (!(std::cin >> new_size) || new_size == 0) {
                clear_input();
                std::cout << "Размер должен быть положительным\n";
                continue;
            }

            matrix_delete(matrix, size);
            size = new_size;
            matrix = matrix_create(size, size);
            std::cout << "Матрица создана\n";
        } else if (command == 2) {
            if (matrix == nullptr) {
                std::cout << "Сначала создайте матрицу\n";
                continue;
            }

            int value = 0;
            std::cout << "Значение: ";
            if (!(std::cin >> value)) {
                clear_input();
                std::cout << "Ошибка ввода\n";
                continue;
            }
            std::cout << '\n';
            matrix_fill(matrix, size, size, value);
        } else if (command == 3) {
            matrix_print(matrix, size, size);
            std::cout << '\n';
        } else if (command == 4) {
            if (matrix == nullptr) {
                std::cout << "Сначала создайте матрицу\n";
                continue;
            }

            std::cout << "Симметричная: "
                      << (matrix_is_symmetric(matrix, size) ? "Да" : "Нет")
                      << '\n';
            std::cout << "След: " << matrix_trace(matrix, size) << '\n';
        } else if (command != 0) {
            std::cout << "Неизвестная команда\n";
        }
    }

    matrix_delete(matrix, size);
    matrix = nullptr;
    return 0;
}