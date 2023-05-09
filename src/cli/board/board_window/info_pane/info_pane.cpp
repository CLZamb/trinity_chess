#include "info_pane.h"

InfoPane::InfoPane(std::shared_ptr<BoardInfoModel> info,
                   std::shared_ptr<InfoView> view)
    : p_info(info)
    , p_view(view) {}

void InfoPane::make_move(const Move &mv) {
  p_info->save_move(mv);
  if (MoveUtils::get_captured_piece(mv)) { p_info->save_capture(mv); }

  Color c = p_info->get_side_to_move_color();
  p_view->update_moves(p_info->get_moves(c), c);
  p_view->update_captures(p_info->get_captures(c), c);
}

void InfoPane::update_turn(const Color &c) { p_info->save_side(c); }

void InfoPane::update() {
  p_view->update_banner(p_info->get_side_to_move_color());
  p_view->update_game_info(p_info->get_info());
}

IPane *InfoPane::get_pane() { return p_view.get(); }
