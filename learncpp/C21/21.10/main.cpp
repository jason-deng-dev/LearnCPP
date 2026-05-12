#include <cstddef>
#include <ostream>
#include <string>
#include <cassert>
#include<iostream>
#include <string_view>

class MyString
{
	std::string s;

public:
	MyString(std::string str)
	    : s{str}
	{
	}

	std::string_view operator()(int start, int length)
	{
		assert(start >= 0);
		assert(start+length <= static_cast<int>(s.length()));
		
		return static_cast<std::string_view>(s).substr(static_cast<size_t>(start), static_cast<size_t>(length));
	}

	friend std::ostream& operator<<(std::ostream& out, const MyString& str);
};

std::ostream& operator<<(std::ostream& out, const MyString& str)
{
  out << str.s;
  return out;
}

int main()
{
    MyString s { "Hello, world!" };
    std::cout << s(7, 5) << '\n'; // start at index 7 and return 5 characters

    return 0;
}
