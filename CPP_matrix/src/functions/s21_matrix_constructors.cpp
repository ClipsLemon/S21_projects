#include "../s21_matrix_oop.h"

S21Matrix::S21Matrix() {
  rows_ = DEFAULT_ROWS;
  cols_ = DEFAULT_COLUMNS;

  matrix_ = new double *[DEFAULT_ROWS];

  for (int r = 0; r < DEFAULT_ROWS; r++) {
    matrix_[r] = new double[DEFAULT_COLUMNS]{};
  }
}

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  matrix_ = new double *[rows];

  for (int r = 0; r < rows; r++) {
    matrix_[r] = new double[cols]{};
  }
}

S21Matrix::S21Matrix(const S21Matrix &other)
    : rows_(other.rows_), cols_(other.cols_) {
  CopyMatrix(other);
}

S21Matrix::S21Matrix(S21Matrix &&other) noexcept
    : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_) {
  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = nullptr;
}

S21Matrix::~S21Matrix() {
  DeleteMatrix();

  rows_ = 0;
  cols_ = 0;
}
