#ifndef PIECE_DRAWINGS_H
#define PIECE_DRAWINGS_H


#include "ui/graphics/components/box_drawing.hpp"

class PieceDrawing {
 public:
  explicit PieceDrawing(const string& piece_type) {
    black_square_drawing = new BoxDrawing(piece_type);
    white_square_drawing = new BoxDrawing(piece_type);
  }

  virtual ~PieceDrawing() {
    delete black_square_drawing;
    delete white_square_drawing;
  }

  void set_fg_color_modifier(BoxModifier::Color mod) {
    black_square_drawing->add_fg_color_modifier(mod);
    white_square_drawing->add_fg_color_modifier(mod);
  }

  void set_atr_modifier(BoxModifier::CodeAttribute mod) {
    black_square_drawing->add_attribute(mod);
    white_square_drawing->add_attribute(mod);
  }

  void set_bg_color_modifier(BoxModifier::Color white_square, BoxModifier::Color black_square) {
    white_square_drawing->add_bg_color_modifier(white_square);
    black_square_drawing->add_bg_color_modifier(black_square);
  }

  Box* get_drawing(bool is_in_black_square) {
    return is_in_black_square ?
      black_square_drawing->get_drawing() : white_square_drawing->get_drawing();
  }

 private:
  BoxDrawing* white_square_drawing = nullptr;
  BoxDrawing* black_square_drawing = nullptr;
};

#endif /* DRAWINGS_H */
