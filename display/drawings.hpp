#ifndef DRAWINGS_H
#define DRAWINGS_H

#include "boxStruct.h"
#include <string>
#include <map>
#include <iostream>

using std::map;
/*
   ╔══════════╦════════════════════════════════╦═════════════════════════════════════════════════════════════════════════╗
   ║  Code    ║             Effect             ║                                   Note                                  ║
   ╠══════════╬════════════════════════════════╬═════════════════════════════════════════════════════════════════════════╣
   ║ 0        ║  Reset / Normal                ║  all attributes off                                                     ║
   ║ 1        ║  Bold or increased intensity   ║                                                                         ║
   ║ 2        ║  Faint (decreased intensity)   ║  Not widely supported.                                                  ║
   ║ 3        ║  Italic                        ║  Not widely supported. Sometimes treated as inverse.                    ║
   ║ 4        ║  Underline                     ║                                                                         ║
   ║ 5        ║  Slow Blink                    ║  less than 150 per minute                                               ║
   ║ 6        ║  Rapid Blink                   ║  MS-DOS ANSI.SYS; 150+ per minute; not widely supported                 ║
   ║ 7        ║  [[reverse video]]             ║  swap foreground and background colors                                  ║
   ║ 8        ║  Conceal                       ║  Not widely supported.                                                  ║
   ║ 9        ║  Crossed-out                   ║  Characters legible, but marked for deletion.  Not widely supported.    ║
   ║ 10       ║  Primary(default) font         ║                                                                         ║
   ║ 11–19    ║  Alternate font                ║  Select alternate font `n-10`                                           ║
   ║ 20       ║  Fraktur                       ║  hardly ever supported                                                  ║
   ║ 21       ║  Bold off or Double Underline  ║  Bold off not widely supported; double underline hardly ever supported. ║
   ║ 22       ║  Normal color or intensity     ║  Neither bold nor faint                                                 ║
   ║ 23       ║  Not italic, not Fraktur       ║                                                                         ║
   ║ 24       ║  Underline off                 ║  Not singly or doubly underlined                                        ║
   ║ 25       ║  Blink off                     ║                                                                         ║
   ║ 27       ║  Inverse off                   ║                                                                         ║
   ║ 28       ║  Reveal                        ║  conceal off                                                            ║
   ║ 29       ║  Not crossed out               ║                                                                         ║
   ║ 30–37    ║  Set foreground color          ║  See color table below                                                  ║
   ║ 38       ║  Set foreground color          ║  Next arguments are `5;n` or `2;r;g;b`, see below                       ║
   ║ 39       ║  Default foreground color      ║  implementation defined (according to standard)                         ║
   ║ 40–47    ║  Set background color          ║  See color table below                                                  ║
   ║ 48       ║  Set background color          ║  Next arguments are `5;n` or `2;r;g;b`, see below                       ║
   ║ 49       ║  Default background color      ║  implementation defined (according to standard)                         ║
   ║ 51       ║  Framed                        ║                                                                         ║
   ║ 52       ║  Encircled                     ║                                                                         ║
   ║ 53       ║  Overlined                     ║                                                                         ║
   ║ 54       ║  Not framed or encircled       ║                                                                         ║
   ║ 55       ║  Not overlined                 ║                                                                         ║
   ║ 60       ║  ideogram underline            ║  hardly ever supported                                                  ║
   ║ 61       ║  ideogram double underline     ║  hardly ever supported                                                  ║
   ║ 62       ║  ideogram overline             ║  hardly ever supported                                                  ║
   ║ 63       ║  ideogram double overline      ║  hardly ever supported                                                  ║
   ║ 64       ║  ideogram stress marking       ║  hardly ever supported                                                  ║
   ║ 65       ║  ideogram attributes off       ║  reset the effects of all of 60-64                                      ║
   ║ 90–97    ║  Set bright foreground color   ║  aixterm (not in standard)                                              ║
   ║ 100–107  ║  Set bright background color   ║  aixterm (not in standard)                                              ║
   ╚══════════╩════════════════════════════════╩═════════════════════════════════════════════════════════════════════════╝
   ╔══════════╦════════════════════════════════╦══════════╗
   ║  Code    ║             COLOR              ║  Note    ║
   ╠══════════╬════════════════════════════════╬══════════╣
   ║ 30       ║  BLACK                         ║  FG CODE ║
   ║ 31       ║  RED                           ║  FG CODE ║
   ║ 32       ║  GREEN                         ║  FG CODE ║
   ║ 33       ║  YELLOW                        ║  FG CODE ║
   ║ 34       ║  BLUE                          ║  FG CODE ║
   ║ 35       ║  MAGENTA                       ║  FG CODE ║
   ║ 36       ║  CYAN                          ║  FG CODE ║
   ║ 37       ║  WHITE                         ║  FG CODE ║
   ║ 90       ║  BRIGHT BLACK                  ║  FG CODE ║
   ║ 91       ║  BRIGHT RED                    ║  FG CODE ║
   ║ 92       ║  BRIGHT GREEN                  ║  FG CODE ║
   ║ 93       ║  BRIGHT YELLOW                 ║  FG CODE ║
   ║ 94       ║  BRIGHT BLUE                   ║  FG CODE ║
   ║ 95       ║  BRIGHT MAGENTA                ║  FG CODE ║
   ║ 96       ║  BRIGHT CYAN                   ║  FG CODE ║
   ║ 97       ║  BRIGHT WHITE                  ║  FG CODE ║
   ║ 40       ║  BLACK                         ║  BG CODE ║
   ║ 41       ║  RED                           ║  BG CODE ║                                                                      ║
   ║ 42       ║  GREEN                         ║  BG CODE ║
   ║ 43       ║  YELLOW                        ║  BG CODE ║
   ║ 44       ║  BLUE                          ║  BG CODE ║
   ║ 45       ║  MAGENTA                       ║  BG CODE ║
   ║ 46       ║  CYAN                          ║  BG CODE ║
   ║ 47       ║  WHITE                         ║  BG CODE ║
   ║ 100      ║  BRIGHT BLACK                  ║  BG CODE ║
   ║ 101      ║  BRIGHT RED                    ║  BG CODE ║
   ║ 102      ║  BRIGHT GREEN                  ║  BG CODE ║
   ║ 103      ║  BRIGHT YELLOW                 ║  BG CODE ║
   ║ 104      ║  BRIGHT BLUE                   ║  BG CODE ║
   ║ 105      ║  BRIGHT MAGENTA                ║  BG CODE ║
   ║ 106      ║  BRIGHT CYAN                   ║  BG CODE ║
   ║ 107      ║  BRIGHT WHITE                  ║  BG CODE ║
   ╚══════════╩════════════════════════════════╩══════════╝
   */
