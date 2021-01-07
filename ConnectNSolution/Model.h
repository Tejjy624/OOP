#ifndef CONNECTN_MODEL_H
#define CONNECTN_MODEL_H

#include <vector>
#include <string>
#include "Player.h"
#include "Board.h"
#include "GameStatus.h"
namespace ConnectNGame {
  class Model {
   public:
    Model(int numRows, int numCols, int numPiecesToWin, char blankSpace);

    const Player& getActivePlayer() const;
    Player& getActivePlayer();

    const Board& getBoard() const;
    Board& getBoard();

    void changeTurn();

    bool isGameOver() const;

    void addPiece(char piece, int col);
    void addPlayer(const Player& player);

    GameStatus getGameStatus() const;

    bool isValidPlayerName(const std::string& potentialName) const;
    bool isValidPieceChoice(char potentialPieceChoice) const;

   private:
    void checkIsGameOver(int colPlayed);
    bool horizontalWin(int colPlayed) const;
    bool verticalWin(int colPlayed) const;
    bool diagonalWin(int colPlayed) const;
    bool leftDiagonalWin(int colPlayed) const;
    bool rightDiagonalWin(int colPlayed) const;
    bool winChecker(int startRow, int startCol, int rowStep, int colStep) const;
    int matchCounter(int startRow, int startCol, int rowStep, int colStep, char piece) const;


   private:
    Board board;
    const int numPiecesToWin;
    std::vector<Player> players;
    int curPlayerTurn;
    bool _isGameOver;
    GameStatus gameStatus;
  };
}

#endif //CONNECTN_MODEL_H
