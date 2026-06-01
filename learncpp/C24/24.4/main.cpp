#include <iostream>
#include <ostream>
#include <string>

class Fruit
{
private:
	std::string name;
	std::string color;

public:
	Fruit(const std::string& n, const std::string& c)
	    : name{n}
	    , color{c}
	{
	}

	std::string_view getName() const { return name; }
	std::string_view getColor() const { return color; }
};

class Apple : public Fruit
{
private:
	double fiber;

public:
	Apple(const std::string& n, const std::string& c, double f)
	    : Fruit{n, c}
	    , fiber{f}
	{
	}

	double getFiber() const {return fiber;}
};

class Banana : public Fruit
{
public:
	Banana(const std::string& n, const std::string& c)
	    : Fruit{n, c}
	{
	}
};



std::ostream& operator<<(std::ostream& out, const Banana& b)
{
	out << "Banana(" << b.getName() << ", " << b.getColor() << ") \n";
	return out;
}

std::ostream& operator<<(std::ostream& out, const Apple& a)
{
	out << "Apple(" << a.getName() << ", " << a.getColor() << ", " << a.getFiber() << ") \n";
	return out;
}



int main()
{
	const Apple a{"Red delicious", "red", 4.2};
	std::cout << a << '\n';

	const Banana b{"Cavendish", "yellow"};
	std::cout << b << '\n';

	return 0;
}
