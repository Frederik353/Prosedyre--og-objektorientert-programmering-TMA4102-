#include "Stopwatch.h"
#include "optimizationTask.h"
#include <array>
#include <iostream>
#include <vector>

constexpr int size = 10000;

int main() {
  Stopwatch stopwatch = Stopwatch();

  stopwatch.start();
//   for (int i = 0; i < 10; i++){
  optimizationTask();
//   }

  double time = stopwatch.stop();

  std::cout << "time: " << time << " s" << std::endl;

  return 0;
}

// oppgave 1 b
/*
Stack
time: 0.005168 s , iterations: 1000000
Heap
time: 13.9412 s , iterations: 1000000
*/
/*
{
Stack allocation
std::array<int, size> arr1;
Heap
std::array<int, size> *arr2 = new std::array<int, size>;
delete arr2;
}
*/

// oppgave 2 a
/*
size: 1 capacity: 1
size: 2 capacity: 2
size: 3 capacity: 4
size: 4 capacity: 4
size: 5 capacity: 8
size: 6 capacity: 8
size: 7 capacity: 8
size: 8 capacity: 8
size: 9 capacity: 16
size: 10 capacity: 16
size: 11 capacity: 16
size: 12 capacity: 16
size: 13 capacity: 16
size: 14 capacity: 16
size: 15 capacity: 16
size: 16 capacity: 16
size: 17 capacity: 32
size: 18 capacity: 32
size: 19 capacity: 32
size: 20 capacity: 32
time: 0.007887 s , iterations: 20
*/
/*
int main() {
  Stopwatch stopwatch = Stopwatch();

  int iterations = 20;
  stopwatch.start();

  std::vector<int> vec;
  for (int i = 0; i < iterations; i++) {
    vec.push_back(i);
    std::cout << "size: " << vec.size() << " capacity: " << vec.capacity()
              << std::endl;
  }

  double time = stopwatch.stop();

  std::cout << "time: " << time << " s , iterations: " << iterations
            << std::endl;

  return 0;
}
 */

// oppgave 2 b
/*
size: 1 capacity: 20
size: 2 capacity: 20
size: 3 capacity: 20
size: 4 capacity: 20
size: 5 capacity: 20
size: 6 capacity: 20
size: 7 capacity: 20
size: 8 capacity: 20
size: 9 capacity: 20
size: 10 capacity: 20
size: 11 capacity: 20
size: 12 capacity: 20
size: 13 capacity: 20
size: 14 capacity: 20
size: 15 capacity: 20
size: 16 capacity: 20
size: 17 capacity: 20
size: 18 capacity: 20
size: 19 capacity: 20
size: 20 capacity: 20
time: 0.006011 s , iterations: 20
*/
/*
std::vector<int> vec;
vec.reserve(20);
*/

// oppgave 2 c
/*
size: 21 capacity: 40
size: 22 capacity: 40
size: 23 capacity: 40
size: 24 capacity: 40
size: 25 capacity: 40
size: 26 capacity: 40
size: 27 capacity: 40
size: 28 capacity: 40
size: 29 capacity: 40
size: 30 capacity: 40
size: 31 capacity: 40
size: 32 capacity: 40
size: 33 capacity: 40
size: 34 capacity: 40
size: 35 capacity: 40
size: 36 capacity: 40
size: 37 capacity: 40
size: 38 capacity: 40
size: 39 capacity: 40
size: 40 capacity: 40
time: 0.006859 s , iterations: 20
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
17 18 19
*/
/*
std::vector<int> vec;
vec.resize(20);
må endres fra push_back til
vec.at(i) = i;
*/

// oppgave 2 d
// time: 0.01364 s , iterations: 1000000 data: 4000k byte

// oppgave 2 e
/*
resize size and content
time: 0.01459 s , iterations: 1000000 data: 4000k byte
reserve capacity
time: 0.006464 s , iterations: 1000000 data: 4000k byte
*/

/*
constexpr int size = 10000;

int main() {
  Stopwatch stopwatch = Stopwatch();

  int iterations = 1000000;
  stopwatch.start();
  std::vector<int> vec;
  vec.reserve(iterations);
  for (int i = 0; i < iterations; i++) {
    vec.push_back(i);
  }

  double time = stopwatch.stop();

  std::cout << "time: " << time << " s , iterations: " << iterations
            << " data: " << (iterations * 4) / 1000 << "k byte" << std::endl;

  //   for (int i : vec) {
  // std::cout << i << " ";
  //   }

  return 0;
}
*/



// oppgave 3 a
// before optimization
// time: 20.8564 s
// time: 19.084 s
// time: 14.1252 s
// time: 15.1243 s
// time: 14.9027 s



// oppgave 3 b
// reserve matrix space
// time: 16.6986 s

// using resize instead 
// time: 14.5644 s
// time: 12.4309 s
// time: 16.0116 s


// continous vector and col == row removal
// time: 2.59576 s


// constexpr and array instead of vector, sum init
// time: 12.4309 s
// does not work since matrix does not fit on stack
// (((10000*10000*4) / 1000) / 1000)
// = 400 MB
// assuming double = 4 byte
// windows 1MB per thread 
// mac linxu 2 - 8 MB


// double to float
// time: 26.1657 s * 10 float
// time: 24.3245 s double
// sum matrix by reference

// pass by reference diagonal
// time: 2.01439 s

