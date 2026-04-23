#include "Random.h"
#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <string_view>

namespace Settings
{
	int player_bust_value{21};
	int dealer_stop_value{17};

}

enum gameState
{
	lose = -1,
	tie,
	win,
};

struct Card
{
	enum Rank
	{
		rank_ace,
		rank_2,
		rank_3,
		rank_4,
		rank_5,
		rank_6,
		rank_7,
		rank_8,
		rank_9,
		rank_10,
		rank_jack,
		rank_queen,
		rank_king,

		max_ranks
	};
	enum Suit
	{
		suit_club,
		suit_diamond,
		suit_heart,
		suit_spade,

		max_suits
	};

	Rank rank{};
	Suit suit{};

	static constexpr std::array allRanks{
	    rank_ace, rank_2, rank_3,  rank_4,    rank_5,     rank_6,   rank_7,
	    rank_8,   rank_9, rank_10, rank_jack, rank_queen, rank_king};
	static constexpr std::array allSuits{suit_club, suit_diamond, suit_heart,
	                                     suit_spade};

	int value() const
	{
		static constexpr std::array rankValue{11, 2, 3,  4,  5,  6, 7,
		                                      8,  9, 10, 10, 10, 10};
		return rankValue[rank];
	}

	friend std::ostream& operator<<(std::ostream& out, const Card& card)
	{
		static constexpr std::array<std::string_view, max_ranks> rankName{
		    "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
		static constexpr std::array suitName{'C', 'D', 'H', 'S'};
		out << rankName[card.rank] << suitName[card.suit];
		return out;
	}
};

class Deck
{
private:
	std::array<Card, 52> m_cards{};
	size_t m_index{0};

public:
	Deck()
	{
		size_t i{0};
		for (auto& suit : Card::allSuits)
		{
			for (auto& rank : Card::allRanks)
			{
				m_cards[i++] = {rank, suit};
			}
		}
	}
	Card& dealCard()
	{
		assert(m_index != 52 && "Out of cards!");
		return m_cards[m_index++];
	}

	void shuffle() { std::shuffle(m_cards.begin(), m_cards.end(), Random::mt); }
	// shuffle()
};

struct Player
{
	int score{};
	int aces{};
	void playCard(Card& card)
	{
		score += card.value();
		if (card.rank == Card::rank_ace)
		{
			aces += 1;
		}
		while (score > Settings::player_bust_value && aces > 0)
		{
			--aces;
			score -= 10;
		}
	}
};

bool dealerTurn(Deck& deck, Player& dealer)
{
	while (dealer.score < Settings::dealer_stop_value)
	{
		auto& card = deck.dealCard();
		dealer.playCard(card);
		std::cout << "The dealer flips a " << card
		          << ". They now have: " << dealer.score << '\n';
		if (dealer.score > Settings::player_bust_value)
		{
			std::cout << "The dealer went bust! \n";
			return true;
		}
	}
	return false;
}

bool playerWantsHit()
{
	while (true)
	{
		std::cout << "(h) to hit, or (s) to stand: ";
		char move{};
		std::cin >> move;
		if (move == 'h')
			return true;
		else if (move == 's')
			return false;
	}
}

bool playerTurn(Deck& deck, Player& player)
{
	while (player.score < Settings::player_bust_value && playerWantsHit())
	{
		auto& card = deck.dealCard();
		player.playCard(card);
		std::cout << "You were dealt " << card << ". You now have: " << player.score
		          << '\n';
	}

	if (player.score > Settings::player_bust_value)
	{
		std::cout << "You went bust! \n";
		return true;
	}
	return false;
}

gameState playRound()
{
	
	Deck deck{};
	deck.shuffle();
	Card& dealerCard = deck.dealCard();
	Card& playerCard1 = deck.dealCard();
	Card& playerCard2 = deck.dealCard();
	Player dealer{};
	Player player{};
	dealer.playCard(dealerCard);
	player.playCard(playerCard1);
	player.playCard(playerCard2);
	std::cout << "The dealer is showing: " << dealerCard << " (" << dealer.score
	          << ")";
	std::cout << "\nYour are showing: " << playerCard1 << " " << playerCard2
	          << " (" << player.score << ")\n";
	if (playerTurn(deck, player))
		return gameState::lose;
	if (dealerTurn(deck, dealer))
		return gameState::win;

	if (player.score < dealer.score)
		return gameState::lose;
	else if (player.score > dealer.score)
		return gameState::win;
	else
		return gameState::tie;
}

int main()
{
	gameState res{playRound()};
	if (res == gameState::win)
		std::cout << "You win!";
	else if (res == gameState::lose)
		std::cout << "You lose!";
	else
		std::cout << "Tie!";
	std::cout << '\n';

	return 0;
}
