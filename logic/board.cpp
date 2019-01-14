#include "board.h"

Board::Board() {}
Board::~Board() {
  // Free each array and sub-array
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      delete board[i][j];
    }
  }

  std::cout << "~Board() is executed";
}

void Board::initialize(Player *player1, Player *player2) {
  this->player1 = player1;
  this->player2 = player2;
  createBoardBoxes();
  setPiecesOnBoard();
}

void Board::createBoardBoxes() {
  createBoxBases();
  // Input input;
  char boxColor = 'w';

  // need to be ordered upside down
  for (int row = 7; row >= 0; --row) {
    for (int col = 0; col < 8; ++col) {
      if (boxColor == 'b') {
        boxColor = 'w';
        board[row][col] = new Box(&wBox, false, Position(row, col));
      } else {
        boxColor = 'b';
        board[row][col] = new Box(&bBox, true, Position(row, col));
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

void Board::movePiece(Position from, Position to) {
  Box *fromBox = getBoxAtPos(from);
  Piece *tempPiece = fromBox->getPiece();

  setPieceAtPos(tempPiece, to);
  fromBox->removePiece();
}

bool Board::isValidPosition(Position pos) {
  return (pos.getPositionX() >= 0) && (pos.getPositionX() < 8) &&
         (pos.getPositionY() >= 0) && (pos.getPositionY() < 8);
}

Piece *Board::getPieceAtPos(Position pos) { getBoxAtPos(pos)->getPiece(); }

void Board::setPieceAtPos(Piece *piece, Position pos) {
  getBoxAtPos(pos)->setPiece(piece);
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


Box *Board::getBoxAtPos(Position pos) {
  unsigned int row = pos.getPositionRow(), col = pos.getPositionColumn();
  // because boxes is a 1d vector we can access by
  // multiplying the row size + 1 time the x(row) plus column
  // i.e accessing (0, 0) should be (0 * 8) + 0 = 0
  // ex: accessing (1, 1) should be (1 * 8) + 1 = 9
  // [  0,  1,  2,  3,  4,  5,  6, 7]
  // [  8,  9, 10, 11, 12, 13, 14, 15]
  // std::cout << (x * 8) + y << std::endl;
  return board[row][col];
}

void Board::createBoxBases() {
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
  cout << " ┃    A        B        C        D       E         F        G       "
          " H    ┃"
       << endl;
  cout << " ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
          "━━━━━━━━━━━┛"
       << endl;
}

bool Board::isValidMove(Player *playerSide, Position from, Position to) {
  Box *fromBox = getBoxAtPos(from);
  Box *destinationBox = getBoxAtPos(to);
  Piece *currentPiece = fromBox->getPiece();

  if (!currentPiece || !currentPiece->getOwner())
    return false;

  if (!isValidPosition(from) || !isValidPosition(to))
    return false;

  if (!fromBox->hasPiece() || destinationBox->hasPiece())
    return false;

  if (!currentPiece->isValidMove(from, to))
    return false;

  if (!(playerSide == currentPiece->getOwner())) {
    std::cout << "wrong player side\n";
    return false;
  }

  return true;
}
