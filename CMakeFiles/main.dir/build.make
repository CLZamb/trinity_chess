# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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

# Include any dependencies generated for this target.
include CMakeFiles/main.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.dir/flags.make

CMakeFiles/main.dir/main.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/cristofher/Desktop/practice/c++/ChessProject/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/main.cpp.o -c /Users/cristofher/Desktop/practice/c++/ChessProject/main.cpp

CMakeFiles/main.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/cristofher/Desktop/practice/c++/ChessProject/main.cpp > CMakeFiles/main.dir/main.cpp.i

CMakeFiles/main.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/cristofher/Desktop/practice/c++/ChessProject/main.cpp -o CMakeFiles/main.dir/main.cpp.s

CMakeFiles/main.dir/logic/board.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/logic/board.cpp.o: logic/board.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/cristofher/Desktop/practice/c++/ChessProject/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/main.dir/logic/board.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/logic/board.cpp.o -c /Users/cristofher/Desktop/practice/c++/ChessProject/logic/board.cpp

CMakeFiles/main.dir/logic/board.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/logic/board.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/cristofher/Desktop/practice/c++/ChessProject/logic/board.cpp > CMakeFiles/main.dir/logic/board.cpp.i

CMakeFiles/main.dir/logic/board.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/logic/board.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/cristofher/Desktop/practice/c++/ChessProject/logic/board.cpp -o CMakeFiles/main.dir/logic/board.cpp.s

CMakeFiles/main.dir/logic/player.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/logic/player.cpp.o: logic/player.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/cristofher/Desktop/practice/c++/ChessProject/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/main.dir/logic/player.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/logic/player.cpp.o -c /Users/cristofher/Desktop/practice/c++/ChessProject/logic/player.cpp

CMakeFiles/main.dir/logic/player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/logic/player.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/cristofher/Desktop/practice/c++/ChessProject/logic/player.cpp > CMakeFiles/main.dir/logic/player.cpp.i

CMakeFiles/main.dir/logic/player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/logic/player.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/cristofher/Desktop/practice/c++/ChessProject/logic/player.cpp -o CMakeFiles/main.dir/logic/player.cpp.s

CMakeFiles/main.dir/logic/AiPlayer.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/logic/AiPlayer.cpp.o: logic/AiPlayer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/cristofher/Desktop/practice/c++/ChessProject/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/main.dir/logic/AiPlayer.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/logic/AiPlayer.cpp.o -c /Users/cristofher/Desktop/practice/c++/ChessProject/logic/AiPlayer.cpp

CMakeFiles/main.dir/logic/AiPlayer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/logic/AiPlayer.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/cristofher/Desktop/practice/c++/ChessProject/logic/AiPlayer.cpp > CMakeFiles/main.dir/logic/AiPlayer.cpp.i

CMakeFiles/main.dir/logic/AiPlayer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/logic/AiPlayer.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/cristofher/Desktop/practice/c++/ChessProject/logic/AiPlayer.cpp -o CMakeFiles/main.dir/logic/AiPlayer.cpp.s

CMakeFiles/main.dir/logic/movement.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/logic/movement.cpp.o: logic/movement.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/cristofher/Desktop/practice/c++/ChessProject/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/main.dir/logic/movement.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/logic/movement.cpp.o -c /Users/cristofher/Desktop/practice/c++/ChessProject/logic/movement.cpp

CMakeFiles/main.dir/logic/movement.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/logic/movement.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/cristofher/Desktop/practice/c++/ChessProject/logic/movement.cpp > CMakeFiles/main.dir/logic/movement.cpp.i

CMakeFiles/main.dir/logic/movement.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/logic/movement.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/cristofher/Desktop/practice/c++/ChessProject/logic/movement.cpp -o CMakeFiles/main.dir/logic/movement.cpp.s

