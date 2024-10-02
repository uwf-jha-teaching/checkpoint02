/***
 * Provided file, never modify
 */
#ifndef CARD_HPP
#define CARD_HPP
template <typename T>
class Card {
  T value;
  Card<T>* next;
 public:
  Card(T value) {
    this->value = value;
    this->next = nullptr;
  }

  T getValue() const { return this->value; }
  void setValue(T value) { this->value = value; }
  Card<T>* getNext() const { return this->next; }
  void setNext(Card<T>* next) { this->next = next; }
};

#endif  // CARD_HPP
