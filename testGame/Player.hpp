#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "../asciiengine/client/AnimationManager.hpp"
#include "../asciiengine/common/entity/Entity.hpp"

#define PLAYER_X_VELOCITY 2
#define PLAYER_Y_VELOCITY 1

enum State {
    Stand = 1,
    Left = 2,
    Right = 3,
    None = 4,
};

class Player : ascii::Entity
{
private:
    int health;
    int state = State::Stand;
    int x, y;
    int entityNameCounter = __COUNTER__;
    ascii::client::AnimationManager playerLeft;
    ascii::client::AnimationManager playerRight;
    ascii::client::AnimationManager playerStand;
public:
    Player(ascii::Engine *m_engine, int health) noexcept;
    MAKE_ENTITY();

    int getHealth() noexcept;
    void setHealth(int amount) noexcept;
    void addHealth(int amount) noexcept;
    void removeHealth(int amount) noexcept;
};

#endif // PLAYER_HPP
