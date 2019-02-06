#ifndef PIECE_H
#define PIECE_H
#include "boxStruct.h"
#include "position.h"
#include <iostream>
#include <string>
#include <vector>

class Piece {
private:
protected:
  std::string m_colorPiece;
  bool capturing = false;
  bool captured = false;
  int value = 0;

public:
  Position pos;
  box *pieceCurrentBlackBox = nullptr;
  box *pieceCurrentWhiteBox = nullptr;

  explicit Piece(std::string c);
  virtual ~Piece();

  virtual box *getDrawingBSquare() { return pieceCurrentBlackBox; }
  virtual box *getDrawingWSquare() { return pieceCurrentWhiteBox; }
  virtual bool checkMove(Position, Position) { return false; }
  virtual std::string getPieceType() { return ""; }
  virtual void possibleMoves(std::vector<std::string> &){};
  virtual int getValue() { return value; }

  void setPosition(Position pos);
  Position *getPosition();
  std::string getColorPiece();
  bool isCapturing() { return capturing; }
  bool isCaptured() { return captured; }
  void setCapturingState(bool capturing) { this->capturing = capturing; }
  void setCapturedState(bool captured) { this->captured = captured; }
};

typedef std::vector<Piece *> PiecesSetPtr;

#endif /* PIECE_H */
