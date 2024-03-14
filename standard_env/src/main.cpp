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

  createFibonacci();

  return 0;
}
