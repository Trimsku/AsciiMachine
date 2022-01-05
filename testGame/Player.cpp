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
    if(state == ascii::Direction::Stand) 
        playerStand.render(engine, 
            engine->getCamera()->getObjectX(x) + getW() / 2, 
            engine->getCamera()->getObjectY(y) + getH() / 2);
    else if(state == ascii::Direction::Right) 
        playerRight.render(engine, 
            engine->getCamera()->getObjectX(x) + getW() / 2/* + PLAYER_X_VELOCITY * deltaTime*/, 
            engine->getCamera()->getObjectY(y) + getH() / 2);
    else if(state == ascii::Direction::Left) 
        playerLeft.render(engine, 
            engine->getCamera()->getObjectX(x) + getW() / 2/* - PLAYER_X_VELOCITY * deltaTime*/, 
            engine->getCamera()->getObjectY(y) + getH() / 2);

    if(Options::getInstance().isDebugging()) {
        engine->draw(0, 0, "x: " + std::to_string(x) + ", y: " + std::to_string(y));
        engine->draw(0, 100, "health: " + std::to_string(health));
    } else {
        engine->draw(0, 0, "health: " + std::to_string(health));
    }
}
void Player::update() noexcept {
    if(is_key_pressed(RIGHT)) {
        x += PLAYER_X_VELOCITY;
        state = ascii::Direction::Right;
        if(engine->getScene()->isConflictingWithOtherObject(this)) {
            x -= PLAYER_X_VELOCITY;
            state = ascii::Direction::Stand;
        }
    } else if(is_key_pressed(LEFT)) {
        x -= PLAYER_X_VELOCITY;
        state = ascii::Direction::Left;
        if(engine->getScene()->isConflictingWithOtherObject(this)) {
            x += PLAYER_X_VELOCITY;
            state = ascii::Direction::Stand;
        }
    } else { // for events
        engine->getScene()->isConflictingWithOtherObject(this);
        state = ascii::Direction::Stand;
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