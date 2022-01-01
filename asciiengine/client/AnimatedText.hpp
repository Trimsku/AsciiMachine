#ifndef ANIMATED_TEXT_HPP
#define ANIMATED_TEXT_HPP

#include "../astd/String.hpp"
#include "../astd/Clock.hpp"
#include "../core/Font.hpp"
#include "../core/Engine.hpp"

namespace ascii::client {
class AnimatedText {
    private:
        int currentTick;
        int timeBetweenUpdate;
        astd::Clock time;
        astd::string texture;
        astd::string getCurrentText();
    public:
        AnimatedText(astd::string texture, int timeBetweenUpdate);
        AnimatedText() = default;
        void update();
        void render(ascii::Engine *engine, int x, int y);
        void renderLast(ascii::Engine *engine, int x, int y);
        bool isFinished();
};
};

#endif // ANIMATED_TEXT_HPP