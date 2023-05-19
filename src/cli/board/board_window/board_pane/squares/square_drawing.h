#ifndef SQUARE_DRAWING_H
#define SQUARE_DRAWING_H

#include <array>
#include <memory>

#include "board/board_window/board_pane/pieces/piece_drawing.hpp"
#include "game/game_typedefs.h"
#include "components/box_modifier.hpp"

class SquareDrawing {
 public:
  using BM = BoxModifier;
  using PtrPieceDrawing = std::unique_ptr<PieceDrawing>;

  SquareDrawing();
  virtual ~SquareDrawing(){};

  void add_side_piece_bg(const PtrPieceDrawing &piece_drawing);
  void remove_side_piece_bg_mod(const PtrPieceDrawing &piece_drawing);
  virtual void set_piece_drawing(PtrPieceDrawing &&sdi);
  PtrPieceDrawing &&remove_piece_drawing();
  void clear();

  Box *get_drawing();
  const char *operator[](int row);

 protected:
  std::array<BM::BGColor, Color::SIZE> m_side_bg_color_mod;
  Box m_empty_drawing;

 private:
  bool m_has_piece{false};
  BM::BGColor m_bg_mod;
  PtrPieceDrawing m_pc_drawing;
};

#endif /* SQUARE_DRAWING_H */
