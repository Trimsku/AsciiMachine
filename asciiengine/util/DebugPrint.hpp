#ifndef DEBUGPRINT_H
#define DEBUGPRINT_H
#include "ColorPrint.hpp"
namespace ascii
{
    enum LogLevel {
        Dev         = Color::Magenta,
        Debug       = Color::Cyan,
        Info        = Color::Green,
        Warn        = Color::Pink,
        Error       = Color::Red,
        Log = Color::Orange,
    };


    template <typename ... Args>
    void printDebug(int verbosity, char const * const format, Args ... args) noexcept {
        if(LogLevel::Dev <= verbosity <= LogLevel::Error) {
            setColor(Color(verbosity));
            astd::print(format, args...);
            setColor(Color::Reset);
        }
    }

} // namespace ascii

#endif //DEBUGPRINT_H