#pragma once
#include "Player.h"
#include "Board.h"
#include <utility>

class GameHandler
{
	Player player1;
	Player player2;
	Board board;
	int counterOfTurn{ 0 };


public:
	GameHandler() = default;
	std::pair<int, int> setBoardSize();
	void runGame();
	bool checkIsValidMove(std::pair<int, int>);
	void upadateBoard(std::pair<int, int>playerMove, Player player);
	bool isOccupied(std::pair<int, int>playerMove);
	int makePlayerMove(Player player);
	bool isVertical(std::pair<int, int>playerMove);
	bool isHorizontal(std::pair<int, int>playerMove);
	bool isCrossBackslash(std::pair<int, int>playerMove);
	bool isWin(std::pair<int, int>playerMove);
};
