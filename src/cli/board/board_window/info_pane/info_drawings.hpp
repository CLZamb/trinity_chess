#ifndef INFO_DRAWINGS_H
#define INFO_DRAWINGS_H
#pragma once

#include <string>
#include <vector>

#include "utils/string_utils.h"

namespace InfoDrawings {
namespace Banner {
static const std::vector<std::string> white = {
    " ┃      ██╗    ██╗██╗  ██╗██╗████████╗███████╗              ┃",
    " ┃      ██║    ██║██║  ██║██║╚══██╔══╝██╔════╝              ┃",
    " ┃      ██║ █╗ ██║███████║██║   ██║   █████╗                ┃",
    " ┃      ██║███╗██║██╔══██║██║   ██║   ██╔══╝                ┃",
    " ┃      ╚███╔███╔╝██║  ██║██║   ██║   ███████╗              ┃",
    " ┃       ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝   ╚═╝   ╚══════╝              ┃",
    " ┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃"};

static const std::vector<std::string> black = {
    " ┃      ██████╗ ██╗      █████╗  ██████╗██╗  ██╗            ┃",
    " ┃      ██╔══██╗██║     ██╔══██╗██╔════╝██║ ██╔╝            ┃",
    " ┃      ██████╔╝██║     ███████║██║     █████╔╝             ┃",
    " ┃      ██╔══██╗██║     ██╔══██║██║     ██╔═██╗             ┃",
    " ┃      ██████╔╝███████╗██║  ██║╚██████╗██║  ██╗            ┃",
    " ┃      ╚═════╝ ╚══════╝╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝            ┃",
    " ┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃"};

const size_t height = white.size();
static const size_t width = string_utils::utf8_strlen(white[0].c_str());
}   // namespace Banner
}   // namespace InfoDrawings

#endif /* INFO_DRAWINGS_H */
