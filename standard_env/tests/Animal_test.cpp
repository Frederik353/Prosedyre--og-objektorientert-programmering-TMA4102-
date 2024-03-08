#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "gtest/gtest.h"

#include <functional>
#include <iostream>
#include <vector>

/*
template<typename Func, typename Result, typename... Args>
void runTest(Func func, const Result& expected, Args... args) {
    auto result = func(args...); // Kaller funksjonen med de gitt argumentene
    std::cout << "Result: " << result << ", Expected: " << expected <<
std::endl; assert(result == expected); // Verifiserer at resultatet er lik det
forventede
}
*/

TEST(Animal_test, testAnimalToString) {
  std::vector<Animal *> animals;
  for (int i = 0; i < 10; i++) {
    if (i % 2 == 0) {
      animals.push_back(new Cat{"Cat", i});
    } else {
      animals.push_back(new Dog{"Dog", i});
    }
  }
  for (auto animal : animals) {
    std::cout << animal->toString() << std::endl;
    ;
  }
}

//   EXPECT_EQ(card.toString(), expectedString);

// int main(int argc, char **argv)
// {
//     testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }
