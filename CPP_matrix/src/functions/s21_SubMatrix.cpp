#include "../s21_matrix_oop.h"

void S21Matrix::SubMatrix(const S21Matrix &other) {
  // если матрицы имеют разные размеры
  if (!EqualSize(other)) {
    throw invalid_argument("different matrix dimensions.");
  }

  // если все в порядке, то суммируем
  // если под матрицу выделилась память
  for (int r = 0; r < rows_; r++) {
    for (int c = 0; c < cols_; c++) {
      matrix_[r][c] = matrix_[r][c] - other.matrix_[r][c];
    }
  }
}
