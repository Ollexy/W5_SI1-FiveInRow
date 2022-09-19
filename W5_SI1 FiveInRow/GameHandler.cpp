#include "GameHandler.h"
#include <utility>

std::pair<int, int>GameHandler::setBoardSize()
{
	std::pair<int, int> board;
	std::cout << "Enter number of rows(1 - 26): ";
	std::cin >> board.first;
	std::cout << "Enter number of columns(1 - 26): ";
	std::cin >> board.second;

	return board;
}

void GameHandler::runGame()
{
	board.createBoard(setBoardSize());
	player1.setPlayerName();
	player1.setPlayerSign();
	player2.setPlayerName();
	if (player1.sign == 'X') {
		player2.sign = 'O';
	}
	else if (player1.sign == 'O')
		player2.sign = 'X';

	int result{};
	do {
		result = makePlayerMove(player1);
		if (result == 1) break;
		result = makePlayerMove(player2);
		counterOfTurn++;
		if (counterOfTurn == board.getBoardSize().first * board.getBoardSize().second) { std::cout << "Remis"; break; }
	} while (result != 1);
}

bool GameHandler::checkIsValidMove(std::pair<int, int> playerMove)
{
	std::pair<int, int> boardSize = board.getBoardSize();
	if ((playerMove.first < 0) || (playerMove.first >= boardSize.first)) {
		std::cout << "Input a proper letter!" << std::endl;
		return false;
	}
	if ((playerMove.second > boardSize.second - 1) || (playerMove.second < 0)) {
		std::cout << "Input a proper number!" << std::endl;
		return false;
	}
	return true;
}

void GameHandler::upadateBoard(std::pair<int, int>playerMove, Player player)
{
	board.markPlayerMove(playerMove, player.sign);
}

bool GameHandler::isOccupied(std::pair<int, int>playerMove)
{
	bool isFree = ((*board.getBoard())[playerMove.first][playerMove.second] == '.');

	return !isFree;
}

int GameHandler::makePlayerMove(Player player)
{
	std::cout << "Turn:    " << player.name << " " << player.sign << std::endl;
	board.printBoard();
	std::pair<int, int> playerMove;
	while (!checkIsValidMove(playerMove = player.inputCoordinate()));
	while (isOccupied(playerMove)) { std::cout << "Field is occupied" << std::endl; break; }
	upadateBoard(playerMove, player);
	if (isWin(playerMove)) {
		std::cout << "Wygrales: " << player.name << std::endl; system("pause");
		return 1;
	}
	else
		return 0;

	system("cls");

}


bool GameHandler::isVertical(std::pair<int, int> playerMove)
{
	auto x = playerMove.first;
	auto y = playerMove.second;
	int xSize = board.getBoardSize().first;
	int ySize = board.getBoardSize().second;
	//vertical
	for (int yPos{ 0 }; yPos < ySize - 4; yPos++) {

		if ((*board.getBoard())[x][y] == (*board.getBoard())[x][yPos] &&
			(*board.getBoard())[x][yPos] == (*board.getBoard())[x][yPos + 1] &&
			(*board.getBoard())[x][yPos + 1] == (*board.getBoard())[x][yPos + 2] &&
			(*board.getBoard())[x][yPos + 2] == (*board.getBoard())[x][yPos + 3] &&
			(*board.getBoard())[x][yPos + 3] == (*board.getBoard())[x][yPos + 4]) {
			return true;
		}
	}
	return false;
}


bool GameHandler::isHorizontal(std::pair<int, int> playerMove)
{
	auto x = playerMove.first;
	auto y = playerMove.second;
	int xSize = board.getBoardSize().first;
	int ySize = board.getBoardSize().second;
	//horizontal
	for (int xPos{ 0 }; xPos < xSize - 4; xPos++) {

		if ((*board.getBoard())[x][y] == (*board.getBoard())[xPos][y] &&
			(*board.getBoard())[xPos][y] == (*board.getBoard())[xPos + 1][y] &&
			(*board.getBoard())[xPos + 1][y] == (*board.getBoard())[xPos + 2][y] &&
			(*board.getBoard())[xPos + 2][y] == (*board.getBoard())[xPos + 3][y] &&
			(*board.getBoard())[xPos + 3][y] == (*board.getBoard())[xPos + 4][y]) {
			return true;
		}
	}
	return false;
}

