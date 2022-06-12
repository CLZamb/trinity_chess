#ifndef SQUARE_DRAWING_H
#define SQUARE_DRAWING_H

#include "graphics/headers/game_drawings.hpp"
#include "pieces_drawings.hpp"

class SquareDrawing {
public:
  SquareDrawing();
  SquareDrawing(bool is_black_squared);
  virtual ~SquareDrawing();
  const Box* get_drawing();
  const char* at(int i);
  void clear_square();
  void update_drawing(const Box* drawing);
  void update_drawing(bool is_black_square);
  bool is_black_square();

private:
  const Box* p_empty_square_drawing;
  const Box* p_cur_drawing {nullptr};
  bool m_black_square {false};
};

class SquaresDrawings {
  public:
    SquaresDrawings() {
      char squareColor = 'w';
      bool is_black_squared = true;

      static const int col_size = 7;
      static const int row_size = 8;
      int position = 0;
      /* 
       * Rows needs to be ordered upside down
       * because the program prints from top to bottom
       * so that 8 should be printed frist
       */

      for (int row = col_size; row >= 0; --row) {
        for (int col = 0; col < row_size; ++col) {
          /*
           * there are 8*8 (from 0 to 63) squares
           * to get the position 
           * we need to multyply rwo by 8 and add the col
           * i.e the bottom right position would be  
           * 8 * 0 + 7 = 7
           * */
          position = row * 8 + col;
          if (squareColor == 'b') {
            squareColor = 'w';
            m_squares[position].update_drawing(!is_black_squared);
          } else {
            squareColor = 'b';
            m_squares[position].update_drawing(is_black_squared);
          }
        }
        squareColor = squareColor == 'b' ? 'w' : 'b';
      }
    }

    virtual ~SquaresDrawings() {}

    SquareDrawing &operator[](size_t i) {
      return m_squares[i];
    }

    void select_square(const size_t &i) {
      prev = m_squares[i].get_drawing();
      selected = *prev;
      mod.add_attribute(DrawingMod::BG_INVERSE, &selected);
      m_squares[i].update_drawing(&selected);
    }

    void deselect_square(const size_t &i) {
      m_squares[i].update_drawing(prev);
    }

  private:
    Box selected;
    const Box* prev;
    static DrawingMod mod;
    std::array<SquareDrawing, utils::constant::ksquares> m_squares;
};

#endif /* SQUARE__DRAWING_H */
