#ifndef PANE_DRAWINGS_H
#define PANE_DRAWINGS_H
#include "utils/string_utils.h"
#pragma once

#include <string>

using std::string;

namespace PaneDrawings {
namespace Borders {

static const string ktop_drawing =
  " ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓";
static const string kempty_row =
  " ┃                                                          ┃";
static const string krow_divider =
  " ┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃";
static const string kbottom_drawing =
  " ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛";

const size_t height = kempty_row.size();
static const size_t width = string_utils::utf8_strlen(kempty_row.c_str());

}
}
#endif /* PANE_DRAWINGS_H */
