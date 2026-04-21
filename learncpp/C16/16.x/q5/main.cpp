#include "Random.h"
#include <cstddef>
#include <ios>
#include <iostream>
#include <limits>
#include <string_view>

namespace Wordlist
{
	std::vector<std::string_view> words{"mystery",   "broccoli",  "account",
	                                    "almost",    "spaghetti", "opinion",
	                                    "beautiful", "distance",  "luggage"};
	std::string_view getRandomWord()
	{
		return words[Random::get<std::size_t>(0,
		                                      static_cast<int>(words.size()) - 1)];
	}
};

class Session
{
public:
	Session()
	{
		m_guesses.reserve(26);
		m_wrong_guesses.reserve(26);
		for ([[maybe_unused]] char c : m_word)
			m_display_word += '_';
	}
	void displayState();
	void doGuess();
	bool checkEnd();
	void endMessage();

private:
	std::string_view m_word{Wordlist::getRandomWord()};
	std::string m_display_word{};
	std::vector<char> m_guesses{};
	std::vector<char> m_wrong_guesses{};
	int m_attempts{6};
};

// check if c is in guesses
template <typename T>
bool checkContains(const T& container, char check)
{
	for (char c : container)
		if (c == check)
			return true;
	return false;
}

// Move this outside of Session to decouple
void Session::displayState()
{
	std::cout << "The word: " << m_display_word;
	std::cout << "    Wrong guesses: ";
	int i{0};
	while (i < m_attempts)
	{
		std::cout << '+';
		++i;
	}
	for (char c : m_wrong_guesses)
		std::cout << c;
	std::cout << '\n';
}

// Move this outside of Session to decouple
char getInput()
{
	while (true)
	{
		std::cout << "Enter your next letter: ";
		char c{};
		std::cin >> c;

		if (!std::cin)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		// Clear out any extraneous input
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		if (c < 'a' || c > 'z')
		{
			std::cout << "Invalid input. Try again. \n";
			continue;
		}
		return c;
	}
}

void Session::doGuess()
{
	// loop until the input is not in guesses
	while (true)
	{
		char guess{getInput()};
		if (checkContains(m_guesses, guess))
		{
			std::cout << "You already guessed that.  Try again. \n \n";
			continue;
		}
		else
		{
			if (!checkContains(m_word, guess))
			{
				m_wrong_guesses.push_back(guess);
				--m_attempts;
				std::cout << "No, " << guess << " is not in the word! \n \n";
			}

			else
			{
				std::size_t i{0};
				for (char c : m_word)
				{
					if (c == guess)
						m_display_word[i] = c;
					++i;
				}
				std::cout << "Yes, " << guess << " is in the word! \n \n";
			}

			m_guesses.push_back(guess);
			break;
		}
	}
}

bool Session::checkEnd()
{
	// std::string implicitly coverts to string_view
	if (m_attempts == 0 || m_word == m_display_word)
		return true;
	return false;
}

void Session::endMessage()
{
	displayState();
	// std::string implicitly coverts to string_view
	if (m_word == m_display_word)
		std::cout << "You won! \n";
	else
		std::cout << "You lost! The word was: " << m_word << '\n';
}

int main()
{
	std::cout << "Welcome to C++man (a variant of Hangman) \n"
	          << "To win: guess the word.  To lose: run out of pluses. \n";
	Session s{};
	while (!s.checkEnd())
	{
		s.displayState();
		s.doGuess();
	}
	s.endMessage();

	return 0;
}
