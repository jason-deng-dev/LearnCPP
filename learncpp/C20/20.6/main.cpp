#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

struct Student
{
	std::string_view name;
	int point;
};

struct Season
{
  std::string_view name{};
  double averageTemperature{};
};

int main()
{
	std::array<Student, 8> arr{{{"Albert", 3},
	                            {"Ben", 5},
	                            {"Christine", 2},
	                            {"Dan", 8}, // Dan has the most points (8).
	                            {"Enchilada", 4},
	                            {"Francis", 1},
	                            {"Greg", 3},
	                            {"Hagrid", 5}}};

	const auto best =
	    std::max_element(arr.begin(), arr.end(), [](const auto& a, const auto& b)
	                     { return a.point < b.point; });
	std::cout << best->name << " is the best student";

	std::array<Season, 4> seasons{
    { { "Spring", 285.0 },
      { "Summer", 296.0 },
      { "Fall", 288.0 },
      { "Winter", 263.0 } }
  };

	/*
	 * Use std::sort here
	 */
	std::sort(seasons.begin(), seasons.end(),
	          [](const auto& a, const auto& b)
	          {
		  return a.averageTemperature < b.averageTemperature;
  });

  for (const auto& season : seasons)
  {
    std::cout << season.name << '\n';
  }


	
	return 0;
}
