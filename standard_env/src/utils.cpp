#include <random>

int randomWithLimits(int lower, int upper) {
  std::random_device rd;
  std::default_random_engine generator(rd());
  std::uniform_int_distribution<int> distribution(lower, upper);
  int number = distribution(generator);
  return number;
}