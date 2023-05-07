#ifndef PANE_DRAWINGS_H
#define PANE_DRAWINGS_H
#pragma once

#include <string>

#include "utils/string_utils.h"

namespace PaneDrawings {
namespace Borders {

static const std::string ktop_drawing =
    " ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓";
static const std::string kempty_row =
    " ┃                                                          ┃";
static const std::string krow_divider =
    " ┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃";
static const std::string kbottom_drawing =
    " ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛";

const size_t height = kempty_row.size();
static const size_t width = StringUtils::utf8_strlen(kempty_row.c_str());

}   // namespace Borders
}   // namespace PaneDrawings
#endif /* PANE_DRAWINGS_H */
