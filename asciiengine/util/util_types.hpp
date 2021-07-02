#ifndef UTIL_TYPES_H
#define UTIL_TYPES_H
#include "../astd/string.hpp"

namespace ascii
{
    namespace util
    {
        using Sprite = astd::string;
        struct Event
        {
            const char* type;
        };

        struct SpriteInfo
        {
            //Sprite
            //Sprite sprite;
            // Average Number of Letters in a Line.
            //int ANLL;
            // Total lines in sprite;
            //int lines;
        };
        
    } // namespace util
    
} // namespace ascii

#endif // UTIL_TYPES_H