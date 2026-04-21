#include <cstddef>
#include <iostream>
#include <limits>
#include <vector>
template <typename T>
std::pair<std::size_t, std::size_t> getMinMaxIndex(const std::vector<T>& arr)
{
	// track indices only — values readable via arr[minIndex], no redundant
	// variables
	std::size_t minIndex{0};
	std::size_t maxIndex{0};
	for (std::size_t i{0}; i < arr.size(); ++i)
	{
		if (arr[i] < arr[minIndex])
			minIndex = i;
		if (arr[i] > arr[maxIndex])
			maxIndex = i;
	}
	return {minIndex, maxIndex};
}

// instead of tracking min/max,
template <typename T>
void printArray(const std::vector<T>& arr)
{
	std::cout << "With array (";
	std::size_t size{arr.size()};
	std::size_t index = 0;
	for (T val : arr)
	{
		std::cout << ' ' << val;
		if (index < size - 1)
			std::cout << ',';
		++index;
	}
	std::cout << " ): \n";
}

template <typename T>
void printMinMax(const std::vector<T>& arr,
                 const std::pair<std::size_t, std::size_t>& minMax)
{
	std::size_t minIndex{minMax.first};
	std::size_t maxIndex{minMax.second};
	T minValue{arr[minIndex]};
	T maxValue{arr[maxIndex]};
	std::cout << "The min element has index " << minIndex << " and value "
	          << minValue << '\n';
	std::cout << "The max element has index " << maxIndex << " and value "
	          << maxValue << '\n';
}

std::vector<int> getArray()
{
	std::vector<int> arr{};
	while (true)
	{
		std::cout << "Enter a number to add (-1 to stop): ";
		int val{};
		std::cin >> val;
		if (!std::cin)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		if (val == -1 )
		{
			if (std::ssize(arr) == 0)
			{
				std::cout << "Must have at least one value! \n";
				continue;
			}
			return arr;
		} 
		arr.push_back(val);
	}
}

int main()
{
	std::vector v1{getArray()};
	printArray(v1);
	printMinMax(v1, getMinMaxIndex(v1));

	return 0;
}
