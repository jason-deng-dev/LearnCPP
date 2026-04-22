#include <cstring>
#include <iostream>

void printStr(const char str[])
{
	while (*str != '\0')
	{
		std::cout << *str;
		++str;
	}

	std::cout << '\n';
}

void printStrR(const char str[])
{
	const char* ptr{str};
	while (*ptr != '\0')
		++ptr;

	while (ptr-- != (str))
	{
		std::cout << *ptr;
	}
	std::cout << '\n';
}

int main()
{
	printStr("Hello, world!");
	printStrR("Hello, world!");
	return 0;
}
