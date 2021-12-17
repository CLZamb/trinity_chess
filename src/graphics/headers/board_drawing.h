#ifndef BOARD_DRAWING_H
#define BOARD_DRAWING_H

#include "Idisplay.h"
#include "section.h"
#include "Idisplay.h"
#include "box.h"
#include "../../board/headers/square.h"

class BoardDrawing : public Displayable {
  public:
    explicit BoardDrawing(std::array<Square, 64>& arr);
    virtual ~BoardDrawing();
    void draw();
    char left_border(int row, int col);

  private:
    void _init();
    shared_ptr<Section> p_top_section;
    shared_ptr<Section> p_main;
    shared_ptr<Section> p_bottom_section;
    std::array<Square, 64>& m_squares;
};

#endif /* BOARD_DRAWING_H */
