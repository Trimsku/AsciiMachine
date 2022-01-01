//
// Created by trimsky on 28.11.2021.
//
#include "../../asciiengine/client/AnimationManager.hpp"

ascii::client::AnimationManager::AnimationManager(AnimatedTexture animation, int timeForAnimationUpdate) {
    texture = animation;
    timeForUpdate = timeForAnimationUpdate;
}

ascii::client::AnimationManager::AnimationManager(astd::string pathToAnimation, int timeForAnimationUpdate) {
    texture = AnimatedTexture(ascii::util::getFileResources(pathToAnimation.c_str()));
    timeForUpdate = timeForAnimationUpdate;
}

void ascii::client::AnimationManager::render(ascii::Engine *engine, int x, int y) {
    update();
    engine->draw(x, y, texture.getCurrentTexture(animationTick));
}

void ascii::client::AnimationManager::update() {
    if(time.getEllapsedTime() >= timeForUpdate) {
        animationTick++;
        if(animationTick == texture.getAnimationsNumber()) animationTick = 0;
        time.restart();
    }
}