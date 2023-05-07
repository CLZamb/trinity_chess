#include "board_info_model.h"

#include "board/position/position_utils.h"

using std::string;

BoardModelInfo::BoardModelInfo() {}
BoardModelInfo::~BoardModelInfo() {}

void BoardModelInfo::update_side(const Color &side) { m_side = side; }

void BoardModelInfo::save_move(const Move &mv) {
  m_moves[m_side] += get_move_string(mv) + " ";
}

void BoardModelInfo::save_capture(const Move &mv) {
  m_captures[m_side] += get_captured_string(mv) + " ";
}

namespace SU = StringUtils;
namespace MU = MoveUtils;
string BoardModelInfo::get_move_string(const Move &m) {
  return string(1, utils::piecetype_to_char(MU::get_piece(m))) + "-" +
         SU::squareindex_to_str(MU::get_from(m)) +
         SU::squareindex_to_str(MU::get_to(m));
}

string BoardModelInfo::get_captured_string(const Move &m) {
  return StringDrawingName::Pieces::get_name_from_piecetype(
      MoveUtils::get_captured_piece(m));
}

void BoardModelInfo::save_info(const std::string &info) { m_info = info; }

string BoardModelInfo::get_moves(Color c) { return m_moves[c]; }

string BoardModelInfo::get_captures(Color c) { return m_captures[c]; }

string BoardModelInfo::get_info() { return m_info; }

Color BoardModelInfo::get_side_to_move_color() { return m_side; }
