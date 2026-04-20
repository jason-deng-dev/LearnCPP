#include <string_view>
#include <vector>
#include <iostream>

template <typename T>
bool isValueInArray(const std::vector<T>& arr, const T& val)
{
	for (const auto& curr : arr)
	{
		if (val == curr)
		{
			return true;
    }
	}
	return false;
	
}

int main()
{
	std::vector<std::string_view> names{"Alex",  "Betty", "Caroline", "Dave",
	                  "Emily", "Fred",  "Greg",     "Holly"};
	std::cout << "Enter name: ";
	std::string input{};
	std::cin >> input;

	// By explicitly specifying std::string_view as a function template argument,
  // the compiler will implicitly convert username to `std::string_view` to match the parameter type.
	std::cout << std::boolalpha << isValueInArray<std::string_view>(names, input);
  

	return 0;
}


