#include "board_fen_info.h"
#include "utils/string_utils.h"

BoardFenInfo::BoardFenInfo(Board& b) : m_board(b) {}

void BoardFenInfo::update_turn(const PlayerInfo & p_info) {
  side_turn = (p_info.color == BLACK) ? 'b' : 'w';
}

Piecetype BoardFenInfo::get_piece_at_square(const size_t &pos) {
  return m_board.get_piece_at_square(pos);
}

void BoardFenInfo::clear() {
  m_board.clear();
}

void BoardFenInfo::set_piece_at_square(const SquareIndices &i, const Piecetype& p) {
  m_board.set_piece_at_square(i, p);
}

void BoardFenInfo::set_castle_permission(CastlePermission perm) {
  m_board.set_castle_permission(perm);
}

void BoardFenInfo::set_en_passant_square(SquareIndices sq) {
  m_board.set_en_passant_square(sq);
}

const int &BoardFenInfo::get_castle_permission()  {
  return m_board.get_castle_permission();
}

const SquareIndices &BoardFenInfo::get_en_passant_square() {
  return m_board.get_en_passant_square();
}

string BoardFenInfo::get_half_moves() { 
  return std::to_string(m_board.get_half_moves());
}
string BoardFenInfo::get_full_moves() { 
  return std::to_string(m_board.get_full_moves());
}

char BoardFenInfo::get_side_turn() { 
  return side_turn;
}

string BoardFenInfo::get_castling_rights_string() {
  int castle_perm = get_castle_permission();
  return string_utils::get_permission_str_from_castle_permission(castle_perm);
}

string BoardFenInfo::get_en_passant_square_string() {
  string position =
    string_utils::squareindex_to_str(get_en_passant_square());

  if ("-not a valid position-" == position)
    return "-";

  return position;
}
