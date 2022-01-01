#ifndef ANIMATION_MANAGER_HPP
#define ANIMATION_MANAGER_HPP

#include "AnimatedTexture.hpp"
#include "../core/Font.hpp"
#include "../core/Engine.hpp"

namespace ascii::client {

class AnimationManager {
private:
    int animationTick = 0;
    int timeForUpdate;
    astd::Clock time;
    AnimatedTexture texture;
public:
    AnimationManager(AnimatedTexture animation, int timeForUpdate);
    AnimationManager(astd::string pathToAnimation, int timeForUpdate);
    void update();
    void render(ascii::Engine *engine, int x, int y);
};

}
#endif // ANIMATION_MANAGER_HPP