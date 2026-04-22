#include <iostream>

void printStr(const char str[])
{
	for (; *str != '\0'; ++str)
		std::cout << *str;
	std::cout << '\n';
}

void printStrR(const char str[])
{ 
	for (; )
}

int main()
{
	printStr("Hello, world!");
	printStrR("Hello, world!");
	return 0;
}
