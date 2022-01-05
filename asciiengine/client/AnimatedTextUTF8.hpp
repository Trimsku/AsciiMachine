#ifndef ANIMATED_TEXT_UTF8_HPP
#define ANIMATED_TEXT_UTF8_HPP

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
        inline astd::string getCurrentText() noexcept;
    public:
        AnimatedTextUTF8(astd::string texture, int timeBetweenUpdate) noexcept;
        AnimatedTextUTF8() = default;
        void update() noexcept;
        void render(ascii::Engine *engine, int x, int y) noexcept;
        inline void renderLast(ascii::Engine *engine, int x, int y) noexcept;
        inline bool isFinished() noexcept;
};
bool AnimatedTextUTF8::isFinished() noexcept {
    return currentTick == -1;
}
astd::string AnimatedTextUTF8::getCurrentText() noexcept {
    return texture.substr(0, currentTick-1);
}
void AnimatedTextUTF8::renderLast(ascii::Engine *engine, int x, int y) noexcept {
    engine->draw(x, y, texture.c_str());
}
}};

#endif // ANIMATED_TEXT_HPP