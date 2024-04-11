#include "Matrix.h"
#include <cassert>
#include <stdexcept>

Matrix::Matrix(int rows, int cols) {
  assert(rows > 0 && cols > 0);
  this->rows = rows;
  this->cols = cols;
  //   this->matrix = new int[n * m];
  matrix = new double *[rows];
  for (int r = 0; r < rows; r++) {
    matrix[r] = new double[cols];
    for (int c = 0; c < cols; c++) {
      matrix[r][c] = 0.0;
    }
  }
}

Matrix::Matrix(int rows) : Matrix::Matrix(rows, rows) {
  for (int i = 0; i < rows; i++) {
    matrix[i][i] = 1;
  }
}

Matrix::Matrix(const Matrix &m) {
  rows = m.rows;
  cols = m.cols;
  matrix = new double *[rows];
  for (int r = 0; r < rows; r++) {
    matrix[r] = new double[cols];
    for (int c = 0; c < cols; c++) {
      matrix[r][c] = m.matrix[r][c];
    }
  }
}

Matrix::~Matrix() {
  for (int r = 0; r < rows; r++) {
    delete[] matrix[r];
  }
  delete[] matrix;
}

// oppgave 4 b
Matrix Matrix::operator=(const Matrix &rhs) {
  if (this != &rhs) {
    for (int r = 0; r < rows; r++) {
      delete[] matrix[r];
    }
    delete[] matrix;
  }
  rows = rhs.rows;
  cols = rhs.cols;
  for (int r = 0; r < rows; r++) {
    matrix[r] = new double[cols];
    for (int c = 0; c < cols; c++) {
      matrix[r][c] = rhs.matrix[r][c];
    }
  }
  return *this;
}

// oppgave 5 a
Matrix Matrix::operator+=(const Matrix &m) {
  if (rows != m.rows || cols != m.cols) {
    throw std::invalid_argument("Matrix dimensions do not match");
  }
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      matrix[r][c] += m.matrix[r][c];
    }
  }
  return *this;
}

// oppgave 5 b
Matrix Matrix::operator+(const Matrix &m) {
  Matrix res = *this;
  res += m;
  return res;
};

Matrix Matrix::operator-=(const Matrix &m) {
  if (rows != m.rows || cols != m.cols) {
    throw std::invalid_argument("Matrix dimensions do not match");
  }
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      matrix[r][c] -= m.matrix[r][c];
    }
  }
  return *this;
}

Matrix Matrix::operator-(const Matrix &m) {
  Matrix res = *this;
  res -= m;
  return res;
};

Matrix Matrix::operator*=(const Matrix &m) {
  if (cols != m.rows) {
    throw std::invalid_argument(
        "Matrix dimensions do not match for multiplication");
  }

  Matrix result(rows, m.cols);
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < m.cols; c++) {
      double sum = 0;
      for (int k = 0; k < cols;
           k++) { // eller bruk m.rows, siden cols == m.rows
        sum += matrix[r][k] * m.matrix[k][c];
      }
      result.matrix[r][c] = sum;
    }
  }
  *this = result;
  return *this;
}

Matrix Matrix::operator*(const Matrix &m) {
  Matrix res = *this;
  res *= m;
  return res;
};

double Matrix::get(int r, int c) const {
  assert(r >= 0 && r < rows);
  assert(c >= 0 && c < cols);
  return matrix[r][c];
}

void Matrix::set(int r, int c, double v) {
  assert(r >= 0 && r < rows);
  assert(c >= 0 && c < cols);
  matrix[r][c] = v;
}

// oppgave 1 d
double *Matrix::operator[](int row) {
  assert(row >= 0 && row < rows);
  return matrix[row];
};

const double *Matrix::operator[](int row) const {
  assert(row >= 0 && row < rows);
  return matrix[row];
};

// oppgave 1 d
double Matrix::getRows() const { return rows; }
double Matrix::getCols() const { return cols; }

// oppgave 2 f
std::ostream &operator<<(std::ostream &os, const Matrix &m) {
  for (int i = 0; i < m.rows; i++) {
    for (int j = 0; j < m.cols; j++) {
      os << m.matrix[i][j] << "  ";
    }
    os << std::endl;
  }
  return os;
}
