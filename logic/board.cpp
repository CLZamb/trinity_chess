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
  // Input input;
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
  int firstRow = 0, secondRow = 1, seventhRow = 6, eightRow = 7;
  string piecesSeq[8] = {"rook", "knight", "bishop", "queen",
                         "king", "bishop", "knight", "rook"};
  for (int i = 0; i < 8; ++i) {
    setPieceAtPos(createPiece(piecesSeq[i], player1), Position(i, eightRow));
    setPieceAtPos(createPiece("pawn", player1), Position(i, seventhRow));

    setPieceAtPos(createPiece("pawn", player2), Position(i, secondRow));
    setPieceAtPos(createPiece(piecesSeq[i], player2), Position(i, firstRow));
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

Piece *Board::createPiece(std::string pieceType, Player *player) {
  Piece *piece = nullptr;

  if (pieceType == "pawn")
    piece = new Pawn(player);
  else if (pieceType == "rook")
    piece = new Rook(player);
  else if (pieceType == "queen")
    piece = new Queen(player);
  else if (pieceType == "king")
    piece = new King(player);
  else if (pieceType == "bishop")
    piece = new Bishop(player);
  else if (pieceType == "knight")
    piece = new Knight(player);
  else
    std::cout << "Piece " << pieceType << " not created" << std::endl;

  return piece;
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
  // before exiting print lower border
  cout << " ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
          "━━━━━━┓"
       << endl;

  // need to be ordered upside down so that the bottom begins at row 0
  for (int row = 7; row >= 0; --row) {
    for (int k = 0; k < box::rowSize; ++k) {
      //  print left border
      if (((k + 1) % 3) == 0)
        // print row number
        std::cout << row + 1 << "┃";
      else
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

void Board::saveCapturedPiece(Piece *capturedPiece) {
  capturedPieces.push_back(capturedPiece);
}
