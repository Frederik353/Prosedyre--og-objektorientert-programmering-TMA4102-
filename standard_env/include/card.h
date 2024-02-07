
#pragma once

#include <string>

enum class Suit { HEARTS, DIAMONDS, CLUBS, SPADES };

enum class Rank {
  TWO = 2,
  THREE,
  FOUR,
  FIVE,
  SIX,
  SEVEN,
  EIGHT,
  NINE,
  TEN,
  JACK = 11,
  QUEEN = 12,
  KING = 13,
  ACE = 14
};

std::string suitToString(Suit suit);

std::string rankToString(Rank rank);
