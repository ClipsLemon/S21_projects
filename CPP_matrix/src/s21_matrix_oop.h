#ifndef S21_MATRIX_OOP_H
#define S21_MATRIX_OOP_H

// стандартные значения
#define DEFAULT_ROWS 0
#define DEFAULT_COLUMNS 0

// БИБЛИОТЕКИ НА ПЕРИОД РАЗРАБОТКИ, НЕ НУЖНЫ В ПРОЕКТЕ
#include <algorithm>
#include <cmath>
// #include <iostream>
#include <stdexcept>
#include <utility>

using namespace std;

class S21Matrix {
 private:
  // Attributes
  int rows_, cols_;  // Rows and columns
  double **matrix_;  // Pointer to the memory where the matrix is allocated

  // дополнительные методы
  /**
   * @brief Метод копирования только матричной части объекта. Не копирует
   * параметры матрицы Обоснование: необходим был для уменьшения дублирования
   * кода в программе.
   *
   * @param source - матрица, которую будем копировать в исходную
   */
  void CopyMatrix(const S21Matrix &source);

  /**
   * @brief Функция производит копирование параметров заданной матрицы в
   * исходную
   *
   */

  /**
   * @brief Функция производит очистку динамической памяти выделенной под
   * матрицу. Необходимо, если, например, был создан объект матрицы. Под матрицу
   * выделилась память стандартным конструктором, а затем был использован
   * перегруженный оператор присванивания
   *
   */
  void DeleteMatrix();

  /**
   * @brief Функция проводит проверку размерности исходной матрицы и переданной
   * матрицы
   *
   * @param other
   * @return true - матрицы соразмерны
   * @return false - матрицы несоразмерны
   */
  bool EqualSize(const S21Matrix &other);

 public:
  S21Matrix();  // базовый конструктор с заранее заданными размерами
  S21Matrix(int rows, int cols);  // параметризированный конструктор
  S21Matrix(const S21Matrix &other);  // конструктор копирования
  S21Matrix(S21Matrix &&other) noexcept;  // конструктор переноса
  ~S21Matrix();                           // деструктор

  bool EqMatrix(const S21Matrix &other) noexcept;
  void SumMatrix(const S21Matrix &other);
  void SubMatrix(const S21Matrix &other);
  void MulNumber(const double num) noexcept;
  void MulMatrix(const S21Matrix &other);
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();

  double &operator()(int row, int col);

  S21Matrix &operator=(const S21Matrix &other) noexcept;
  S21Matrix &operator=(S21Matrix &&other) noexcept;

  S21Matrix operator+(const S21Matrix &other);

  S21Matrix operator-(const S21Matrix &other);

  S21Matrix operator*(const S21Matrix &other) const;
  S21Matrix operator*(double num);
  friend S21Matrix operator*(double number, S21Matrix &matrix) noexcept;

  bool operator==(const S21Matrix &other) noexcept;

  S21Matrix &operator+=(const S21Matrix &other);

  S21Matrix &operator-=(const S21Matrix &other);

  S21Matrix &operator*=(const S21Matrix &other);
  S21Matrix &operator*=(double num);

  // дополнительные методы
  // сетеры и гетеры
  /**
   * @brief Взять количество строк
   *
   * @return int - количество строк
   */
  int GetRow();

  /**
   * @brief Взять столбцы
   *
   * @return int - количество столбцов
   */
  int GetCol();

  /**
   * @brief Взять элемент матрицы (с возможностью редактирования)
   *
   * @param row - строка
   * @param col - столбец
   * @return double& - ссылка на элемент
   */
  double &GetMatrixEl(int row, int col);

  /**
   * @brief Взять матрицу (с возможностью редактирования)
   *
   * @return double** ссылка на матрицу
   */
  double **GetMatrix();

  /**
   * @brief Задать новое количество строк
   *
   * @param new_row - новое количество строк
   */
  void SetRows(int new_row);

  /**
   * Задать новое количество столбцов
   *
   * @param new_col - новое количество столбцов
   */
  void SetCols(int new_col);

  /**
   * @brief Функция возвращает минор матрицы
   *
   * @param row - вычеркиваемая строка
   * @param column - вычеркиваемый столбец
   * @return double - значение миноры матрицы за вычетом row и columnt
   */
  double GetMinor(int row, int col);
};

#endif