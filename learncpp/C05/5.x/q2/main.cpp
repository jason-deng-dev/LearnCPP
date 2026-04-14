#include <iostream>
#include <string>

int main() {
  std::cout << "How old are you?\n";

  //
  int age{};
  std::cin >> age;

  std::cout << "Allowed to drive a car in Texas: ";

  constexpr int legalAge {16};
  if (age >= legalAge)
    std::cout << "Yes";
  else
    std::cout << "No.";

  std::cout << ".\n";
  return 0;
}
