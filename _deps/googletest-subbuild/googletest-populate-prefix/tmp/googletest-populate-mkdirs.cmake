# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/cristofher/code/c++/chess_project/trinity_engine/_deps/googletest-src"
  "/Users/cristofher/code/c++/chess_project/trinity_engine/_deps/googletest-build"
  "/Users/cristofher/code/c++/chess_project/trinity_engine/_deps/googletest-subbuild/googletest-populate-prefix"
  "/Users/cristofher/code/c++/chess_project/trinity_engine/_deps/googletest-subbuild/googletest-populate-prefix/tmp"
  "/Users/cristofher/code/c++/chess_project/trinity_engine/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
  "/Users/cristofher/code/c++/chess_project/trinity_engine/_deps/googletest-subbuild/googletest-populate-prefix/src"
  "/Users/cristofher/code/c++/chess_project/trinity_engine/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/cristofher/code/c++/chess_project/trinity_engine/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp/${subDir}")
endforeach()
