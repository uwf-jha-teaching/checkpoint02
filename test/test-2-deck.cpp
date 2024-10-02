#include "catch/catch.hpp"
#include "../deck.hpp"

TEST_CASE("Deck class add/draw", "[deck]") {
  Deck<int> deck;

  SECTION("Cards can be added to and draw from the deck") {
    deck.addCard(42);
    CHECK(deck.getSize() == 1);
    CHECK(deck.drawCard() == 42);
    CHECK(deck.getSize() == 0);

    deck.addCard(10);
    deck.addCard(20);
    deck.addCard(30);
    CHECK(deck.getSize() == 3);
    CHECK(deck.drawCard() == 30);
    CHECK(deck.drawCard() == 20);
    CHECK(deck.drawCard() == 10);
  }
}

