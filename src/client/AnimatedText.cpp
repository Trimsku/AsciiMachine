#include "../../asciiengine/client/AnimatedText.hpp"

namespace ascii { namespace client {

ascii::client::AnimatedText::AnimatedText(astd::string text, int timeBetweenUpdate_m) noexcept {
    currentTick = 0;
    texture = text;
    timeBetweenUpdate = timeBetweenUpdate_m;
}

void ascii::client::AnimatedText::update() noexcept {
    if(time.getEllapsedTime() >= timeBetweenUpdate) {
        if(!isFinished()) currentTick++;
        if(currentTick > texture.size()) currentTick = -1;
        time.restart();
    }
}

void ascii::client::AnimatedText::render(ascii::Engine *engine, int x, int y) noexcept {
    update();
    if(!isFinished()) engine->draw(x, y, getCurrentText());
}

}}