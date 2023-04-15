#ifndef BOARD_CHECK_MODEL_INFO_H
#define BOARD_CHECK_MODEL_INFO_H

#include "board_check_decorator.h"
#include "board_info_model.h"
#include "utils/string_utils.h"

class BoardCheckInfoDecorator : public BoardCheckDecorator {
 public:
  BoardCheckInfoDecorator(unique_ptr<IBoardCheckBehaviour> &&m,
                          BoardModelInfo &bmi);
  virtual ~BoardCheckInfoDecorator();

  bool is_string_format_valid(const string &s) override;
  bool is_in_check(const Move &m) override;
  bool is_legal_move(Move &m) override;
  bool is_checkmate() override;

 private:
  string str_move;

  const string Kwrong_format =
      "Move is an not in a recognizable format, please try again";
  const string Killegal_move = "is an illegal move";
  const string Kin_check = "cannot make that move, player is in check";
  const string Kcheckmate = "checkmate ";
  const string Kwon = " won";

  BoardModelInfo &m_board_model_info;
};

#endif /* BOARD_CHECK_H */
