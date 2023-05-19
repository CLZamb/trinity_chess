#ifndef CHESS_H
#define CHESS_H

#include "board/check_move/IChess_validator.h"
#include "board/position/position_fen.h"
#include "board/special_moves/special_move_controller.h"
#include "components/const_event_emitter.h"
#include "configuration/board_info.h"
#include "game/turn/side_to_move.h"

class Chess :public ConstEventEmitter {
 public:
  explicit Chess(BoardConfigInfo &board_config);

  void change_side();
  void make_move(const Move &mv);
  bool is_checkmate();
  bool is_player_in_check(const Move &mv);
  bool is_legal_move(Move &mv);
  bool is_string_move_format_valid(const std::string &m);
  Move convert_string_to_move(const std::string &m);
  Color get_cur_color_side();
  void set_validator(std::unique_ptr<IChessValidator> &&validator) {
    p_validator = std::move(validator);
  }

  std::unique_ptr<IChessValidator> get_validator() { 
    return std::move(p_validator); 
  }

 private:
  SideToMove m_side_to_move;
  Position m_position;
  PositionFen m_position_fen;
  SpecialMove m_special_move;
  std::unique_ptr<IChessValidator> p_validator;
};

#endif /* CHESS_H */
