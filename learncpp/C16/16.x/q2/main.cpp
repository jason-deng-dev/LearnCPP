#include <cassert>
#include <iostream>
#include <string_view>
#include <vector>

namespace Items
{
	enum types
	{
		healthPotion,
		torch,
		arrow,
		maxTypes,
	};

};

// Split into singular/plural to handle irregular plurals (e.g. "torches" not "torchs")
std::string_view getNameSingle(const Items::types& type)
{
	switch (type)
	{
	case Items::healthPotion: return "health potion";
	case Items::torch: return "torch";
	case Items::arrow: return "arrow";
	default: return "???";
	}
}
std::string_view getNamePlural(const Items::types& type)
{
	switch (type)
	{
	case Items::healthPotion: return "health potions";
	case Items::torch: return "torches";
	case Items::arrow: return "arrows";
	default: return "???";
	}
}

// Split from getTotalCount — printing and counting are separate concerns
void printTotalItems(const std::vector<int>& inventory)
{
	std::size_t index{0};
	for (int count : inventory)
	{
		std::cout << "You have " << count << ' ';
		if (count <= 1)
			std::cout << getNameSingle(static_cast<Items::types>(index));
		else
			std::cout << getNamePlural(static_cast<Items::types>(index));
		
		std::cout << '\n';
		++index;
	}
}

int getTotalCount(const std::vector<int>& inventory)
{
	int sum{0};
	for (int count : inventory)
	{
		sum += count;
	}
	return sum;
}

int main()
{
	// maxTypes is int
	// size() == std::size_t (unsigned int)
	std::vector<int> inventory{1, 5, 10};
	assert(std::ssize(inventory) == Items::maxTypes);
	printTotalItems(inventory);
	std::cout << "Have " << getTotalCount(inventory) << " items \n";
	return 0;
}
