#ifndef BOARD_DRAWING_H
#define BOARD_DRAWING_H

#include "Idisplay.h"
#include "section.h"
#include "Idisplay.h"
#include "box.h"
#include "../../board/headers/square.h"

class BoardDrawing : public Displayable {
  public:
    explicit BoardDrawing(Square* square[]);
    virtual ~BoardDrawing();
    void _init();
    void draw();
    char left_border(int row, int col);

  private:
    shared_ptr<Section> p_top_section;
    shared_ptr<Section> p_main;
    shared_ptr<Section> p_bottom_section;

    Square** p_squares;
};

#endif /* BOARD_DRAWING_H */
