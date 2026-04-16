#include <iostream>

enum class Animal {
  pigs,
  chicken,
};

std::string_view getAnimalName(Animal animal) {
  switch (animal) {
    case Animal::pigs:
      return "pigs";
    case Animal::chicken:
      return "chicken";
    default:
      return "Invalid animal";
  }
}

void printNumberOfLegs(Animal animal) {
  switch (animal) {
    case Animal::pigs:
      std::cout << "4 \n";
      break;
    case Animal::chicken:
      std::cout << "2 \n";
      break;
    default:
      std::cout << "Invalid animal";
      break;
  }
}

int main() {
  Animal pig{Animal::pigs};
  Animal chicken{Animal::chicken};
  printNumberOfLegs(pig);
  printNumberOfLegs(chicken);

  return 0;
}
