#include "../s21_matrix_oop.h"

S21Matrix &S21Matrix::operator=(const S21Matrix &other) noexcept {
  S21Matrix copy{other};
  *this = move(copy);

  return *this;
}

S21Matrix &S21Matrix::operator=(S21Matrix &&other) noexcept {
  if (this != &other) {
    swap(rows_, other.rows_);
    swap(cols_, other.cols_);
    swap(matrix_, other.matrix_);
  }

  return *this;
}

double &S21Matrix::operator()(int row, int col) {
  if (row < 0 || col < 0 || row > rows_ - 1 || col > cols_ - 1) {
    throw std::out_of_range("Index is outside the matrix.");
  }

  return matrix_[row][col];
}

S21Matrix S21Matrix::operator+(const S21Matrix &other) {
  S21Matrix tmp(*this);
  tmp.SumMatrix(other);

  return tmp;
}

S21Matrix S21Matrix::operator-(const S21Matrix &other) {
  S21Matrix tmp(*this);
  tmp.SubMatrix(other);

  return tmp;
}

S21Matrix S21Matrix::operator*(const S21Matrix &other) const {
  S21Matrix tmp(*this);
  tmp.MulMatrix(other);

  return tmp;
}

S21Matrix S21Matrix::operator*(double num) {
  S21Matrix tmp(*this);
  tmp.MulNumber(num);

  return tmp;
}

S21Matrix operator*(double number, S21Matrix &matrix) noexcept {
  S21Matrix tmp = matrix * number;
  return tmp;
}

bool S21Matrix::operator==(const S21Matrix &other) noexcept {
  return EqMatrix(other);
}

S21Matrix &S21Matrix::operator+=(const S21Matrix &other) {
  SumMatrix(other);
  return *this;
}

S21Matrix &S21Matrix::operator-=(const S21Matrix &other) {
  SubMatrix(other);
  return *this;
}

S21Matrix &S21Matrix::operator*=(const S21Matrix &other) {
  MulMatrix(other);
  return *this;
}

S21Matrix &S21Matrix::operator*=(double num) {
  MulNumber(num);
  return *this;
}