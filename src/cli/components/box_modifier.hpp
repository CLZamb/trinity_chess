#ifndef BOX_MODIFIER_H
#define BOX_MODIFIER_H

#include <cstring>
#include <list>
#include <regex>
#include <string>
#include <unordered_map>
#include <array>


#include "box.h"

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

std::string getColorName(int colorCode) {
    if (colorCode < 16) {
        // Basic colors
        switch (colorCode) {
            case 0:  return "black";
            case 1:  return "red";
            case 2:  return "green";
            case 3:  return "yellow";
            case 4:  return "blue";
            case 5:  return "magenta";
            case 6:  return "cyan";
            case 7:  return "white";
            case 8:  return "bright black";
            case 9:  return "bright red";
            case 10: return "bright green";
            case 11: return "bright yellow";
            case 12: return "bright blue";
            case 13: return "bright magenta";
            case 14: return "bright cyan";
            case 15: return "bright white";
            default: return "unknown";
        }
    }
    else if (colorCode < 232) {
        // 6x6x6 cube of colors
        int cubeIndex = colorCode - 16;
        int r = cubeIndex / 36;
        int g = (cubeIndex % 36) / 6;
        int b = cubeIndex % 6;
        r = (r == 0) ? 0 : (r * 40 + 55);
        g = (g == 0) ? 0 : (g * 40 + 55);
        b = (b == 0) ? 0 : (b * 40 + 55);
        return "rgb(" + std::to_string(r) + "," + std::to_string(g) + "," + std::to_string(b) + ")";
    }
    else {
        // Gray-scale ramp
        int grayLevel = (colorCode - 232) * 10 + 8;
        return "gray(" + std::to_string(grayLevel) + ")";
    }
}

void printColorNames() {
    for (int i = 0; i < 256; i++) {
        std::cout << "\x1b[38;5;" << i << "m" << " " << i << " " << getColorName(i) << "\x1b[0m" << std::endl;
    }
}
*/

class BoxModifier {
 public:
  enum ModType {
    ATTRIBUTE,
    BGCOLOR,
    FGCOLOR,
  };

  enum Attribute {
    RESET = 0,
    BG_INVERSE = 7,
    SLOW_BLINK = 5,
  };

  enum BGColor {
    RED_BG = 1,
    WHITE_BG = 255,

    GREEN_BG = 35,
    GREY_BG = 252,
  };

  enum FGColor {
    BLACK_FG = 232,
    WHITE_FG = 231,
    GREEN_FG = 32,

    BLACK_SQ_FG_1 = 233,
    BLACK_SQ_FG_2 = 234,
    BLACK_SQ_FG_3 = 235,
    BLACK_SQ_FG_4 = 236,
    BLACK_SQ_FG_5 = 237,

    WHITE_SQ_FG_1 = 251,
    WHITE_SQ_FG_2 = 252,
    WHITE_SQ_FG_3 = 253,
    WHITE_SQ_FG_4 = 254,
    WHITE_SQ_FG_5 = 255,
  };

  BoxModifier() {}
  virtual ~BoxModifier() {}

  static void add_fg_color(FGColor c, Box *drawing) {
    prepend_mod_as_const_char_array(drawing, modifier_fg_color_to_str(c).c_str());
  }

  static void add_fg_color(std::array<FGColor, Box::kRowSize>& c, Box *drawing) {
    std::array<std::string, Box::kRowSize> codes;
    size_t index = 0;

    for (const FGColor f : c) {
      codes[index++] = modifier_fg_color_to_str(f);
    }

    prepend_mods_as_const_char_array(drawing, codes);
  }

  static void add_bg_color(BGColor c, Box *drawing) {
    prepend_mod_as_const_char_array(drawing, modifier_bg_color_to_str(c).c_str());
  }

  static void add_attribute(Attribute c, Box *drawing) {
    prepend_mod_as_const_char_array(drawing, modifier_to_str(c).c_str());
  };

  static void add_reset_attr(Box *drawing) {
    append_mod_as_const_char_array(drawing, modifier_to_str(RESET).c_str());
  }

  static void remove_mod(ModType mt, Box *drawing) {
    remove_mod(drawing, kMod_regex.at(mt));
  }

 private:
  static void remove_mod_at_row(const std::string& mod, char* arr) {
    static std::regex box_mod_regex;
    static std::string str;

    str = arr;
    box_mod_regex = mod;

    str = std::regex_replace(str, box_mod_regex, "");
    std::strcpy(arr, str.c_str());
  }

  static void remove_mod(Box* box, const std::string& mod) {
    for (int i = 0; i < Box::kRowSize; ++i) {
      remove_mod_at_row(mod, box->content[i]);
    }
  }

  static void append_mod_as_const_char_array(Box* box, const char code[]) { char temp_copy[Box::kCharSize];
    std::string test;

    for (int i = 0; i < Box::kRowSize; ++i) {
      Box::copy_row(temp_copy, box->content[i]);
      Box::copy_row(box->content[i], temp_copy, code);
    }
  }

  static void prepend_mod_as_const_char_array(Box* box, const char code[]) {
    char temp_copy[Box::kCharSize];
    for (int i = 0; i < Box::kRowSize; ++i) {
      Box::copy_row(temp_copy, box->content[i]);
      Box::copy_row(box->content[i], code, temp_copy);
    } 
  }

  static void prepend_mods_as_const_char_array(Box* box, std::array<std::string, Box::kRowSize>& codes) {
    char temp_copy[Box::kCharSize];
    for (size_t i = 0; i < Box::kRowSize; ++i) {
      Box::copy_row(temp_copy, box->content[i]);
      Box::copy_row(box->content[i], codes[i].c_str(), temp_copy);
    }
  }

  static std::string modifier_fg_color_to_str(const FGColor c) {
    return "\033[38;5;" + std::to_string(c) + "m";
  }

  static std::string modifier_bg_color_to_str(const BGColor c) {
    return "\x1B[48;5;" + std::to_string(c) + "m";
  }

  static std::string modifier_to_str(const Attribute a) {
    return "\033[" + std::to_string(a) + "m";
  }

  inline static const std::unordered_map<ModType, std::string> kMod_regex{
      {  ModType::FGCOLOR,  "\033\\[38;5;\\d+m"},
      {  ModType::BGCOLOR,  "\x1B\\[48;5;\\d+m"},
      {ModType::ATTRIBUTE, "\033\\[(?!0m)\\d+m"},
  };
};

#endif /* BOX_MODIFIER_H */
