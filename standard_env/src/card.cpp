#include "card.h"
#include <string>

std::string suitToString(Suit suit) {
  switch (suit) {
  case Suit::CLUBS:
    return "clubs";
  case Suit::DIAMONDS:
    return "diamonds";
  case Suit::HEARTS:
    return "hearts";
  case Suit::SPADES:
    return "spades";
  default:
    return "memory or typcast error";
  }
}

std::string rankToString(Rank rank) {
  switch (rank) {
  case Rank::TWO:
    return "two";
  case Rank::THREE:
    return "three";
  case Rank::FOUR:
    return "four";
  case Rank::FIVE:
    return "five";
  case Rank::SIX:
    return "six";
  case Rank::SEVEN:
    return "seven";
  case Rank::EIGHT:
    return "eight";
  case Rank::NINE:
    return "nine";
  case Rank::TEN:
    return "ten";
  case Rank::JACK:
    return "jack";
  case Rank::QUEEN:
    return "queen";
  case Rank::KING:
    return "king";
  case Rank::ACE:
    return "ace";
  default:
    return "memory or typcast error";
  }
}

// oppgave 1 e
/*
type sikkerhet så man ikke sender inn farger til noe som skulle ha verdi,
sikkrer også at udefinerte verdier ikke blir sendt inn
lesbarhet
*/
