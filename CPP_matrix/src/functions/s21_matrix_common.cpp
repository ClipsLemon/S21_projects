#include "../s21_matrix_oop.h"

void S21Matrix::CopyMatrix(const S21Matrix &source) {
  if (this != &source) {
    matrix_ = new double *[source.rows_];
    for (int r = 0; r < source.rows_; r++) {
      matrix_[r] = new double[source.cols_];
      for (int c = 0; c < source.cols_; c++) {
        matrix_[r][c] = source.matrix_[r][c];
      }
    }
  }
}

void S21Matrix::DeleteMatrix() {
  for (int r = 0; r < rows_; r++) {
    delete[] matrix_[r];
  }
  delete[] matrix_;
}

bool S21Matrix::EqualSize(const S21Matrix &other) {
  if (other.rows_ == rows_ && other.cols_ == cols_) {
    return true;
  } else {
    return false;
  }
}

int S21Matrix::GetRow() { return rows_; }

int S21Matrix::GetCol() { return cols_; }

double &S21Matrix::GetMatrixEl(int row, int col) { return (*this)(row, col); }

double **S21Matrix::GetMatrix() { return matrix_; }

void S21Matrix::SetRows(int new_row) {
  S21Matrix tmp(move(*this));
  rows_ = new_row;
  cols_ = tmp.cols_;
  matrix_ = new double *[rows_];
  for (int r = 0; r < rows_; r++) {
    matrix_[r] = new double[cols_]{};
    if (r < tmp.rows_) {
      for (int c = 0; c < cols_; c++) {
        matrix_[r][c] = tmp.matrix_[r][c];
      }
    }
  }
}

void S21Matrix::SetCols(int new_col) {
  S21Matrix tmp(move(*this));
  rows_ = tmp.rows_;
  cols_ = new_col;
  matrix_ = new double *[rows_];
  for (int r = 0; r < rows_; r++) {
    matrix_[r] = new double[cols_]{};
    for (int c = 0; c < tmp.cols_ && c < cols_; c++) {
      matrix_[r][c] = tmp.matrix_[r][c];
    }
  }
}

double S21Matrix::GetMinor(int row, int col) {
  S21Matrix minor_matrix(rows_ - 1, cols_ - 1);
  for (int n = 0, min_n = 0; n < rows_; n++) {
    if (n != row) {
      for (int m = 0, min_m = 0; m < cols_; m++) {
        if (m != col) {
          minor_matrix.matrix_[min_n][min_m++] = matrix_[n][m];
        }
      }
      min_n++;
    }
  }
  double minor = minor_matrix.Determinant();

  return minor;
}
