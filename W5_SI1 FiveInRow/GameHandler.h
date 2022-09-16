#pragma once
#include "Player.h"
#include "Board.h"
#include <utility>

class GameHandler
{
	Player player1;
	Player player2;
	Board board;


public:
	GameHandler() = default;
	std::pair<int,int> setBoardSize();
	void runGame();
	bool checkIsValidMove(std::pair<int, int>);
	void upadateBoard(std::pair<int, int>playerMove, Player player);
	bool isOccupied(std::pair<int, int>playerMove);
	void makePlayerMove(Player player);
	bool isInBoardRange(int x, int y);
	//bool isVertical();
	//bool isHorizontal();
	//bool isCross();
	bool isWin(std::pair<int, int>playerMove);
};

