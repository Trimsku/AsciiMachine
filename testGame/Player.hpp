#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "../asciiengine/client/AnimationManager.hpp"
#include "Options.hpp"

#define PLAYER_X_VELOCITY 4
#define PLAYER_Y_VELOCITY 2

enum State {
    Stand = 1,
    Left = 2,
    Right = 3,
    None = 4,
};

class Player
{
private:
    int state = State::Stand;
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
    void tick() noexcept;
    int getState();
    inline int getX() noexcept {
        return x - getW();
    }
    inline int getY() noexcept {
        return y - getH();
    }
    __always_inline static int getW() noexcept {
        return 75;
    }
    __always_inline static int getH() noexcept {
        return 200;
    }
    __always_inline void setX(int x_) noexcept {
        x = x_;
    }
    __always_inline void setY(int y_) noexcept {
        y = y_;
    }
    __always_inline const char* getSceneName() noexcept {
        return ("player" + std::to_string(entityNameCounter)).c_str();
    }

    int getHealth() noexcept;
    void setHealth(int amount) noexcept;
    void addHealth(int amount) noexcept;
    void removeHealth(int amount) noexcept;
};

#endif // PLAYER_HPP
