#ifndef DRAWINGS_H
#define DRAWINGS_H

#include "boxStruct.h"
#include <string>
#include <map>
#include <ostream>

using std::map;

struct IDrawing {
  enum Code {
    BG_INVERSE  = 7,
    BG_B_BLACK  = 90,
    FG_GREEN    = 32,
    FG_WHITE    = 37,
    FG_DEFAULT  = 39,
    BG_DEFAULT  = 49,
  };
  virtual box* drawing() = 0;
  virtual ~IDrawing() {}

 protected:
  void modifier(const Code mod, box* drawing) {
    const int column_size = box::char_size;
    int sizeBox = sizeof(char[column_size]);
    char temp[column_size];
    for (int i = 0; i < box::row_size; ++i) {
      snprintf(temp, column_size, "%s", drawing->content[i]);
      snprintf(
          drawing->content[i], sizeBox,
          "%s%d%s%s",
          "\033[", mod, "m", temp);
    }
  }
};

class PieceDrawing : public IDrawing {
 private:
    static const map<std::string, box> piece_drawing;
    box m_drawing;
 public:
    explicit PieceDrawing(std::string piece) {
      if (piece_drawing.find(piece) == piece_drawing.end()) throw "invalid key";

      m_drawing = piece_drawing.at(piece);

      const int column_size = box::char_size;
      int sizeBox = sizeof(char[column_size]);
      char temp[column_size];
      for (int i = 0; i < box::row_size; ++i) {
        snprintf(temp, column_size, "%s", m_drawing.content[i]);
        snprintf(
            m_drawing.content[i], sizeBox,
            "%s%s",
            temp, "\033[0m");
      }
    }
    virtual ~PieceDrawing() {}

    box* drawing() override { return &m_drawing; }
    void set_drawing(box* newBox) { m_drawing = *newBox; }
};


class Player2Comp : public IDrawing {
  IDrawing *drawing_ptr;
 public:
  explicit Player2Comp(IDrawing* drawing) {
    this->drawing_ptr = drawing;
  }
  virtual ~Player2Comp() {}
  box* drawing() {
    return drawing_ptr->drawing();
  }
};

class Player1 : public IDrawing {
  IDrawing *drawing_ptr;
 public:
  explicit Player1(IDrawing* drawing) {
    this->drawing_ptr = drawing;
  }
  virtual ~Player1() {}
  box* drawing() {
    modifier(FG_WHITE, drawing_ptr->drawing());
    return drawing_ptr->drawing();
  }
};

class WhiteSquare : public IDrawing {
  IDrawing *drawing_ptr;
 public:
  explicit WhiteSquare(IDrawing* drawing) {
    this->drawing_ptr = drawing;
  }
  virtual ~WhiteSquare() {}
  box* drawing() {
    modifier(BG_INVERSE, drawing_ptr->drawing());
    return drawing_ptr->drawing();
  }
};

class BlackSquare : public IDrawing {
  IDrawing *drawing_ptr;
 public:
  explicit BlackSquare(IDrawing* drawing) {
    this->drawing_ptr = drawing;
  }
  virtual ~BlackSquare() {}
  box* drawing() {
    modifier(BG_B_BLACK, drawing_ptr->drawing());
    return drawing_ptr->drawing();
  }
};

#endif /* DRAWINGS_H */
