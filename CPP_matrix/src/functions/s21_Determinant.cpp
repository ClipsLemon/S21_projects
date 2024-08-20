#include "../s21_matrix_oop.h"

double S21Matrix::Determinant() {
  if (rows_ != cols_) {
    throw domain_error("The matrix is not square.");
  }
  S21Matrix copy(*this);

  int not_zero = 0, all_zero = 1, sign = 1;
  double *tmp = NULL;
  double result = 1.;

  for (int rows = 0; rows < copy.rows_ - 1 && result; rows++) {
    for (not_zero = rows, all_zero = 1; not_zero < copy.rows_;
         not_zero++) {  // ищем ненулевой элемент
      if (copy.matrix_[not_zero][rows]) {
        tmp = copy.matrix_[not_zero];
        all_zero = 0;  // все - не нули
        break;
      }
    }

    if (copy.matrix_[rows][rows] == 0. &&
        tmp) {  // если элемент диагонали равен нулю и есть ненулевой
      copy.matrix_[not_zero] = copy.matrix_[rows];
      copy.matrix_[rows] = tmp;
      sign = -sign;
    }  // при смене строк/столбцов местами меняется знак определителя
    if (all_zero) {  // если все нули - определитель равен нулю
      result = 0.;
    } else {
      for (int m = rows + 1; m < copy.rows_; m++) {
        double tmp = copy.matrix_[m][rows] / copy.matrix_[rows][rows];

        for (int n = rows; n < copy.cols_; n++) {
          copy.matrix_[m][n] -= copy.matrix_[rows][n] * tmp;
        }
      }
    }
  }
  for (int k = 0; k < rows_; k++) {
    result *= copy.matrix_[k][k];
  }
  result *= sign;

  return result;
}