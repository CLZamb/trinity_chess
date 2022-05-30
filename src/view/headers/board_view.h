#ifndef BOARD_VIEW_H
#define BOARD_VIEW_H

#include "view.h"
#include "board/headers/square.h"

class BoardView : public View {
  public:
    BoardView();
    virtual ~BoardView();
    void draw() override;
    void parser_fen(const string& s);
    void add_view_to_window_pos(View& v, Window::Pane_pos pos);

  private:
    void setup_board_squares();
    char left_border(const int &row,const int &col);
    void set_piece_drawing_at_square_pos(Piecetype type, SquareIndices position);
    bool is_number(const char &c);

    shared_ptr<Section> p_top_section;
    shared_ptr<Section> p_main;
    shared_ptr<Section> p_bottom_section;
    std::array<SquareDrawing, utils::constant::ksquares> m_squares;
    PiecesDrawings m_pieces_drawings;
};

#endif /* BOARD_VIEW_H */
