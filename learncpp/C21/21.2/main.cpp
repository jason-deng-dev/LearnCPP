#include <iostream>
#include <numeric>

class Fraction
{
	// should use direct list init
	int m_num{0};
	int m_denom{1};

public:
	// do default denom = 1;
	// to prevent copy/copy list init and implicit function return/parameter
	// conversion
	explicit Fraction(int num, int denom = 1)
	    : m_num(num)
	    , m_denom(denom)
	{
		reduce();
	}
	// should use const here on print since it can't change values
	void print() const { std::cout << m_num << '/' << m_denom << '\n'; }

	friend Fraction operator*(const Fraction& a, const Fraction& b)
	{
		return Fraction{a.m_num * b.m_num, a.m_denom * b.m_denom};
	}
	friend Fraction operator*(const Fraction& a, int b)
	{
		return Fraction{a.m_num * b, a.m_denom};
	}

	friend Fraction operator*(int b, const Fraction& a) { return a * b; }
	void reduce()
	{
		int gcd = std::gcd(m_denom, m_num);
		m_num = m_num / gcd;
		m_denom = m_denom / gcd;
  }
};

int main()
{
    Fraction f1{2, 5};
    f1.print();

    Fraction f2{3, 8};
    f2.print();

    Fraction f3{ f1 * f2 };
    f3.print();

    Fraction f4{ f1 * 2 };
    f4.print();

    Fraction f5{ 2 * f2 };
    f5.print();

    Fraction f6{ Fraction{1, 2} * Fraction{2, 3} * Fraction{3, 4} };
    f6.print();

    Fraction f7{0, 6};
    f7.print();

    return 0;
}
