
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

// oppgave 2 a
class Card {
private:
  Suit s;
  Rank r;

public:
  Card(Suit suit, Rank rank);
  Suit getSuit();
  Rank getRank();
  std::string rankToString();
  std::string rankToShortString();
  std::string suitToString();
  std::string suitToShortString();
};
