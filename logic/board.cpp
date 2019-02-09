#include "board.h"

Board::Board() {}
Board::~Board() {
  // Free each array and sub-array
  for (int i = 0; i < 8; ++i)
    for (int j = 0; j < 8; ++j)
      delete board[i][j];
}

void Board::initialize(Player *player1, Player *player2) {
  this->player1 = player1;
  this->player2 = player2;
  createBoardSquares();
  setPiecesOnBoard();
}

void Board::createBoardSquares() {
  createSquareBases();
  char squareColor = 'w';

  // need to be ordered upside down
  for (int row = 7; row >= 0; --row) {
    for (int col = 0; col < 8; ++col) {
      if (squareColor == 'b') {
        squareColor = 'w';
        board[row][col] = new Square(&wSquare, false, Position(row, col));
      } else {
        squareColor = 'b';
        board[row][col] = new Square(&bSquare, true, Position(row, col));
      }
    }
    squareColor = squareColor == 'b' ? 'w' : 'b';
  }
}

void Board::setPiecesOnBoard() {
  std::vector<std::pair<std::string, std::string>> piecesSeq = {
      // player2 pieces - pieces color "black"
      {"rook", "a8"}, {"knight", "b8"}, {"bishop", "c8"}, {"queen", "d8"},
      {"king", "e8"}, {"bishop", "f8"}, {"knight", "g8"}, {"rook", "h8"},
      {"pawn", "a7"}, {"pawn", "b7"},   {"pawn", "c7"},   {"pawn", "d7"},
      {"pawn", "e7"}, {"pawn", "f7"},   {"pawn", "g7"},   {"pawn", "h7"},

      {"pawn", "a2"}, {"pawn", "b2"},   {"pawn", "c2"},   {"pawn", "d2"},
      {"pawn", "e2"}, {"pawn", "f2"},   {"pawn", "g2"},   {"pawn", "h2"},
      {"rook", "a1"}, {"knight", "b1"}, {"bishop", "c1"}, {"queen", "d1"},
      {"king", "e1"}, {"bishop", "f1"}, {"knight", "g1"}, {"rook", "h1"},
      // player1 pieces - pieces color "white"
  };

  for (int p2 = 0, p1 = 16; p2 < 16 && p1 < 32; p2++, p1++) {
    addToBoard(piecesSeq[p2].first, piecesSeq[p2].second, "black");
    addToBoard(piecesSeq[p1].first, piecesSeq[p1].second, "white");
  }

  player1->setPieces(piecefactory.getPieces("white"));
  player2->setPieces(piecefactory.getPieces("black"));
}

void Board::addToBoard(string type, string position, string color) {
  Position pos(position);
  setPieceAtPos(piecefactory.createPiece(type, color, pos), pos);
}

Piece *Board::getPieceAtPos(Position pos) {
  return getSquareAtPos(pos)->getPiece();
}

void Board::setPieceAtPos(Piece *piece, Position pos) {
  if (!piece)
    return;
  getSquareAtPos(pos)->setPiece(piece);
}

Board::Square *Board::getSquareAtPos(Position pos) {
  unsigned int row = pos.getPositionRow(), col = pos.getPositionColumn();
  return board[row][col];
}

void Board::clearSquareAt(Position pos) { getSquareAtPos(pos)->clearSquare(); }

void Board::createSquareBases() {
  int sizeBox = sizeof(char[box::charsSize]);
  for (int i = 0; i < box::rowSize; ++i) {
    snprintf(wSquare.content[i], sizeBox, "%s", "░░░░░░░░░");
    snprintf(bSquare.content[i], sizeBox, "%s", "█████████");
  }
}

bool Board::isPieceAt(Position pos) { return getSquareAtPos(pos)->hasPiece(); }

void Board::print() {
  system(CLEAR);
  cout << " ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
          "━━"
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

  cout << " ┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
          "━━"
          "━━━━━━┃"
       << endl;
  cout << " ┃    A        B        C        D        E        F        G     "
          "  "
          " H    ┃"
       << endl;
  cout << " ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
          "━━━━━━━━━━━┛"
       << endl;
}

Board::Square::Square(box *baseDrawing, bool blackBox, Position pos)
    : pBaseDrawing(baseDrawing), pCurrentDrawing(baseDrawing), squarePos(pos),
      blackBox(blackBox) {}

Board::Square::~Square() {}

void Board::Square::setPiece(Piece *piece) {
  occupied = true;
  Position pos = squarePos;
  this->pPiece = piece;
  this->pPiece->setPosition(squarePos);

  if (blackBox)
    pCurrentDrawing = pPiece->getDrawingBSquare();
  else
    pCurrentDrawing = pPiece->getDrawingWSquare();
}

void Board::Square::clearSquare() {
  pCurrentDrawing = pBaseDrawing;
  occupied = false;
  pPiece = nullptr;
}

box *Board::Square::getCurrentDrawing() { return pCurrentDrawing; }
Piece *Board::Square::getPiece() { return this->pPiece; }
bool Board::Square::isBlackBox() { return blackBox; }
