#include "board.h"
#include <sstream>

Board::Board() {}
Board::~Board() {
  // Free each array and sub-array
  for (int i = 0; i < 64; ++i)
    delete p_board[i];
}

void Board::_init(Player* player1, Player* player2) {
  m_bb._init();
  this->player1 = player1;
  this->player2 = player2;
  create_board_squares();
  set_pieces_on_board();
}

void Board::create_board_squares() {
  create_square_bases();
  char squareColor = 'w';

  int position = 0;
  // need to be ordered upside down
  for (int row = 7; row >= 0; --row) {
    for (int col = 0; col < 8; ++col) {
      position = row * 8 + col;
      if (squareColor == 'b') {
        squareColor = 'w';
        p_board[position] = new Square(&wSquare, false);
      } else {
        squareColor = 'b';
        p_board[position] = new Square(&bSquare, true);
      }
    }
    squareColor = squareColor == 'b' ? 'w' : 'b';
  }
}

void Board::set_pieces_on_board() {
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
    add_to_board(piecesSeq[p2].first, piecesSeq[p2].second, "black");
    add_to_board(piecesSeq[p1].first, piecesSeq[p1].second, "white");
  }
}

void Board::add_to_board(string type, int position, string color) {
  Piece* piece = nullptr;
  if (type == "pawn")
    piece = color == "black"? &m_bb.m_b_pawn : &m_bb.m_w_pawn;
  else if (type == "rook")
    piece = color == "black"? &m_bb.m_b_rook : &m_bb.m_w_rook;
  else if (type == "queen")
    piece = color == "black"? &m_bb.m_b_queen : &m_bb.m_w_queen;
  else if (type == "king")
    piece = color == "black"? &m_bb.m_b_king : &m_bb.m_w_king;
  else if (type == "bishop")
    piece = color == "black"? &m_bb.m_b_bishop : &m_bb.m_w_bishop;
  else if (type == "knight")
    piece = color == "black"? &m_bb.m_b_knigth : &m_bb.m_w_knigth;
  else
    std::cout << "Piece " << type << " not created" << std::endl;

  get_square_at_pos(position)->set_piece(piece);
}

Piece* Board::get_piece_at_pos(int pos) {
  if (!get_square_at_pos(pos))
    return nullptr;

  return get_square_at_pos(pos)->get_piece();
}

Board::Square* Board::get_square_at_pos(int pos) { return p_board[pos]; }

void Board::create_square_bases() {
  int sizeBox = sizeof(char[box::char_size]);
  for (int i = 0; i < box::row_size; ++i) {
    snprintf(wSquare.content[i], sizeBox, "%s", "░░░░░░░░░");
    snprintf(bSquare.content[i], sizeBox, "%s", "█████████");
  }
}

std::string toString(std::ostream &str) {
  std::ostringstream ss;
  ss << str.rdbuf();
  return ss.str();
}

void Board::print() {
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
    for (int k = 0; k < box::row_size; ++k) {
      // left border
      if ((((k + 1) % 3)) == 0)
        os << row + 1 << "┃";
      else
        os << ' ' << "┃";
      for (int col = 0; col < 8; col++) {
        os << p_board[(row * 8) + col]->get_content(k);
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
U64 Board::get_piece_attacks(Piece* piece, int from) {
  return m_bb.get_piece_attacks(piece, SquareIndices(from));
}

U64 Board::get_non_attack_moves(Piece* piece, int from) {
  return m_bb.get_non_attack_moves(piece, SquareIndices(from));
}

void Board::make_move(Piece* p, int from, int to) {
  if (!p)
    return;

  get_square_at_pos(from)->clear_square();
  get_square_at_pos(to)->set_piece(p);
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
      return "";
      break;
  }
}

void Board::undo_move(int pieceType, int pos) {
  std::string color;
  std::string type = get_str_type(pieceType);

  if (pieceType > 0 && pieceType < 7) {
    color = "black";
    m_bb.set_bit_at_b_pieces(pos);
  } else {
    color = "white";
    m_bb.set_bit_at_w_pieces(pos);
  }

  add_to_board(type, pos, color);
  Piece* piece = get_square_at_pos(pos)->get_piece();
  piece->set_bit(pos);
  m_bb.add_value(piece->get_value());
}

U64 Board::get_own_pieces_occ(bool is_black) {
  if (is_black)
    return m_bb.m_all_b_pieces;

  return  m_bb.m_all_w_pieces;
}

U64 Board::get_all_w_pieces() { return m_bb.m_all_w_pieces; }
U64 Board::get_all_b_pieces() { return m_bb.m_all_b_pieces; }
void Board::generate_all_moves(bool side, MoveList* moveList) {
  return m_bb.generate_all_moves(side, moveList);
}

int Board::get_board_score() { return m_bb.evaluate_board(); }

Board::Square::Square(box* baseDrawing, bool blackBox)
    : p_base_drawing(baseDrawing), p_cur_drawing(baseDrawing),
      m_black_box(blackBox) {}

Board::Square::~Square() {}

void Board::Square::set_piece(Piece* piece) {
  m_occupied = true;
  this->p_piece = piece;
  p_cur_drawing = m_black_box ?
    p_piece->get_drawing_B_square() : p_piece->get_drawing_W_square();
}

void Board::Square::clear_square() {
  p_cur_drawing = p_base_drawing;
  m_occupied = false;
  p_piece = nullptr;
}

box* Board::Square::get_current_drawing() { return p_cur_drawing; }
Piece* Board::Square::get_piece() { return this->p_piece; }
bool Board::Square::is_black_box() { return m_black_box; }
bool Board::Square::has_piece() { return m_occupied; }
char* Board::Square::get_content(int i) { return p_cur_drawing->content[i]; }
