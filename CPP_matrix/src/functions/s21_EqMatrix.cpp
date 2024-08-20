#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

bool S21Matrix::EqMatrix(const S21Matrix &other) noexcept {
  bool code = true;
  // если матрицы одинаковы, то проверяем
  if (EqualSize(other)) {
    for (int r = 0; r < rows_; r++) {
      for (int c = 0; c < cols_; c++) {
        if (fabs(matrix_[r][c] - other.matrix_[r][c]) >= 1e-7) {
          code = false;
          r = rows_;
          c = cols_;
        }
      }
    }
  } else {
    code = false;
  }
  return code;
}