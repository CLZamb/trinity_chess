#include "board_info_model.h"
#include "board/chess/position/position_utils.h"
#include "utils/string_utils.h"

using std::string;

BoardInfoModel::BoardInfoModel() {}
BoardInfoModel::~BoardInfoModel() {}

void BoardInfoModel::save_side(const Color &side) { 
  m_side = side; 
  m_info = m_turn_string[m_side];
}

void BoardInfoModel::save_move(const Move &mv) {
  m_moves[m_side] += get_move_string(mv) + " ";
}

void BoardInfoModel::save_capture(const Move &mv) {
  m_captures[m_side] += get_captured_string(mv) + " ";
}

void BoardInfoModel::update_turn(const Color &side) {
  m_side = side;
}

namespace SU = StringUtils;
namespace MU = MoveUtils;
string BoardInfoModel::get_move_string(const Move &m) {
  return string(1, utils::piecetype_to_char(MU::get_piece(m))) + "-" +
         SU::square_to_str(MU::get_from(m)) +
         SU::square_to_str(MU::get_to(m));
}

string BoardInfoModel::get_captured_string(const Move &m) {
  return StringDrawingName::Pieces::get_name_from_piecetype(
      MoveUtils::get_captured_piece(m));
}

void BoardInfoModel::save_info(const std::string &info) { m_info = info; }

string BoardInfoModel::get_moves(Color c) { return m_moves[c]; }

string BoardInfoModel::get_captures(Color c) { return m_captures[c]; }

string BoardInfoModel::get_info() { return m_info; }

Color BoardInfoModel::get_side_to_move_color() { return m_side; }
