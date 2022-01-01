#include "../../asciiengine/client/AnimatedText.hpp"

ascii::client::AnimatedText::AnimatedText(astd::string text, int timeBetweenUpdate_m) {
    currentTick = 0;
    texture = text;
    timeBetweenUpdate = timeBetweenUpdate_m;
}

astd::string ascii::client::AnimatedText::getCurrentText() {
    return texture.substr(0, currentTick);
}

void ascii::client::AnimatedText::update() {
    if(time.getEllapsedTime() >= timeBetweenUpdate) {
        if(!isFinished()) currentTick++;
        if(currentTick > texture.size()) currentTick = -1;
        time.restart();
    }
}

void ascii::client::AnimatedText::render(ascii::Engine *engine, int x, int y) {
    update();
    if(!isFinished()) engine->draw(x, y, getCurrentText());
}
void ascii::client::AnimatedText::renderLast(ascii::Engine *engine, int x, int y) {
    engine->draw(x, y, texture);
}

bool ascii::client::AnimatedText::isFinished() {
    return currentTick == -1;
}