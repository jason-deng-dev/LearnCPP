#include <iostream>
#include <string>

int main() {
  std::cout << "Input your full name: ";
  std::string name{};
  std::getline(std::cin >> std::ws, name);
  std::cout << "input your age: ";
  int age {};
  std::cin >> age;

  // name.length() is unsigned; cast to int so age isn't implicitly converted to unsigned
  std::cout << age + static_cast<int>(name.length());


  return 0;
}
