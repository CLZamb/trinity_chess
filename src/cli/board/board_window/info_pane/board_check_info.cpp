#include "board_check_info.h"
#include "utils/string_utils.h"

using std::shared_ptr;
using std::string;
using std::unique_ptr;
using PtrBCB = std::unique_ptr<IBoardCheck>;
using PtrBMI = std::shared_ptr<IBoardSaveInfo>;
using BCD = BoardCheckDecorator;

BoardCheckInfo::BoardCheckInfo(std::unique_ptr<IBoardCheck> m,
                               std::shared_ptr<IBoardSaveInfo> bsi)
    : BCD(std::move(m))
    , m_board_info_model(bsi) {}

void BoardCheckInfo::update_turn(const Color &c) {
  BCD::update_turn(c);
  m_board_info_model->save_info(m_turn_string[c]);
  m_side = c;
}

bool BoardCheckInfo::is_string_move_format_valid(const string &s) {
  bool valid_format = BCD::is_string_move_format_valid(s);

  if (!valid_format) {
    str_move = s;
    m_board_info_model->save_info("{ " + s + " } " + Kwrong_format);
  }

  return valid_format;
}

bool BoardCheckInfo::is_player_in_check(const Move &m) {
  bool in_check = BCD::is_player_in_check(m);

  if (in_check) { m_board_info_model->save_info(Kin_check); }

  return in_check;
}

bool BoardCheckInfo::is_legal_move(Move &m) {
  bool legal_move = BCD::is_legal_move(m);

  if (!legal_move) {
    m_board_info_model->save_info("{ " + str_move + " } " + Killegal_move);
  }

  return legal_move;
}

bool BoardCheckInfo::is_checkmate() {
  bool checkmate = BCD::is_checkmate();

  if (checkmate) {
    string player_color_str = StringUtils::get_color_str_from_color(m_side);
    m_board_info_model->save_info(Kcheckmate + player_color_str + Kwon);
  }

  return checkmate;
}
