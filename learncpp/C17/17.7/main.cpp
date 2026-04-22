#include <iostream>
#include <iterator>

constexpr int pSquares[]{0, 1, 4, 9};

// don't need & on int, cheap
bool isPerfSquare(int input)
{
	// use const auto& to avoid copying / mutating
	for (const auto& i : pSquares)
	{
		if (i == input)
		{
			return true;
		}
	}

	return false;
}

int main()
{
	while (true)
	{
		std::cout << "Enter a single digit integer, or -1 to quit: ";
		int input{};
		std::cin >> input;

		if (input == -1)
		{
			std::cout << "Bye \n";
			break;
		}

		if (isPerfSquare(input))
			std::cout << input << " is a perfect square \n";
		else
			std::cout << input << " is not a perfect square \n";
	}
	return 0;
}
