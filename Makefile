# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.13.4/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.13.4/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/cristofher/Desktop/practice/c++/ChessProject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/cristofher/Desktop/practice/c++/ChessProject

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/local/Cellar/cmake/3.13.4/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/local/Cellar/cmake/3.13.2/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/cristofher/Desktop/practice/c++/ChessProject/CMakeFiles /Users/cristofher/Desktop/practice/c++/ChessProject/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/cristofher/Desktop/practice/c++/ChessProject/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named main

# Build rule for target.
main: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 main
.PHONY : main

# fast build rule for target.
main/fast:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/build
.PHONY : main/fast

display/Idisplay.o: display/Idisplay.cpp.o

.PHONY : display/Idisplay.o

# target to build an object file
display/Idisplay.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/display/Idisplay.cpp.o
.PHONY : display/Idisplay.cpp.o

display/Idisplay.i: display/Idisplay.cpp.i

.PHONY : display/Idisplay.i

# target to preprocess a source file
display/Idisplay.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/display/Idisplay.cpp.i
.PHONY : display/Idisplay.cpp.i

display/Idisplay.s: display/Idisplay.cpp.s

.PHONY : display/Idisplay.s

# target to generate assembly for a file
display/Idisplay.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/display/Idisplay.cpp.s
.PHONY : display/Idisplay.cpp.s

general/game.o: general/game.cpp.o

.PHONY : general/game.o

# target to build an object file
general/game.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/general/game.cpp.o
.PHONY : general/game.cpp.o

general/game.i: general/game.cpp.i

.PHONY : general/game.i

# target to preprocess a source file
general/game.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/general/game.cpp.i
.PHONY : general/game.cpp.i

general/game.s: general/game.cpp.s

.PHONY : general/game.s

# target to generate assembly for a file
general/game.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/general/game.cpp.s
.PHONY : general/game.cpp.s

general/messages.o: general/messages.cpp.o

.PHONY : general/messages.o

# target to build an object file
general/messages.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/general/messages.cpp.o
.PHONY : general/messages.cpp.o

general/messages.i: general/messages.cpp.i

.PHONY : general/messages.i

# target to preprocess a source file
general/messages.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/general/messages.cpp.i
.PHONY : general/messages.cpp.i

general/messages.s: general/messages.cpp.s

.PHONY : general/messages.s

# target to generate assembly for a file
general/messages.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/general/messages.cpp.s
.PHONY : general/messages.cpp.s

general/pieces/bishop.o: general/pieces/bishop.cpp.o

.PHONY : general/pieces/bishop.o

# target to build an object file
general/pieces/bishop.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/general/pieces/bishop.cpp.o
.PHONY : general/pieces/bishop.cpp.o

general/pieces/bishop.i: general/pieces/bishop.cpp.i

.PHONY : general/pieces/bishop.i

# target to preprocess a source file
general/pieces/bishop.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/general/pieces/bishop.cpp.i
.PHONY : general/pieces/bishop.cpp.i

general/pieces/bishop.s: general/pieces/bishop.cpp.s

.PHONY : general/pieces/bishop.s

# target to generate assembly for a file
general/pieces/bishop.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/general/pieces/bishop.cpp.s
.PHONY : general/pieces/bishop.cpp.s

general/pieces/king.o: general/pieces/king.cpp.o

.PHONY : general/pieces/king.o

# target to build an object file
general/pieces/king.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/general/pieces/king.cpp.o
.PHONY : general/pieces/king.cpp.o

general/pieces/king.i: general/pieces/king.cpp.i

.PHONY : general/pieces/king.i

# target to preprocess a source file
general/pieces/king.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/general/pieces/king.cpp.i
.PHONY : general/pieces/king.cpp.i

general/pieces/king.s: general/pieces/king.cpp.s

.PHONY : general/pieces/king.s

# target to generate assembly for a file
general/pieces/king.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/general/pieces/king.cpp.s
.PHONY : general/pieces/king.cpp.s

general/pieces/knight.o: general/pieces/knight.cpp.o

