#include "catch/catch.hpp"
#include "../deck.hpp"
#include <string>

TEST_CASE("Card class works correctly", "[card]") {
  Card<int> card(42);
  CHECK(card.getValue() == 42);

  Card<std::string> stringCard("hello");
  CHECK(stringCard.getValue() == "hello");
}

TEST_CASE("Deck class initialization", "[deck]") {
  Deck<int> deck;
  SECTION("Deck starts out empty") {
    CHECK(deck.getSize() == 0);
  }
}