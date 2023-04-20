#ifndef SQUARE_DRAWING_H
#define SQUARE_DRAWING_H

#include "ui/components/box_modifier.hpp"

class SquareDrawing {
public:
  SquareDrawing();
  SquareDrawing(bool is_black_squared);
  virtual ~SquareDrawing();
  const Box* get_drawing();
  const char* at_row(int i);

  void clear_square();
  void update_current_drawing(const Box* drawing);
  void set_piece_drawing(const Box* drawing);
  void set_base_square_drawing(bool is_black_square);
  bool is_black_square();
  void select();
  void deselect();
  bool is_selected();
  void set_is_selected(const bool&);

private:
  const Box* get_original_drawing();
  const Box* p_empty_square_drawing {nullptr};
  const Box* p_piece_square_drawing {nullptr};
  const Box* p_cur_drawing {nullptr};
  Box m_select_drawing;
  bool m_black_square {false};
  bool m_is_selected {false};
  bool m_has_piece {false};
  bool m_is_next_selected {false};
  static BoxModifier mod;
};

#endif /* SQUARE__DRAWING_H */
