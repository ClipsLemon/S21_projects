#include "../s21_matrix_oop.h"

S21Matrix S21Matrix::Transpose() {
  S21Matrix transposed(cols_, rows_);
  for (int r = 0; r < rows_; r++) {
    for (int c = 0; c < cols_; c++) {
      transposed.GetMatrixEl(c, r) = matrix_[r][c];
    }
  }

  return transposed;
}