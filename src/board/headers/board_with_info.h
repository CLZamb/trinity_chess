#ifndef BOARD_WITH_INFO_H
#define BOARD_WITH_INFO_H

#include "board.h"
#include "info.h"
#include "savable.h"
#include "../../game/headers/game_turn_observer.h"

class BoardWithInfo : public GameTurnObserver {
 public:
  BoardWithInfo();
  virtual ~BoardWithInfo();

  void make_move(Move m);
  void update_turn(GameTurn::players turn);
  void update_game_info(const string& info);
  bool is_checkmate();
  bool is_legal_move(std::shared_ptr<Player> turn, Move& m);
  void _init();
  std::shared_ptr<Player> get_turn();
  Displayable* get_board_drawing();
  Displayable* get_info_drawing();

 private:
  string get_turn_info(players turn);
  string get_str_moves(const Move& m);
  void save_move(const Move& m);
  void save_capture(const Move& m);
  Board m_board;
  Info m_info;
};

#endif /* BOARD_WITH_INFO_H */
