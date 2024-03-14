#pragma once
#include <cassert>
#include <ostream>


// oppgave 2 a
class Matrix {
    private:
    int rows;
    int cols;
    int** matrix;

    public:
    Matrix(int rows, int cols);
    explicit Matrix(int rows);
    ~Matrix();
    int get(int row, int col) const;
    void set(int row, int col, double value);
    double* operator[](int row);
    const double* operator[](int row) const;
    int getRows() const;
    int getCols() const;
    friend std::ostream& operator<<(std::ostream& os, const Matrix& m);


};