#ifndef COLORPRINT_H
#define COLORPRINT_H
#include "../astd/uniprint.hpp"

#if defined(__unix__) || defined(__unix) || defined(__linux__) || defined(__APPLE__) || defined(__MACH__)
#define UNIX_COLOR
#elif defined(WIN32) || defined(_WIN32) || defined(_WIN64)
#define WIN_COLOR
#else
#define UNKNOWN_PLATFORM
#endif

namespace ascii {

    enum Color{
    #if defined(UNIX_COLOR)
        Black       = 30,
        DarkBlue    = 34,
        DarkGreen   = 32,
        LightBlue   = 36,
        DarkRed     = 31,
        Magenta     = 35,
        Orange      = 33,
        LightGray   = 37,
        Gray        = 90,
        Blue        = 94,
        Green       = 92,
        Cyan        = 96,
        Red         = 91,
        Pink        = 95,
        Yellow      = 93,
        White       = 97,
        Reset = 0,
    #elif defined(WIN_COLOR) 
        Black           = 0,
        DarkBlue        = 1,
        DarkGreen       = 2,
        LightBlue       = 3,
        DarkRed         = 4,
        Magenta         = 5,
        Orange          = 6, // Actually, may looks like brown
        LightGray       = 7,
        Gray            = 8,
        Blue            = 9,
        Green           = 10,
        Cyan            = 11,
        Red             = 12,
        Pink            = 13,
        Yellow          = 14,
        White           = 15,
    #endif
    };
    inline void setColor(Color color) {
    #if defined(WIN_COLOR)
        static const HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
        const auto colorNum = static_cast<uint8_t>(color);
        SetConsoleTextAttribute(handle, colorNum);
    #elif defined(UNIX_COLOR)
        astd::print("\x1b[%im", int(color));
    #endif
    }
}

#endif //COLORPRINT_H