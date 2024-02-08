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
TEST(CardTest, testRankToString) {
  Rank r = Rank::ACE;
  EXPECT_EQ("Ace", rankToString(r));
}

TEST(CardTest, testSuitToString) {
  Suit s = Suit::HEARTS;
  EXPECT_EQ("Hearts", suitToString(s));
}

// oppgave 2 f
TEST(CardTest, ConstructorTest) {
  Card card(Suit::HEARTS, Rank::ACE);
  EXPECT_EQ(card.getSuit(), Suit::HEARTS);
  EXPECT_EQ(card.getRank(), Rank::ACE);
}

TEST(CardTest, GetSuitTest) {
  Card card(Suit::DIAMONDS, Rank::TEN);
  EXPECT_EQ(card.getSuit(), Suit::DIAMONDS);
}

TEST(CardTest, GetRankTest) {
  Card card(Suit::CLUBS, Rank::FOUR);
  EXPECT_EQ(card.getRank(), Rank::FOUR);
}

TEST(CardTest, ToStringTest) {
  Card card(Suit::SPADES, Rank::QUEEN);
  std::string expectedString = "Queen of Spades";
  EXPECT_EQ(card.toString(), expectedString);
}

// int main(int argc, char **argv)
// {
//     testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }
