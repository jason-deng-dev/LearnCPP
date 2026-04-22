#include <array>
#include <ios>
#include <iostream>
#include <string>
#include <string_view>

namespace Animal
{
	enum Type
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

	// constexpr for: lookup table, fixed at compile-time, no runtime init
	constexpr std::array<Data, maxSize> data{
	    {{"dog", 4, "woof"}, {"cat", 4, "meow"}}};
	constexpr std::array types{dog, cat};

	static_assert(std::size(data) == maxSize);
	static_assert(std::size(types) == maxSize);
};

// overload operator >>
// to integrate Animal::Name with cin's fail state system
// if (!std::cin) just works
std::istream& operator>>(std::istream& in, Animal::Type& animal)
{
	std::string input{};
	std::getline(in >> std::ws, input);

	for (std::size_t index = 0; index < Animal::data.size(); ++index)
	{
		if (input == Animal::data[index].name)
		{
			animal = static_cast<Animal::Type>(index);
			return in;
		}
	}

	in.setstate(std::ios_base::failbit);
	return in;
}

void printAnimalData(Animal::Type type)
{
	const Animal::Data& animal{Animal::data[type]};
	std::cout << "A " << animal.name << " has " << animal.legs
	          << " legs and says " << animal.sound << ".\n";
}

int main()
{
	std::cout << "Enter an animal: ";
	Animal::Type type{};
	std::cin >> type;

	// If users input didn't match
	if (!std::cin)
	{
		std::cin.clear();
		std::cout << "That animal couldn't be found.\n";
		type = Animal::maxSize; // set to invalid option so we don't match below
	}
	else
		printAnimalData(type);

	std::cout << "\nHere is the data for the rest of the animals:\n";
	for (auto a : Animal::types)
	{
		if (a != type)
			printAnimalData(a);
	}

	return 0;

	return 0;
}
