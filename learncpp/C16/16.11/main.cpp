#include <iostream>
#include <vector>
#include <iterator>

void printStack(const std::vector<int>& stack)
{
	std::cout << "(Stack:";
	for (int i : stack)
			std::cout << ' ' << i;
	if (std::ssize(stack) == 0)
		std::cout << " empty";
	std::cout << ") \n";
}

void pushPrintStack(std::vector<int>& stack, int num)
{
	std::cout << "Push " << num << ' ';
	stack.push_back(num);
	printStack(stack);
}

void popPrintStack(std::vector<int>& stack)
{
	std::cout << "Pop    ";
	stack.pop_back();
	printStack(stack);
}

int main()
{
	std::vector<int> stack{};
	printStack(stack);
	pushPrintStack(stack, 1);
	pushPrintStack(stack, 2);
	pushPrintStack(stack, 3);
  popPrintStack(stack);
	pushPrintStack(stack, 4);
  popPrintStack(stack);
  popPrintStack(stack);
  popPrintStack(stack);
	return 0;
}
