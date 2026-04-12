#include <iostream>

int getNumber() {
  int num{};
  std::cin >> num;
  return num;
}

int main() {

  std::cout << "Enter an integer: ";
  int smaller{getNumber()};
  std::cout << "Enter a larger integer: ";
  int larger{getNumber()};

  if (smaller > larger) {
    int temp = larger;
    larger = smaller;
    smaller = temp;
  }

  std::cout << "Smaller is " << smaller;
  std::cout << "Bigger is " << larger;

  return 0;
}
