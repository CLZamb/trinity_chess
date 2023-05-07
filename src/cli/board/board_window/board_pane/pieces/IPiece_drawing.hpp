#ifndef IPIECE_DRAWING_H
#define IPIECE_DRAWING_H

#include <memory>
#include "game/game_typedefs.h"
#include "ui_components/box.h"

class IPieceDrawing {
 public:
  virtual std::unique_ptr<IPieceDrawing> clone() = 0;
  virtual ~IPieceDrawing() = default;
  virtual Box &get_drawing() = 0;
  virtual const Color& get_color() const = 0;

};

#endif /* IPIECE_DRAWING_H */
