#ifndef BOARD_VIEW_H
#define BOARD_VIEW_H

#include "configuration/board_configuration.h"
#include "board_window.h"

class BoardView : public BoardWindow, public GameTurnObserver  {
 public:
  BoardView(const string f, const BoardConfig& b);
  virtual ~BoardView();

  void update_turn(const PlayerInfo &) override;
  void update();
  void print();
  string get_next_string_move();
  void make_move(const Move& m);
  void add_info_pane(BoardCheck &b);
  void add_board_pane(const string& fen);
  void add_keyboard_pane(const string& fen);

 private:
  BoardModelInfo m_board_model_info;
  PlayerInfo m_turn_info;
  BoardComponents m_components;
};

#endif /* BOARD_VIEW_H */
