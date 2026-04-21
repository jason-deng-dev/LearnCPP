#include <vector>
#include <string_view>
int main()
{
	std::vector a{2, 4, 6, 8, 10, 12};
	const std::vector b{1.2, 3.4, 5.6, 7.8};
	using namespace std::literals::string_view_literals;
	const std::vector c{"A"sv, "B"sv, "C"sv, "D"sv};
	std::vector d{12};
	std::vector<int> e(12);
	return 0;
}
