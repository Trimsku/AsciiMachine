#include "../../asciiengine/client/AnimatedTextBuilderUTF8.hpp"

namespace ascii { namespace client {

AnimatedTextBuilderUTF8::AnimatedTextBuilderUTF8() noexcept {}

AnimatedTextBuilderUTF8 AnimatedTextBuilderUTF8::addText(astd::string text, int delay) noexcept {
    texts.push(AnimatedTextUTF8(text, delay));
    return *this;
}

void AnimatedTextBuilderUTF8::render(ascii::Engine *engine, int x, int y) noexcept {
    bool isLastFinished = true;
    for(int i = 0; i < texts.size(); i++) {
        if(!texts[i].isFinished() && isLastFinished) {
            texts[i].render(engine, x, y+i*50);
            isLastFinished = false;
            continue;
        }
        if(texts[i].isFinished()) texts[i].renderLast(engine, x, y+i*engine->getFontSize());
    }
}

}} // namespace ascii::client