CMakeFiles/main.dir/logic/bitboard.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/logic/bitboard.cpp.o: logic/bitboard.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/cristofher/Desktop/practice/c++/ChessProject/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/main.dir/logic/bitboard.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/logic/bitboard.cpp.o -c /Users/cristofher/Desktop/practice/c++/ChessProject/logic/bitboard.cpp

CMakeFiles/main.dir/logic/bitboard.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/logic/bitboard.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/cristofher/Desktop/practice/c++/ChessProject/logic/bitboard.cpp > CMakeFiles/main.dir/logic/bitboard.cpp.i

CMakeFiles/main.dir/logic/bitboard.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/logic/bitboard.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/cristofher/Desktop/practice/c++/ChessProject/logic/bitboard.cpp -o CMakeFiles/main.dir/logic/bitboard.cpp.s

CMakeFiles/main.dir/logic/transposition_table.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/logic/transposition_table.cpp.o: logic/transposition_table.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/cristofher/Desktop/practice/c++/ChessProject/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/main.dir/logic/transposition_table.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/logic/transposition_table.cpp.o -c /Users/cristofher/Desktop/practice/c++/ChessProject/logic/transposition_table.cpp

CMakeFiles/main.dir/logic/transposition_table.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/logic/transposition_table.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/cristofher/Desktop/practice/c++/ChessProject/logic/transposition_table.cpp > CMakeFiles/main.dir/logic/transposition_table.cpp.i

CMakeFiles/main.dir/logic/transposition_table.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/logic/transposition_table.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/cristofher/Desktop/practice/c++/ChessProject/logic/transposition_table.cpp -o CMakeFiles/main.dir/logic/transposition_table.cpp.s

CMakeFiles/main.dir/logic/Transposition_table_entry.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/logic/Transposition_table_entry.cpp.o: logic/Transposition_table_entry.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/cristofher/Desktop/practice/c++/ChessProject/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/main.dir/logic/Transposition_table_entry.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/logic/Transposition_table_entry.cpp.o -c /Users/cristofher/Desktop/practice/c++/ChessProject/logic/Transposition_table_entry.cpp

CMakeFiles/main.dir/logic/Transposition_table_entry.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/logic/Transposition_table_entry.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/cristofher/Desktop/practice/c++/ChessProject/logic/Transposition_table_entry.cpp > CMakeFiles/main.dir/logic/Transposition_table_entry.cpp.i

CMakeFiles/main.dir/logic/Transposition_table_entry.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/logic/Transposition_table_entry.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/cristofher/Desktop/practice/c++/ChessProject/logic/Transposition_table_entry.cpp -o CMakeFiles/main.dir/logic/Transposition_table_entry.cpp.s

CMakeFiles/main.dir/logic/ZobristKey.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/logic/ZobristKey.cpp.o: logic/ZobristKey.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/cristofher/Desktop/practice/c++/ChessProject/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/main.dir/logic/ZobristKey.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/logic/ZobristKey.cpp.o -c /Users/cristofher/Desktop/practice/c++/ChessProject/logic/ZobristKey.cpp

CMakeFiles/main.dir/logic/ZobristKey.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/logic/ZobristKey.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/cristofher/Desktop/practice/c++/ChessProject/logic/ZobristKey.cpp > CMakeFiles/main.dir/logic/ZobristKey.cpp.i

CMakeFiles/main.dir/logic/ZobristKey.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/logic/ZobristKey.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/cristofher/Desktop/practice/c++/ChessProject/logic/ZobristKey.cpp -o CMakeFiles/main.dir/logic/ZobristKey.cpp.s

CMakeFiles/main.dir/display/Idisplay.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/display/Idisplay.cpp.o: display/Idisplay.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/cristofher/Desktop/practice/c++/ChessProject/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/main.dir/display/Idisplay.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/display/Idisplay.cpp.o -c /Users/cristofher/Desktop/practice/c++/ChessProject/display/Idisplay.cpp

