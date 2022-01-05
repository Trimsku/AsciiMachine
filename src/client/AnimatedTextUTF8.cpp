#include "../../asciiengine/client/AnimatedTextUTF8.hpp"

namespace ascii { namespace client {

AnimatedTextUTF8::AnimatedTextUTF8(astd::string text, int timeBetweenUpdate_m) noexcept {
    currentTick = 0;
    texture = text;
    timeBetweenUpdate = timeBetweenUpdate_m;
}

void AnimatedTextUTF8::update() noexcept {
    if(time.getEllapsedTime() >= timeBetweenUpdate) {
        if(!isFinished()) currentTick++;
        if(currentTick > texture.size()) currentTick = -1;
        time.restart();
    }
}

void AnimatedTextUTF8::render(ascii::Engine *engine, int x, int y) noexcept {
    update();
    if(!isFinished()) engine->draw(x, y, getCurrentText().c_str());
}
}}