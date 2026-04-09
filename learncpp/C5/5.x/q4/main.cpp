#include <string>
#include <iostream>
#include <string_view>

std::string getName(char personNum) {
  std::cout << "Enter name of person #" << personNum;
  std::string name{};
  std::getline(std::cin >> std::ws, name);
  return name;
}

int getAge(std::string_view name) {
  std::cout << "Enter age of " << name;
  int age{};
  std::cin >> age;
  return age;
}

int main() {
  std::string name1{getName('1')};
  int age1 {getAge(name1)};
  std::string name2{getName('2')};
  int age2{getAge(name2)};

  if (age1 > age2) 
    std::cout << name1 << " (age" << age1 << ") is older than "<<name2 <<" (age" << age2 << ")";
  else 
    std::cout << name2 << " (age" << age2 << ") is older than "<<name1 <<" (age" << age1 << ")";
  
}
