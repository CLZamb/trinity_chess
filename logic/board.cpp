#include "board.h"
#include <sstream>

Board::Board() {
  // pieces_start_pos = "rnbqkbnr/pp1ppppp/8/2p5/4P3/8/PPPP1PPP/RNBQKBNR w KQkq c6 0 2";
}

Board::~Board() {
  // Free each array and sub-array
  for (int i = 0; i < 64; ++i)
    delete p_board[i];
}

void Board::_init() {
  m_bb._init();
  create_board_squares();
  parser_fen(pieces_start_pos);
}

void Board::set_players(Player* player1, Player* player2) {
  this->player1 = player1;
  this->player2 = player2;
}

void Board::create_board_squares() {
  create_squares_drawing();
  char squareColor = 'w';

  int position = 0;
  // need to be ordered upside down
  for (int row = 7; row >= 0; --row) {
    for (int col = 0; col < 8; ++col) {
      position = row * 8 + col;
      if (squareColor == 'b') {
        p_board[position] = new Square(&bSquare, true);
        squareColor = 'w';
      } else {
        p_board[position] = new Square(&wSquare, false);
        squareColor = 'b';
      }
    }
    squareColor = (squareColor == 'b') ? 'w' : 'b';
  }
}

void Board::create_squares_drawing() {
  wSquare = *PieceDrawing("BaseWhiteSquare").get_drawing();
  bSquare = *PieceDrawing("BaseBlackSquare").get_drawing();
}

void Board::parser_fen(string fen) {
  char char_piece = ' ';
  int square = A1;
  int piece_int;
  static std::map <char, int> piece_map = {
    {'P', bP}, {'R', bR}, {'N', bN}, {'B', bB}, {'Q', bQ}, {'K', bK},
    {'p', wP}, {'r', wR}, {'n', wN}, {'b', wB}, {'q', wQ}, {'k', wK},
  };

  m_bb.reset_all_pieces_bitboard();
  for (unsigned int i = 0; i < fen.length() && square < SquareEnd; ++i) {
    char_piece = fen[i];
    piece_int = piece_map[char_piece];
    if (piece_int) {
      m_bb.set_piece_at_pos(piece_int, square);
      add_to_board(piece_int, square++);

    } else if (is_number(char_piece)) {
      square += (char_piece - '0');
    }
  }
}

bool Board::is_number(char c) {
  return c >= '0' && c <= '8';
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
  os << " ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
  // need to be print upside down so that the bottom begins at row 0
  for (int row = 7; row >= 0; --row) {
    for (int k = 0; k < box::kRowSize; ++k) {
      // left border
      if (!((k + 1) % 3))
        os << row + 1 << "┃";
      else
        os << ' ' << "┃";

      for (int col = 0; col < 8; col++) {
        os << p_board[(row * 8) + col]->at(k);
      }
      // right border
      os << "┃" << '\n';
    }
  }

  os << " ┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃" << endl;
  os << " ┃    A        B        C        D        E        F        G       H     ┃" << endl;
  os << " ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;

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

void Board::capture_piece(int piece_captured, int pos) {
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
      m_is_black_square(blackBox) {}

Board::Square::~Square() {}

void Board::Square::set_piece(Piece* piece) {
  this->p_piece = piece;
  p_cur_drawing = piece->get_drawing(m_is_black_square);
}

void Board::Square::clear_square() {
  p_cur_drawing = p_base_drawing;
  p_piece = nullptr;
}

box* Board::Square::get_current_drawing() { return p_cur_drawing; }
Piece* Board::Square::get_piece() { return this->p_piece; }
bool Board::Square::is_black_square() { return m_is_black_square; }
char* Board::Square::at(int i) { return p_cur_drawing->content[i]; }
