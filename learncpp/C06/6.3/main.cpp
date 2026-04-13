#include <iostream>
#include <string>
constexpr bool isEven(int x) { return (x % 2 == 0); }

int main() {
  std::cout << "enter a int: ";
  int x{};
  std::cin >> x;

  std::string status{};
  if (isEven(x))
    status = "even";
  else
    status = "odd";

  std::cout << x << " is " << status << "\n";
  return 0;
}
