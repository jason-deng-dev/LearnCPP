#include "Random.h"
#include <iostream>
int getInt();

bool getGuess(int goal, int attempt) {
  std::cout << "Guess #" << attempt << ": ";
  int guess{};
  std::cin >> guess;
  if (guess != goal) {
    if (guess > goal)
      std::cout << "Your guess is too high.\n";
    else
      std::cout << "Your guess is too low. \n";
    return false;
  }
  return true;
}

void startGame() {
  int min{};
  int max{};
  while (min >= max) {
    std::cout << "Enter a min value: ";
    min = {getInt()};
    std::cout << "Enter a max value: ";
    max = {getInt()};
    if (min >= max) {
      std::cout << "min must be smaller than max \n";
    }
  }

  std::cout << "Enter the number of attempts you get: ";
  int attemptInput{getInt()};

  int goal{Random::get(min, max)};
  int attempt{1};
  bool correctGuess{false};
  std::cout << "Let's play a game. Guess my number " << min << "-" << max
            << ", " << attemptInput << " tries \n";
  while (attempt <= attemptInput) {
    bool result{getGuess(goal, attempt)};
    if (result == true) {
      correctGuess = true;
      break;
    }
    ++attempt;
  }
  if (correctGuess) {
    std::cout << "Correct! You win! \n";
  } else {
    std::cout << "You lose. Number was " << goal << '\n';
  }
}

bool getNewGame() {
  char input{};
  while (input != 'y' && input != 'n') {
    std::cout << "Start new game (y/n)?: ";
    std::cin >> input;
  }
  if (input == 'y') {
    return true;
  } else {
    return false;
  }
}

int getInt() {
  int x{};
  std::cin >> x;
  return x;
}

int main() {
  bool gameOn{true};
  while (gameOn) {
    startGame();
    bool newGame{getNewGame()};
    if (!newGame)
      gameOn = false;
  }
  std::cout << "Thanks for playing. \n";
  return 0;
}
