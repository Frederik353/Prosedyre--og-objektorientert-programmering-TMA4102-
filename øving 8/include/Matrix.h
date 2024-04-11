#pragma once
#include <cassert>
#include <ostream>


// oppgave 2 a
class Matrix {
private:
  int rows;
  int cols;
  double **matrix;

public:
  Matrix(int rows, int cols);
  explicit Matrix(int rows);
  Matrix(const Matrix &m);
  ~Matrix();
  double get(int row, int col) const;
  void set(int row, int col, double value);
  double getRows() const;
  double getCols() const;
  double *operator[](int row);
  const double *operator[](int row) const;
  friend std::ostream &operator<<(std::ostream &os, const Matrix &m);
  Matrix operator=(const Matrix &m);
  Matrix operator+=(const Matrix &m);
  Matrix operator+(const Matrix &m);
  Matrix operator-=(const Matrix &m);
  Matrix operator-(const Matrix &m);
  Matrix operator*=(const Matrix &m);
  Matrix operator*(const Matrix &m);
};