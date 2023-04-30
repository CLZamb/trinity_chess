#ifndef BOARD_CHECK_MODEL_INFO_H
#define BOARD_CHECK_MODEL_INFO_H

#include "board/board_window/info_pane/board_info_model.h"
#include "board_check_decorator.h"
#include "ui/components/pane.h"
#include "utils/string_utils.h"

class BoardCheckInfoDecorator : public BoardCheckDecorator {
 public:
  BoardCheckInfoDecorator(std::unique_ptr<IBoardCheckBehaviour> &&m,
                          std::shared_ptr<BoardModelInfo> b);
  virtual ~BoardCheckInfoDecorator();

  bool is_string_format_valid(const string &s) override;
  bool is_player_in_check(const Move &m) override;
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

  std::shared_ptr<BoardModelInfo> m_board_model_info;
};

#endif /* BOARD_CHECK_H */
