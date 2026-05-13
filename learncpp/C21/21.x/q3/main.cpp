#include <cassert>
#include <iostream>
#include <ostream>

class IntArray
{
	int m_len = 0;
	int* m_startPtr = nullptr;

public:
	IntArray(int len)
	    : m_len(len)
	{
		// allocates len contiguous ints on heap
		m_startPtr = new int[len];
	}

	IntArray(const IntArray& arr)
	{
		delete[] m_startPtr;
		m_len = arr.m_len;
		if (arr.m_startPtr)
		{
			m_startPtr = new int[m_len];
			for (int i{0}; i < m_len; ++i)
			{
				*(m_startPtr + i) = *(arr.m_startPtr + i);
			}
		}
		else
			m_startPtr = nullptr;
	}

	IntArray& operator=(const IntArray& source)
	{
		if (this != &source)
		{
			*this = *this{source};
		}
		return *this;
	}

	~IntArray() { delete[] m_startPtr; }

	int& operator[](int index)
	{
		assert(index < m_len && "Out of bounds");
		return *(m_startPtr + index);
	}

	friend std::ostream& operator<<(std::ostream& out, IntArray arr)
	{
		int* curr = arr.m_startPtr;
		while (curr != arr.m_startPtr + arr.m_len)
		{
			out << *curr << ' ';
			++curr;
		}
		return out;
	}
};

IntArray fillArray()
{
	IntArray a(5);

	a[0] = 5;
	a[1] = 8;
	a[2] = 2;
	a[3] = 3;
	a[4] = 6;

	return a;
}

int main()
{
	IntArray a{fillArray()};

	std::cout << a << '\n';

	auto& ref{
	    a}; // we're using this reference to avoid compiler self-assignment errors
	a = ref;

	IntArray b(1);
	b = a;

	a[4] = 7;

	std::cout << b << '\n';

	return 0;
}
