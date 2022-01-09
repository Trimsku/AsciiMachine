#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "../asciiengine/client/AnimationManager.hpp"
#include "Options.hpp"
#include "../asciiengine/common/Camera.hpp"

#define PLAYER_X_VELOCITY 5
#define PLAYER_Y_VELOCITY 2

class Player
{
private:
    int state = ascii::Direction::Stand;
    int x, y;
    int xVelocity = 0, yVelocity = 0;
    int health;
    int entityNameCounter = __COUNTER__;
    ascii::Engine *engine;
    ascii::client::AnimationManager playerLeft;
    ascii::client::AnimationManager playerRight;
    ascii::client::AnimationManager playerStand;
public:
    Player(ascii::Engine *m_engine, int health) noexcept;
    void render(double deltaTime) noexcept;
    void update() noexcept;
    int getState();
    inline int getX() noexcept {
        return x - getW();
    }
    inline int getY() noexcept {
        return y - getH();
    }
    inline static int getW() noexcept {
        return 75;
    }
    inline static int getH() noexcept {
        return 200;
    }
    inline void setX(int x_) noexcept {
        x = x_;
    }
    inline void setY(int y_) noexcept {
        y = y_;
    }
    inline const char* getSceneName() noexcept {
        return ("player" + std::to_string(entityNameCounter)).c_str();
    }

    int getHealth() noexcept;
    void setHealth(int amount) noexcept;
    void addHealth(int amount) noexcept;
    void removeHealth(int amount) noexcept;
};

#endif // PLAYER_HPP
