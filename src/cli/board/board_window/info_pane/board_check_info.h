#ifndef BOARD_CHECK_INFO_DECORATOR_H
#define BOARD_CHECK_INFO_DECORATOR_H

#include "board/board_window/info_pane/IBoard_info_updater.h"
#include "board/board_window/info_pane/chess_validator_decorator.hpp"
#include "board/board_window/info_pane/game_info_source.h"

class BoardCheckInfo : public ChessValidatorDecorator {
 public:
  explicit BoardCheckInfo(std::unique_ptr<IChessValidator> m);
  void update_turn(const Color &c) override;
  bool is_string_move_format_valid(const std::string &s) override;
  bool is_player_in_check(const Move &m) override;
  bool is_legal_move(Move &m) override;
  bool is_checkmate() override;
  void set_info_saver(IBoardSaveInfo &board_save_info) {
    p_info = &board_save_info;
  }

 private:
  const std::string Kwrong_format =
      "Move is an not in a recognizable format, please try again";
  const std::string Killegal_move = "is an illegal move";
  const std::string Kin_check = "cannot make that move, player is in check";
  const std::string Kcheckmate = "checkmate ";
  const std::string Kwon = " won";
  std::array<std::string, Color::SIZE> m_turn_string{"Is white turn",
                                                     "Is black turn"};
  IBoardSaveInfo *p_info;
  Color m_side;
};

#endif /* BOARD_CHECK_INFO_DECORATOR_H */
