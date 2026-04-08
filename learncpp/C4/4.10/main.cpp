// number 0-9, tell if prime or not
#include <iostream>

void isPrime() {
  std::cout << "The digit is a prime";
}

int main() {
  std::cout << "Enter a number 0-9: ";
  int x{};
  std::cin >> x;
  if (x == 2)
    isPrime();
  else if (x == 3)
    isPrime();
  else if (x == 5)
    isPrime();
  else if (x == 7)
    isPrime();
  else
    std::cout << "The digit is not a prime";
    

}


