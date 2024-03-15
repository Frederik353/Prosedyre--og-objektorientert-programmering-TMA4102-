#include "Matrix.h"
#include <bits/stdc++.h>
#include <iostream>

#define MOD 1000000007

int a, b, c, d;
// oppgave 1 a
void fib2(int *res, int n) {
  if (n == 0) {
    res[0] = 0;
    res[1] = 1;
    return;
  }
  fib2(res, n / 2);
  a = res[0];
  b = res[1];
  c = 2 * b - a;

  if (c < 0) {
    c += MOD;
  }

  c = (a * c) % MOD;
  d = (a * a + b * b) % MOD;

  if (n % 2 == 0) {
    res[0] = c;
    res[1] = d;
  } else {
    res[0] = d;
    res[1] = c + d;
  }
}

void fillInFibonacciNumbers(int *result, int length) {
  if (length > 1) {
    result[0] = 0;
  }
  if (length > 2) {
    result[1] = 1;
  }
  for (int i = 2; i < length; i++) {
    result[i] = (result[i - 1] + result[i - 2]) % MOD;
  }
}

// oppgave 1 b
void printArray(int *arr, int len) {
  for (int i = 0; i < len; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

// oppgave 1 c
void createFibonacci() {
  int len;
  std::cout << "Enter the length of the fibonacci sequence: ";
  std::cin >> len;
  int *res = new int[len];
  fillInFibonacciNumbers(res, len);
  printArray(res, len);
}

int main() {
  int a{0};
  int len = 10;
  int *res = new int[len];
  fillInFibonacciNumbers(res, len);
  printArray(res, len);

  int *res2 = new int[2];
  fib2(res2, len - 2);
  printArray(res2, 2);

  std::cout << "------------------------------------------" << std::endl;
  createFibonacci();

  Matrix m(10);
  std::cout << m;

  //   oppgave 5 c
  Matrix A = Matrix(2, 2);
  A[0][0] = 1.0;
  A[0][1] = 2.0;
  A[1][0] = 3.0;
  A[1][1] = 4.0;
  Matrix B = Matrix(2, 2);
  B[0][0] = 4.0;
  B[0][1] = 3.0;
  B[1][0] = 2.0;
  B[1][1] = 1.0;
  Matrix C = Matrix(2, 2);
  C[0][0] = 1.0;
  C[0][1] = 3.0;
  C[1][0] = 1.5;
  C[1][1] = 2.0;
  A += B + C;

  std::cout << "------ A += B + C ------" << std::endl;
  std::cout << A;
  std::cout << "------------" << std::endl;
  std::cout << B;
  std::cout << "------------" << std::endl;
  std::cout << C;

  return 0;
}
