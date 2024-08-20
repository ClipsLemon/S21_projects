#include "../s21_matrix_oop.h"

S21Matrix S21Matrix::InverseMatrix() {
  S21Matrix result(1, 1);
  if (rows_ != cols_) {
    throw domain_error("The matrix is not square.");
  }
  if (rows_ != 1) {
    double determinant = Determinant();
    // если детерминант равен 0, матрица не может быть транспонирована
    if (determinant != 0) {
      // здесь же матрица и создастся
      S21Matrix tmp(CalcComplements());
      result = tmp.Transpose();

      determinant = 1. / determinant;
      for (int n = 0; n < rows_; n++) {
        for (int m = 0; m < cols_; m++) {
          result.matrix_[n][m] *= determinant;
        }
      }
    } else {
      throw domain_error("Matrix determinant is 0.");
    }
  } else {
    result.matrix_[0][0] = 1.0 / matrix_[0][0];
  }
  return result;
}
