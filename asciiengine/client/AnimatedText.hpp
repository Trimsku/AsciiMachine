#pragma once

#include "../astd/String.hpp"
#include "../astd/Clock.hpp"
#include "../core/Font.hpp"
#include "../core/Engine.hpp"

namespace ascii { namespace client {
class AnimatedText {
    private:
        int currentTick;
        int timeBetweenUpdate;
        astd::Clock time;
        astd::string texture;
        inline astd::string getCurrentText() noexcept;
    public:
        AnimatedText(astd::string texture, int timeBetweenUpdate) noexcept;
        AnimatedText() = default;
        void update() noexcept;
        void render(ascii::Engine *engine, int x, int y) noexcept;
        inline void renderLast(ascii::Engine *engine, int x, int y) noexcept;
        inline bool isFinished() noexcept;
};

void AnimatedText::renderLast(ascii::Engine *engine, int x, int y) noexcept {
    engine->draw(x, y, texture);
}
bool AnimatedText::isFinished() noexcept {
    return currentTick == -1;
}
astd::string AnimatedText::getCurrentText() noexcept {
    return texture.substr(0, currentTick);
}
}} // namespace ascii::client;