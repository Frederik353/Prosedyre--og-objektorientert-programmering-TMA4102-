#include "hand.h"
#include <string>
#include <vector>

class Player {
private:
  Hand hand;
  int money = 0;
  std::string name;

public:
  Player(const std::string name) : name{name} {};
  std::string getName();
  std::string handSumToString();

  void addCardToHand(const Card &card);
  std::vector<int> getHandSum();
  void printHand(int numFirstCards = -1);
  void getCard();
  void printHandShort(int numFirstCards = -1);
};