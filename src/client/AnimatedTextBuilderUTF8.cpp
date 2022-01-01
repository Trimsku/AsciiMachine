#include "../../asciiengine/client/AnimatedTextBuilderUTF8.hpp"

namespace ascii::client
{

AnimatedTextBuilderUTF8::AnimatedTextBuilderUTF8() {

}

AnimatedTextBuilderUTF8 AnimatedTextBuilderUTF8::addText(astd::string text, int delay) {
    texts.push(AnimatedTextUTF8(text, delay));
    return *this;
}

void AnimatedTextBuilderUTF8::render(ascii::Engine *engine, int x, int y) {
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

bool AnimatedTextBuilderUTF8::isFinished() {
    return texts[texts.size()].isFinished();
}

} // namespace ascii::client