#pragma once

#include "../astd/Container.hpp"
#include "AnimatedTextUTF8.hpp"

namespace ascii { namespace client {
    class AnimatedTextBuilderUTF8 {
        private:
            astd::container<AnimatedTextUTF8> texts; 
        public:
            AnimatedTextBuilderUTF8() noexcept;
            void render(ascii::Engine *engine, int x, int y) noexcept;
            AnimatedTextBuilderUTF8 addText(astd::string text, int delay) noexcept;
            bool isFinished() noexcept;
    };
}}; // namespace ascii::client