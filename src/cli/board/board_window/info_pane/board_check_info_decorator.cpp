#include "board_check_info_decorator.h"

using std::shared_ptr;
using std::unique_ptr;

BoardCheckInfoDecorator::BoardCheckInfoDecorator(
    unique_ptr<IBoardCheckBehaviour> &&m, shared_ptr<BoardModelInfo> bmi)
    : BoardCheckDecorator(std::move(m)), m_board_model_info(bmi) {}

BoardCheckInfoDecorator::~BoardCheckInfoDecorator() {}

void BoardCheckInfoDecorator::update_side(Color c) {
  BoardCheckDecorator::update_side(c);
  m_board_model_info->update_side(c);
}

bool BoardCheckInfoDecorator::is_string_format_valid(const string &s) {
  bool valid_format = BoardCheckDecorator::is_string_format_valid(s);
  str_move = s;

  if (!valid_format) {
    m_board_model_info->save_info("{ " + s + " } " + Kwrong_format);
  }

  return valid_format;
}

bool BoardCheckInfoDecorator::is_player_in_check(const Move &m) {
  bool in_check = BoardCheckDecorator::is_player_in_check(m);

  if (in_check) {
    m_board_model_info->save_info(Kin_check);
  }

  return in_check;
}

bool BoardCheckInfoDecorator::is_legal_move(Move &m) {
  bool legal_move = BoardCheckDecorator::is_legal_move(m);

  if (!legal_move) {
    m_board_model_info->save_info("{ " + str_move + " } " + Killegal_move);
  }

  return legal_move;
}

bool BoardCheckInfoDecorator::is_checkmate() {
  bool checkmate = BoardCheckDecorator::is_checkmate();
  Color player_color = m_board_model_info->get_side_to_move_color();
  string player_color_str =
      string_utils::get_color_str_from_color(player_color);

  if (checkmate) {
    m_board_model_info->save_info(Kcheckmate + player_color_str + Kwon);
  }

  return checkmate;
}
