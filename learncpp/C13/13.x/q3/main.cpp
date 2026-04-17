#include <iostream>

template <typename T>
struct Triad {
  T first{};
  T second{};
  T third{};
};

// template guide
template <typename T>
Triad(T, T, T) -> Triad<T>;

template <typename T>
void print(Triad<T> t){
  std::cout << '[' << t.first << ", " << t.second << ", " <<t.third << "] \n";
}


int main()
{
	Triad t1{ 1, 2, 3 }; // note: uses CTAD to deduce template arguments
	print(t1);

	Triad t2{ 1.2, 3.4, 5.6 }; // note: uses CTAD to deduce template arguments
	print(t2);

	return 0;
}
