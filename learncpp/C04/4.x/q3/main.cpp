#include <iostream>

double getHeight() {
  std::cout << "Enter the height of the tower in meters: ";
  double height{};
  std::cin >> height;
  return height;
}

double getDistanceFallen(int secondsPassed) {
  return (9.8 * (secondsPassed * secondsPassed)) / 2;
}

bool updateHeight(double height, int secondsPassed) {
  double ballHeight = height - getDistanceFallen(secondsPassed);
  if (ballHeight > 0) {
    std::cout << "At " << secondsPassed
              << " seconds, the ball is at height: " << ballHeight << '\n';
  } else {
    std::cout << "At " << secondsPassed
              << " seconds, the ball is on the ground. \n";
  }
  return ballHeight > 0;
}

void simulateFall(double height) {
  if (!updateHeight(height, 0))
    return;
  if (!updateHeight(height, 1))
    return;
  if (!updateHeight(height, 2))
    return;
  if (!updateHeight(height, 3))
    return;
  if (!updateHeight(height, 4))
    return;
  if (!updateHeight(height, 5))
    return;
}

int main() {
  simulateFall(getHeight());
  return 0;
}
