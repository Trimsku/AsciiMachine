#include "../../asciiengine/client/AnimatedTextBuilder.hpp"

namespace ascii { namespace client {

AnimatedTextBuilder::AnimatedTextBuilder() noexcept {}

AnimatedTextBuilder AnimatedTextBuilder::addText(astd::string text, int delay) noexcept {
    texts.push(AnimatedText(text, delay));
    return *this;
}

void AnimatedTextBuilder::render(ascii::Engine *engine, int x, int y) noexcept {
    bool isLastFinished = true;
    for(int i = 0; i < texts.size(); i++) {
        if(!texts[i].isFinished() && isLastFinished) {
            texts[i].render(engine, x, y+i*50);
            isLastFinished = false;
            continue;
        }
        if(texts[i].isFinished()) texts[i].renderLast(engine, x, y+i*50);
    }
}

}} // namespace ascii::client