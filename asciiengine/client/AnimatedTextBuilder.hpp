#ifndef ANIMATED_TEXT_BUILDER_HPP
#define ANIMATED_TEXT_BUILDER_HPP

#include "../astd/Container.hpp"
#include "AnimatedText.hpp"

namespace ascii::client
{
    class AnimatedTextBuilder {
        private:
            astd::container<AnimatedText> texts; 
        public:
            AnimatedTextBuilder();
            void render(ascii::Engine *engine, int x, int y);
            bool isFinished();
            AnimatedTextBuilder addText(astd::string text, int delay);
    };
} // namespace ascii::client


#endif // !ANIMATED_TEXT_BUILDER_HPP