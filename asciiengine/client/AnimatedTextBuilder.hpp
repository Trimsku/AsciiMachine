#pragma once

#include "../astd/Container.hpp"
#include "AnimatedText.hpp"

namespace ascii { namespace client {
    class AnimatedTextBuilder {
        private:
            astd::container<AnimatedText> texts; 
        public:
            AnimatedTextBuilder() noexcept;
            void render(ascii::Engine *engine, int x, int y) noexcept;
            inline bool isFinished() noexcept;
            AnimatedTextBuilder addText(astd::string text, int delay) noexcept;
    };

    bool AnimatedTextBuilder::isFinished() noexcept {
        return texts[texts.size()].isFinished();
    }
}}; // namespace ascii::client