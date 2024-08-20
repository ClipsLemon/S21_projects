#include "../s21_matrix_oop.h"

S21Matrix S21Matrix::CalcComplements() {
  if (rows_ != cols_) {
    throw domain_error("The matrix is not square.");
  }
  S21Matrix result(rows_, cols_);
  // если нет ошибок
  if (rows_ != 1) {
    for (int n = 0; n < rows_; n++) {
      for (int m = 0; m < cols_; m++) {
        result.matrix_[n][m] = GetMinor(n, m) * powl(-1., n + m);
      }
    }
  } else {
    result.matrix_[0][0] = matrix_[0][0];
  }
  return result;
}
