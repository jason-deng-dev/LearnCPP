#include <cstddef>
#include <iostream>
#include <vector>

// Implement printArray() here
template <typename T>
void printArray(const std::vector<T>& arr)
{
	for (std::size_t index{0}; index < arr.size(); ++index)
	{
		std::cout << arr[index] << ' ';
	}
	std::cout << '\n';
}

template <typename T>
std::size_t searchArray(const std::vector<T>& arr, T i)
{
	for (std::size_t index{0}; index < arr.size(); ++index)
	{
		if (arr[index] == i)
			return index;
	}
	return arr.size();
}

int getValue()
{
	while (true)
	{
		std::cout << "Enter a value 1 - 9: ";
		int a{};
		std::cin >> a;
		if (a <= 9 && a >= 1)
		{
			
			return a;
		}
	}
}

int main()
{
	int a{getValue()};
	std::cout << a;
	std::vector arr{4, 6, 7, 3, 8, 2, 1, 9};
	printArray(arr); // use function template to print array
	std::size_t index{searchArray(arr, a)};
	
	if (index == arr.size())
	{
		std::cout << a <<" not found";
	}
	else
	{
		std::cout << a << " at "<<index;
  }
	return 0;
}
