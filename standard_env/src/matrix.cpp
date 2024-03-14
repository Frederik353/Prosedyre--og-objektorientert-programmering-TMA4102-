#include "matrix.h"
#include <cassert>

Matrix::Matrix(int rows, int cols) {
  assert(rows > 0 && cols > 0);
  this->rows = rows;
  this->cols = cols;
  this->matrix = new int[n * m];
  matrix = new int *[rows];
  for (int r = 0; r < rows; r++) {
    matrix[r] = new double[cols];
    for (int c = 0; c < cols; c++) {
      matrix[r][c] = 0.0;
    }
  }
}

explicit Matrix::Matrix(int rows) : Matrix::Matrix(rows, rows) {
  for (int i = 0; i < rows; i++) {
    matrix[i][i] = 1;
  }
}

Matrix::~Matrix() {
  for (int r = 0; r < rows; r++) {
    delete[] matrix[r];
  }
  delete[] matrix;
}

Matrix::get(int r, int c) {
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
int Matrix::getRows() const { return rows; }
int Matrix::getCols() const { return cols; }

// oppgave 2 f
friend std::ostream &operator<<(std::ostream &os, const Matrix &m) {
  for (int i = 0; i < m.rows; i++) {
    for (int j = 0; j < m.cols; j++) {
      os << m.matrix[i][j] << " ";
    }
    os << std::endl;
  }
}
