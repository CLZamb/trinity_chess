#ifndef DRAWINGS_H
#define DRAWINGS_H

#include "box.h"
#include <string>
#include <string.h>
#include <map>
#include <iostream>
#include <vector>
#include "../../graphics//headers/game_drawings.hpp"
#include "../../board/headers/utils.h"

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

class DrawingMod {
  public:
    enum Code {
      BG_NORMAL  = 0,
      BG_INVERSE = 7,
      FG_BLACK   = 30,
      FG_GREEN   = 32,
      FG_WHITE   = 97,
      FG_DEFAULT = 39,
      BG_DEFAULT = 49,
      BG_BLACK   = 40,
      BG_WHITE   = 47,
    };

    DrawingMod() {}
    ~DrawingMod() {}

    std::string modifier_to_str(const Code mod) {
      return "\033[" + std::to_string(mod) + "m";
    }

    void append(Code c, Box* drawing) {
      mod = modifier_to_str(c).c_str();

      for (int i = 0; i < Box::kRowSize; ++i) {
        Box::copy_row(temp_copy, drawing->content[i]);
        Box::copy_row(drawing->content[i], temp_copy, mod);
      }
    }

    void prepend(Code c, Box* drawing) {
      mod = modifier_to_str(c).c_str();

      for (int i = 0; i < Box::kRowSize; ++i) {
        Box::copy_row(temp_copy, drawing->content[i]);
        Box::copy_row(drawing->content[i], mod, temp_copy);
      }
    }

  private:
    static const int kColumnSize = Box::kCharSize;
    static const int kSizeBox = sizeof(char[kColumnSize]);
    char temp_copy[kColumnSize];
    const char* mod;
};


class Drawing {
  public:
    explicit Drawing(std::string piece) {
      if (piece_drawing.find(piece) == piece_drawing.end())
        throw "invalid piece name";

      m_drawing = piece_drawing.at(piece);
      piece_mod.append(DrawingMod::BG_NORMAL, &m_drawing);
    }
    virtual ~Drawing() {}

    Box* get_drawing() { return &m_drawing; }
    void set_drawing(Box* newBox) { m_drawing = *newBox; }
    void addModifier(DrawingMod::Code mod_code) {
      piece_mod.prepend(mod_code, &m_drawing);
    }

  private:
    static const map<std::string, Box> piece_drawing;
    Box m_drawing;
    DrawingMod piece_mod;
};

const map<std::string, Box> piece_drawing = const_piece_drawing;

class PieceDrawing {
 public:
  explicit PieceDrawing(const string& piece_type) {
    black_square_drawing = new Drawing(piece_type);
    white_square_drawing = new Drawing(piece_type);
    black_square_drawing->addModifier(DrawingMod::BG_INVERSE);
  }

  ~PieceDrawing() {
    delete black_square_drawing;
    delete white_square_drawing;
  }

  void set_drawing_mod(DrawingMod::Code mod) {
    black_square_drawing->addModifier(mod);
    white_square_drawing->addModifier(mod);
  }

  Box* get_drawing(bool is_in_black_square) {
    return is_in_black_square ?
      black_square_drawing->get_drawing() : white_square_drawing->get_drawing();
  }

 private:
  Drawing* white_square_drawing = nullptr;
  Drawing* black_square_drawing = nullptr;
};

class DrawingBuilder {
 public:
  virtual void build_drawing(Piecetype pct)  = 0;
  virtual PieceDrawing* get_drawing() { return nullptr; }

 protected:
  DrawingBuilder() {}
};


class StandardDrawingBuilder : public DrawingBuilder {
 public:
  StandardDrawingBuilder() : piece_drawing(nullptr) {}
  ~StandardDrawingBuilder() {}

  void build_drawing(Piecetype pct) override {
    std::string piece_type = utils::get_piece_str_name_from_piecetype(pct);
    piece_drawing = new PieceDrawing(piece_type);
  }

  PieceDrawing* get_drawing() override {
    return piece_drawing;
  }

 private:
  PieceDrawing* piece_drawing;
};

//
#endif /* DRAWINGS_H */
