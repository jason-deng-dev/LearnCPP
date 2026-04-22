#include <array>
#include <cstddef>
#include <iostream>

template<typename T, auto N>
void printArray(const std::array<T, N>& arr)
{
	std::cout << "The array (";

	auto separator {""};
	for (T c : arr)
	{
    std::cout << separator <<c;
    separator = ", ";
	}
	std::cout << ") has length " << N << '\n';
}

int main()
{
    constexpr std::array arr1 { 1, 4, 9, 16 };
    printArray(arr1);

    constexpr std::array arr2 { 'h', 'e', 'l', 'l', 'o' };
    printArray(arr2);

    return 0;
}
