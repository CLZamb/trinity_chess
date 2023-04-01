#ifndef BOARD_COLOR_MODIFIER_H
#define BOARD_COLOR_MODIFIER_H

#include <string>
#include "box.h"

using std::string;

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

class BoxModifier {
  public:
    enum CodeAttribute {
      RESET      = 0,
      BG_INVERSE = 7,
      SLOW_BLINK = 100,
      DEFAULT    = 90,
    };

    enum Color {
      BLACK_FG                = 232,
      BLACK_BG_BLACK_SQUARE   = 1,
      BLACK_BG_WHITE_SQUARE   = 255,

      WHITE_FG                = 231,
      WHITE_BG_BLACK_SQUARE   = 35,
      WHITE_BG_WHITE_SQUARE   = 252,

      WHITE_FG_BG      = 254,
      GREEN_FG_BG      = 10, 
    };

    BoxModifier() {}
    virtual ~BoxModifier() {}

    void add_attribute(CodeAttribute c, Box* drawing) {
      mod = modifier_to_str(c).c_str();
      prepend(mod, drawing);
    };

    void add_bg_color(Color c, Box* drawing) {
      mod = modifier_bg_color_to_str(c).c_str();
      prepend(mod, drawing);
    }

    void add_fg_color(Color c, Box* drawing) {
      mod = modifier_fg_color_to_str(c).c_str();
      prepend(mod, drawing);
    }

    void reset(Box* drawing) {
      mod = modifier_to_str(RESET).c_str();
      append(mod, drawing);
    }

  private:
    void prepend(const char code[] , Box* drawing) {
      for (int i = 0; i < Box::kRowSize; ++i) {
        Box::copy_row(temp_copy, drawing->content[i]);
        Box::copy_row(drawing->content[i], code, temp_copy);
      }
    }

    void append(const char code[] , Box* drawing) {
      for (int i = 0; i < Box::kRowSize; ++i) {
        Box::copy_row(temp_copy, drawing->content[i]);
        Box::copy_row(drawing->content[i], temp_copy, code);
      }
    }

    std::string modifier_to_str(const CodeAttribute ca) {
      return "\033[" + std::to_string(ca) + "m";
    }

    string modifier_bg_color_to_str(const Color c) {
      return "\x1B[48;5;" + std::to_string(c) + "m";
    }

    string modifier_fg_color_to_str(const Color c) {
      return "\033[38;5;" + std::to_string(c) + "m";
    }

    static const int kColumnSize = Box::kCharSize;
    static const int kSizeBox = sizeof(char[kColumnSize]);
    char temp_copy[kColumnSize];
    const char* mod;
};

#endif /* BOARD_COLOR_MODIFIER_H */
