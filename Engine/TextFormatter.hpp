#ifndef TEXTFORMATTER_HPP
#define TEXTFORMATTER_HPP

#include <windows.h>
#include <iostream>
#include <thread>
#include <iomanip>
#include "../Source/Globals.hpp"
#include <algorithm>
#include <cctype>

namespace TextColors
{
    static int BLUE = 1;
    static int GREEN = 2;
    static int LIGHTBLUE = 3;
    static int RED = 4;
    static int PURPLE = 5;
    static int YELLOW = 6;
    static int WHITE = 7;
    static int GREY = 8;
    static int BLUEBERRY = 9;
    static int LIGHTGREEN = 10;
    static int CYAN = 11;
    static int ROSE = 12;
    static int PINK = 13;
    static int BEIGE = 14;
}


namespace TextFunctions{


    static void changeTextColor(int color)
    {
        SetConsoleTextAttribute(cmd::hOutput, color);
    }

    static void typeWriteMessage(std::string& s, int time)
    {
        for (const auto c : s) {
            std::cout << c << std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(time));
        }
        printf("\n");
    }

    static void print(std::string& message)
    {
        std::cout<<message<<std::endl;
    }

    static void printWithColor(std::string& message, int color)
    {
        SetConsoleTextAttribute(cmd::hOutput, color);
        std::cout<<message;
        SetConsoleTextAttribute(cmd::hOutput, TextColors::WHITE);
    }

    static bool setCursor(short x, short y)
    {
        return SetConsoleCursorPosition(cmd::hOutput, {x, y});
    }
    static COORD getConsoleCursorPosition(HANDLE hConsoleOutput)
    {
        CONSOLE_SCREEN_BUFFER_INFO cbsi;
        if (GetConsoleScreenBufferInfo(hConsoleOutput, &cbsi))
        {
            return cbsi.dwCursorPosition;
        }
        else
        {
            COORD invalid = { 0, 0 };
            return invalid;
        }
    }

    static std::string toLower(std::string data) {

         std::transform(data.begin(), data.end(), data.begin(),
    [](unsigned char c){ return std::tolower(c); });

        return data;
    }
}

#endif //TEXTFORMATTER_HPP
