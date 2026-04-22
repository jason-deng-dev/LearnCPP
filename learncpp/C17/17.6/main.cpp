#include <array>
#include <ios>
#include <iostream>
#include <limits>
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

void printAnimal(const Animal::Name& n)
{
	Animal::Data& currData = getAnimalData(n);
	std::cout << currData.name << " has " << currData.legs << " legs and says "
	          << currData.sound ;
}

void printAnimals(const Animal::Name& n)
{
	printAnimal(n);
	std::cout << "\n \n" << "Here is the data for the rest of the animals:\n";

	for (auto& name : Animal::names)
	{
		if (name != n)
		{
			printAnimal(name);
			std::cout<< '\n';
		}
	}
}



Animal::Name getAnimal()
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
		for (auto& n : Animal::names)
		{
			if (getAnimalData(n).name == name)
			{
				return n;
			}
		}

		std::cout << "That animal couldn't be found.\n";
		continue;
	}
}

int main()
{
	printAnimals(getAnimal());
	return 0;
}
