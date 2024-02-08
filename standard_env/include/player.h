#include "hand.h"
#include <string>

class Player {
private:
  Hand hand;
  int money = 0;
  std::string name;

public:
  std::string getName();
  void addCardToHand(Card card);
  int getHandSum();
  void printHand();
  void printHandShort();
}