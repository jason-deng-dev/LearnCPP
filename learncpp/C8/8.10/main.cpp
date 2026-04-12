#include <iostream>

void q1() {
  for (int i{0}; i <= 20; i += 2) {
    std::cout << i << '\n';
  }
}

int sumTo(int num) {
  int sum{0};
  for (; num >= 1; --num)
    sum += num;
  return sum;
}

void fizzbuzz(int num) {
  for (int i{1}; i <= num; ++i) {
    if (i % 3 == 0 && i % 5 == 0)
      std::cout << "fizzbuzz \n";
    else if (i % 3 == 0)
      std::cout << "fizz \n";
    else if (i % 5 == 0)
      std::cout << "buzz\n";
    else
      std::cout << i << '\n';
  }
}
void fizzbuzz_2(int num) {
  for (int i{1}; i <= num; ++i) {
    bool printed{false};
    if (i % 3 == 0) {
      std::cout << "fizz";
      printed = true;
    }
    if (i % 5 == 0) {
      std::cout << "buzz";
      printed = true;
    }
    if (i % 7 == 0) {
      std::cout << "pop";
      printed = true;
    }
    if (!printed)
      std::cout << i;
    std::cout << '\n';
  }
}
int main() {
  // q1();
  // std::cout << sumTo(5);
  // fizzbuzz(15);
  fizzbuzz_2(15);
  return 0;
}
