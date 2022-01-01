#ifndef ANIMATED_TEXT_BUILDER_UTF_8_HPP
#define ANIMATED_TEXT_BUILDER_UTF_8_HPP

#include "../astd/Container.hpp"
#include "AnimatedTextUTF8.hpp"

namespace ascii::client
{
    class AnimatedTextBuilderUTF8 {
        private:
            astd::container<AnimatedTextUTF8> texts; 
        public:
            AnimatedTextBuilderUTF8();
            void render(ascii::Engine *engine, int x, int y);
            bool isFinished();
            AnimatedTextBuilderUTF8 addText(astd::string text, int delay);
    };
} // namespace ascii::client


#endif // !ANIMATED_TEXT_BUILDER_UTF_8_HPP