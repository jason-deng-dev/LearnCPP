// Enter a single character: a
// You entered 'a', which has ASCII code 97.
#include <iostream>

int getASCII(int x) {
  return x;
}

int main() {
  std::cout << "Enter a single character";
  char c{};
  std::cin >> c;
  std::cout << "You entered \'" << c << "\', which has ASCII code " << getASCII(c) << ". \n";

  return 1;
}
