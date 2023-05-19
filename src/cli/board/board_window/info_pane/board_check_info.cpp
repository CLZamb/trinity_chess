#include "board_check_info.h"
#include "utils/string_utils.h"

using std::string;
using CVD = ChessValidatorDecorator;

BoardCheckInfo::BoardCheckInfo(std::unique_ptr<IChessValidator> m)
    : CVD(std::move(m)) {}

void BoardCheckInfo::update_turn(const Color &c) {
  CVD::update_turn(c);
  p_info->save_info(m_turn_string[c]);
  m_side = c;
}

bool BoardCheckInfo::is_string_move_format_valid(const string &s) {
  bool valid_format = CVD::is_string_move_format_valid(s);

  if (!valid_format) {
    string str_move = s;
    p_info->save_info("{ " + s + " } " + Kwrong_format);
  }

  return valid_format;
}

bool BoardCheckInfo::is_player_in_check(const Move &m) {
  bool in_check = CVD::is_player_in_check(m);

  if (in_check) { p_info->save_info(Kin_check); }

  return in_check;
}

bool BoardCheckInfo::is_legal_move(Move &m) {
  bool legal_move = CVD::is_legal_move(m);

  if (!legal_move) {
    string str_move = StringUtils::move_to_string(m);
    p_info->save_info("{ " + str_move + " } " + Killegal_move);
  }

  return legal_move;
}

bool BoardCheckInfo::is_checkmate() {
  bool checkmate = CVD::is_checkmate();

  if (checkmate) {
    string player_color_str = StringUtils::get_color_str_from_color(m_side);
    p_info->save_info(Kcheckmate + player_color_str + Kwon);
  }

  return checkmate;
}
