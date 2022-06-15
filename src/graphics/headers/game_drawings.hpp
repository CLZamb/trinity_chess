#ifndef GAME_DRAWINGS_H
#define GAME_DRAWINGS_H

#pragma once

#include<vector>
#include<unordered_map>
#include<string>
#include"box.h"
using std::string;

namespace DrawingPieces {
  static const string bishop_str_name = "bishop"; 
  static const string king_str_name   = "king"; 
  static const string knight_str_name = "knight"; 
  static const string pawn_str_name   = "pawn"; 
  static const string queen_str_name  = "queen"; 
  static const string rook_str_name   = "rook"; 
  static const string white_square_str_name = "WhiteSquare";
  static const string black_square_str_name = "BlackSquare";

static const std::unordered_map<std::string, Box> const_piece_drawing = {
  {
    bishop_str_name,
    {{
       "   ▗◘▖   ",
       "   ▚/▞   ",
       "    █    ",
       "   ▟█▙   ",
       "         ",
     }}
  },
  {
    king_str_name,
    {{
       "  ▁ ✜ ▁  ",
       " ( ╲|╱ ) ",
       "  ╲███╱  ",
       " [█████] ",
       "         ",
     }}
  },
  {
    knight_str_name,
    {{
       "         ",
       "   █ █   ",
       "  ████   ",
       "   ███   ",
       "         ",
     }}
  },
  {
    pawn_str_name,
    {{
       "   ▗▄▖   ",
       "   ▜█▛   ",
       "   ▗█▖   ",
       "  ▗███▖  ",
       "         ",
     }}
  },
  {
    queen_str_name,
    {{
       "         ",
       "  █ █ █  ",
       "  █████  ",
       "  █████  ",
       "         ",
     }}
  },
  {
    rook_str_name,
    {{
       "  ▄ ▄ ▄  ",
       "  ▜███▛  ",
       "   ███   ",
       " ▄█████▄ ",
       "         ",
     }}

  },
  {
    white_square_str_name,
    {{
       "\033[38;5;251m█████████\033[0m",
       "\033[38;5;252m█████████\033[0m",
       "\033[38;5;253m█████████\033[0m",
       "\033[38;5;254m█████████\033[0m",
       "\033[38;5;255m█████████\033[0m",
     }}
  },
  {
    black_square_str_name,
    {{
       "\033[38;5;232m█████████\033[0m",
       "\033[38;5;233m█████████\033[0m",
       "\033[38;5;234m█████████\033[0m",
       "\033[38;5;235m█████████\033[0m",
       "\033[38;5;236m█████████\033[0m",
     }}
  },
};

}

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

  static const std::vector<std::string> player1 = {
    " ┃ ██████╗██╗     █████╗██╗   ███████████████╗      ██╗     ┃",
    " ┃ ██╔══████║    ██╔══██╚██╗ ██╔██╔════██╔══██╗    ███║     ┃",
    " ┃ ██████╔██║    ███████║╚████╔╝█████╗ ██████╔╝    ╚██║     ┃",
    " ┃ ██╔═══╝██║    ██╔══██║ ╚██╔╝ ██╔══╝ ██╔══██╗     ██║     ┃",
    " ┃ ██║    █████████║  ██║  ██║  █████████║  ██║     ██║     ┃",
    " ┃ ╚═╝    ╚══════╚═╝  ╚═╝  ╚═╝  ╚══════╚═╝  ╚═╝     ╚═╝     ┃",
    " ┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃"};

  static const std::vector<std::string> player2 = {
    " ┃ ██████╗██╗     █████╗██╗   ███████████████╗     ██████╗  ┃",
    " ┃ ██╔══████║    ██╔══██╚██╗ ██╔██╔════██╔══██╗    ╚════██╗ ┃",
    " ┃ ██████╔██║    ███████║╚████╔╝█████╗ ██████╔╝     █████╔╝ ┃",
    " ┃ ██╔═══╝██║    ██╔══██║ ╚██╔╝ ██╔══╝ ██╔══██╗    ██╔═══╝  ┃",
    " ┃ ██║    █████████║  ██║  ██║  █████████║  ██║    ███████╗ ┃",
    " ┃ ╚═╝    ╚══════╚═╝  ╚═╝  ╚═╝  ╚══════╚═╝  ╚═╝    ╚══════╝ ┃",
    " ┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃"};

  const int height = player1.size();
  static const int width = utf8_strlen(player1[0].c_str());
}  // namespace Drawing

