#include "board.h"

Board::Board() {
  // pieces_start_pos = " rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR b KQkq e3 1 1";
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
  movement_controller._init(turn->has_black_pieces());
}

void Board::set_players(Player* player1, Player* player2) {
  this->player1 = player1;
  this->player2 = player2;
  this->turn = player1;
}

void Board::undo_square_move(int piece, int piece_captured, int from, int to) {
  move_squares(m_bb.get_piece(piece), from, to);

  if (piece_captured)
    add_to_board(piece_captured, from);
}

void Board::move_piece_to_square(int piece, int from, int to) {
  move_squares(m_bb.get_piece(piece), from, to);
  move_piece_bits(piece, from, to);
}

void Board::move_squares(Piece* piece, int from, int to) {
  if (!piece || !get_square_at_pos(from) || !get_square_at_pos(to))
    return;

  get_square_at_pos(from)->clear_square();
  get_square_at_pos(to)->set_piece(piece);
}

Piece* Board::get_piece_at_square(int pos) {
  if (!get_square_at_pos(pos))
    return nullptr;

  return get_square_at_pos(pos)->get_piece();
}

PlayerMove Board::get_next_move() { return turn->get_next_move(); }
Player* Board::active_player() {  return turn; }

std::ostream& operator<<(std::ostream& os, const Board& board) {
  system(CLEAR);
  int counter = 0;
  int size = sizeof(Drawing::player1)/sizeof(Drawing::player1[0]);
  os << " ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
  // need to be print upside down so that the bottom begins at row 0
  // for each board row
  for (int row = 7; row >= 0; --row) {
    // for each box row
    for (int k = 0; k < box::kRowSize; ++k) {
      // left border
      if ((k + 1) % 3)
        os << ' ';
      else
        os << row + 1;

      os << "┃";
      // for each board column
      for (int col = 0; col < 8; col++) {
        os << board.p_board[(row * 8) + col]->at(k);
      }
      os << "┃";
      // right border
      // score
      if (counter < size)
        os << Drawing::player1[counter++];

      os << "\n";
    }
  }
  os
    << " ┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃\n"
    << " ┃    A        B        C        D        E        F        G       H     ┃\n"
    << " ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
  return os;
}

Board::Square* Board::get_square_at_pos(int pos) { return p_board[pos]; }

void Board::create_board_squares() {
  create_squares_drawing();
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

void Board::add_to_board(int type, int position) {
  get_square_at_pos(position)->set_piece(m_bb.get_piece(type));
}

bool Board::is_number(char c) {
  return c >= '0' && c <= '8';
}

void Board::undo_last_move() {
  movement_controller.undo_last_move();
}

void Board::move_piece(Move mv) {
  movement_controller.move_piece(mv);
}

bool Board::is_valid_move(Move mv) {
  return movement_controller.is_valid_move(mv);
}

bool Board::get_checkmate() {
  return movement_controller.get_checkmate();
}

Movement* Board::get_movement() {
  return &movement_controller;
}

void Board::generate_all_moves(bool side, MoveList* moveList) {
  return m_bb.generate_all_moves(side, moveList);
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

void Board::undo_move(int piece, int piece_captured, int from, int to) {
  m_bb.undo_move(piece, piece_captured, from, to);
}

U64 Board::get_piece_attacks(int type, int from) {
  return m_bb.get_piece_attacks(type, SquareIndices(from));
}

U64 Board::get_non_attack_moves(int type, int from) {
  return m_bb.get_non_attack_moves(type, SquareIndices(from));
}

U64 Board::get_own_pieces_occ(bool is_black) {
  if (is_black) return m_bb.get_all_b_bitboard();

  return  m_bb.get_all_w_bitboard();
}

U64 Board::get_all_pieces_bitboard() const {
  return m_bb.get_all_pieces_bitboard();
}

U64 Board::get_piece_bitboard(int piece) const {
  return m_bb.get_piece_bitboard(piece);
}

int Board::get_piece_at(int pos) {
  return m_bb.get_piece_at_pos(pos);
}

int Board::evaluate_board() { return m_bb.evaluate_board(); }

// Board::Square
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

char* Board::Square::at(int i) { return p_cur_drawing->content[i]; }
bool Board::Square::is_black_square() { return m_is_black_square; }

Piece* Board::Square::get_piece() { return this->p_piece; }
box* Board::Square::get_current_drawing() { return p_cur_drawing; }
