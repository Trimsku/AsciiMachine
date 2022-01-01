#include "../../asciiengine/client/AnimatedTextBuilder.hpp"

namespace ascii::client
{

AnimatedTextBuilder::AnimatedTextBuilder() {

}

AnimatedTextBuilder AnimatedTextBuilder::addText(astd::string text, int delay) {
    texts.push(AnimatedText(text, delay));
    return *this;
}

void AnimatedTextBuilder::render(ascii::Engine *engine, int x, int y) {
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

bool AnimatedTextBuilder::isFinished() {
    return texts[texts.size()].isFinished();
}

} // namespace ascii::client