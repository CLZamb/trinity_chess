#ifndef GAME_H
#define GAME_H

#include "board/fen/board_fen_controller.h"
#include "ui/graphics/board/board_ui.h"
#include "game/turn/side_to_move.h"
#include "configuration/IConfiguration.h"

// TESTS FEN
// const string start_fen = "4k3/8/8/4pP2/8/8/8/4K2R w - e6 0 1";
// const string start_fen = "4k3/8/8/4pP2/8/8/8/4K2R w - e6 0 1";
// const string start_fen = "r3k3/ppp5/8/8/8/8/5PPP/4K2R w Kq - 0";
// const string start_fen = "k1R5/8/2Q5/8/1q6/2r5/8/K7 b - - 0 1";
// const string start_fen = "3kq2r/8/8/8/8/8/8/3K1Q2 w - - 0 1";
// const string start_fen = "2Q5/k7/8/2R5/7r/7r/8/K7 b - - 0 1";
// const string start_fen = "6k1/5Q2/8/8/8/8/7R/6K1 b - - 0 1";

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

  const string start_fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

  SideToMove m_turn;
  Board m_board;
  BoardCheck m_board_check;
  BoardFenController m_board_fen;
  BoardUi m_board_ui;
  // Players m_players;
  // IpcPipe m_ipc_search;
};

#endif /* GAME_H */
