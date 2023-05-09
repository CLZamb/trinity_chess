#ifndef SQUARE_DRAWING_H
#define SQUARE_DRAWING_H

#include <array>
#include <memory>

#include "board/board_window/board_pane/pieces/IPiece_drawing.hpp"
#include "game/game_typedefs.h"
#include "ui_components/box_modifier.hpp"

class SquareDrawing {
 public:
  using BM = BoxModifier;
  explicit SquareDrawing();
  virtual ~SquareDrawing() = default;

  void add_side_piece_bg(const std::unique_ptr<IPieceDrawing> &piece_drawing);
  void remove_side_piece_bg_mod(
      const std::unique_ptr<IPieceDrawing> &piece_drawing);
  virtual void set_piece_drawing(std::unique_ptr<IPieceDrawing> &&sdi);
  std::unique_ptr<IPieceDrawing> &&remove_piece_drawing();
  void clear();

  Box *get_drawing();
  const char *operator[](int row);

 protected:
  std::array<BM::BGColor, Color::SIZE> m_side_bg_color_mod;
  Box m_empty_drawing;

 private:
  bool m_has_piece;
  BM::BGColor m_bg_mod;
  std::unique_ptr<IPieceDrawing> m_pc_drawing;
};

#endif /* SQUARE_DRAWING_H */
