# C++ Deck Class Template
[![Points badge](../../blob/badges/.github/badges/points.svg)](../../actions)

## Project Outcomes:
Develop a C++ program that uses:
- Class template
- Singly-linked list

## Preparatory Readings:
- Templates Chapter
- Linked-list Chapter

## Background Information:
### Project overview:
In this project, students will be asked to implement a C++ class template that
simulates a deck of cards that can be used in a card game. The Deck class
should use a template argument for the Card class as the base type of the
template. The Deck class should support initiation, draw from top, and shuffle.
The Deck class should be implemented as a singly-linked list.

### Project Requirements:
Your application must function as described below:
1. The Card class should have methods for getting and setting the card value.
1. The Deck class should be implemented as a C++ class template, which means
   that it should be able to handle any type of card as a template argument.
1. The Deck class should support initiation, draw from top, shuffle, and other
   fundamental operations.
1. The Deck class should be implemented as a singly-linked list, which means
   that each card in the deck should be represented as a node in the list.
1. The class template should be in its own header file. Do not use cpp file to
   keep it simple.
1. You are provided with a test suite in the folder [test/](test/). Your
   implementation must pass all tests provided in this test suite. Read these
   files to get a better understanding of the requirement.


## Code organizations
### Card Class Template
Provided in the card.hpp file as a class template. Its base type can be int,
string, etc.

### Deck Class Template
The Deck class template should have the features.
1. It is a singly-linked list with the Card class as its node.
2. It should have the following methods:
    + The default constructor to initialize an empty deck
    + The destructor to release the memory
    + The rest of big three are not required. Do not waste time on them.
    + The ``void addCard(T value)`` method to add a card with a value to the
      beginning of the deck.
    + The ``T drawCard()`` method to remove and return the value of the first
      card in the deck. Your program should exit if the deck is empty. Print
      error message to cout in that case.
    + The ``int getSize()`` method to return the current size of the deck.
    + The ``void shuffle()`` method to shuffle the deck. Algorithm will be
      explained after.
3. You can decide all other private instance variables. Think about:
    + Do you need a tail pointer?
    + Do you need a size variable?

### Shuffling a linked-list
+ You will need a random number generation algorithm in the shuffling process.
  The ``std::srand`` function is part of the C standard library, and it's used
  to seed the random number generator that's used by functions like
  ``std::rand``. The basic idea is that you call ``std::srand`` with an integer
  value, which sets the initial seed value for the random number generator.
  Then, when you call ``std::rand``, it generates a pseudo-random number based
  on the current seed value. You can then use the modulo operator on N to
  convert the random number to the range of 1 to N.
+ The shuffling algorithm used in the solution is called the Fisher-Yates
  shuffle (also known as the Knuth shuffle or the Durstenfeld shuffle). This
  algorithm shuffles an array (or in our case, a linked list) in-place by
  iterating over the elements of the array and swapping each element with a
  randomly chosen element that comes after it. Below is the example on an array.

```
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    const int ARRAY_SIZE = 10;
    int arr[ARRAY_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Seed the random number generator
    std::srand(std::time(nullptr));

    // Iterate over the array and swap each element with a randomly chosen element that comes after it
    for (int i = 0; i < ARRAY_SIZE; i++) {
        int randIndex = i + (std::rand() % (ARRAY_SIZE - i));
        int temp = arr[i];
        arr[i] = arr[randIndex];
        arr[randIndex] = temp;
    }

    return 0;
}
```

+ For linked list, you cannot use ``[]`` syntax anymore but you can make a
  private function to find the pointer to the i-th card object. Then, use
  getValue and setValue of the Card class to do the value swapping. This method
  may look like ``Card<T> *getCardAt(int index)``

### Implementation Notes:
Your application must function as described below:
1. Your program must adhere to the class descriptions provided in this README.
1. Your program must compile and pass tests.
   - All tests must pass by running together with `make test-all`. You can run
     individual test during development.
1. You classes must be memory leak free. Memory leakage will be checked and
   graded in autograding.

### Submission Requirements:
1. All code must be added and committed to your local git repository.
2. All code must be pushed to the GitHub repository created when you "accepted" the assignment.
    1. After pushing, with `git push origin main`, visit the web URL of your repository to verify that your code is there.
    If you don't see the code there, then we can't see it either.
3. Your code must compile and run. The auto-grading tests will indicate your score for your submission.
    1. The auto-grading build should begin automatically when you push your code to GitHub.
    2. If your program will not compile, the graders will not be responsible for trying to test it.
    3. You should get an email regarding the status of your build, if it does not pass, keep trying.

## Important Notes:
- Projects will be graded on whether they correctly solve the problem, and
  whether they adhere to good programming practices.
- Projects must be received by the time specified on the due date. Projects
  received after that time will get a grade of zero.
- Please review the academic honesty policy.
    - Note that viewing another student's solution, whether in whole or in
      part, is considered academic dishonesty.
    - Also note that submitting code obtained through the Internet or other
      sources, whether in whole or in part, is considered academic dishonesty.
    - All programs submitted will be reviewed for evidence of academic
      dishonesty, and all violations will be handled accordingly.

## Grading
- View on GitHub:
    1. On your GitHub repo page, Click the :arrow_forward: **Actions** tab to see your graded results.
    1. If it isn't a green check mark (:heavy_check_mark:) then at least part of the testing failed.
    1. Click the commit message for the failing version then click "Autograding" on the left side of the page.
    1. Follow the :x: path and expand things to see what errors exist.
    1. At the bottom of the _education/autograding_ section, you can view the score for the auto-grading portion of the rubric.
        It will look something like ***40/50***.
