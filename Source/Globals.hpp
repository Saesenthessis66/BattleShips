//
// Created by lucja on 18.06.2024.
//

#ifndef GLOBALS_HPP
#define GLOBALS_HPP

#include <windows.h>

namespace cmd
{
    static HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    static HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
}

#endif //GLOBALS_HPP
