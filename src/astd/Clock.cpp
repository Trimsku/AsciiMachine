#include "../../asciiengine/astd/Clock.hpp"
namespace astd
{
    Clock::Clock() : start_time(SDL_GetTicks()) {}
    
    unsigned int Clock::getEllapsedTime() {
        return SDL_GetTicks() - start_time;
    }
    void Clock::restart() {
        start_time = SDL_GetTicks();
    }
} // namespace ascii