#ifndef INFO_DRAWINGS_H
#define INFO_DRAWINGS_H
#pragma once

#include <string>
#include <vector>

#include "utils/string_utils.h"

namespace InfoBanners {
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
static const size_t width = StringUtils::utf8_strlen(white[0].c_str());
}   // namespace InfoBanners
#endif /* INFO_DRAWINGS_H */
