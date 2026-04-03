#include <iostream> // for std::cout and std::cin

// asks for 3 numbers and prints
int main()
{
    std::cout << "Enter 3 numbers: "; // ask user for a number
    int x{};                          // define variable x to hold user input
    int y{};
    int z{};
    std::cin >> x >> y >> z; // get number from keyboard and store it in variable x
    std::cout << "You entered " << x << ", " << y << ", and " << z << ".\n";

    return 0;
}
