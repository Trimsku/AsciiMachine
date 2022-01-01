#include "../../asciiengine/client/AnimatedTextUTF8.hpp"

ascii::client::AnimatedTextUTF8::AnimatedTextUTF8(astd::string text, int timeBetweenUpdate_m) {
    currentTick = 0;
    texture = text;
    timeBetweenUpdate = timeBetweenUpdate_m;
}

astd::string ascii::client::AnimatedTextUTF8::getCurrentText() {
    return texture.substr(0, currentTick-1);
}

void ascii::client::AnimatedTextUTF8::update() {
    if(time.getEllapsedTime() >= timeBetweenUpdate) {
        if(!isFinished()) currentTick++;
        if(currentTick > texture.size()) currentTick = -1;
        time.restart();
    }
}

void ascii::client::AnimatedTextUTF8::render(ascii::Engine *engine, int x, int y) {
    update();
    if(!isFinished()) engine->draw(x, y, getCurrentText().c_str());
}
void ascii::client::AnimatedTextUTF8::renderLast(ascii::Engine *engine, int x, int y) {
    engine->draw(x, y, texture.c_str());
}

bool ascii::client::AnimatedTextUTF8::isFinished() {
    return currentTick == -1;
}