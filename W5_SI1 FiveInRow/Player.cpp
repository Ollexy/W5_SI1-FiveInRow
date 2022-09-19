#include "Player.h"

std::pair<int, int>  Player::inputCoordinate()
{
	char column;
	int row;
	std::pair<int, int> move;
	std::cout << "Please enter a coordinate ";
	std::cin >> column >> row;
	column = std::toupper(column);
	move.first = static_cast<int>(column - 'A');
	move.second = row - 1;

	return move;
}

void Player::setPlayerName()
{
	std::cout << "Enter player name: ";
	std::cin >> name;
}

void Player::setPlayerSign()
{
	std::cout << "Enter your sign (X/O): ";
	std::cin >> sign;
	sign = std::toupper(sign);
}

