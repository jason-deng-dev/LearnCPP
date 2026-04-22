#include "Random.h"
#include <array>
#include <cstddef>
#include <iostream>
#include <string>
#include <string_view>

namespace Potion
{
	enum Type
	{
		healing,
		mana,
		speed,
		invisibility,
		maxTypes,
	};

	constexpr std::array types{healing, mana, speed, invisibility};
	constexpr std::array costs{20, 30, 12, 50};
	constexpr std::array<std::string_view, maxTypes> names{
	    "healing", "mana", "speed", "invisibility"};

	static_assert(types.size() == maxTypes);
	static_assert(costs.size() == maxTypes);
	static_assert(names.size() == maxTypes);
};

void shop()
{
	std::cout << "Here is our selection for today:\n";
	for (auto type : Potion::types)
	{
		std::cout << type << ") " << Potion::names[type] << " costs "
		          << Potion::costs[type] << '\n';
	}
	std::cout << '\n';
}

class Player
{
private:
	// store min/max gold, so not magic number
	static constexpr int s_minGold{80};
	static constexpr int s_maxGold{120};

	std::string m_name{};
	int m_gold{Random::get(s_minGold, s_maxGold)};

	// array<type, length>
	std::array<int, Potion::maxTypes> m_inventory{};

public:
	Player(std::string_view name)
	    : m_name{name}
	{
	}

	// Not needed since we have name in main():
	// std::string& getName() { return m_name; }

	// need const to make sure can't change the inventory
	int getPotion(Potion::Type p) const { return m_inventory[p]; }
	int getGold() { return m_gold; }
};

int main()
{
	std::cout << "Welcome to Roscoe's potion emporium! \n";
	std::cout << "Enter your name: ";
	std::string name{};

	// read full line for name
	std::getline(std::cin >> std::ws, name);
	Player p{name};
	std::cout << "Hello, " << name << ", you have " << p.getGold()
	          << " gold. \n\n";

	shop();

	std::cout << "Thanks for shopping at Roscoe's potion emporium!";
	return 0;
}
