#include "Stopwatch.h"
#include <vector>
#include <iostream>



constexpr size_t matrixSize = 10000;

// Utdelt kode til oppgave 3
void setDiagonalValue(std::vector<double>& matrix, double newValue, size_t maxColIndex){
    // i * matrixSize + j
    for (int pos = 0; pos < maxColIndex + 1; pos++){
        matrix.at(pos * maxColIndex + pos) = newValue;
    }
}

double sumMatrix(std::vector<double>& matrix){
    double sum = 0.0;
    for (int pos = 0; pos < matrix.size(); pos++){
        double value = matrix.at(pos);
        sum += value;
    }
    return sum;
}

void optimizationTask() {
    
    // Create a matrix with zeros
    std::vector<double> matrix( matrixSize * matrixSize);

    // Set all elements on the diagonal to 0.41
    setDiagonalValue(matrix, 0.41, matrixSize - 1 );

    // Sum all elements in the matrix
    double total = sumMatrix(matrix);

    double coolerNumber = total + 2;

    std::cout << "TDT" << coolerNumber << std::endl;
}