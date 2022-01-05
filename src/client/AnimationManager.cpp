//
// Created by trimsky on 28.11.2021.
//
#include "../../asciiengine/client/AnimationManager.hpp"

namespace ascii { namespace client {

AnimationManager::AnimationManager(AnimatedTexture animation, int timeForAnimationUpdate) noexcept {
    texture = animation;
    timeForUpdate = timeForAnimationUpdate;
}

AnimationManager::AnimationManager(astd::string pathToAnimation, int timeForAnimationUpdate) noexcept {
    texture = AnimatedTexture(ascii::util::getFileResources(pathToAnimation.c_str()));
    timeForUpdate = timeForAnimationUpdate;
}

void AnimationManager::render(ascii::Engine *engine, int x, int y) noexcept {
    update();
    engine->draw(x, y, texture.getCurrentTexture(animationTick));
}

void AnimationManager::update() noexcept {
    if(time.getEllapsedTime() >= timeForUpdate) {
        animationTick++;
        if(animationTick == texture.getAnimationsNumber()) animationTick = 0;
        time.restart();
    }
}
}}