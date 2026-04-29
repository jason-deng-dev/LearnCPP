#include <iostream>
#include <string>

int factorial(int a)
{
	if (a <= 0)
		return 1;
	return a * factorial(a - 1);
}

int sumOfDigits(int a)
{
	if (a < 10)
		return a;
	return sumOfDigits(a / 10) + a % 10;
}

void getBinary(int a)
{

	if (a == 0)
		return;

	getBinary(a / 2);
	std::cout << a % 2;
}



int main()
{
	// for (int i{0}; i < 7; ++i)
	// {
	// 	std::cout << factorial(i)<<' ';
	// }
	// std::cout << sumOfDigits(93427);
	getBinary(0);
}
