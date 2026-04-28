#include <cstddef>
#include <iostream>
#include <string>
#include <algorithm>


int main()
{
	std::cout << "How many names would you like to enter? ";
	std::size_t length{};
	std::cin >> length;
	auto* array{new std::string[length]{}};
	for (int i = 1; i <= length; ++i)
	{
		std::cout << "Enter name #" << i << ": ";
		std::string tempName{};
		std::cin >> tempName;
		array[i-1] = tempName;
	}
	
  std::sort(array, array+static_cast<size_t>(length));
	std::cout << "\nHere is your sorted list:\n";
	for (int j = 1; j <= length; ++j)
	{
		std::cout << "Name #"<< j << ": "<<array[j-1]<<'\n';		
  }

	
	return 0;
}
