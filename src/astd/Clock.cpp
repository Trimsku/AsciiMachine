#include "../../asciiengine/astd/Clock.hpp"
namespace astd
{
    Clock::Clock() : startTime(SDL_GetTicks()) {}
    
    unsigned int Clock::getEllapsedTime() {
        return SDL_GetTicks() - startTime;
    }
    void Clock::restart() {
        startTime = SDL_GetTicks();
    }
} // namespace ascii