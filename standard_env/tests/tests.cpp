#include "card.h"
#include "gtest/gtest.h"
#include <functional>
#include <iostream>

/*
template<typename Func, typename Result, typename... Args>
void runTest(Func func, const Result& expected, Args... args) {
    auto result = func(args...); // Kaller funksjonen med de gitt argumentene
    std::cout << "Result: " << result << ", Expected: " << expected <<
std::endl; assert(result == expected); // Verifiserer at resultatet er lik det
forventede
}
*/

TEST(CardTest, testSuitToString) {
  Rank r = Rank::ACE;
  ASSERT_STREQ("ace", rankToString(r).c_str());
  Suit s = Suit::HEARTS;
  ASSERT_STREQ("hearts", suitToString(s).c_str());
}

// int main(int argc, char **argv)
// {
//     testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }
