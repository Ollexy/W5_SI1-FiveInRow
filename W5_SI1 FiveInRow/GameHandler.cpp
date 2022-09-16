#include "GameHandler.h"
#include <utility>

std::pair<int,int>GameHandler::setBoardSize()
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
	else if(player1.sign == 'O')
		player2.sign = 'X';

	
	while (true) {
		makePlayerMove(player1);
        if (!isWin()) break;
		makePlayerMove(player2);
        if (!isWin()) break;
	}
}

bool GameHandler::checkIsValidMove(std::pair<int, int> playerMove)
{
	std::pair<int, int> boardSize = board.getBoardSize();
	if ((playerMove.first < 0) || (playerMove.first >=boardSize.first )) {
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

void GameHandler::makePlayerMove(Player player)
{
	std::cout << "Turn:    " << player.name << " " << player.sign << std::endl;
	board.printBoard();
	std::pair<int, int> playerMove;
	while (!checkIsValidMove(playerMove = player.inputCoordinate()));
	while (isOccupied(playerMove)) { std::cout << "Field is occupied" << std::endl; break; }
	upadateBoard(playerMove, player);
	system("cls");
}

bool GameHandler::isInBoardRange(int x, int y)
{
	if (x >= 0 && x < board.getBoardSize().first && y >= 0 && y < board.getBoardSize().second) {
		return true;
	}
	return false;
}

//bool GameHandler::isVertical()
//{
//	int points{};
//
//	return true;
//
//}

bool GameHandler::isWin(std::pair<int, int>playerMove){
	auto x = playerMove.first;
	auto y = playerMove.second;

		if ((board[x][y] == sign && board[x][y + 1] == sign && board[x][y + 2] == sign &&
			board[x][y + 3] == sign && board[x][y + 4] == sign)
			(board[x][y - 1] == sign && board[x][y] == sign && board[x][y + 1] == sign &&
				board[x][y + 2] == sign && board[x][y + 3] == sign)
			(board[x][y - 2] == sign && board[x][y - 1] == sign && board[x][y] == sign &&
				board[x][y + 1] == sign && board[x][y + 2] == sign)
			(board[x][y - 3] == sign && board[x][y - 2] == sign && board[x][y - 1] == sign &&
				board[x][y] == sign && board[x][y + 1] == sign)
			(board[x][y - 4] == sign && board[x][y - 3] == sign && board[x][y - 2] == sign &&
				board[x][y - 1] == sign && board[x][y] == sign)) {
			std::cout << "Congratulations! You won!" << std::endl;
			return true;
		}
		return false;
	
}
