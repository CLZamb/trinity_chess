#ifndef PIECE_DRAWINGS_H
#define PIECE_DRAWINGS_H


#include "ui/components/box_drawing.hpp"

using StringDrawingName::Pieces::pawn;
using StringDrawingName::Pieces::rook;
using StringDrawingName::Pieces::knight;
using StringDrawingName::Pieces::bishop;
using StringDrawingName::Pieces::queen;
using StringDrawingName::Pieces::king;

class PieceDrawing {
 public:
  explicit PieceDrawing(Piecetype pct) {
    string piece_type =
        StringDrawingName::Pieces::get_piece_from_piecetype(pct);
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
  string get_piece_str_name_from_piecetype(Piecetype piece_type) {
    const unordered_map<Piecetype, string> piece_str_name{
      {bP, pawn},   {bR, rook},   {bN, knight}, {bB, bishop},
      {bQ, queen},  {bK, king},   {wP, pawn},   {wR, rook},
      {wN, knight}, {wB, bishop}, {wQ, queen},  {wK, king}
    };

    auto search = piece_str_name.find(piece_type);
    // check if the key exists
    if (search == piece_str_name.end())
      return "";

    return search->second;
  }
  BoxDrawing* white_square_drawing = nullptr;
  BoxDrawing* black_square_drawing = nullptr;
};

#endif /* DRAWINGS_H */