namespace MenuDrawings {
constexpr std::string_view p_menu_top =
(
"\t\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n"
"\t\t\t\t┃                                                                              ┃\n"
"\t\t\t\t┃                                                                              ┃\n"
"\t\t\t\t┃                                                                              ┃\n"
"\t\t\t\t┃                       ██████╗██╗  ██╗███████╗███████╗███████╗                ┃\n"
"\t\t\t\t┃                      ██╔════╝██║  ██║██╔════╝██╔════╝██╔════╝                ┃\n"
"\t\t\t\t┃                      ██║     ███████║█████╗  ███████╗███████╗                ┃\n"
"\t\t\t\t┃                      ██║     ██╔══██║██╔══╝  ╚════██║╚════██║                ┃\n"
"\t\t\t\t┃                      ╚██████╗██║  ██║███████╗███████║███████║                ┃\n"
"\t\t\t\t┃                       ╚═════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝                ┃\n"
"\t\t\t\t┃                                                                              ┃\n"
"\t\t\t\t┃                                                                              ┃\n"
"\t\t\t\t┃                                                                              ┃\n"
"\t\t\t\t┃                                                                              ┃\n"
"\t\t\t\t┃                                                                              ┃\n"
"\t\t\t\t┃                                                                              ┃\n"
"\t\t\t\t┃                                                                              ┃\n"
"\t\t\t\t┃                                                                              ┃\n"
"\t\t\t\t┃                                                                              ┃"
);

constexpr std::string_view left_margin = {"\t\t\t\t┃                            "};
constexpr std::string_view left_margin_selected = {"\t\t\t\t┃                          ➤ "};
constexpr std::string_view empty_row = "\t\t\t\t┃                                                                              ┃";

constexpr std::string_view right_margin = {"┃"};
constexpr std::string_view p_menu_bottom = (
"\t\t\t\t┃                                                                              ┃\n"
"\t\t\t\t┃                                                                              ┃\n"
"\t\t\t\t┃                                                                              ┃\n"
"\t\t\t\t┃                                                                              ┃\n"
"\t\t\t\t┃                                                                              ┃\n"
"\t\t\t\t┃                                                                              ┃\n"
"\t\t\t\t┃                                                                              ┃\n"
"\t\t\t\t┃                                                                              ┃\n"
"\t\t\t\t┃                                                                              ┃\n"
"\t\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n"
);

} // MenuDrawinge GameDrawings

// "\t\t**                          Welcome to chess Game                               *\n "
// "\t\t**                            1. New Game                                       *\n "
// "\t\t**                            2. Continue                                       *\n "
// "\t\t**                            3. Load Game                                      *\n "
// "\t\t**                            4. Setting                                        *\n "
// "\t\t**                            5. Quit                                           *\n "

// "\t\t**                          Welcome to chess Game                               *\n "
// "\t\t**                            1. Easy                                           *\n "
// "\t\t**                            2. Normal                                         *\n "
// "\t\t**                            3. Hard                                           *\n "
// "\t\t**                            4. Expert                                         *\n "

namespace GameDrawing {

constexpr std::string_view game_over =
(
 "   ███████████████████████████████████████████████████████████\n"
 "   ███████████████████████████████████████████████████████████\n"
 "   ███████████████████████████████████████████████████████████\n"
 "   ███████████████████████████████████████████████████████████\n"
 "   ████████████▀▀▀▀▀▀▀███▛▀▀▀▀███▛▀▀████▀▀▀█▀▀▀▀▀▀▀▀▀▜████████\n"
 "   ███████████  ▐███████▌ ▖█▌▗ ██▌ ▖ ▐█  ▖ █ ▗▐███████████████\n"
 "   █████████▌  ████████  ▖████  ▐▌  ▖▗  ▘ ▝█▗ ▐███████████████\n"
 "   █████████▌ ▘███▄▖▖ █ ▘ ▀▀▀▀ ▘▐▌▘▖▄▖ ▙▖▗ █ ▗▗▄▄▄▟███████████\n"
 "   █████████▙▙ ▀▜██▌ ▘█▘▖▘▙▙▟▄▘▝▐▛▗ █▙▙█▌▗▝█▝▗▐███████████████\n"
 "   ████████████▚▗▘▖▝▝▝█▖▖▚████▝▝▟▙▗▝▟███▞▗▗█▘▖▖▘▖▖▖▖▖▟████████\n"
 "   ███████████▀▛▀▛▜▜▜██▜▀▛████▜▜▜▛▜▜▜▜▀▛▜▀▛█▜▜▜▜▜▀▛▜██████████\n"
 "   █████████▛▀▞▟█▟▙▌▀▌█▚▚▜████▐▗▜▛▞▖████████▚▐▐▟▟▙▙▚▐▐████████\n"
 "   █████████▛▌▙████▌▛▞█▌▌▙████▚▌█▛▞▞████████▚▌████▙▚▙▜████████\n"
 "   ██████████▟▞████▜▟▜██▟▚▛█▜▟▚█▟█▜▜▟▟▟▟████▙▜▟█▛█▟▙▙█████████\n"
 "   █████████▙▙▜█████▞▛████▞▙█▟███▛▛▙████████▟▜▟▟▟▙▜███████████\n"
 "   ██████████▟▛▟▜▟▜▟▟████▙█▙▙█████▜▟▜▜▛▛▛▛▛█▟▜▟█▙▛▙▙▜█████████\n"
 "   ███████████████████████████████████████████████████████████\n"
 "   ███████████████████████████████████████████████████████████\n"
 "   ███████████████████████████████████████████████████████████\n"
 "   ███████████████████████████████████████████████████████████\n"
);

} // Game Drawing
#endif /*  */
