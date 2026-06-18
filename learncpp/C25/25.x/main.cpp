#include <memory>
#include <ostream>
#include <iostream>
#include <vector>

class Shape
{
public:
	virtual std::ostream& print(std::ostream& out ) const = 0;

	friend std::ostream& operator<<(std::ostream& out, const Shape& s)
	{
		return s.print(out);
	};

	virtual ~Shape() = default;
};

class Point
{
public:
	int x{};
	int y{};
	Point(int a = 0, int b = 0)
	    : x{a}
	    , y{b}
	{
	}

	friend std::ostream& operator<<(std::ostream& out, const Point& p)
	{
		return out << "Point(" << p.x << ", " << p.y << ')';
	}
};

class Triangle : public Shape
{
	Point m_p1{};
	Point m_p2{};
	Point m_p3{};

public:
	Triangle(const Point& p1, const Point& p2, const Point& p3)
	    : m_p1{p1}
	    , m_p2{p2}
	    , m_p3{p3}
	{
	}

	std::ostream& print(std::ostream& out) const override
	{
		return out << "Triangle(" << m_p1 << ", " << m_p2 << ", " << m_p3 << ")\n";
  }
};

class Circle : public Shape
{
	
	

public:
	int m_r{};
	Point m_p{};
	Circle(const Point& p, int r)
	    : m_r{r}, m_p{p}
	    
	{
	}

	std::ostream& print(std::ostream& out) const override
	{
		return out << "Circle(" << m_p << ", radius " << m_r << ")\n";
  }
};

int getLargestRadius(const std::vector<std::unique_ptr<Shape>>& v)
{
	int maxRadius = 0;

	for (const auto s : v)
	{
		auto circle = dynamic_cast<Circle*>(s);
		if (circle == nullptr)
			continue;
		maxRadius = std::max(maxRadius, circle->m_r);
	}
	return maxRadius;
	
}

int main()
{
	std::vector<std::unique_ptr<Shape>> v;
	v.reserve(3);
	

	Circle c1 = 
	
	v.push_back(new Circle{Point{1, 2}, 7});
	
	  ,
	  new Triangle{Point{ 1, 2 }, Point{ 3, 4 }, Point{ 5, 6 }},
	  new Circle{Point{ 7, 8 }, 3}
	};

	// print each shape in vector v on its own line here

	std::cout << "The largest radius is: " << getLargestRadius(v) << '\n'; // write this function

	// delete each element in the vector here

	return 0;
}
