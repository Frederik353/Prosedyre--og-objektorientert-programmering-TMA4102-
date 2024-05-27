#include <iostream>
#include <vector>
#include <thread>
#include <numeric>
#include <execution>

constexpr size_t matrixSize = 10000;

void setDiagonalValue(std::vector<double>& matrix, double newValue) {
    for (size_t i = 0; i < matrixSize; ++i) {
        matrix[i * matrixSize + i] = newValue;
    }
}

void partialSum(const std::vector<double>& matrix, double& sum, size_t start, size_t end) {
    sum = std::accumulate(matrix.begin() + start, matrix.begin() + end, 0.0);
}

// double sumMatrix(const std::vector<double>& matrix) {
//     double sum1 = 0.0, sum2 = 0.0;
//     size_t mid = matrix.size() / 2;

//     std::thread t1(partialSum, std::ref(matrix), std::ref(sum1), 0, mid);
//     std::thread t2(partialSum, std::ref(matrix), std::ref(sum2), mid, matrix.size());

//     t1.join();
//     t2.join();

//     return sum1 + sum2;
// }

double sumMatrix(const std::vector<double>& matrix) {
    return std::reduce(std::execution::par, matrix.begin(), matrix.end(), 0.0);
}

void optimizationTask() {
    std::vector<double> matrix(matrixSize * matrixSize, 0.0);

    setDiagonalValue(matrix, 0.41);
    double total = sumMatrix(matrix);

    double coolerNumber = total + 2;

    std::cout << "TDT" << coolerNumber << std::endl;
}
