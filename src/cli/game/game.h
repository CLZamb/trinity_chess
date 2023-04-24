#ifndef GAME_H
#define GAME_H

#include "board/check_move/board_check.h"
#include "board/fen/fen_parser.h"
#include "board/special_moves/special_move_controller.h"
#include "game/turn/side_to_move.h"
#include "configuration/IConfiguration.h"
#include "ui/board_window/board_window.h"

class Game {
 public:
  Game(IConfiguration &);

  virtual ~Game();
  void play();
  void set_configuration(IConfiguration&);

 private:
  void attach_observers_to_game_turn();
  void make_move(const Move& m);
  void update_board_view(const Move&);
  bool is_valid_string_move(const string& str_move);
  bool is_valid_move(const string& str_move, Move& mv);
  Move string_to_move(const string& m);

  SideToMove m_turn;
  Position m_position;
  SpecialMove m_special_move;
  BoardCheck m_board_check;
  BoardWindow m_board_ui;
  FenParser m_fen_parser;
  // Players m_players;
  // IpcPipe m_ipc_search;
};

#endif /* GAME_H */
