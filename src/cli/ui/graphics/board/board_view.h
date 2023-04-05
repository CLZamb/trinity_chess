#ifndef BOARD_VIEW_H
#define BOARD_VIEW_H

#include "ui/graphics/components/view.h"
#include "ui/graphics/board/pieces/pieces_drawings.hpp"
#include "squares_drawing.h"

class BoardView : public View {
  public:
    BoardView();
    virtual ~BoardView();
    void update_board_drawing();
    void parse_fen(const string& s);
    void add_left_pane(IPane *v);
    void add_right_pane(IPane *v);
    void select_next_square(const size_t &i);
    void selected_square(const size_t &i);
    void deselect_square(const size_t &i);

  private:
    void clear();
    void clear_square_on_range(const int start, const int end);
    void set_piece_drawing_at_square_pos(SquareIndices position, Piecetype type);
    char left_border(const int &row,const int &col);
    bool is_middle_of_square(const int &i);
    bool is_number(char c);

    const string m_top_section = "top";
    const string m_board_section = "board";
    const string m_bottom_section = "bottom";

    PiecesDrawings m_pieces_drawings;
    SquaresDrawings m_squares_drawings;
};

#endif /* BOARD_VIEW_H */
