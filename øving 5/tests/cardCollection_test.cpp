#include "card.h"           // Include your class definition
#include "cardCollection.h" // Include your class definition
#include <gtest/gtest.h>

class CardCollectionTest : public ::testing::Test {
protected:
  CardCollection collection;

  void SetUp() override {}
};

TEST_F(CardCollectionTest, AddsCardSuccessfully) {
  Card card(Suit::HEARTS, Rank::ACE);
  CardCollection collection;
  collection.addCard(card);
  EXPECT_EQ(collection.size(), 1);
}

TEST_F(CardCollectionTest, DrawCardWhenNotEmpty) {
  Card card(Suit::HEARTS, Rank::ACE);
  collection.addCard(card); // Add a card to ensure the collection isn't empty
  auto drawnCard = collection.drawCard();
  EXPECT_TRUE(drawnCard.has_value()); // Check that a card was drawn
  EXPECT_EQ(collection.size(), 0);    // Assuming you have a size() method
}

TEST_F(CardCollectionTest, DrawCardWhenEmpty) {
  auto drawnCard = collection.drawCard();
  EXPECT_FALSE(drawnCard.has_value()); // Check that no card was drawn
}

TEST_F(CardCollectionTest, RemoveCardByValidIndex) {
  Card card(Suit::HEARTS, Rank::ACE);
  collection.addCard(card); // Add a card
  auto removedCard = collection.removeCardByIndex(0);
  EXPECT_TRUE(removedCard.has_value()); // Card should be removed
  EXPECT_EQ(collection.size(), 0);      // Collection should be empty now
}

TEST_F(CardCollectionTest, RemoveCardByInvalidIndex) {
  auto removedCard = collection.removeCardByIndex(
      0); // Assuming the collection is initially empty
  EXPECT_FALSE(removedCard.has_value()); // No card should be removed
}

TEST_F(CardCollectionTest, SwapCards) {
  Card card1(Suit::DIAMONDS, Rank::KING);
  Card card2(Suit::HEARTS, Rank::ACE);
  collection.addCard(card1);
  collection.addCard(card2);
  collection.swap(0, 1);
  EXPECT_EQ(collection.at(0), card2);
  EXPECT_EQ(collection.at(1), card1);
}
