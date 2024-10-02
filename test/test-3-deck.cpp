#include "catch/catch.hpp"
#include "../deck.hpp"
#include <algorithm>
#include <vector>
#include <iostream>

bool isSame(int arr1[], int arr2[], int size) {
  for (int i = 0; i < size; i++) {
    if (arr1[i] != arr2[i]) {
      return false;
    }
  }
  return true;
}

bool isPermutation(int arr1[], int arr2[], int size) {
  // Sort the two arrays
  std::sort(arr1, arr1 + size);
  std::sort(arr2, arr2 + size);
  return isSame(arr1, arr2, size);
}

void print(int arr[], int size) {
  for (int i = 0; i < size; ++i)
    std::cout << arr[i] << " ";
  std::cout << std::endl;
}

TEST_CASE("Deck class initialization 1", "[deck]") {
  Deck<int> deck;

  SECTION("Deck can be shuffled") {
    const int size = 10;
    int arr1[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[size];
    for (int i = 0; i < size; ++i)
      deck.addCard(arr1[i]);
    deck.shuffle();
    CHECK(deck.getSize() == size);  // same size after shuffle
    for (int i = 0; i < size; ++i)
      arr2[i] = deck.drawCard();

    // if you are really unlucky, it is the same after shuffling,
    // just rerun the test then.
    CHECK(!isSame(arr1, arr2, size));

    // print(arr2, size);
    CHECK(isPermutation(arr1, arr2, size));
  }
}
