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
  set_all_pieces_on_board();
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

void Board::create_square_bases() {
  int sizeBox = sizeof(char[box::char_size]);
  for (int i = 0; i < box::row_size; ++i) {
    snprintf(wSquare.content[i], sizeBox, "%s", "░░░░░░░░░");
    snprintf(bSquare.content[i], sizeBox, "%s", "█████████");
  }
}

void Board::set_all_pieces_on_board() {
  std::vector<std::pair<int, int>> piecesSeq = {
    // player2 pieces - pieces color "black"
    {bR, A8}, {bN, B8}, {bB, C8}, {bQ, D8},
    {bK, E8}, {bB, F8}, {bN, G8}, {bR, H8},
    {bP, A7}, {bP, B7}, {bP, C7}, {bP, D7},
    {bP, E7}, {bP, F7}, {bP, G7}, {bP, H7},
    //
    {wP, A2}, {wP, B2}, {wP, C2}, {wP, D2},
    {wP, E2}, {wP, F2}, {wP, G2}, {wP, H2},
    {wR, A1}, {wN, B1}, {wB, C1}, {wQ, D1},
    {wK, E1}, {wB, F1}, {wN, G1}, {wR, H1},
    // player1 pieces - pieces color "white"
  };

  for (int p2 = 0, p1 = 16; p2 < 16 && p1 < 32; p2++, p1++) {
    add_to_board(piecesSeq[p2].first, piecesSeq[p2].second);
    add_to_board(piecesSeq[p1].first, piecesSeq[p1].second);
  }
}

void Board::add_to_board(int type, int position) {
  get_square_at_pos(position)->set_piece(m_bb.get_piece(type));
}

void Board::move_squares(Piece* piece, int from, int to) {
  if (!piece || !get_square_at_pos(from) || !get_square_at_pos(to))
    return;

  get_square_at_pos(from)->clear_square();
  get_square_at_pos(to)->set_piece(piece);
}

Board::Square* Board::get_square_at_pos(int pos) { return p_board[pos]; }

std::string toString(std::ostream &str) {
  std::ostringstream ss;
  ss << str.rdbuf();
  return ss.str();
}

void Board::print() {
  system(CLEAR);
  std::stringstream os;
  os << " ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
        "━━━━┓"
     << endl;

  // need to be print upside down so that the bottom begins at row 0
  for (int row = 7; row >= 0; --row) {
    for (int k = 0; k < box::row_size; ++k) {
      // left border
      if (!((k + 1) % 3))
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

Piece* Board::get_piece_at_square(int pos) {
  if (!get_square_at_pos(pos))
    return nullptr;

  return get_square_at_pos(pos)->get_piece();
}

void Board::move_piece_to_square(int piece, int from, int to) {
  move_squares(m_bb.get_piece(piece), from, to);
  move_piece_bits(piece, from, to);
}

void Board::generate_all_moves(bool side, MoveList* moveList) {
  return m_bb.generate_all_moves(side, moveList);
}

U64 Board::get_all_pieces_bitboard() const {
  return m_bb.get_all_pieces_bitboard();
}

U64 Board::get_piece_attacks(int type, int from) {
  return m_bb.get_piece_attacks(type, SquareIndices(from));
}

U64 Board::get_non_attack_moves(int type, int from) {
  return m_bb.get_non_attack_moves(type, SquareIndices(from));
}

int Board::get_piece_at(int pos) {
  return m_bb.get_piece_at_pos(pos);
}

void Board::move_piece_bits(int piece, int from, int to) {
  m_bb.make_move_bb(piece, from, to);
}

void Board::update_killers(Move mv) {
  m_bb.update_killers(mv);
}

void Board::update_search_history(int piece, int to, int depth) {
  m_bb.update_search_history(piece, to, depth);
}

void Board::capture_piece(int piece, int piece_captured, int pos) {
  m_bb.capture_piece(piece_captured, pos);
}

void Board::undo_square_move(int piece, int piece_captured, int from, int to) {
  move_squares(m_bb.get_piece(piece), from, to);

  if (piece_captured)
    add_to_board(piece_captured, from);
}

void Board::undo_move(int piece, int piece_captured, int from, int to) {
  m_bb.undo_move(piece, piece_captured, from, to);
}

U64 Board::get_own_pieces_occ(bool is_black) {
  if (is_black)
    return m_bb.get_all_b_bitboard();

  return  m_bb.get_all_w_bitboard();
}

int Board::get_board_score() { return m_bb.evaluate_board(); }
U64 Board::get_piece_bitboard(int piece) const {
  return m_bb.get_piece_bitboard(piece);
}

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
char* Board::Square::get_content(int i) { return p_cur_drawing->content[i]; }