class IDrawing {
 public:
  enum Code {
    BG_NORMAL   = 0,
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
  std::string modifier(const Code mod) {
    return "\033[" + std::to_string(mod) + "m";
  }

  void prepend_modifier(std::string mod, box* drawing) {
    const int kColumnSize = box::kCharSize;
    int sizeBox = sizeof(char[kColumnSize]);
    char prev_copy[kColumnSize];
    const char* char_mod = mod.c_str();

    for (int i = 0; i < box::kRowSize; ++i) {
      snprintf(prev_copy, kColumnSize, "%s", drawing->content[i]);
      snprintf(
          drawing->content[i], sizeBox,
          "%s%s",
          char_mod, prev_copy);
    }
  }

  void append_modifier(std::string mod, box* drawing) {
    const int kColumnSize = box::kCharSize;
    int sizeBox = sizeof(char[kColumnSize]);
    char prev_copy[kColumnSize];
    const char* char_mod = mod.c_str();

    for (int i = 0; i < box::kRowSize; ++i) {
      snprintf(prev_copy, kColumnSize, "%s", drawing->content[i]);
      snprintf(
          drawing->content[i], sizeBox,
          "%s%s",
          prev_copy, char_mod);
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
      append_modifier(modifier(BG_NORMAL), &m_drawing);
    }
    virtual ~PieceDrawing() {}

    box* drawing() override { return &m_drawing; }
    void set_drawing(box* newBox) { m_drawing = *newBox; }
};


class Player2 : public IDrawing {
  IDrawing *drawing_ptr;
 public:
  explicit Player2(IDrawing* drawing) : drawing_ptr(drawing) {}
  virtual ~Player2() {}

  box* drawing() { return drawing_ptr->drawing(); }
};

class Player1 : public IDrawing {
  IDrawing *drawing_ptr;
 public:
  explicit Player1(IDrawing* drawing) : drawing_ptr(drawing) {}
  virtual ~Player1() {}

  box* drawing() {
    prepend_modifier(modifier(FG_WHITE), drawing_ptr->drawing());
    return drawing_ptr->drawing();
  }
};

class WhiteSquare : public IDrawing {
  IDrawing *drawing_ptr;
 public:
  explicit WhiteSquare(IDrawing* drawing) : drawing_ptr(drawing) {}
  virtual ~WhiteSquare() {}

  box* drawing() {
    prepend_modifier(modifier(BG_INVERSE), drawing_ptr->drawing());
    return drawing_ptr->drawing();
  }
};

class BlackSquare : public IDrawing {
  IDrawing *drawing_ptr;
 public:
  explicit BlackSquare(IDrawing* drawing) : drawing_ptr(drawing) {}
  virtual ~BlackSquare() {}

  box* drawing() {
    prepend_modifier(modifier(BG_B_BLACK), drawing_ptr->drawing());
    return drawing_ptr->drawing();
  }
};

#endif /* DRAWINGS_H */
