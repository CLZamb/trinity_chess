#ifndef COMMON_H
#define COMMON_H

#include <iostream>
#include <string>

using std::string;
#ifdef _WIN32
#define CLEAR "cls"
#else
// Assume Unix system
#define CLEAR "clear"
#endif

typedef uint64_t U64;

#endif /* COMMON_H */
