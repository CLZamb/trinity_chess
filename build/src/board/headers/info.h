#ifndef INFO_H
#define INFO_H

// #include <string>
// #include "utils.h"
#include <assert.h>     /* assert */
#include <memory>
#include <string>
#include <vector>
#include "drawing.hpp"
#include "board.h"

using std::vector;
using std::string;
using std::make_unique;
using std::shared_ptr;

class Info {
 public:
    explicit Info(Board *b);
    virtual ~Info();
    void draw_info_board();
    void _init(Pane* pane);

 private:
    const unsigned int kLineMaxLen = Banner::kBannerLen - 4/*┃  ┃*/;
    void clear_block();
    void recursive_block(shared_ptr<Section>&, string msg, int cur_row);
    void format_block(shared_ptr<Section>&, string msg);
    string format_line(string);
    Pane* m_drawing;
    Board* p_board;
    const vector<string>* p_p1_banner = &Banner::player1;
    const vector<string>* p_p2_banner = &Banner::player2;

    shared_ptr<Section> player_banner;
    shared_ptr<Section> board_score;
    shared_ptr<Section> black_captures;
    shared_ptr<Section> white_captures;
    shared_ptr<Section> black_moves;
    shared_ptr<Section> white_moves;
};

#endif /* INFO_H */
