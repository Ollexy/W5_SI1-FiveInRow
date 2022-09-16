#include "Board.h"
#include <iostream>

void Board::createBoard(std::pair<int, int>board)
{	
	for (int j = 0; j < board.first; j++) {
		std::vector<char> row;
		for (int i = 0; i < board.second; i++)
			row.push_back('.');
		gameBoard.push_back(row);
	}
}

void Board::printBoard()
{
	std::cout << "   ";
	for (int i = 0; i < gameBoard[0].size(); i++) {
		std::cout << (char)('A' + i) << " ";
	}
	std::cout << std::endl;
	for (int i = 1; i < gameBoard.size(); i++)
	{
		if (i < 10)
			std::cout << i << "  ";
		else
			std::cout << i << " ";

		for (int j = 0; j < gameBoard[i].size(); j++) {
			std::cout << gameBoard[j][i] << " ";
		}
		std::cout << std::endl;
	}
}

std::pair<int, int> Board::getBoardSize()
{
	std::pair<int, int> boardSize;
	boardSize.first = gameBoard[0].size();
	boardSize.second = gameBoard.size();
	return boardSize;
}

void Board::markPlayerMove(std::pair<int, int> playerMove, char sign)
{
	gameBoard[playerMove.first][playerMove.second] = sign;
}

std::vector<std::vector<char>>* Board::getBoard()
{
	return gameBoardPtr;
}

