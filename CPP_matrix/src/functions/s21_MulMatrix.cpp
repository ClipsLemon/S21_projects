#include "../s21_matrix_oop.h"

void S21Matrix::MulMatrix(const S21Matrix &other) {
  // если матрица не проходит по значениям
  if (cols_ != other.rows_) {
    throw invalid_argument(
        "The number of columns of the first matrix is not "
        "equal to the number of rows of the second matrix.");
  }

  // создаем копию, в которую будем писать данные
  S21Matrix result(rows_, other.cols_);
  for (int n = 0; n < rows_; n++) {
    for (int m = 0; m < other.cols_; m++) {
      for (int r = 0; r < cols_; r++) {
        result.matrix_[n][m] += (matrix_[n][r] * other.matrix_[r][m]);
      }
    }
  }

  *this = move(result);
}
