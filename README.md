chess engine written in C++17

# Trinity Engine
[![demo](https://asciinema.org/a/rmERXeUQ3NtZV9hqdSLAoO0nY.svg)](https://asciinema.org/a/rmERXeUQ3NtZV9hqdSLAoO0nY?autoplay=1)
![alt text](https://raw.githubusercontent.com/CLZamb/trinity_engine/v1/chess_screenshot.png)

## Features
- Board representation
    - [Bitboards](https://en.wikipedia.org/wiki/Bitboard)
- Move generation
    - [Magic bitboard hashing](https://www.chessprogramming.org/Magic_Bitboards)
- Search
    - [Negamax search](https://www.chessprogramming.org/Negamax)
    - [Principal variation search](https://www.chessprogramming.org/Principal_Variation_Search)
    - [Iterative deepening](https://en.wikipedia.org/wiki/Iterative_deepening_depth-first_search)
    - [Quiescence search](https://en.wikipedia.org/wiki/Quiescence_search)
- Evaluation
    - [Piece square tables](https://www.chessprogramming.org/Piece-Square_Tables)
    - [Pawn structure](https://www.chessprogramming.org/Pawn_Structure)
    - [Mobility](https://www.chessprogramming.org/Mobility)
- Move ordering
    - [Hash move](https://www.chessprogramming.org/Hash_Move)
    - [MVV/LVA](https://www.chessprogramming.org/MVV-LVA)
    - [Killer heuristic](https://www.chessprogramming.org/Killer_Heuristic)
    - [History heuristic](https://www.chessprogramming.org/History_Heuristic)
- Other
    - [Zobrist hashing](https://www.chessprogramming.org/Zobrist_Hashing) / [Transposition table](https://en.wikipedia.org/wiki/Transposition_table)
    - [Null move pruning](https://www.chessprogramming.org/Null_Move_Pruning)

## Building
Unix:
```
cmake .
make
```
## Run
```
./main
```
### To Do
- Polyglot
- King Safety
- Center Control
- Game Phases 
- Perft Testing

## License
MIT License

Copyright (c) 2019 Cristian L Zambrano

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