bool GameHandler::isCrossBackslash(std::pair<int, int> playerMove)
{
	auto x = playerMove.first;
	auto y = playerMove.second;
	int xSize = board.getBoardSize().first;
	int ySize = board.getBoardSize().second;



	bool xCrossBackslash{ false };
	for (int i{ 0 }; i < ySize - 4; i++) {
		for (int xPos{ 0 }, yPos{ 0 }; yPos + i < ySize - 4; xPos++, yPos++) {
			if ((*board.getBoard())[x][y] == (*board.getBoard())[xPos][yPos + i] &&
				(*board.getBoard())[xPos][yPos + i] == (*board.getBoard())[xPos + 1][yPos + i + 1] &&
				(*board.getBoard())[xPos + 1][yPos + i + 1] == (*board.getBoard())[xPos + 2][yPos + i + 2] &&
				(*board.getBoard())[xPos + 2][yPos + i + 2] == (*board.getBoard())[xPos + 3][yPos + i + 3] &&
				(*board.getBoard())[xPos + 3][yPos + i + 3] == (*board.getBoard())[xPos + 4][yPos + i + 4]) {
				return xCrossBackslash = true;
			}
		}
	}

	bool yCrossBackslash{ false };
	for (int i{ 0 }; i < xSize - 4; i++) {
		for (int xPos{ 0 }, yPos{ 0 }; xPos + i < xSize - 4; xPos++, yPos++) {
			if ((*board.getBoard())[x][y] == (*board.getBoard())[xPos + i][yPos] &&
				(*board.getBoard())[xPos + i][yPos] == (*board.getBoard())[xPos + i + 1][yPos + 1] &&
				(*board.getBoard())[xPos + i + 1][yPos + 1] == (*board.getBoard())[xPos + i + 2][yPos + 2] &&
				(*board.getBoard())[xPos + i + 2][yPos + 2] == (*board.getBoard())[xPos + i + 3][yPos + 3] &&
				(*board.getBoard())[xPos + i + 3][yPos + 3] == (*board.getBoard())[xPos + i + 4][yPos + 4]) {
				return yCrossBackslash = true;
			}
		}
	}


	bool yCrossSlash{ false };
	for (int i{ 0 }; i < ySize - 4; i++) {
		for (int xPos{ xSize - 1 }, yPos{ 0 }; yPos + i < ySize - 4; xPos--, yPos++) {
			if ((*board.getBoard())[x][y] == (*board.getBoard())[xPos][yPos + i] &&
				(*board.getBoard())[xPos][yPos + i] == (*board.getBoard())[xPos - 1][yPos + i + 1] &&
				(*board.getBoard())[xPos - 1][yPos + i + 1] == (*board.getBoard())[xPos - 2][yPos + i + 2] &&
				(*board.getBoard())[xPos - 2][yPos + i + 2] == (*board.getBoard())[xPos - 3][yPos + i + 3] &&
				(*board.getBoard())[xPos - 3][yPos + i + 3] == (*board.getBoard())[xPos - 4][yPos + i + 4]) {
				yCrossSlash = true;
			}
		}
	}

	bool xCrossSlash{ false };
	for (int i{ 0 }; i < ySize - 4; i++) {
		for (int xPos{ xSize - 1 }, yPos{ 0 }; xPos - i > 4; xPos--, yPos++) {
			if ((*board.getBoard())[x][y] == (*board.getBoard())[xPos - i][yPos] &&
				(*board.getBoard())[xPos - i][yPos] == (*board.getBoard())[xPos - 1 - i][yPos + 1] &&
				(*board.getBoard())[xPos - 1 - i][yPos + 1] == (*board.getBoard())[xPos - 2 - i][yPos + 2] &&
				(*board.getBoard())[xPos - 2 - i][yPos + 2] == (*board.getBoard())[xPos - 3 - i][yPos + 3] &&
				(*board.getBoard())[xPos - 3 - i][yPos + 3] == (*board.getBoard())[xPos - 4 - i][yPos + 4]) {
				xCrossSlash = true;
			}
		}
	}

	if (xCrossBackslash || yCrossBackslash || yCrossSlash || xCrossSlash) { return true; }
	else return false;
}


bool GameHandler::isWin(std::pair<int, int>playerMove) {

	if (isVertical(playerMove) || isHorizontal(playerMove) || isCrossBackslash(playerMove)) { return true; }
	else return false;
}