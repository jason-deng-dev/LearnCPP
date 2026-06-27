#include <iostream>
#include <string>

template <typename T1, typename T2>
class Pair
{
	T1 v1{};
	T2 v2{};

public:
	Pair(const T1& v1param, const T2& v2param)
	    : v1{v1param}
	    , v2{v2param}
	{
	}

	T1& first() { return v1; }
	T2& second() { return v2; }

	const T1& first() const { return v1; }
	const T2& second() const { return v2; }
};

template <typename T>
class StringValuePair : public Pair<std::string, T>
{
	public:
	StringValuePair(const std::string& str, const T& v)
	    : Pair<std::string, T>(str, v)
	{
	}
};

int main()
{
	StringValuePair<int> svp { "Hello", 5 };
	std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

	return 0;
}
