#include "board.h"

Board::Board() {}
Board::~Board() {
  // Free each array and sub-array
  for (int i = 0; i < 8; ++i)
    for (int j = 0; j < 8; ++j)
      delete board[i][j];

  for (Piece *iter : capturedPieces)
    delete iter;
  capturedPieces.clear();

  std::cout << "~Board() is executed";
}

void Board::initialize(Player *player1, Player *player2) {
  this->player1 = player1;
  this->player2 = player2;
  createBoardSquares();
  setPiecesOnBoard();
}

void Board::createBoardSquares() {
  createSquareBases();
  char boxColor = 'w';

  // need to be ordered upside down
  for (int row = 7; row >= 0; --row) {
    for (int col = 0; col < 8; ++col) {
      if (boxColor == 'b') {
        boxColor = 'w';
        board[row][col] = new Square(&wBox, false, Position(row, col));
      } else {
        boxColor = 'b';
        board[row][col] = new Square(&bBox, true, Position(row, col));
      }
    }
    boxColor = boxColor == 'b' ? 'w' : 'b';
  }
}

void Board::setPiecesOnBoard() {
  PieceFactory piecefactory;

  char columns[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
  string piecesSeq[8] = {"rook", "knight", "bishop", "queen",
                         "king", "bishop", "knight", "rook"};

  for (int i = 0; i < 8; ++i) {
    setPieceAtPos(piecefactory.createPiece(piecesSeq[i], player2),
                  Position(columns[i], '8'));
    setPieceAtPos(piecefactory.createPiece("pawn", player2),
                  Position(columns[i], '7'));

    setPieceAtPos(piecefactory.createPiece("pawn", player1),
                  Position(columns[i], '2'));
    setPieceAtPos(piecefactory.createPiece(piecesSeq[i], player1),
                  Position(columns[i], '1'));
  }
}

bool Board::isValidPosition(Position pos) {
  return (pos.getPositionX() >= 0) && (pos.getPositionX() < 8) &&
         (pos.getPositionY() >= 0) && (pos.getPositionY() < 8);
}

Piece *Board::getPieceAtPos(Position pos) {
  return getSquareAtPos(pos)->getPiece();
}

void Board::setPieceAtPos(Piece *piece, Position pos) {
  getSquareAtPos(pos)->setPiece(piece);
}

void Board::saveCapturedPiece(Piece *capturedPiece) {
  capturedPieces.push_back(capturedPiece);
}

Square *Board::getSquareAtPos(Position pos) {
  unsigned int row = pos.getPositionRow(), col = pos.getPositionColumn();
  return board[row][col];
}

void Board::createSquareBases() {
  int sizeBox = sizeof(char[box::charsSize]);
  for (int i = 0; i < box::rowSize; ++i) {
    snprintf(wBox.content[i], sizeBox, "%s", "░░░░░░░░░");
    snprintf(bBox.content[i], sizeBox, "%s", "█████████");
  }
}

void Board::print() {
  system(CLEAR);
  cout << " ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
          "━━━━━━┓"
       << endl;

  // need to be print upside down so that the bottom begins at row 0
  for (int row = 7; row >= 0; --row) {
    for (int k = 0; k < box::rowSize; ++k) {
      if (((k + 1) % 3) == 0)
        // print row number and left border
        std::cout << row + 1 << "┃";
      else
        //  print left border
        std::cout << ' ' << "┃";

      for (int col = 0; col < 8; ++col)
        std::cout << board[row][col]->getCurrentDrawing()->content[k];

      std::cout << "┃" << '\n';
    }
  }

  cout << " ┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
          "━━━━━━┃"
       << endl;
  cout << " ┃    A        B        C        D        E        F        G       "
          " H    ┃"
       << endl;
  cout << " ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
          "━━━━━━━━━━━┛"
       << endl;
}
