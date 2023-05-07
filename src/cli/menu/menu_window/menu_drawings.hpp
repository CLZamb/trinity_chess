#ifndef MENU_DRAWINGS_H
#define MENU_DRAWINGS_H

#pragma once

#include <string_view>

// ------ TODO ----
// "\t\t**                          Welcome to chess Game                               *\n "
// "\t\t**                            1. New Game                                        *\n "
// "\t\t**                            2. Continue                                      *\n "
// "\t\t**                            3. Load Game                                      *\n "
// "\t\t**                            4. Settings                                      *\n "
// "\t\t**                            5. Quit                                           *\n "

// "\t\t**                          Welcome to chess Game                               *\n "
// "\t\t**                            1. Easy                                           *\n "
// "\t\t**                            2. Normal                                         *\n "
// "\t\t**                            3. Hard                                           *\n "
// "\t\t**                            4. Expert                                         *\n "

namespace MenuDrawings {

constexpr std::string_view left_margin = {"\t\t\t\t┃                            "};
constexpr std::string_view left_margin_selected = {"\t\t\t\t┃                          ➤ "};
constexpr std::string_view right_margin = {"┃"};
constexpr std::string_view empty_row = "\t\t\t\t┃                                                                              ┃";

constexpr std::string_view menu_top =
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
"\t\t\t\t┃                                                                              ┃");
constexpr std::string_view menu_bottom = (
"\t\t\t\t┃                                                                              ┃\n"
"\t\t\t\t┃                                                                              ┃\n"
"\t\t\t\t┃                                                                              ┃\n"
"\t\t\t\t┃                                                                              ┃\n"
"\t\t\t\t┃                                                                              ┃\n"
"\t\t\t\t┃                                                                              ┃\n"
"\t\t\t\t┃                                                                              ┃\n"
"\t\t\t\t┃                                                                              ┃\n"
"\t\t\t\t┃                                                                              ┃\n"
"\t\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");

}  // namespace MenuDrawings


#endif /*  */
