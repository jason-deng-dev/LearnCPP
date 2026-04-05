#include<iostream>

int doubleNumber(int x)
{
    return 2*x;
}

int main(){
    std::cout << "Enter value: ";
    int c {};
    std::cin >> c;
    std::cout << doubleNumber(c) << '\n';
    return 0;
}
