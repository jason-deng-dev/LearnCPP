#include <array>
#include <ios>
#include <iostream>
#include <limits>
#include <optional>
#include <string_view>

namespace Animal
{
	enum Name
	{
		dog,
		cat,
		maxSize,
	};

	struct Data
	{
		std::string_view name{};
		int legs{};
		std::string_view sound{};
	};

	std::array<Data, maxSize> dataArr{{{"dog", 4, "woof"}, {"cat", 4, "meow"}}};
	static_assert(std::size(dataArr) == maxSize);

	std::array names{dog, cat};
	static_assert(std::size(names) == maxSize);
};

constexpr Animal::Data& getAnimalData(Animal::Name name)
{
	return Animal::dataArr[name];
}

void printAnimals(Animal::Name& )
{
	
}

std::optional<Animal::Name> getAnimal()
{
	while (true)
	{
		std::cout << "Enter an animal: ";
		std::string name{};
		std::cin >> name;

		// input error handling
		if (!std::cin)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		// valid animal handling
		bool found {false};
		for (auto& n : Animal::names)
		{
			if (getAnimalData(n).name == name)
			{
				return n;
      }
			
		}
		if (!found)
		{
			std::cout << "That animal couldn't be found.\n";
			continue;
		}
		
		break;
	}
}



int main()
{
	Animal::Name& name{getAnimal()};

	return 0;
}
