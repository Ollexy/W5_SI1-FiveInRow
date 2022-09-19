#pragma once
#include <string>
#include <iostream>
#include <utility>

class Player
{
public:
	std::string name;
	char sign;

	Player() = default;
	std::pair<int, int> inputCoordinate();
	void setPlayerName();
	void setPlayerSign();
};
