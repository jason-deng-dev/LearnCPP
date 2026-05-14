// fixed point number with 2 fraction digits 12.34, 3.00
// range -32768.99 to 32767.99

#include <cassert>
#include <cmath>
#include <cstdlib>
#include <iostream>

#include <cstdint>
#include <istream>
#include <ostream>
#include <string>
class FixedPoint2
{
	int16_t val;
	int8_t frac;

public:
	FixedPoint2(int16_t a, int8_t b)
	    : val{a}
	    , frac(b)
	{
		// handle negative
		if (val < 0 || frac < 0)
		{
			if (val > 0)
				val = -val;
			if (frac > 0)
				frac = -frac;
		}

		// either both are positive or both negative

		// handle overflow
		// if (frac > 99)
		// {
		// 	frac = -1*(100-frac);
		// 	val++;
		// }
		// else if (frac < -99)
		// {
		// 	frac =  (100+frac);
		// 	val--;
		// }
		val += frac / 100;
		frac = frac % 100;
	}

	// delgate to copy constructor
	FixedPoint2(double d)
	    : FixedPoint2(
	          static_cast<int16_t>(std::trunc(d)),
	          static_cast<std::int8_t>(std::round(d * 100) - std::trunc(d) * 100))
	{
		// int16_t value = static_cast<int16_t>(a * 100);

		// frac = static_cast<int8_t>(value % 100);

		// // handle rounding from 3rd decimal
		// if (static_cast<int>(a * 1000) % 10 >= 5)
		// {
		// 	frac++;
		// }
		// if (static_cast<int>(a * 1000) % 10 <= -5)
		// {
		// 	frac--;
		// }

		// val = value / 100;

		// FixedPoint2 temp {val, frac};
		// val = temp.val;
		// frac = temp.frac;
	}

	operator double() const { return val + static_cast<double>(frac) / 100; }

	friend std::ostream& operator<<(std::ostream& out, FixedPoint2& fp)
	{
		out << static_cast<double>(fp);
		return out;
	}

	friend bool testDecimal(const FixedPoint2& fp);

	friend bool operator==(FixedPoint2& f1, FixedPoint2& f2)
	{
		return f1.frac == f2.frac && f1.val == f2.val;
	}

	friend std::istream& operator>>(std::istream& in, FixedPoint2& f)
	{
		// std::string v{};
		// in >> v;
		// FixedPoint2 temp{std::stod(v)};
		// f.frac = temp.frac;
		// f.val = temp.val;

		double d{};
		in >> d;
		f = FixedPoint2{d};
		return in;
	}

	FixedPoint2 operator-() const
	{
		// return FixedPoint2{static_cast<int16_t>(-val),
		// static_cast<int8_t>(-frac)};
		return FixedPoint2{-static_cast<double>(*this)};
	}

	friend FixedPoint2 operator+(FixedPoint2& f1, FixedPoint2& f2)
	{
		// return FixedPoint2{static_cast<int16_t>(f1.val + f2.val),
		//                    static_cast<int8_t>(f1.frac + f2.frac)};
		return FixedPoint2{ static_cast<double>(f1) + static_cast<double>(f2) };
	}
};

bool testDecimal(const FixedPoint2& fp)
{
	if (fp.val >= 0)
		return fp.frac >= 0 && fp.frac < 100;
	else
		return fp.frac <= 0 && fp.frac > -100;
}

int main()
{
	assert(FixedPoint2{0.75} == FixedPoint2{0.75});    // Test equality true
	assert(!(FixedPoint2{0.75} == FixedPoint2{0.76})); // Test equality false

	// Test additional cases -- h/t to reader Sharjeel Safdar for these test cases
	assert(FixedPoint2{0.75} + FixedPoint2{1.23} ==
	       FixedPoint2{1.98}); // both positive, no decimal overflow
	assert(FixedPoint2{0.75} + FixedPoint2{1.50} ==
	       FixedPoint2{2.25}); // both positive, with decimal overflow
	assert(FixedPoint2{-0.75} + FixedPoint2{-1.23} ==
	       FixedPoint2{-1.98}); // both negative, no decimal overflow
	assert(FixedPoint2{-0.75} + FixedPoint2{-1.50} ==
	       FixedPoint2{-2.25}); // both negative, with decimal overflow
	assert(FixedPoint2{0.75} + FixedPoint2{-1.23} ==
	       FixedPoint2{-0.48}); // second negative, no decimal overflow
	assert(FixedPoint2{0.75} + FixedPoint2{-1.50} ==
	       FixedPoint2{-0.75}); // second negative, possible decimal overflow
	assert(FixedPoint2{-0.75} + FixedPoint2{1.23} ==
	       FixedPoint2{0.48}); // first negative, no decimal overflow
	assert(FixedPoint2{-0.75} + FixedPoint2{1.50} ==
	       FixedPoint2{0.75}); // first negative, possible decimal overflow

	FixedPoint2 a{-0.48};
	assert(static_cast<double>(a) == -0.48);
	assert(static_cast<double>(-a) == 0.48);

	std::cout << "Enter a number: "; // enter 5.678
	std::cin >> a;
	std::cout << "You entered: " << a << '\n';
	assert(static_cast<double>(a) == 5.68);

	return 0;
}
