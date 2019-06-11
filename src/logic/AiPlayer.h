#ifndef AIPLAYER_H
#define AIPLAYER_H
#include "search.h"
#include "player.h"

class AiPlayer : public Player {
 public:
    explicit AiPlayer(bool has_black_pieces, Search* search);
    virtual ~AiPlayer();

    PlayerMove get_next_move() override;

 private:
    Search* p_search;
    string convert_to_string_pos(Move mv);
};

#endif /* AIPLAYER_H */
