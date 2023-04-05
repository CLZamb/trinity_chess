#ifndef INFO_DRAWINGS_H
#define INFO_DRAWINGS_H
#pragma once

#include <vector>
#include <string>

using std::vector;
using std::string;

namespace InfoDrawings {
namespace Banner {
  int constexpr length(const char* str) {
    return *str ? 1 + length(str + 1) : 0;
  }

  int constexpr utf8_strlen(const char* str) {
    const int len = length(str);
    int c = 0, i = 0, ix = 0, q = 0;
    for (q=0, i=0, ix=len; i < ix; i++, q++) {
      c = (unsigned char) str[i];
      if      (c >= 0 && c <= 127) i+=0;
      else if ((c & 0xE0) == 0xC0) i+=1;
      else if ((c & 0xF0) == 0xE0) i+=2;
      else if ((c & 0xF8) == 0xF0) i+=3;
      else
        return 0;  // invalid utf8
    }
    return q;
  }

  static const vector<string> player1 = {
    " ┃ ██████╗██╗     █████╗██╗   ███████████████╗      ██╗     ┃",
    " ┃ ██╔══████║    ██╔══██╚██╗ ██╔██╔════██╔══██╗    ███║     ┃",
    " ┃ ██████╔██║    ███████║╚████╔╝█████╗ ██████╔╝    ╚██║     ┃",
    " ┃ ██╔═══╝██║    ██╔══██║ ╚██╔╝ ██╔══╝ ██╔══██╗     ██║     ┃",
    " ┃ ██║    █████████║  ██║  ██║  █████████║  ██║     ██║     ┃",
    " ┃ ╚═╝    ╚══════╚═╝  ╚═╝  ╚═╝  ╚══════╚═╝  ╚═╝     ╚═╝     ┃",
    " ┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃"};

  static const vector<string> player2 = {
    " ┃ ██████╗██╗     █████╗██╗   ███████████████╗     ██████╗  ┃",
    " ┃ ██╔══████║    ██╔══██╚██╗ ██╔██╔════██╔══██╗    ╚════██╗ ┃",
    " ┃ ██████╔██║    ███████║╚████╔╝█████╗ ██████╔╝     █████╔╝ ┃",
    " ┃ ██╔═══╝██║    ██╔══██║ ╚██╔╝ ██╔══╝ ██╔══██╗    ██╔═══╝  ┃",
    " ┃ ██║    █████████║  ██║  ██║  █████████║  ██║    ███████╗ ┃",
    " ┃ ╚═╝    ╚══════╚═╝  ╚═╝  ╚═╝  ╚══════╚═╝  ╚═╝    ╚══════╝ ┃",
    " ┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃"};

  const unsigned long height = player1.size();
  static const int width = utf8_strlen(player1[0].c_str());
}  // namespace Drawing

namespace Borders {
static const string ktop_drawing =
  " ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓";
static const string kempty_row =
  " ┃                                                          ┃";
static const string krow_divider =
  " ┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃";
static const string kbottom_drawing =
  " ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛";
}
}

#endif /* INFO_DRAWINGS_H */
