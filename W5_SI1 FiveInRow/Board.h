#pragma once
#include <vector>
#include <utility>
class Board
{
public:
	void createBoard(std::pair<int, int>board);
	void printBoard();
	Board() = default;
	std::pair<int, int> getBoardSize();
	void markPlayerMove(std::pair<int, int> playerMove, char sign);
	std::vector<std::vector<char>>* getBoard();
private:
	std::vector<std::vector<char>>gameBoard;
	std::vector<std::vector<char>>* gameBoardPtr = &gameBoard;

};
