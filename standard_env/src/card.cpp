#include "card.h"
#include <string>
// oppgave 1 e
/*
type sikkerhet så man ikke sender inn farger til noe som skulle ha verdi,
sikkrer også at udefinerte verdier ikke blir sendt inn
lesbarhet
*/

// oppgave 2 b
Card::Card(Suit suit, Rank rank) : s{suit}, r{rank} {}

// oppgave 2 a
std::string Card::suitToString() {
  switch (s) {
  case Suit::CLUBS:
    return "Clubs";
  case Suit::DIAMONDS:
    return "Diamonds";
  case Suit::HEARTS:
    return "Hearts";
  case Suit::SPADES:
    return "Spades";
  default:
    return "memory or typcast error";
  }
}

std::string Card::suitToShortString() {
  switch (s) {
  case Suit::CLUBS:
    return "♣";
  case Suit::DIAMONDS:
    return "♦";
  case Suit::HEARTS:
    return "♥";
  case Suit::SPADES:
    return "♠";
  default:
    return "memory or typcast error";
  }
}

std::string Card::rankToString() {
  switch (r) {
  case Rank::TWO:
    return "Two";
  case Rank::THREE:
    return "Three";
  case Rank::FOUR:
    return "Four";
  case Rank::FIVE:
    return "Five";
  case Rank::SIX:
    return "Six";
  case Rank::SEVEN:
    return "Seven";
  case Rank::EIGHT:
    return "Eight";
  case Rank::NINE:
    return "Nine";
  case Rank::TEN:
    return "Ten";
  case Rank::JACK:
    return "Jack";
  case Rank::QUEEN:
    return "Queen";
  case Rank::KING:
    return "King";
  case Rank::ACE:
    return "Ace";
  default:
    return "memory or typcast error";
  }
}

std::string Card::rankToShortString() {
  switch (r) {
  case Rank::TWO:
    return "2";
  case Rank::THREE:
    return "3";
  case Rank::FOUR:
    return "4";
  case Rank::FIVE:
    return "5";
  case Rank::SIX:
    return "6";
  case Rank::SEVEN:
    return "7";
  case Rank::EIGHT:
    return "8";
  case Rank::NINE:
    return "9";
  case Rank::TEN:
    return "10";
  case Rank::JACK:
    return "J";
  case Rank::QUEEN:
    return "Q";
  case Rank::KING:
    return "K";
  case Rank::ACE:
    return "A";
  default:
    return "memory or typcast error";
  }
}

// // oppgave 2 c
Suit Card::getSuit() { return s; }

// // oppgave 2 d
Rank Card::getRank() { return r; }

// oppgave 2 e
std::string Card::toString() {
  return rankToString() + " of " + suitToString();
}

std::string Card::toShortString() {
  return rankToShortString() + suitToShortString();
}
