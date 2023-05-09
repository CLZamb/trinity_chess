#ifndef INFO_PANE_H
#define INFO_PANE_H

#include "board/board_window/IBoard_side_pane.h"
#include "board/board_window/info_pane/board_info_model.h"
#include "board/board_window/info_pane/info_view.h"

class InfoPane : public IBoardSidePane, public GameTurnObserver {
 public:
  InfoPane(std::shared_ptr<BoardInfoModel> info,
           std::shared_ptr<InfoView> view);
  virtual ~InfoPane() = default;

  void update() override;
  void make_move(const Move &mv) override;
  void update_turn(const Color &info) override;
  IPane *get_pane() override;

 private:
  std::shared_ptr<BoardInfoModel> p_info;
  std::shared_ptr<InfoView> p_view;
};

#endif /* INFO_PANE_H */
