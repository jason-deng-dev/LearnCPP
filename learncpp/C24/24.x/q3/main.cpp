#include <cstddef>
#include <iostream>
#include <random>
#include <string>
#include <string_view>

class Creature
{
protected:
	std::string name;
	char symbol;
	int hp;
	int dmg;
	int gold;

public:
	Creature(std::string_view p_name, char p_symbol, int p_hp, int p_dmg,
	         int p_gold)
	    : name{p_name}
	    , symbol{p_symbol}
	    , hp{p_hp}
	    , dmg{p_dmg}
	    , gold{p_gold}
	{
	}

	std::string_view getName() const { return name; }
	char getSymbol() const { return symbol; }
	int getHealth() const { return hp; }
	int getDMG() const { return dmg; }
	int getGold() const { return gold; }

	void reduceHealth(int amount) { hp -= amount; }
	bool isDead() const { return hp <= 0; }
	void addGold(int amount) { gold += amount; }
};

class Monster : public Creature
{
private:
	static inline Creature monsterData[]{{"dragon", 'D', 20, 4, 100},
	                                     {"orc", 'o', 4, 2, 25},
	                                     {"slime", 's', 1, 1, 10}};

public:
	enum Type
	{
		dragon,
		orc,
		slime,
		max_types
	};

	static_assert(std::size(monsterData) == max_types);

	Monster(Type type)
	    : Creature{monsterData[type]}
	{
	}

	static Monster getRandomMonster()
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> distr(0, max_types - 1);
		return Monster{static_cast<Type>(distr(gen))};
	}
};

class Player : public Creature
{
	int level{1};

public:
	Player(std::string_view p_name)
	    : Creature{p_name, '@', 10, 1, 0}
	{
	}

	void levelUp()
	{
		level++;
		dmg++;
	}

	int getLevel() const { return level; }

	bool hasWon() const { return level == 20; }

	void hit(Monster& m)
	{
		m.reduceHealth(dmg);
		std::cout << "You hit the " << m.getName() << " for " << dmg
		          << " damage. \n";
	}

	void getHit(Monster& m)
	{
		reduceHealth(m.getDMG());
		std::cout << "The " << m.getName() << " hit you for " << m.getDMG()
		          << " damage. \n";
	}

	bool encounter(Monster& m)
	{
		std::cout << "(R)un or (F)ight:";
		char action{};
		std::cin >> action;

		if (action == 'f')
		{
			hit(m);
			if (!m.isDead())
			{
				getHit(m);
			}
		}

		else
		{
			std::random_device rd;
			std::mt19937 gen(rd());
			std::uniform_int_distribution<> distr(0, 1);
			int success = distr(gen);

			if (success)
			{
				std::cout << "You successfully fled.\n";
				return true;
			}
			else
			{
				std::cout << "You failed to flee. \n";
				getHit(m);
			}
		}
		return false;
	}
};

Player createPlayer()
{
	std::cout << "Enter your name: ";
	std::string playerName;
	std::cin >> playerName;

	Player p{playerName};
	std::cout << "Welcome, " << p.getName() << ".\n";

	return p;
}

int main()
{
	Player p{createPlayer()};
	while (!p.isDead() && !p.hasWon())
	{
		Monster m{Monster::getRandomMonster()};
		std::cout << "You have encountered a " << m.getName() << ".\n";

		while (!m.isDead() && !p.isDead())
		{
			bool escaped = p.encounter(m);
			if (escaped)
			{
				break;
			}
		}
		if (m.isDead()) 
		{
			std::cout << "You killed the " << m.getName() << '\n';
			p.addGold(m.getGold());
			p.levelUp();
			std::cout << "You are now level " << p.getLevel() << '\n';
			std::cout << "You found " << m.getGold() << " gold. \n";
    }
	}
	if (p.isDead())
	{
		std::cout << "You died at level " << p.getLevel() << " with " << p.getGold()
		          << " gold. \n";
	}
	else
	{
		std::cout << "You won and reached level "<< p.getLevel() << "! with " << p.getGold() << " gold. \n";
  }

	return 0;
}
