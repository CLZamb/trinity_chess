#include "headers/board.h"

Board::Board(string fen /*"rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR"*/ ) {
  parser_fen(fen);
  m_view.parser_fen(fen);
}

Board::~Board() {}

bool Board::is_checkmate() { return checkmate; }

void Board::update_turn(const PlayerInfo &turn) {
  m_turn_info = turn;
}

bool Board::is_legal_move(Move& m) {
  if (!exist_piece_at_square(m.get_from())) return false;
  if (!check_piece_belongs_to_current_player(m.get_from())) return false; 

  if (is_attack_move(m.get_to())) {
    return is_legal_attack_move(m);
  }

  return is_legal_non_attack_move(m);
}

bool Board::exist_piece_at_square(const int& pos) {
  if (get_piece_at_square(pos)) return true ;
  return false;
}

bool Board::is_attack_move(const int& pos) {
  if (check_captured_belongs_to_opponent_player(pos)) 
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

bool Board::check_piece_belongs_to_current_player(const int& pos) {
  Piece* piece = get_piece_at_square(pos);
  if (!piece) return false;
  return piece->is_black() == (m_turn_info.get_color() == BLACK);
}

bool Board::check_captured_belongs_to_opponent_player(const int& pos) {
  Piece* captured = get_piece_at_square(pos);
  if (!captured) return false;

  return captured->is_black() == (m_turn_info.get_color() != BLACK);
}

void Board::make_move(Move mv) {
  SquareIndices from = mv.get_from();
  SquareIndices to = mv.get_to();
  Piece* piece = get_piece_at_square(from);

  board_state.move(piece->is_black(),from , to);
  move_piece_to_square(piece, from, to);
  save_move(mv);
  update_board_view();
}

void Board::update_board_view() {
  m_view.parser_fen(get_fen());
}

void Board::save_move(const Move &m) {
  m_info.save_move(utils::square_int_to_str(m.get_from()) +
                   utils::square_int_to_str(m.get_to()));
  m_info.save_capture(utils::get_piece_str_name_from_piecetype(m.get_captured_piece()));
}

void
Board::move_piece_to_square(Piece* pc, SquareIndices from, SquareIndices to) {
  if (!pc)
    return;

  get_square_at_pos(from).clear_square();
  get_square_at_pos(to).set_piece(pc);
}

Piece* Board::get_piece_at_square(int pos) {
  return get_square_at_pos(pos).get_piece();
}

void Board::parser_fen(string fen) {
  clear_board();
  SquareIndices square = A1;
  int rank = 7;
  int file = 0;
  Piecetype piece;

  for (const char& c : fen) {
    piece = utils::get_square_index_from_char_key(c);
    if (piece) {
      square = static_cast<SquareIndices>(rank * 8 + file);
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

void Board::clear_board() {
  int pos = 0;
  bool is_black = false;
  for(auto& square: m_squares) {
    square.clear_square();
    board_state.clear_bit_at_player_pieces(is_black, static_cast<SquareIndices>(pos));
    board_state.clear_bit_at_player_pieces(!is_black, static_cast<SquareIndices>(pos));
    pos++;
  }
}

void Board::add_to_board(Piecetype type, SquareIndices position) {
  get_square_at_pos(position).set_piece(m_pieces.get_piece(type));
  board_state.set_bit_at_player_pieces(utils::check::is_black_piece(type), position);
}

bool Board::is_number(char c) {
  return c >= '0' && c <= '8';
}

Square& Board::get_square_at_pos(int pos) { 
  return m_squares[pos]; 
}

string Board::get_fen() {
  string fen;
  return fen;
}

BoardView& Board::get_view() {
  return m_view;
}

BoardInfo& Board::get_info() {
  return m_info;
}