.PHONY : general/pieces/knight.o

# target to build an object file
general/pieces/knight.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/general/pieces/knight.cpp.o
.PHONY : general/pieces/knight.cpp.o

general/pieces/knight.i: general/pieces/knight.cpp.i

.PHONY : general/pieces/knight.i

# target to preprocess a source file
general/pieces/knight.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/general/pieces/knight.cpp.i
.PHONY : general/pieces/knight.cpp.i

general/pieces/knight.s: general/pieces/knight.cpp.s

.PHONY : general/pieces/knight.s

# target to generate assembly for a file
general/pieces/knight.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/general/pieces/knight.cpp.s
.PHONY : general/pieces/knight.cpp.s

general/pieces/pawn.o: general/pieces/pawn.cpp.o

.PHONY : general/pieces/pawn.o

# target to build an object file
general/pieces/pawn.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/general/pieces/pawn.cpp.o
.PHONY : general/pieces/pawn.cpp.o

general/pieces/pawn.i: general/pieces/pawn.cpp.i

.PHONY : general/pieces/pawn.i

# target to preprocess a source file
general/pieces/pawn.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/general/pieces/pawn.cpp.i
.PHONY : general/pieces/pawn.cpp.i

general/pieces/pawn.s: general/pieces/pawn.cpp.s

.PHONY : general/pieces/pawn.s

# target to generate assembly for a file
general/pieces/pawn.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/general/pieces/pawn.cpp.s
.PHONY : general/pieces/pawn.cpp.s

general/pieces/piece.o: general/pieces/piece.cpp.o

.PHONY : general/pieces/piece.o

# target to build an object file
general/pieces/piece.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/general/pieces/piece.cpp.o
.PHONY : general/pieces/piece.cpp.o

general/pieces/piece.i: general/pieces/piece.cpp.i

.PHONY : general/pieces/piece.i

# target to preprocess a source file
general/pieces/piece.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/general/pieces/piece.cpp.i
.PHONY : general/pieces/piece.cpp.i

general/pieces/piece.s: general/pieces/piece.cpp.s

.PHONY : general/pieces/piece.s

# target to generate assembly for a file
general/pieces/piece.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/general/pieces/piece.cpp.s
.PHONY : general/pieces/piece.cpp.s

general/pieces/queen.o: general/pieces/queen.cpp.o

.PHONY : general/pieces/queen.o

# target to build an object file
general/pieces/queen.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/general/pieces/queen.cpp.o
.PHONY : general/pieces/queen.cpp.o

general/pieces/queen.i: general/pieces/queen.cpp.i

.PHONY : general/pieces/queen.i

# target to preprocess a source file
general/pieces/queen.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/general/pieces/queen.cpp.i
.PHONY : general/pieces/queen.cpp.i

general/pieces/queen.s: general/pieces/queen.cpp.s

.PHONY : general/pieces/queen.s

# target to generate assembly for a file
general/pieces/queen.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/general/pieces/queen.cpp.s
.PHONY : general/pieces/queen.cpp.s

general/pieces/rook.o: general/pieces/rook.cpp.o

.PHONY : general/pieces/rook.o

# target to build an object file
general/pieces/rook.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/general/pieces/rook.cpp.o
.PHONY : general/pieces/rook.cpp.o

general/pieces/rook.i: general/pieces/rook.cpp.i

.PHONY : general/pieces/rook.i

# target to preprocess a source file
general/pieces/rook.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/general/pieces/rook.cpp.i
.PHONY : general/pieces/rook.cpp.i

general/pieces/rook.s: general/pieces/rook.cpp.s

.PHONY : general/pieces/rook.s

# target to generate assembly for a file
general/pieces/rook.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/general/pieces/rook.cpp.s
.PHONY : general/pieces/rook.cpp.s

logic/AiPlayer.o: logic/AiPlayer.cpp.o

.PHONY : logic/AiPlayer.o

# target to build an object file
logic/AiPlayer.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/logic/AiPlayer.cpp.o
.PHONY : logic/AiPlayer.cpp.o

