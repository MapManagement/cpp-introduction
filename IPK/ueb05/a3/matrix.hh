#include <array>
#include <iostream>
#include <ostream>
#include <stdexcept>
template <typename T, int columns, int rows> class Matrix {
  std::array<std::array<T, columns>, rows> storage;

public:
  // a)
  Matrix() {
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < columns; ++j) {
        storage[i][j] = 0;
      }
    }
  }

  template <typename X> Matrix(X container) {
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < columns; ++j) {
        storage[i][j] = container[i][j];
      }
    }
  }

  // a)
  void print() {
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < columns; ++j) {
        std::cout << storage[i][j];

        if (j != columns - 1) {
          std::cout << " ";
        }
      }
      std::cout << std::endl;
    }
  }

  // a)
  int &get(unsigned int row, unsigned int column) {
    if (row > rows) {
      throw std::out_of_range("Not enough rows");
    }

    if (column > columns) {
      throw std::out_of_range("Not enough columns");
    }

    return storage[row][column];
  }

  // b)
  Matrix<T, rows, columns> transpose() {
    Matrix<T, rows, columns> transponierteMatrix;

    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < columns; ++j) {
        transponierteMatrix.get(j, i) = storage[i][j];
      }
    }

    return transponierteMatrix;
  }

  // c)
  Matrix<T, columns, rows> add(Matrix<T, columns, rows> matrix) {
    Matrix<T, columns, rows> summeMatrix;

    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < columns; ++j) {
        summeMatrix.get(i, j) = storage[i][j] + matrix.get(i, j);
      }
    }

    return summeMatrix;
  }

  // c)
  Matrix<T, columns, rows> subtract(Matrix<T, columns, rows> matrix) {
    Matrix<T, columns, rows> differenzMatrix;

    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < columns; ++j) {
        differenzMatrix.get(i, j) = storage[i][j] - matrix.get(i, j);
      }
    }

    return differenzMatrix;
  }

  // d)
};