CMakeFiles/main.dir/display/Idisplay.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/display/Idisplay.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/cristofher/Desktop/practice/c++/ChessProject/display/Idisplay.cpp > CMakeFiles/main.dir/display/Idisplay.cpp.i

CMakeFiles/main.dir/display/Idisplay.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/display/Idisplay.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/cristofher/Desktop/practice/c++/ChessProject/display/Idisplay.cpp -o CMakeFiles/main.dir/display/Idisplay.cpp.s

CMakeFiles/main.dir/general/game.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/general/game.cpp.o: general/game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/cristofher/Desktop/practice/c++/ChessProject/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/main.dir/general/game.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/general/game.cpp.o -c /Users/cristofher/Desktop/practice/c++/ChessProject/general/game.cpp

CMakeFiles/main.dir/general/game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/general/game.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/cristofher/Desktop/practice/c++/ChessProject/general/game.cpp > CMakeFiles/main.dir/general/game.cpp.i

CMakeFiles/main.dir/general/game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/general/game.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/cristofher/Desktop/practice/c++/ChessProject/general/game.cpp -o CMakeFiles/main.dir/general/game.cpp.s

CMakeFiles/main.dir/general/messages.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/general/messages.cpp.o: general/messages.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/cristofher/Desktop/practice/c++/ChessProject/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/main.dir/general/messages.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/general/messages.cpp.o -c /Users/cristofher/Desktop/practice/c++/ChessProject/general/messages.cpp

CMakeFiles/main.dir/general/messages.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/general/messages.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/cristofher/Desktop/practice/c++/ChessProject/general/messages.cpp > CMakeFiles/main.dir/general/messages.cpp.i

CMakeFiles/main.dir/general/messages.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/general/messages.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/cristofher/Desktop/practice/c++/ChessProject/general/messages.cpp -o CMakeFiles/main.dir/general/messages.cpp.s

CMakeFiles/main.dir/general/pieces/bishop.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/general/pieces/bishop.cpp.o: general/pieces/bishop.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/cristofher/Desktop/practice/c++/ChessProject/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/main.dir/general/pieces/bishop.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/general/pieces/bishop.cpp.o -c /Users/cristofher/Desktop/practice/c++/ChessProject/general/pieces/bishop.cpp

CMakeFiles/main.dir/general/pieces/bishop.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/general/pieces/bishop.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/cristofher/Desktop/practice/c++/ChessProject/general/pieces/bishop.cpp > CMakeFiles/main.dir/general/pieces/bishop.cpp.i

CMakeFiles/main.dir/general/pieces/bishop.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/general/pieces/bishop.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/cristofher/Desktop/practice/c++/ChessProject/general/pieces/bishop.cpp -o CMakeFiles/main.dir/general/pieces/bishop.cpp.s

CMakeFiles/main.dir/general/pieces/king.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/general/pieces/king.cpp.o: general/pieces/king.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/cristofher/Desktop/practice/c++/ChessProject/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/main.dir/general/pieces/king.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/general/pieces/king.cpp.o -c /Users/cristofher/Desktop/practice/c++/ChessProject/general/pieces/king.cpp

CMakeFiles/main.dir/general/pieces/king.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/general/pieces/king.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/cristofher/Desktop/practice/c++/ChessProject/general/pieces/king.cpp > CMakeFiles/main.dir/general/pieces/king.cpp.i

CMakeFiles/main.dir/general/pieces/king.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/general/pieces/king.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/cristofher/Desktop/practice/c++/ChessProject/general/pieces/king.cpp -o CMakeFiles/main.dir/general/pieces/king.cpp.s

CMakeFiles/main.dir/general/pieces/knight.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/general/pieces/knight.cpp.o: general/pieces/knight.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/cristofher/Desktop/practice/c++/ChessProject/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/main.dir/general/pieces/knight.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/general/pieces/knight.cpp.o -c /Users/cristofher/Desktop/practice/c++/ChessProject/general/pieces/knight.cpp

