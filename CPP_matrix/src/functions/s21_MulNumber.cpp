#include "../s21_matrix_oop.h"

void S21Matrix::MulNumber(const double num) noexcept {
  for (int r = 0; r < rows_; r++) {
    for (int c = 0; c < cols_; c++) {
      matrix_[r][c] = matrix_[r][c] * num;
    }
  }
}