logic/AiPlayer.i: logic/AiPlayer.cpp.i

.PHONY : logic/AiPlayer.i

# target to preprocess a source file
logic/AiPlayer.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/logic/AiPlayer.cpp.i
.PHONY : logic/AiPlayer.cpp.i

logic/AiPlayer.s: logic/AiPlayer.cpp.s

.PHONY : logic/AiPlayer.s

# target to generate assembly for a file
logic/AiPlayer.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/logic/AiPlayer.cpp.s
.PHONY : logic/AiPlayer.cpp.s

logic/Transposition_table_entry.o: logic/Transposition_table_entry.cpp.o

.PHONY : logic/Transposition_table_entry.o

# target to build an object file
logic/Transposition_table_entry.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/logic/Transposition_table_entry.cpp.o
.PHONY : logic/Transposition_table_entry.cpp.o

logic/Transposition_table_entry.i: logic/Transposition_table_entry.cpp.i

.PHONY : logic/Transposition_table_entry.i

# target to preprocess a source file
logic/Transposition_table_entry.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/logic/Transposition_table_entry.cpp.i
.PHONY : logic/Transposition_table_entry.cpp.i

logic/Transposition_table_entry.s: logic/Transposition_table_entry.cpp.s

.PHONY : logic/Transposition_table_entry.s

# target to generate assembly for a file
logic/Transposition_table_entry.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/logic/Transposition_table_entry.cpp.s
.PHONY : logic/Transposition_table_entry.cpp.s

logic/ZobristKey.o: logic/ZobristKey.cpp.o

.PHONY : logic/ZobristKey.o

# target to build an object file
logic/ZobristKey.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/logic/ZobristKey.cpp.o
.PHONY : logic/ZobristKey.cpp.o

logic/ZobristKey.i: logic/ZobristKey.cpp.i

.PHONY : logic/ZobristKey.i

# target to preprocess a source file
logic/ZobristKey.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/logic/ZobristKey.cpp.i
.PHONY : logic/ZobristKey.cpp.i

logic/ZobristKey.s: logic/ZobristKey.cpp.s

.PHONY : logic/ZobristKey.s

# target to generate assembly for a file
logic/ZobristKey.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/logic/ZobristKey.cpp.s
.PHONY : logic/ZobristKey.cpp.s

logic/bitboard.o: logic/bitboard.cpp.o

.PHONY : logic/bitboard.o

# target to build an object file
logic/bitboard.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/logic/bitboard.cpp.o
.PHONY : logic/bitboard.cpp.o

logic/bitboard.i: logic/bitboard.cpp.i

.PHONY : logic/bitboard.i

# target to preprocess a source file
logic/bitboard.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/logic/bitboard.cpp.i
.PHONY : logic/bitboard.cpp.i

logic/bitboard.s: logic/bitboard.cpp.s

.PHONY : logic/bitboard.s

# target to generate assembly for a file
logic/bitboard.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/logic/bitboard.cpp.s
.PHONY : logic/bitboard.cpp.s

logic/board.o: logic/board.cpp.o

.PHONY : logic/board.o

# target to build an object file
logic/board.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/logic/board.cpp.o
.PHONY : logic/board.cpp.o

logic/board.i: logic/board.cpp.i

.PHONY : logic/board.i

# target to preprocess a source file
logic/board.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/logic/board.cpp.i
.PHONY : logic/board.cpp.i

logic/board.s: logic/board.cpp.s

.PHONY : logic/board.s

# target to generate assembly for a file
logic/board.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/logic/board.cpp.s
.PHONY : logic/board.cpp.s

logic/movement.o: logic/movement.cpp.o

.PHONY : logic/movement.o

# target to build an object file
logic/movement.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/logic/movement.cpp.o
.PHONY : logic/movement.cpp.o

logic/movement.i: logic/movement.cpp.i

.PHONY : logic/movement.i

# target to preprocess a source file
logic/movement.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/logic/movement.cpp.i
.PHONY : logic/movement.cpp.i

