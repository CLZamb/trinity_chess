#include "headers/board.h"

Board::Board(){
  // parser_fen("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");
}

Board::~Board() {
  // Free each array and sub-array
  for (int i = 0; i < 64; ++i)
    delete p_squares[i];
}

void Board::_init() {
  m_bdrawing._init();
  create_board_squares();
  parser_fen("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");
}

bool Board::is_checkmate() {
  return checkmate;
}

bool Board::is_legal_move(std::shared_ptr<Player> turn, Move& m) {
  if (!exist_piece_at_square(m.get_from())) return false;

  if (check_piece_belongs_to_current_player(turn, m.get_from())) return false; 

  if (is_attack_move(turn, m.get_to())) {
    return is_legal_attack_move(m);
  }

  return is_legal_non_attack_move(m);
}

bool Board::exist_piece_at_square(const int& pos) {
  if (get_piece_at_square(pos)) return true ;
  return false;
}

bool Board::is_attack_move(std::shared_ptr<Player> turn, const int& pos) {
  if (check_captured_belongs_to_opponent_player(turn, pos)) 
    return true;

  return false;
}
bool Board::is_legal_non_attack_move(Move& m) {
  Piece* piece = get_piece_at_square(m.get_from());
  return piece->is_legal_non_attack_move(m, board_state);
}

bool Board::is_legal_attack_move(Move& m){
  Piece* piece = get_piece_at_square(m.get_from());
  Piece* captured = get_piece_at_square(m.get_to());
  m.set_capture_piece(captured->get_type_and_color());
  return piece->is_legal_attack_move(m, board_state);
}

bool Board::check_piece_belongs_to_current_player(std::shared_ptr<Player> turn, const int& pos) {
  Piece* piece = get_piece_at_square(pos);
  if (!piece) return false;
  return piece->is_black() != turn->has_black_pieces();
}

bool Board::check_captured_belongs_to_opponent_player(std::shared_ptr<Player> turn, const int& pos) {
  Piece* captured = get_piece_at_square(pos);
  if (!captured) return false;

  return captured->is_black() == turn->get_opponent()->has_black_pieces();
}

void Board::make_move(Move mv) {
  SquareIndices from = mv.get_from();
  SquareIndices to = mv.get_to();
  Piece* piece = get_piece_at_square(from);
  board_state.move(piece->is_black(),from , to);

  move_piece_to_square(piece, from, to);
}

void
Board::move_piece_to_square(Piece* pc, SquareIndices from, SquareIndices to) {
  if (!pc || !get_square_at_pos(from) || !get_square_at_pos(to))
    return;

  get_square_at_pos(from)->clear_square();
  get_square_at_pos(to)->set_piece(pc);
}

Piece* Board::get_piece_at_square(int pos) {
  Square* square = get_square_at_pos(pos);

  if (!square)
    return nullptr;

  return square->get_piece();
}

void Board::create_board_squares() {
  create_empty_squares_drawing();
  char squareColor = 'w';
  bool is_black_box = true;

  int position = 0;
  /* 
   * Rows needs to be ordered upside down
   * because the program prints from top to bottom
   * so that 8 should be printed frist
  */
  for (int row = 7; row >= 0; --row) {
    for (int col = 0; col < 8; ++col) {
      /*
       * there are 8*8 (from 0 to 63) squares
       * to get the position 
       * we need to multyply rwo by 8 and add the col
       * i.e the bottom right position would be  
       * 8 * 0 + 7 = 7
       * */
      position = row * 8 + col;
      if (squareColor == 'b') {
        squareColor = 'w';
        p_squares[position] = new Square(&wSquare, !is_black_box);
      } else {
        squareColor = 'b';
        p_squares[position] = new Square(&bSquare, is_black_box);
      }
    }
    squareColor = squareColor == 'b' ? 'w' : 'b';
  }
}

void Board::create_empty_squares_drawing() {
  wSquare = *Drawing("BaseWhiteSquare").get_drawing();
  bSquare = *Drawing("BaseBlackSquare").get_drawing();
}

void Board::parser_fen(string fen) {
  SquareIndices square = A1;
  int rank = 7;
  int file = 0;
  int piece;

  for (const char& c : fen) {
    piece = utils::get_square_index_from_char_key(c);
    if (piece) {
      square = static_cast<SquareIndices>(rank * 8 + file);
      // m_bb.set_piece_at_pos(piece, square);
      add_to_board(piece, square);
      file++;

    } else if (is_number(c)) {
      file += (c - '0');

    } else if (c == '/') {
      rank--;
      file = 0;
    }

    if (rank < 0) break;
  }
}

void Board::add_to_board(int type, SquareIndices position) {
  get_square_at_pos(position)->set_piece(m_pieces.get_piece(type));
}

bool Board::is_number(char c) {
  return c >= '0' && c <= '8';
}

Square* Board::get_square_at_pos(int pos) { return p_squares[pos]; }


Displayable* Board::get_drawing() {
  return &m_bdrawing;
}
