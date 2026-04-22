
#include <string_view>
#include <array>
#include <iostream>

struct Item
{
	std::string_view name{};
	int gold {};
};

template <typename T, auto N>
void printItems(const std::array<T,N>& arr)
{
	for (const auto& item : arr)
		std::cout << "A " << item.name << " costs " << item.gold << " gold.\n";
}

int main()
{
	constexpr std::array<Item,4> items{{{"sword", 5}, {"dagger", 3},
	                           {"club", 2}, {"spear", 7}}};
  printItems(items);
	
	return 0;
}
