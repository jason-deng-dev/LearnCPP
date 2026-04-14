#include <iostream>

double getValue() {
  std::cout << "Enter a double value: ";
  double x{};
  std::cin >> x;
  return x;
}

int main() {
  double a{getValue()};
  double b{getValue()};
  std::cout << "Enter +, -, *, or / :";
  char c {};
  std::cin >> c;
  if (c == '+') {
    std::cout <<  static_cast<double>(a+b) << '\n';
  }
  else if (c == '-') {
    std::cout <<  static_cast<double>(a-b) << '\n';
  }
  else if (c == '*') {
    std::cout <<  static_cast<double>(a*b) << '\n';
  }
  else if (c == '/') {
    std::cout <<  static_cast<double>(a/b) << '\n';
  } 
  return 1;
}
