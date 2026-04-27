#include <iostream>
#include <iterator>
#include <utility>

int main()
{
	int array[]{6, 3, 2, 9, 7, 1, 5, 4, 8};
	int size = static_cast<int>(std::size(array));

	for (int j{0}; j < size - 1; ++j)
	{
		bool swapped {false};
		for (int i{0}; i < size - 1 - j; ++i)
		{
			if (array[i] > array[i + 1])
			{
				swapped = true;
        std::swap(array[i], array[i + 1]);
      }
		}
		if (!swapped)
		{
			std::cout<< "Early termination on iteration "<<j+1<<'\n';
			break;
    };
	}
	for (auto& v : array)
	{
		std::cout << v << ' ';
  }
}

