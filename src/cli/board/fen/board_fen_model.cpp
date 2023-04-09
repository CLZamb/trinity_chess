#include "board_fen_model.h"
#include "utils/string_utils.h"

BoardFenModel::BoardFenModel(Board& b) : m_board(b) {}

Piecetype BoardFenModel::get_piece_at_square(const size_t &pos) {
  return m_board.get_piece_at_square(pos);
}

void BoardFenModel::clear() {
  m_board.clear();
}

void BoardFenModel::set_piece_at_square(const SquareIndices &i, const Piecetype& p) {
  m_board.set_piece_at_square(i, p);
}

void BoardFenModel::set_castle_permission(CastlePermission perm) {
  m_board.set_castle_permission(perm);
}

void BoardFenModel::set_en_passant_square(SquareIndices sq) {
  m_board.set_en_passant_square(sq);
}

const int &BoardFenModel::get_castle_permission()  {
  return m_board.get_castle_permission();
}

const SquareIndices &BoardFenModel::get_en_passant_square() {
  return m_board.get_en_passant_square();
}

string BoardFenModel::get_half_moves() { 
  return std::to_string(m_board.get_half_moves());
}

string BoardFenModel::get_full_moves() { 

  return std::to_string(m_board.get_full_moves());
}

char BoardFenModel::get_side_turn() { 
  return side_turn;
}

void BoardFenModel::set_side_turn(const char& c) { 
  side_turn = c;
}

string BoardFenModel::get_castling_rights_string() {
  int castle_perm = get_castle_permission();
  return string_utils::get_permission_str_from_castle_permission(castle_perm);
}

string BoardFenModel::get_en_passant_square_string() {
  string position =
    string_utils::squareindex_to_str(get_en_passant_square());

  if ("-not a valid position-" == position)
    return "-";

  return position;
}
