#ifndef GLOBALS_HPP
#define GLOBALS_HPP

#include <windows.h>

  #define VK_R_KEY 0x52

namespace cmd
{
    static HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    static HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);

    enum KeyPressed
    {
        ACCEPT = 0,
        BACK,
        ROTATE,
        UP,
        DOWN,
        RIGHT,
        LEFT
    };
}

#endif //GLOBALS_HPP
