#ifndef CLOCK_HPP
#define CLOCK_HPP
#include <SDL2/SDL.h>

namespace astd
{
    class Clock {
    public:
        Clock();
        unsigned int getEllapsedTime();
        void restart();
    private:
        unsigned int startTime;
    };
}; // namespace ascii


#endif // CLOCK_HPP