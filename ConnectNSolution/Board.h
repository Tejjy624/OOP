#ifndef CONNECTN_BOARD_H
#define CONNECTN_BOARD_H
#include <vector>
#include <string>
namespace ConnectNGame {
  class Board {
   public:
    using iterator = std::vector<std::string>::iterator;
    using const_iterator = std::vector<std::string>::const_iterator;
    using reverse_iterator = std::vector<std::string>::reverse_iterator;
    using const_reverse_iterator = std::vector<std::string>::const_reverse_iterator;


    Board(int numRows, int numCols, char blankChar);

    int getNumRows() const;
    int getNumCols() const;

    const_iterator begin() const;
    const_iterator end() const;

    iterator begin();
    iterator end();

    reverse_iterator rbegin();
    reverse_iterator rend();
    const_reverse_iterator crbegin() const;
    const_reverse_iterator crend() const;

    int getNumPiecesInColumn(int col) const;
    bool canAddPieceTo(int col) const;
    bool isColInBounds(int col) const;
    bool isInBounds(int row, int col) const;
    bool columnIsFull(int col) const;

    void addPiece(char piece, int col);
    const char& at(int row, int col) const;
    char& at(int row, int col);

    bool isFull() const;
    int getRowLastPiecePlayedFellIn() const;

   private:
    static bool isBetween(int val, int low, int high);

   private:
    std::vector<std::string> boardState;
    std::vector<int> piecesInColumn;
    const char blankChar;
    int rowPieceFellIn;
  };
}

#endif //CONNECTN_BOARD_H
