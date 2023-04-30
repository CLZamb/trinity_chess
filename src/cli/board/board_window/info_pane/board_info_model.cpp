#include "board_info_model.h"

#include "board/position/position_utils.h"

BoardModelInfo::BoardModelInfo() {}
BoardModelInfo::~BoardModelInfo() {}

void BoardModelInfo::update_turn(const Color &side) { m_side = side; }

void BoardModelInfo::save_move(const Move &mv) {
  m_moves[m_side] += get_move_string(mv) + " ";
}

void BoardModelInfo::save_capture(const Move &mv) {
  m_captures[m_side] += get_captured_string(mv) + " ";
}

std::string BoardModelInfo::get_move_string(const Move &m) {
  return std::string(1, utils::piecetype_to_char(MoveUtils::get_piece(m))) + "-" +
         string_utils::squareindex_to_str(MoveUtils::get_from(m)) +
         string_utils::squareindex_to_str(MoveUtils::get_to(m));
}

std::string BoardModelInfo::get_captured_string(const Move &m) {
  return StringDrawingName::Pieces::get_piece_from_piecetype(
      MoveUtils::get_captured_piece(m));
}

void BoardModelInfo::save_info(const std::string &info) { m_info = info; }

std::string BoardModelInfo::get_moves(Color c) { return m_moves[c]; }

std::string BoardModelInfo::get_captures(Color c) { return m_captures[c]; }

std::string BoardModelInfo::get_info() { return m_info; }

Color BoardModelInfo::get_player_color() { return m_side; }
