#ifndef BOARD_VIEW_H
#define BOARD_VIEW_H

#include "view.h"
#include "board/headers/square.h"
#include "player/headers/input_observer.h"
#include "game/headers/game_turn.h"

class BoardView : public View, public InputObserver {
  public:
    BoardView();
    virtual ~BoardView();
    void draw() override;
    void parser_fen(const string& s);
    void add_view_at_window_pos(View& v, Window::Pane_pos pos);
    void add_pane_at_window_pos(Displayable *v, Window::Pane_pos pos);
    void clear_square_on_range(const int start, const int end);
    void handle_input_event(const InputEvent &) override;

  private:
    void clear();
    void selected_option(const int& pos);
    void deselected_option(const int& pos);
    void set_piece_drawing_at_square_pos(Piecetype type, SquareIndices position);
    char left_border(const int &row,const int &col);
    bool is_number(const char &c);

    const string m_top_section = "top";
    const string m_board_section = "board";
    const string m_bottom_section = "bottom";

    const string m_top_section_drawing = 
      " ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓";
    const vector<string> m_bottom_section_drawing = {
      " ┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃",
      " ┃    A        B        C        D        E        F        G       H     ┃",
      " ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛"};

    PiecesDrawings m_pieces_drawings;
    SquaresDrawings m_squares_drawings;
};

#endif /* BOARD_VIEW_H */
