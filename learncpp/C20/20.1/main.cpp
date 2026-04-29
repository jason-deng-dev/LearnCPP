#include <functional>
#include <ios>
#include <iostream>
#include <limits>
using ArithimicFunction = std::function<int(int, int)>;

namespace Input
{

	void ignoreline()
	{
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	bool validateInput()
	{
		if (!std::cin)
		{
			std::cin.clear();
			ignoreline();
			return false;
		}
		if (std::cin.peek() != '\n')
		{
			std::cout << "Invalid input.\n";
			ignoreline();
			return false;
		}
		return true;
	}

	int getInt()
	{
		while (true)
		{
			int val{};
			std::cout << "Enter an integer: ";
			std::cin >> val;
			if (!validateInput())
				continue;
			return val;
		}
	}

	char getOperation()
	{
		char op{};
		do
		{
			std::cout << "Enter operation '+','-','*','/' : ";
			std::cin >> op;
			if (!validateInput())
				continue;
		} while (op != '+' && op != '-' && op != '*' && op != '/');
		return op;
	}
};

namespace Operation
{
	int add(int a, int b)
	{
		return a + b;
	}
	int subtract(int a, int b)
	{
		return a - b;
	}
	int multiply(int a, int b)
	{
		return a * b;
	}
	int divide(int a, int b)
	{
		return a / b;
	}

}

ArithimicFunction getArithmeticFunction(char op)
{
	switch (op)
	{
	case '+': return &Operation::add;
	case '-': return &Operation::subtract;
	case '*': return &Operation::multiply;
	case '/': return &Operation::divide;
	}
	return nullptr;
}

int main()
{
	int n1{Input::getInt()};
	char operation{Input::getOperation()};
	int n2{Input::getInt()};
	int result = getArithmeticFunction(operation)(n1,n2);
	
	std::cout << n1<< operation << n2<< '='<< result;
}
