#ifndef UNIPRINT_H
#define UNIPRINT_H

#include <cstdio>
#include "../astd/string.hpp"

namespace astd
{
    //https://docs.microsoft.com/ru-ru/archive/msdn-magazine/2015/march/windows-with-c-using-printf-with-modern-c
    template <typename T>
    T Argument(T value) noexcept {
        return value;
    }
    const char* Argument(astd::string *value) noexcept;

    template <typename ... Args>
    void print(char const * const format, Args ... args) noexcept {
        printf(format, Argument(args)...);
    }
} // namespace astd

#endif // UNIPRINT_H