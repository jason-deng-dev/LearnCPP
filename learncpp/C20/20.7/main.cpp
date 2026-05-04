#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <random>
#include <vector>

namespace config
{
	constexpr int multMin{2};
	constexpr int multMax{6};
}

std::random_device rd;
std::mt19937 gen(rd());

int getRandom(int s, int e)
{
	std::uniform_int_distribution<> distr(s, e);
	return distr(gen);
}

std::vector<int> getValues(int start, int count, int multiplier)
{
	std::vector<int> res;
	for (int c = count; c > 0; --c)
	{
		res.push_back(start * start * multiplier);
		start++;
	}
	return res;
}

std::vector<int> setupGame()
{
	std::cout << "Start where? ";
	int start{};
	std::cin >> start;

	std::cout << "How many? ";
	int count{};
	std::cin >> count;
	int multiplier{getRandom(config::multMin, config::multMax)};
	std::cout << "I generated " << count
	          << " suqare numbers. Do you know what each number is after "
	             "multiplying it by "
	          << multiplier << "?\n";
	return getValues(start, count, multiplier);
}

int getGuess()
{
	int guess{};
	std::cin >> guess;
	return guess;
}

bool foundAndDeleted(int guess, std::vector<int>& values)
{
	auto found{std::find(values.begin(), values.end(), guess)};
	if (found == values.end())
	{
		return false;
	}
	values.erase(found);

	return true;
}

int getMin(const std::vector<int>& values, int guess)
{
	return *std::min_element(values.begin(), values.end(),
			                            [guess](const auto& a, const auto& b)
			                            {// true if a is less than b
				                            if (std::abs(guess-a) <= std::abs(guess-b)){
                                      return true;
				                            }
                                      return false;
					                            });
}

void printSuccess(const std::vector<int>& values)
{
	std::cout << "Nice! ";
	if (values.size() == 0)
	{
		std::cout << "You found all numbers, good job!\n";
	}
	else
	{
		std::cout << values.size() << " number(s) left.\n";
	}
}

void printFailure(const std::vector<int>& values, int guess)
{
	std::cout << guess << " is wrong! \nTry " << getMin(values, guess)
	          << " next time.";
}

int main()
{
	std::vector<int> values{setupGame()};
	while (true)
	{
		int guess = getGuess();
		if (!foundAndDeleted(guess, values))
		{
    printFailure(values, guess);
			break;
		}
		printSuccess(values);
		if (values.size() == 0)
			break;
	}
	return 0;
}
