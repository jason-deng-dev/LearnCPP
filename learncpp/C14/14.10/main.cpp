#include <iostream>
#include <string>

class Ball {
private:
  std::string m_color{"none"};
  double m_radius{0.0};

public:
  Ball(std::string_view color, double radius)
      : m_color{color}, m_radius{radius} {};

  const std::string& getColor() const { return m_color; }
  double getRadius() const { return m_radius; }
};

void print(Ball& b) { std::cout << b.getColor() << b.getRadius(); };

int main() {
  Ball blue{"blue", 10.0};
  print(blue);

  Ball red{"red", 12.0};
  print(red);

  return 0;
}