CMakeFiles/main.dir/general/pieces/knight.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/general/pieces/knight.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/cristofher/Desktop/practice/c++/ChessProject/general/pieces/knight.cpp > CMakeFiles/main.dir/general/pieces/knight.cpp.i

CMakeFiles/main.dir/general/pieces/knight.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/general/pieces/knight.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/cristofher/Desktop/practice/c++/ChessProject/general/pieces/knight.cpp -o CMakeFiles/main.dir/general/pieces/knight.cpp.s

CMakeFiles/main.dir/general/pieces/pawn.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/general/pieces/pawn.cpp.o: general/pieces/pawn.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/cristofher/Desktop/practice/c++/ChessProject/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/main.dir/general/pieces/pawn.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/general/pieces/pawn.cpp.o -c /Users/cristofher/Desktop/practice/c++/ChessProject/general/pieces/pawn.cpp

CMakeFiles/main.dir/general/pieces/pawn.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/general/pieces/pawn.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/cristofher/Desktop/practice/c++/ChessProject/general/pieces/pawn.cpp > CMakeFiles/main.dir/general/pieces/pawn.cpp.i

CMakeFiles/main.dir/general/pieces/pawn.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/general/pieces/pawn.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/cristofher/Desktop/practice/c++/ChessProject/general/pieces/pawn.cpp -o CMakeFiles/main.dir/general/pieces/pawn.cpp.s

CMakeFiles/main.dir/general/pieces/piece.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/general/pieces/piece.cpp.o: general/pieces/piece.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/cristofher/Desktop/practice/c++/ChessProject/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object CMakeFiles/main.dir/general/pieces/piece.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/general/pieces/piece.cpp.o -c /Users/cristofher/Desktop/practice/c++/ChessProject/general/pieces/piece.cpp

CMakeFiles/main.dir/general/pieces/piece.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/general/pieces/piece.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/cristofher/Desktop/practice/c++/ChessProject/general/pieces/piece.cpp > CMakeFiles/main.dir/general/pieces/piece.cpp.i

CMakeFiles/main.dir/general/pieces/piece.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/general/pieces/piece.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/cristofher/Desktop/practice/c++/ChessProject/general/pieces/piece.cpp -o CMakeFiles/main.dir/general/pieces/piece.cpp.s

CMakeFiles/main.dir/general/pieces/queen.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/general/pieces/queen.cpp.o: general/pieces/queen.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/cristofher/Desktop/practice/c++/ChessProject/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Building CXX object CMakeFiles/main.dir/general/pieces/queen.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/general/pieces/queen.cpp.o -c /Users/cristofher/Desktop/practice/c++/ChessProject/general/pieces/queen.cpp

CMakeFiles/main.dir/general/pieces/queen.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/general/pieces/queen.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/cristofher/Desktop/practice/c++/ChessProject/general/pieces/queen.cpp > CMakeFiles/main.dir/general/pieces/queen.cpp.i

CMakeFiles/main.dir/general/pieces/queen.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/general/pieces/queen.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/cristofher/Desktop/practice/c++/ChessProject/general/pieces/queen.cpp -o CMakeFiles/main.dir/general/pieces/queen.cpp.s

CMakeFiles/main.dir/general/pieces/rook.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/general/pieces/rook.cpp.o: general/pieces/rook.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/cristofher/Desktop/practice/c++/ChessProject/CMakeFiles --progress-num=$(CMAKE_PROGRESS_19) "Building CXX object CMakeFiles/main.dir/general/pieces/rook.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/general/pieces/rook.cpp.o -c /Users/cristofher/Desktop/practice/c++/ChessProject/general/pieces/rook.cpp

CMakeFiles/main.dir/general/pieces/rook.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/general/pieces/rook.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/cristofher/Desktop/practice/c++/ChessProject/general/pieces/rook.cpp > CMakeFiles/main.dir/general/pieces/rook.cpp.i

