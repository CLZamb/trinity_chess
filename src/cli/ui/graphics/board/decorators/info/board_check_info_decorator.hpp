#ifndef BOARD_CHECK_MODEL_INFO_H
#define BOARD_CHECK_MODEL_INFO_H

#include "board_info_model.h"
#include "board_check_decorator.h"
#include "utils/string_utils.h"

class BoardCheckInfoDecorator : public BoardCheckDecorator {
public:
  BoardCheckInfoDecorator(unique_ptr<IBoardCheckBehaviour>&& m, BoardModelInfo& bmi) :
    BoardCheckDecorator(std::move(m)), m_board_model_info(bmi) {
  }

  virtual ~BoardCheckInfoDecorator() {}

  bool is_string_format_valid(const string& s) override {
    bool valid_format = BoardCheckDecorator::is_string_format_valid(s);

    if (!valid_format)
      m_board_model_info.save_info("{ " + s + " } " + Kwrong_format);

    return valid_format;
  }

  bool is_in_check(const Move& m) override {
    bool in_check = BoardCheckDecorator::is_in_check(m);

    if (in_check)
      m_board_model_info.save_info(Kin_check);

    return in_check;
  }

  bool is_legal_move(Move& m) override {
    bool legal_move = BoardCheckDecorator::is_legal_move(m);

    if (!legal_move)
      m_board_model_info.save_info(Killegal_move);

    return legal_move;
  }

  bool is_checkmate() override {
    bool checkmate = BoardCheckDecorator::is_checkmate();
    Color player_color = m_board_model_info.get_player_info().color;
    string player_color_str = string_utils::get_color_str_from_color(player_color);

    if (checkmate)
      m_board_model_info.save_info(Kcheckmate + player_color_str + Kwon);

    return checkmate;
  }

 private:
  string str_error;

  const string Kwrong_format =
    "Move is an not in a recognizable format, please try again";
  const string Killegal_move =
    "is an illegal move";
  const string Kin_check =
    "cannot make that move, player is in check";
  const string Kcheckmate =
    "checkmate ";
  const string Kwon =
    " won";

  BoardModelInfo& m_board_model_info;
};

#endif /* BOARD_CHECK_H */
