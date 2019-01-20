#ifndef PIECE_H
#define PIECE_H
// #include "../logic/board.h"
// #include "../display/display.h"
// #include "../logic/box.h"
#include "boxStruct.h"
#include "player.h"
#include "position.h"
#define SH_FG_BLUE "\033[0;34m"
#define SH_DEFAULT "\033[0m"
#define SH_BG_GREEN "\033[0;42m"
#define SH_UNDERLINE "\033[4m"
#define SH_BG_WHITE "\033[1;47m"
#define SH_FG_WHITE "\033[1;37m"
#define SH_FG_LIGHT_GREY "\033[0;37m"
// #include <string>

class Piece {
private:
protected:
  Player *pPlayer;
  bool capturing = false;
  bool knight = false;
  bool king = false;

public:
  Position pos;
  explicit Piece(Player *side);
  virtual ~Piece();

  virtual box *getDrawingBSquare() { return nullptr; }
  virtual box *getDrawingWSquare() { return nullptr; }
  virtual bool checkMove(Position, Position) { return false; }

  Position *getPosition();
  // void pieceDrawing();
  Player *getOwner() { return pPlayer; }
  bool isCapturing() { return capturing; }
  bool isKnight() { return knight; }
  bool isKing() { return king; }
  void setCapturingState(bool capturing) { this->capturing = capturing; }
};

#endif /* PIECE_H */
