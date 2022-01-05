#ifndef CLOCK_HPP
#define CLOCK_HPP
#include <SDL2/SDL.h>

namespace astd
{
    class Clock {
    public:
        Clock() noexcept;
        inline unsigned int getEllapsedTime() noexcept;
        inline void restart() noexcept;
    private:
        unsigned int startTime;
    };
    unsigned int Clock::getEllapsedTime() noexcept {
        return SDL_GetTicks() - startTime;
    }
    void Clock::restart() noexcept {
        startTime = SDL_GetTicks();
    }
}; // namespace ascii


#endif // CLOCK_HPP