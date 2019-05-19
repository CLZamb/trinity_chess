#include "drawings.hpp"

const map<std::string, box> PieceDrawing::piece_drawing = {
  {
    "bishop", box({{
      "█████████",
      "███(/)███",
      "███▙ ▟███",
      "███▀ ▀███",
      "█████████",
    }})
  },
  {
    "king", box({{
      "██▁ ✜ ▁██",
      "█( ╲|╱ )█",
      "██╲▁▁▁╱██",
      "█[▁▁▁▁▁]█",
      "█████████",
    }})
  },
  {
    "knight", box({{
      "█████████",
      "████ █ ██",
      "███    ██",
      "████   ██",
      "█████████",
    }})
  },
  {
    "pawn", box({{
      "█████████",
      "███( )███",
      "███▛ ▜███",
      "██▛   ▜██",
      "█████████",
    }})
  },
  {
    "queen", box({{
      "█████████",
      "██ █ █ ██",
      "██     ██",
      "██     ██",
      "█████████",
    }})
  },
  {
    "rook", box({{
      "█████████",
      "██▀█▀█▀██",
      "██▙   ▟██",
      "██▀   ▀██",
      "█████████",
    }})
  },
  {
    "BaseWhiteSquare", box({{
      "░░░░░░░░░",
      "░░░░░░░░░",
      "░░░░░░░░░",
      "░░░░░░░░░",
      "░░░░░░░░░",
    }})
  },
  {
    "BaseBlackSquare", box({{
      "█████████",
      "█████████",
      "█████████",
      "█████████",
      "█████████",
    }})
  }
};
