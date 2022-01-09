#pragma once

#include "../astd/String.hpp"
#include "../astd/Clock.hpp"
#include "../core/Font.hpp"
#include "../core/Engine.hpp"

namespace ascii { namespace client {
class AnimatedTextUTF8 {
    private:
        int currentTick;
        int timeBetweenUpdate;
        astd::Clock time;
        astd::string texture;
        astd::string getCurrentText() noexcept;
    public:
        AnimatedTextUTF8(astd::string texture, int timeBetweenUpdate) noexcept;
        AnimatedTextUTF8() = default;
        void update() noexcept;
        void render(ascii::Engine *engine, int x, int y) noexcept;
        void renderLast(ascii::Engine *engine, int x, int y) noexcept;
        bool isFinished() noexcept;
};
}};