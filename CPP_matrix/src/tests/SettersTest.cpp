#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

TEST(Setters, set_new_rows_higher) {
  S21Matrix matrix(3, 4);
  matrix.SetRows(5);
  EXPECT_EQ(matrix.GetRow(), 5);
}

TEST(Setters, set_new_rows_lower) {
  S21Matrix matrix(3, 4);
  matrix.SetRows(1);
  EXPECT_EQ(matrix.GetRow(), 1);
}

TEST(Setters, set_new_cols_higher) {
  S21Matrix matrix(3, 4);
  matrix.SetCols(5);
  EXPECT_EQ(matrix.GetCol(), 5);
}

TEST(Setters, set_new_cols_lower) {
  S21Matrix matrix(3, 4);
  matrix.SetCols(1);
  EXPECT_EQ(matrix.GetCol(), 1);
}
