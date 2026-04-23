#include "Random.h"
#include <array>
#include <cctype>
#include <cstddef>
#include <ios>
#include <iostream>
#include <limits>
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
	int potionCount(Potion::Type p) const { return m_inventory[p]; }
	int gold() const { return m_gold; }
	void buy(size_t item);
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

int getInput()
{
	while (true)
	{
		char input{};
		std::cin >> input;

		// extraction failure
		if (!std::cin)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		// prevent leftover
		bool leftover = std::cin.peek() != '\n';
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		if (!leftover && input == 'q')
			return -1;

		if (leftover || !std::isdigit(input) ||
		    (input - '0' >= Potion::maxTypes))
		{
			std::cout << "This is an invalid input. Try again: ";
			continue;
		}
		return input - '0';
	}
}

void inventory(Player& player)
{
	std::cout << "Your inventory contains: \n";

	for (Potion::Type t : Potion::types)
	{
		if (player.potionCount(t)>0)
			std::cout << player.potionCount(t) << "x potion of "<<Potion::names[t] << '\n';
	}

	std::cout << "You escaped with " << player.gold() << " gold remaining. \n\n";
}

void Player::buy(size_t item)
{
	int itemCost = Potion::costs[item];
	if (itemCost > m_gold)
	{
		std::cout << "You can not afford that. \n\n";
	}
	else
	{
		m_gold -= itemCost;
		m_inventory[item] += 1;
		std::cout << "You purchased a potion of "
		          << Potion::names[item] << ". You have "
		          << m_gold << " gold left. \n\n";
	}
}

int main()
{
	std::cout << "Welcome to Roscoe's potion emporium! \n";
	std::cout << "Enter your name: ";
	std::string name{};

	// read full line for name
	std::getline(std::cin >> std::ws, name);
	Player p{name};
	std::cout << "Hello, " << name << ", you have " << p.gold() << " gold. \n\n";

	while (true)
	{
		shop();
		std::cout
		    << "Enter the number of the potion you'd like to buy, or 'q' to quit: ";
		int input{getInput()};
		if (input == -1)
		{
			inventory(p);
			break;
		}
		p.buy(static_cast<size_t>(input));
	}

	std::cout << "Thanks for shopping at Roscoe's potion emporium! \n";
	return 0;
}
