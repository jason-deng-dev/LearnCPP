#include <iostream>
#include <string_view>
class Ball {
private:
  std::string m_color{"black"};
  double m_radius{10.0};
  void print() { std::cout << m_color << static_cast<int>(m_radius); }

public:
  Ball(double radius) : Ball("black", radius) {};
  Ball(const std::string_view color = "black", double radius = 10.0)
      : m_color{color}, m_radius(radius) {
    print();
  };
};

int main() {
  Ball def{};
  Ball blue{"blue"};
  Ball twenty{20.0};
  Ball blueTwenty{"blue", 20.0};

  return 0;
}
