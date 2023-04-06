#ifndef GAME_H
#define GAME_H

#include "ui/graphics/board/board_ui.h"
#include "board/check_move/board_check.h"
#include "game/turn/game_turn.h"
#include "configuration/IConfiguration.h"

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

  // const string start_fen = "4k3/8/8/4pP2/8/8/8/4K2R w - e6 0 1";
  // const string start_fen = "4k3/8/8/4pP2/8/8/8/4K2R w - e6 0 1";
  // const string start_fen = "r3k3/ppp5/8/8/8/8/5PPP/4K2R w Kq - 0";
  // const string start_fen = "k1R5/8/2Q5/8/1q6/2r5/8/K7 b - - 0 1";
  // const string start_fen = "3kq2r/8/8/8/8/8/8/3K1Q2 w - - 0 1";
  // const string start_fen = "2Q5/k7/8/2R5/7r/7r/8/K7 b - - 0 1";
  const string start_fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

  GameTurn m_game_turn;
  Board m_board;
  BoardUi m_board_ui;
  BoardCheck m_board_check;
  BoardFenInfo m_board_fen_info;
  BoardFen m_board_fen;
  // Players m_players;
  // IpcPipe m_ipc_search;
};

#endif /* GAME_H */
