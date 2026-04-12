#include <iostream>

int calculate(int a, int b, char operation) {
  switch (operation) {
    case '+':
      return a + b;
    case '-':
      return a - b;
    case '*':
      return a * b;
    case '/':
      return a / b;
    case '%':
      return a % b;
    default:
      std::cout << "Invalid operator \n";
      return 0;
  }
}

int getNumber() {
  std::cout << "Enter a number: ";
  int x{};
  std::cin >> x;
  return x;
}
char getChar() {
  std::cout << "Enter an operator: ";
  char x{};
  std::cin >> x;
  return x;
}

int main() {
  int a{getNumber()};
  int b{getNumber()};
  char op{getChar()};
  int res{calculate(a, b, op)};

  std::cout << "result is " << res << '\n';
  return 0;
}
