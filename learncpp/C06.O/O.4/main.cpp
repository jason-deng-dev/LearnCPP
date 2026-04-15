#include <iostream>

void printBinary(int num) {
  for (int i{128}; i >= 1; i /= 2) {
    if (i == 8)
      std::cout << ' ';
    if (num - i >= 0) {
      std::cout << 1;
      num -= i;
    } else {
      std::cout << 0;
    }
  }
}

int main() {
  std::cout << "Enter 0 - 255: ";
  int x{};
  std::cin >> x;
  printBinary(x);
}
