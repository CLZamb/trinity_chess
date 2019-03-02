#include "board.h"
#include <sstream>

Board::Board() {}
Board::~Board() {
  // Free each array and sub-array
  for (int i = 0; i < 64; ++i)
    delete board[i];
}

void Board::initialize(Player *player1, Player *player2) {
  m_bb._init();
  this->player1 = player1;
  this->player2 = player2;
  createSquareBases();
  createBoardSquares();
  setPiecesOnBoard();
}

void Board::createBoardSquares() {
  createSquareBases();
  char squareColor = 'w';

  int position = 0;
  // need to be ordered upside down
  for (int row = 7; row >= 0; --row) {
    for (int col = 0; col < 8; ++col) {
      position = row * 8 + col;
      if (squareColor == 'b') {
        squareColor = 'w';
        board[position] = new Square(&wSquare, false, position);
      } else {
        squareColor = 'b';
        board[position] = new Square(&bSquare, true, position);
      }
    }
    squareColor = squareColor == 'b' ? 'w' : 'b';
  }
}

void Board::setPiecesOnBoard() {
  std::vector<std::pair<std::string, int>> piecesSeq = {
      // player2 pieces - pieces color "black"
      {"rook", A8}, {"knight", B8}, {"bishop", C8}, {"queen", D8},
      {"king", E8}, {"bishop", F8}, {"knight", G8}, {"rook", H8},
      {"pawn", A7}, {"pawn", B7}, {"pawn", C7}, {"pawn", D7},
      {"pawn", E7}, {"pawn", F7}, {"pawn", G7}, {"pawn", H7},
      //
      {"pawn", A2}, {"pawn", B2}, {"pawn", C2}, {"pawn", D2},
      {"pawn", E2}, {"pawn", F2}, {"pawn", G2}, {"pawn", H2},
      {"rook", A1}, {"knight", B1}, {"bishop", C1}, {"queen", D1},
      {"king", E1}, {"bishop", F1}, {"knight", G1}, {"rook", H1},
      // player1 pieces - pieces color "white"
     };

  for (int p2 = 0, p1 = 16; p2 < 16 && p1 < 32; p2++, p1++) {
    addToBoard(piecesSeq[p2].first, piecesSeq[p2].second, "black");
    addToBoard(piecesSeq[p1].first, piecesSeq[p1].second, "white");
  }
}

void Board::addToBoard(string type, int position, string color) {
  Piece *piece = nullptr;
  if (type == "pawn")
    piece = color == "black"? &m_bb.blackPawn : &m_bb.whitePawn;
  else if (type == "rook")
    piece = color == "black"? &m_bb.blackRook : &m_bb.whiteRook;
  else if (type == "queen")
    piece = color == "black"? &m_bb.blackQueen : &m_bb.whiteQueen;
  else if (type == "king")
    piece = color == "black"? &m_bb.blackKing : &m_bb.whiteKing;
  else if (type == "bishop")
    piece = color == "black"? &m_bb.blackBishop : &m_bb.whiteBishop;
  else if (type == "knight")
    piece = color == "black"? &m_bb.blackKnigth : &m_bb.whiteKnigth;
  else
    std::cout << "Piece " << type << " not created" << std::endl;

  getSquareAtPos(position)->setPiece(piece);
}

Piece *Board::getPieceAtPos(int pos) {
  if (!getSquareAtPos(pos))
    return nullptr;

  return getSquareAtPos(pos)->getPiece();
}

Board::Square *Board::getSquareAtPos(int pos) { return board[pos]; }

void Board::createSquareBases() {
  int sizeBox = sizeof(char[box::charsSize]);
  for (int i = 0; i < box::rowSize; ++i) {
    snprintf(wSquare.content[i], sizeBox, "%s", "░░░░░░░░░");
    snprintf(bSquare.content[i], sizeBox, "%s", "█████████");
  }
}

bool Board::isPieceAt(int pos) { return getSquareAtPos(pos)->hasPiece(); }

std::string toString(std::ostream &str) {
  std::ostringstream ss;
  ss << str.rdbuf();
  return ss.str();
}

void Board::print() {
  char squareColor = 'w';
  // TODO(me) make an impovement in the array
  // example obtain the bitboard as
  // pieces["blackPawns",  'b');

  system(CLEAR);
  std::stringstream os;
  os << " ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
        "━━━━┓"
     << endl;

  // need to be print upside down so that the bottom begins at row 0
  for (int row = 7; row >= 0; --row) {
    for (int k = 0; k < box::rowSize; ++k) {
      // left border
      if ((((k + 1) % 3)) == 0)
        os << row + 1 << "┃";
      else
        os << ' ' << "┃";
      for (int col = 0; col < 8; col++) {
        os << board[(row * 8) + col]->getContent(k);
      }
      // right border
      os << "┃" << '\n';
    }
  }

  os << " ┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
        "━━"
        "━━━━┃"
     << endl;
  os << " ┃    A        B        C        D        E        F        G       "
        "H "
        "    ┃"
     << endl;
  os << " ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
        "━━"
        "━━━━┛"
     << endl;

  cout << toString(os);
}

// U64 Board::getPiecesBB(int pieceType) { return m_bb.getPiecesBB(pieceType); }
U64 Board::getPieceAttacks(Piece *piece, SquareIndices from) {
  return m_bb.getPieceAttacks(piece, from);
}

U64 Board::getNonAttackMoves(Piece *piece, SquareIndices from) {
  return m_bb.getNonAttackMoves(piece, from);
}

void Board::make_move(Piece* p, int from, int to) {
  if (!p)
    return;

  getSquareAtPos(from)->clearSquare();
  getSquareAtPos(to)->setPiece(p);
  m_bb.move(p, from, to);
}

void Board::capture_piece(Piece* p, int pos) {
  m_bb.capture_piece(p, pos);
}

std::string Board::get_str_type(int type) {
  switch (type) {
    case wP:
    case bP:
      return "pawn";
    case wR:
    case bR:
      return "rook";
    case wN:
    case bN:
      return "knight";
    case wB:
    case bB:
      return "bishop";
    case wQ:
    case bQ:
      return "queen";
    case wK:
    case bK:
      return "king";
    default:
      break;
  }
}

void Board::undo_move(int pieceType, int pos) {
  std::string color;
  std::string type = get_str_type(pieceType);

  if (pieceType > 0 && pieceType < 7) {
    color = "black";
    m_bb.setBitAtBlackPieces(pos);
  } else {
    color = "white";
    m_bb.setBitAtWhitePieces(pos);
  }

  addToBoard(type, pos, color);
  Piece* piece = getSquareAtPos(pos)->getPiece();
  piece->setBit(pos);
  m_bb.add_value(piece->getValue());
}

Board::Square::Square(box *baseDrawing, bool blackBox, int pos)
    : pBaseDrawing(baseDrawing), pCurrentDrawing(baseDrawing), squarePos(pos),
      blackBox(blackBox) {}

Board::Square::~Square() {}

void Board::Square::setPiece(Piece *piece) {
  occupied = true;
  this->pPiece = piece;

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
char* Board::Square::getContent(int i) { return pCurrentDrawing->content[i]; }
