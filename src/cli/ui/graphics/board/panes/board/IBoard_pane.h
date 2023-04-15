#ifndef IBOARD_PANE_H
#define IBOARD_PANE_H

#include "game/players/player_info.hpp"
#include "ui/graphics/board/panes/IUi_board.h"
#include "utils/move.hpp"
#include "ui/input/board/keyboard/key_code.h"

class IBoardPane : public IUiPaneComponent {
 public:
  virtual ~IBoardPane() = default;
  virtual void make_move(const Move &mv) = 0;
  virtual bool handle_event(KeyCode::Key, std::string& callback) = 0;
  virtual void update_turn(const PlayerInfo &) = 0;
};

#endif /* IBOARD_PANE_H */
