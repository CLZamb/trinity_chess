#ifndef AIPLAYER_H
#define AIPLAYER_H
#include "movement.h"

class AiPlayer : public Player {
 public:
    explicit AiPlayer(bool has_black_pieces, Movement* movement_controller);
    virtual ~AiPlayer();

    PlayerMove get_next_move() override;

 private:
    Movement::MoveGenerator* p_move_generator;
    string convert_to_string_pos(Move mv);
    std::vector<string> square_str{65};
};

#endif /* AIPLAYER_H */