CMakeFiles/main.dir/general/pieces/rook.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/general/pieces/rook.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/cristofher/Desktop/practice/c++/ChessProject/general/pieces/rook.cpp -o CMakeFiles/main.dir/general/pieces/rook.cpp.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/main.cpp.o" \
"CMakeFiles/main.dir/logic/board.cpp.o" \
"CMakeFiles/main.dir/logic/player.cpp.o" \
"CMakeFiles/main.dir/logic/AiPlayer.cpp.o" \
"CMakeFiles/main.dir/logic/movement.cpp.o" \
"CMakeFiles/main.dir/logic/bitboard.cpp.o" \
"CMakeFiles/main.dir/logic/transposition_table.cpp.o" \
"CMakeFiles/main.dir/logic/Transposition_table_entry.cpp.o" \
"CMakeFiles/main.dir/logic/ZobristKey.cpp.o" \
"CMakeFiles/main.dir/display/Idisplay.cpp.o" \
"CMakeFiles/main.dir/general/game.cpp.o" \
"CMakeFiles/main.dir/general/messages.cpp.o" \
"CMakeFiles/main.dir/general/pieces/bishop.cpp.o" \
"CMakeFiles/main.dir/general/pieces/king.cpp.o" \
"CMakeFiles/main.dir/general/pieces/knight.cpp.o" \
"CMakeFiles/main.dir/general/pieces/pawn.cpp.o" \
"CMakeFiles/main.dir/general/pieces/piece.cpp.o" \
"CMakeFiles/main.dir/general/pieces/queen.cpp.o" \
"CMakeFiles/main.dir/general/pieces/rook.cpp.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

bin/main: CMakeFiles/main.dir/main.cpp.o
bin/main: CMakeFiles/main.dir/logic/board.cpp.o
bin/main: CMakeFiles/main.dir/logic/player.cpp.o
bin/main: CMakeFiles/main.dir/logic/AiPlayer.cpp.o
bin/main: CMakeFiles/main.dir/logic/movement.cpp.o
bin/main: CMakeFiles/main.dir/logic/bitboard.cpp.o
bin/main: CMakeFiles/main.dir/logic/transposition_table.cpp.o
bin/main: CMakeFiles/main.dir/logic/Transposition_table_entry.cpp.o
bin/main: CMakeFiles/main.dir/logic/ZobristKey.cpp.o
bin/main: CMakeFiles/main.dir/display/Idisplay.cpp.o
bin/main: CMakeFiles/main.dir/general/game.cpp.o
bin/main: CMakeFiles/main.dir/general/messages.cpp.o
bin/main: CMakeFiles/main.dir/general/pieces/bishop.cpp.o
bin/main: CMakeFiles/main.dir/general/pieces/king.cpp.o
bin/main: CMakeFiles/main.dir/general/pieces/knight.cpp.o
bin/main: CMakeFiles/main.dir/general/pieces/pawn.cpp.o
bin/main: CMakeFiles/main.dir/general/pieces/piece.cpp.o
bin/main: CMakeFiles/main.dir/general/pieces/queen.cpp.o
bin/main: CMakeFiles/main.dir/general/pieces/rook.cpp.o
bin/main: CMakeFiles/main.dir/build.make
bin/main: CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/cristofher/Desktop/practice/c++/ChessProject/CMakeFiles --progress-num=$(CMAKE_PROGRESS_20) "Linking CXX executable bin/main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.dir/build: bin/main

.PHONY : CMakeFiles/main.dir/build

CMakeFiles/main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main.dir/clean

CMakeFiles/main.dir/depend:
	cd /Users/cristofher/Desktop/practice/c++/ChessProject && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/cristofher/Desktop/practice/c++/ChessProject /Users/cristofher/Desktop/practice/c++/ChessProject /Users/cristofher/Desktop/practice/c++/ChessProject /Users/cristofher/Desktop/practice/c++/ChessProject /Users/cristofher/Desktop/practice/c++/ChessProject/CMakeFiles/main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main.dir/depend

