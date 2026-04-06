#include "io.h"
#include <iostream>

int readNumber(){
    std::cout << "enter a number: ";
    int x {};
    std::cin >> x;
    return x;
}

void writeAnswer(int x){
    std::cout << x << '\n';
}
