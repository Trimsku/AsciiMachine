#include "Player.hpp"

Player::Player(ascii::Engine *m_engine, int _health) noexcept : engine(m_engine), playerLeft("resources/textures/PlayerLeft.txt", 100), playerRight("resources/textures/PlayerRight.txt", 100), playerStand("resources/textures/PlayerStand.txt", 800) {
    health = _health;
    x = 0;
    y = 0;
}

int Player::getState() {
    return state;
}

void Player::render(double deltaTime) noexcept {
    if(state == State::Stand) playerStand.render(engine, x - engine->getCamera()->x, y - engine->getCamera()->y);
    else if(state == State::Right) playerRight.render(engine, x - engine->getCamera()->x + PLAYER_X_VELOCITY * deltaTime, y - engine->getCamera()->y);
    else if(state == State::Left) playerLeft.render(engine, x - engine->getCamera()->x - PLAYER_X_VELOCITY * deltaTime, y - engine->getCamera()->y);

    if(Options::getInstance().isDebugging()) {
        engine->draw(0, 0, "x: " + std::to_string(x) + ", y: " + std::to_string(y));
        engine->draw(0, 50, "cameraX: " + std::to_string(engine->getCamera()->x) + ", cameraY: " + std::to_string(engine->getCamera()->y));
        engine->draw(0, 100, "health: " + std::to_string(health));
    } else {
        engine->draw(0, 0, "health: " + std::to_string(health));
    }
}
void Player::tick() noexcept {
    if(is_key_pressed(RIGHT)) {
        x += PLAYER_X_VELOCITY;
        if(engine->getScene()->isConflictingWithOtherObject(this)) {
            x -= PLAYER_X_VELOCITY;
            state = State::Stand;
        } else state = State::Right;
    } else if(is_key_pressed(LEFT)) {
        x -= PLAYER_X_VELOCITY;
        if(engine->getScene()->isConflictingWithOtherObject(this)) {
            x += PLAYER_X_VELOCITY;
            state = State::Stand;
        } else state = State::Left;
    } else { // for events
        engine->getScene()->isConflictingWithOtherObject(this);
        state = State::Stand;
    }
    if(is_key_pressed(UP) && !engine->isUsingGravity()) {
        y -= PLAYER_Y_VELOCITY;
        if(engine->getScene()->isConflictingWithOtherObject(this)) {
            y += PLAYER_Y_VELOCITY;
        }
    } else if(is_key_pressed(DOWN) && !engine->isUsingGravity()) {
        y += PLAYER_Y_VELOCITY;
        if(engine->getScene()->isConflictingWithOtherObject(this)) {
            y -= PLAYER_Y_VELOCITY;
        }
    }
}

int Player::getHealth() noexcept {
    return health;
}
void Player::setHealth(int amount) noexcept {
    health = amount;
}
void Player::addHealth(int amount) noexcept {
    health += amount;
}
void Player::removeHealth(int amount) noexcept {
    health -= amount;
}