logic/movement.s: logic/movement.cpp.s

.PHONY : logic/movement.s

# target to generate assembly for a file
logic/movement.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/logic/movement.cpp.s
.PHONY : logic/movement.cpp.s

logic/player.o: logic/player.cpp.o

.PHONY : logic/player.o

# target to build an object file
logic/player.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/logic/player.cpp.o
.PHONY : logic/player.cpp.o

logic/player.i: logic/player.cpp.i

.PHONY : logic/player.i

# target to preprocess a source file
logic/player.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/logic/player.cpp.i
.PHONY : logic/player.cpp.i

logic/player.s: logic/player.cpp.s

.PHONY : logic/player.s

# target to generate assembly for a file
logic/player.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/logic/player.cpp.s
.PHONY : logic/player.cpp.s

logic/transposition_table.o: logic/transposition_table.cpp.o

.PHONY : logic/transposition_table.o

# target to build an object file
logic/transposition_table.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/logic/transposition_table.cpp.o
.PHONY : logic/transposition_table.cpp.o

logic/transposition_table.i: logic/transposition_table.cpp.i

.PHONY : logic/transposition_table.i

# target to preprocess a source file
logic/transposition_table.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/logic/transposition_table.cpp.i
.PHONY : logic/transposition_table.cpp.i

logic/transposition_table.s: logic/transposition_table.cpp.s

.PHONY : logic/transposition_table.s

# target to generate assembly for a file
logic/transposition_table.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/logic/transposition_table.cpp.s
.PHONY : logic/transposition_table.cpp.s

main.o: main.cpp.o

.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i

.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s

.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/main.cpp.s
.PHONY : main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... main"
	@echo "... display/Idisplay.o"
	@echo "... display/Idisplay.i"
	@echo "... display/Idisplay.s"
	@echo "... general/game.o"
	@echo "... general/game.i"
	@echo "... general/game.s"
	@echo "... general/messages.o"
	@echo "... general/messages.i"
	@echo "... general/messages.s"
	@echo "... general/pieces/bishop.o"
	@echo "... general/pieces/bishop.i"
	@echo "... general/pieces/bishop.s"
	@echo "... general/pieces/king.o"
	@echo "... general/pieces/king.i"
	@echo "... general/pieces/king.s"
	@echo "... general/pieces/knight.o"
	@echo "... general/pieces/knight.i"
	@echo "... general/pieces/knight.s"
	@echo "... general/pieces/pawn.o"
	@echo "... general/pieces/pawn.i"
	@echo "... general/pieces/pawn.s"
	@echo "... general/pieces/piece.o"
	@echo "... general/pieces/piece.i"
	@echo "... general/pieces/piece.s"
	@echo "... general/pieces/queen.o"
	@echo "... general/pieces/queen.i"
	@echo "... general/pieces/queen.s"
	@echo "... general/pieces/rook.o"
	@echo "... general/pieces/rook.i"
	@echo "... general/pieces/rook.s"
	@echo "... logic/AiPlayer.o"
	@echo "... logic/AiPlayer.i"
	@echo "... logic/AiPlayer.s"
	@echo "... logic/Transposition_table_entry.o"
	@echo "... logic/Transposition_table_entry.i"
	@echo "... logic/Transposition_table_entry.s"
	@echo "... logic/ZobristKey.o"
	@echo "... logic/ZobristKey.i"
	@echo "... logic/ZobristKey.s"
	@echo "... logic/bitboard.o"
	@echo "... logic/bitboard.i"
	@echo "... logic/bitboard.s"
	@echo "... logic/board.o"
	@echo "... logic/board.i"
	@echo "... logic/board.s"
	@echo "... logic/movement.o"
	@echo "... logic/movement.i"
	@echo "... logic/movement.s"
	@echo "... logic/player.o"
	@echo "... logic/player.i"
	@echo "... logic/player.s"
	@echo "... logic/transposition_table.o"
	@echo "... logic/transposition_table.i"
	@echo "... logic/transposition_table.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

