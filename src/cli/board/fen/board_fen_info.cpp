#include "board_fen_info.h"

string BoardFenInfo::get_half_moves() { return str_half_moves; }
string BoardFenInfo::get_full_moves() { return str_full_moves; }
char BoardFenInfo::get_side_turn() { return side_turn; }
void BoardFenInfo::update_fen_current_side_turn_color(Color c) {
  current_side_color = c;
  side_turn = (current_side_color == BLACK) ? 'b' : 'w';
}

void BoardFenInfo::update_str_half_moves(const int& hm) {
  str_half_moves = std::to_string(hm);
}

void BoardFenInfo::update_str_full_moves(const int& fm) {
  str_full_moves = std::to_string(fm);
}

bool BoardFenInfo::is_king_piece(const Piecetype& pct) {
  return (pct == wK) || (pct == bK);
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
