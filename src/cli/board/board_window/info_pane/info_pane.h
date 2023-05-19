#ifndef INFO_PANE_H
#define INFO_PANE_H

#include "board/board_window/IBoard_pane_component.h"
#include "board/board_window/info_pane/board_info_model.h"
#include "board/board_window/info_pane/game_info_source.h"
#include "board/board_window/info_pane/info_view.h"
#include "board/check_move/IChess_validator.h"
#include "board/chess.h"
#include "game/turn/side_to_move.h"

class InfoPane : public IBoardPaneComponent, public GameTurnObserver {
 public:
  explicit InfoPane(Chess& chess);
  virtual ~InfoPane() = default;

  void update_turn(const Color &info) override;
  void make_move(const Move &mv) override;
  void update() override;
  IPane *get_view() override { return &m_view; }

 private:
  BoardInfoModel m_info;
  InfoView m_view;
};

#endif /* INFO_PANE_H */
