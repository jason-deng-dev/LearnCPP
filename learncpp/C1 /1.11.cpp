#include <iostream>
// Enter an integer: 4
// Double that number is: 8
int main()
{
    std::cout << "Enter an integer: ";
    int x{};
    std::cin >> x;
    std::cout << "Double that number is: " << x*2 << '\n';
    std::cout << "Triple that number is: " << x*3 << '\n';

    return 0;
}
