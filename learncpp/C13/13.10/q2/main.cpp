#include <iostream>

struct Fraction {
  int numerator{};
  int denominator{1};
};

Fraction getFraction() {
  std::cout << "Enter numerator: ";
  int numerator{};
  std::cin >> numerator;
  std::cout << "Enter denominator: ";
  int denominator{};
  std::cin >> denominator;
  return Fraction{numerator, denominator};
}

void printFraction(Fraction& fraction) {
  std::cout << fraction.numerator << '/' << fraction.denominator;
}

Fraction multiplyFraction(Fraction& f1, Fraction& f2) {
  return{f1.numerator*f2.numerator, f1.denominator*f2.denominator};
}

int main() {
  Fraction f1 = getFraction();
  Fraction f2 = getFraction();
  Fraction resFraction = multiplyFraction(f1, f2);
  std::cout << "Fraction multiplied = ";
  printFraction(resFraction);

  return 0;
}

