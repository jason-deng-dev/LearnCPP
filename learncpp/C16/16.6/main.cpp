#include <cstddef>
#include <ios>
#include <iostream>
#include <limits>
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

template <typename T>
T getValue(T low, T high)
{
	while (true)
	{
		std::cout << "Enter a value 1 - 9: ";
		T a{};
		std::cin >> a;
		if (a <= high && a >= low)
		{
			return a;
		}
		// if user entered an invalid char
		if (!std::cin)
			std::cin.clear(); // reset error flags

		// ignore any extra characters in the input buffer (regardless of whether we
		// had an error or not)
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}

template <typename T>
T findMax(const std::vector<T>& a)
{
	if (a.size() == 0)
		return {};
	T max{a.data()[0]};
	for (std::size_t i{1}; i < a.size(); ++i)
		if (a[i] > max)
			max = a[i];
	return max;
}

int main()
{
	// auto a{getValue(1.0, 9.0)};
	// std::vector arr{4.4, 6.6, 7.7, 3.3, 8.8, 2.2, 1.1, 9.9};

	// printArray(arr); // use function template to print array
	// std::size_t index{searchArray(arr, a)};

	// if (index == arr.size())
	// {
	// 	std::cout << a << " not found";
	// }
	// else
	// {
	// 	std::cout << a << " at " << index;
	// }

	std::vector data1{84, 92, 76, 81, 56};
	std::cout << findMax(data1) << '\n';

	std::vector data2{-13.0, -26.7, -105.5, -14.8};
	std::cout << findMax(data2) << '\n';

	std::vector<int> data3{};
	std::cout << findMax(data3) << '\n';
	return 0;
}
