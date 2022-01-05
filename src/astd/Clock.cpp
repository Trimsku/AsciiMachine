#include "../../asciiengine/astd/Clock.hpp"
namespace astd
{
    Clock::Clock() noexcept : startTime(SDL_GetTicks()) {}
} // namespace ascii