#ifndef BOX_DRAWINGS_H
#define BOX_DRAWINGS_H

#include "ui/board/board_pane/board_drawings.hpp"
#include "box_modifier.hpp"

using std::string;

class BoxDrawing {
 public:
  explicit BoxDrawing(std::string name_type) { 
    if (is_square(name_type))
      m_drawing = BoardDrawings::Squares::Ksquares.at(name_type);
    else if (is_piece(name_type))
      m_drawing = BoardDrawings::Pieces::Kpieces.at(name_type);
    else
      throw "invalid piece or square name";

    piece_color_mod.reset(&m_drawing);
  }

  virtual ~BoxDrawing() {}

  Box* get_drawing() { return &m_drawing; }
  void set_drawing(Box* newBox) { m_drawing = *newBox; }
  void add_attribute(BoxModifier::CodeAttribute mod_code) {
    piece_color_mod.add_attribute(mod_code, &m_drawing);
  }

  void add_fg_color_modifier(BoxModifier::Color mod_code) {
    piece_color_mod.add_fg_color(mod_code, &m_drawing);
  }

  void add_bg_color_modifier(BoxModifier::Color mod_code) {
    piece_color_mod.add_bg_color(mod_code, &m_drawing);
  }

private:
  bool is_piece(const string &type) {
    return  
    BoardDrawings::Pieces::Kpieces.find(type) !=
    BoardDrawings::Pieces::Kpieces.end();
  }

  bool is_square(const string &type) {
    return  
    BoardDrawings::Squares::Ksquares.find(type) !=
    BoardDrawings::Squares::Ksquares.end();
  }

  Box m_drawing;
  BoxModifier piece_color_mod;
};

#endif /* DRAWINGS_H */
