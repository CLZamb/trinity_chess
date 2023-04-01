#ifndef SQUARE_DRAWING_H
#define SQUARE_DRAWING_H

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
  static BoxModifier mod;
};

class SquaresDrawings {
  public:
    SquaresDrawings() {
      char squareColor = 'w';
      bool is_black_squared = true;

      static const int col_size = 7;
      static const int row_size = 8;
      unsigned int position = 0;
      /* 
       * Rows needs to be ordered upside down
       * because the program prints from top to bottom
       * so that the 8th row should be printed frist
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
          position = static_cast<unsigned int> (row * 8 + col);
          if (squareColor == 'b') {
            squareColor = 'w';
            m_squares[position].set_base_square_drawing(!is_black_squared);
          } else {
            squareColor = 'b';
            m_squares[position].set_base_square_drawing(is_black_squared);
          }
        }
        squareColor = squareColor == 'b' ? 'w' : 'b';
      }
    }

    virtual ~SquaresDrawings() {}

    SquareDrawing &operator[](size_t i) {
      return m_squares[i];
    }

    void select_next_square(const size_t &new_pos) {
      m_squares[prev_pos].deselect();
      prev_pos = new_pos;
      m_squares[new_pos].select();
    }

    void selected_square(const size_t &i) {
      if (m_squares[i].is_selected()) return;

      m_squares[i].select();
      m_squares[i].set_is_selected(true);
    }

    void desselected_square(const size_t &i) {
      if (!m_squares[i].is_selected())  return;

      m_squares[i].set_is_selected(false);
      m_squares[i].deselect();
    }

  private:
    size_t prev_pos = A1;
    std::array<SquareDrawing, utils::constant::ksquares> m_squares;
};

#endif /* SQUARE__DRAWING_H */
