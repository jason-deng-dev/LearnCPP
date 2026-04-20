#include <vector>
#include <cassert>
#include <iostream>

namespace Animals
{
	enum names
	{
		chicken,
		dog,
		cat,
		elephant,
		duck,
		snake,
		maxNames
	};
	const std::vector legs{2, 4, 4, 4, 2, 0};
};

int main()
{
	assert(Animals::legs.size() == Animals::maxNames);

	std::cout << Animals::legs[Animals::elephant];
	return 0;
}
