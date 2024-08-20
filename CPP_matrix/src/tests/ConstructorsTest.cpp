#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

TEST(Constructors, default_test) {
  S21Matrix test_matrix;
  EXPECT_EQ(test_matrix.GetRow(), DEFAULT_ROWS);
  EXPECT_EQ(test_matrix.GetCol(), DEFAULT_COLUMNS);
}