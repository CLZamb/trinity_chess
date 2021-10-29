#include "headers/board_with_info.h"

BoardWithInfo::BoardWithInfo() : m_board(mv) {}
BoardWithInfo::~BoardWithInfo() {}

void BoardWithInfo::_init() {
  m_info._init();
  m_board._init();
}

void BoardWithInfo::make_move(Move m) {
  string from = utils::square_int_to_str(m.get_from());
  string to = utils::square_int_to_str(m.get_to());

  Piece* captured = m_board.get_piece_at_square(m.get_to());

  m_board.make_move(m);
  m_info.save_moves(from + to);

  if (captured) {
    m_info.save_captures(
        utils::get_piece_str_name_from_piecetype(
          captured->get_type_and_color()));
  }
}

void BoardWithInfo::update_turn(GameTurn::players turn) {
  string info;
  info += m_board.get_turn()->get_str_color_pieces();
  info += " to move - (player ";
  info += (turn == GameTurn::player_2) ? "2" : "1";
  info += ")";

  m_info.save_game_info(info);
}

Board* BoardWithInfo::get_board() {
  return &m_board;
}

Info* BoardWithInfo::get_info() {
  return &m_info;
}
