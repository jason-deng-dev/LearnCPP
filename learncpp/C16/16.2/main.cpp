#include <iostream>
#include <vector>

int main()
{
	std::cout << "Enter 3 integer values: ";
	std::vector<int> values(3);
	std::cin >> values[0] >> values[1] >> values[2];
	std::cout << "Sum: " << values[0] + values[1] + values[2] << '\n';
	std::cout << "Product: " << values[0] * values[1] * values[2] << '\n';
	return 0;
}

