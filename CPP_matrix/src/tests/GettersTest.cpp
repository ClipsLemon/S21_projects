#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

TEST(Getters, get_row) {
  S21Matrix matrix(3, 4);
  EXPECT_EQ(matrix.GetRow(), 3);
}

TEST(Getters, get_col) {
  S21Matrix matrix(3, 4);
  EXPECT_EQ(matrix.GetCol(), 4);
}

TEST(Getters, get_matrix) {
  S21Matrix matrix(2, 2);
  double **mtr = matrix.GetMatrix();
  int code = 1;
  for (int r = 0; r < matrix.GetRow(); r++) {
    for (int c = 0; c < matrix.GetCol(); c++) {
      if (matrix.GetMatrixEl(r, c) != mtr[r][c]) {
        code = 0;
        r = matrix.GetRow();
        c = matrix.GetCol();
      }
    }
  }
  EXPECT_EQ(code, 1);
}