#include <array>
#include <cstddef>
#include <iostream>
#include <ostream>
#include <random>
#include <utility>
#include <vector>

namespace Utility
{
	std::mt19937 rng{std::random_device{}()};

	std::size_t getRandom(std::size_t x, std::size_t y)
	{
		std::uniform_int_distribution<std::size_t> dist{x, y};
		return dist(rng);
	}

}


// board class
// display logic
// handle controls
// check end state
class Board
{
	std::array<std::array<int, 4>, 4> m_board{};

public:
	Board()
	{
		int i = 1;
		for (std::size_t r = 0; r < 4; ++r)
		{
			for (std::size_t c = 0; c < 4; ++c)
			{
				m_board[r][c] = i;
				++i;
			}
		}
		m_board[3][3] = 0;

		std::array<char, 4> moves{'w', 'a', 's', 'd'};
		for (int c = 0; c < 200; ++c)
		{
			move(moves[Utility::getRandom(0, 3)]);
		}
	}

	friend std::ostream& operator<<(std::ostream& out, const Board& b)
	{
		for (std::size_t r = 0; r < 4; ++r)
		{
			for (std::size_t c = 0; c < 4; ++c)
			{
				int val = b.m_board[r][c];

				if (val < 10)
				{
					if (val == 0)
						std::cout << "  ";
					else
						std::cout << ' ' << val;
				}
				else
				{
					std::cout << val;
				}
				std::cout << "  ";
			}
			std::cout << "\n";
		}

		return out;
	}

	bool isEnd()
	{
		int i = 1;
		for (std::size_t r = 0; r < 4; ++r)
		{
			for (std::size_t c = 0; c < 4; ++c)
			{
				if (i == 16)
					return true;

				if (m_board[r][c] != i)
					return false;

				++i;
			}
		}
		return false;
	}

	void move(char m)
	{
		// find open space r, c
		// depending on direction, shift all values in row = r, column = c
		// wasd

		std::size_t row{}, col{};

		for (std::size_t r = 0; r < 4; ++r)
		{
			for (std::size_t c = 0; c < 4; ++c)
			{
				if (m_board[r][c] == 0)
				{
					row = r;
					col = c;
				}
			}
		}

		if (m == 'a' && col < 3)
			std::swap(m_board[row][col], m_board[row][col + 1]);

		if (m == 'd' && col > 0)
			std::swap(m_board[row][col], m_board[row][col - 1]);

		if (m == 'w' && row < 3)
			std::swap(m_board[row][col], m_board[row + 1][col]);

		if (m == 's' && row > 0)
			std::swap(m_board[row][col], m_board[row - 1][col]);
	}
};

// user class
// recieve inputs => call board class

void playGame()
{
	Board board{};

	while (!board.isEnd())
	{
		std::cout << board;
		char move{};
		std::cin >> move;
		board.move(move);
	}
}

int main()
{
	playGame();

	return 0;
}
