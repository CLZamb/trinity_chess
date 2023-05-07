#ifndef SQUARE_DRAWING_H
#define SQUARE_DRAWING_H

#include <memory>

#include "board/board_window/board_pane/pieces/IPiece_drawing.hpp"
#include "square_drawing_info.hpp"

class SquareDrawing {
 public:
  explicit SquareDrawing(const SquareDrawingInfo &square_drawing_info);
  virtual ~SquareDrawing() = default;

  void set_piece_drawing(std::unique_ptr<IPieceDrawing> &&piece_drawing);
  std::unique_ptr<IPieceDrawing> &&remove_piece_drawing();
  void clear();

  Box *get_drawing();
  const char *operator[](int row);
  // char &operator()(int row, int col);

 private:
  void add_bg_color_mod_to_piece();
  bool m_has_piece;
  Box m_empty;
  BoxModifier::BGColor m_bg_mod;
  std::unique_ptr<IPieceDrawing> m_pc_drawing;
  std::array<BoxModifier::BGColor, Color::SIZE> m_side_bg_color_mod;
};

#endif /* SQUARE_DRAWING_H */
