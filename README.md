# Trinity Engine
A CLI chess game written in C++17.
The game has two input types, text ie: "a2a4" and 
Keyboard input listening ie: "w,a,s,d" and "arrows:up,down,left,right" and "enter" to move pieces.
Side panes such as info pane and statistics pane can be added to the board window.

[![demo](https://asciinema.org/a/rmERXeUQ3NtZV9hqdSLAoO0nY.svg)](https://asciinema.org/a/rmERXeUQ3NtZV9hqdSLAoO0nY?autoplay=1)
![alt text](https://raw.githubusercontent.com/CLZamb/trinity_engine/dev/chess_screenshot.png)

# Features
## UI
- UI Components
    - Window: Each window can contain up to three panaes.
    - Pane: can contain sub-section
- Menu
    - Welcome menu three option: play, configuration and Quit
- Input
    - Keyboard: Event driven input listening
    - Text: Player types each move ie: "a2a4"
- Board
    - Main Board Pane: shows the board.
    - Info Pane: it shows the side to move(black, white), shows the moves, and captures, and general info such as invalid move.
    - Statistics Pane: WIP
## Chess Engine
- Not Implemented yet, Int this vesion the AI needs to be reimplemented so that the AI can beat previous versions and performs better.
- TODO
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
cmake -S . -B build 
cmake --build build -j 18

```
## Run
```
./build/bin/Chess

```
### To Do
```
- Polyglot
- King Safety
- Center Control
- Game Phases 
- Perft Testing
```

## License
MIT License

Copyright (c) 2023 CLZamb 

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
