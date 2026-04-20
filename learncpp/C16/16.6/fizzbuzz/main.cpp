#include <iostream>
#include <vector>

void fizzbuzz(int count)
{
	// use static since if we call fizzbuzz mutltiple times, we don't need to
	// reinitalize these
	// const for accidental modifcations
	static const std::vector<int> divisors{3, 5, 7, 11, 13, 17, 19};
	static const std::vector words{"fizz", "buzz", "pop", "bang", "jazz", "pow", "boom"};

	for (int i{1}; i <= count; ++i)
	{
		bool divisible = false;
		for (int j{0}; j < 7; ++j)
		{

			if (i % divisors.data()[j] == 0)
			{
				std::cout << words.data()[j];
				divisible = true;
			}
		}
		if (!divisible)
			std::cout << i;
		std::cout << '\n';
	}
}

int main()
{
  fizzbuzz(150);
	return 0;
}
