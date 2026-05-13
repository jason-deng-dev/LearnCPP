#include <cstdint>
#include <iostream>
#include <ostream>

class Average
{
	std::int32_t sum{};
	int count{};

public:
	Average& operator+=(int b)
	{
		this->sum += b;
		this->count++;
		return *this;
	}
	friend std::ostream& operator<<(std::ostream& out, Average& avg);
};

std::ostream& operator<<(std::ostream& out, Average& avg)
{
	if (avg.count == 0)
	{
		out << 0;
	}
	else
	{
		if (avg.sum % avg.count == 0)
			out << avg.sum / avg.count;
		else
      out << avg.sum / static_cast<double>(avg.count);
	}

	return out;
}

int main()
{
	Average avg{};
	std::cout << avg << '\n';

	avg += 4;
	std::cout << avg << '\n'; // 4 / 1 = 4

	avg += 8;
	std::cout << avg << '\n'; // (4 + 8) / 2 = 6

	avg += 24;
	std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12

	avg += -10;
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5

	(avg += 6) += 10;         // 2 calls chained together
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7

	Average copy{avg};
	std::cout << copy << '\n';

	return 0;
}
