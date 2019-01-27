#ifndef AIPLAYER_H
#define AIPLAYER_H
#include "player.h"

class AiPlayer : public Player {
public:
  explicit AiPlayer(std::string);
  virtual ~AiPlayer();

  Input *getPlayerNextMove() override;
};

#endif /* AIPLAYER_H */
