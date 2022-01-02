#include "Player.hpp"

Player::Player(ascii::Engine *m_engine, int _health) noexcept : Entity(m_engine), playerLeft("resources/textures/PlayerLeft.txt", 100), playerRight("resources/textures/PlayerRight.txt", 100), playerStand("resources/textures/PlayerStand.txt", 800) {
    health = _health;
    x = 0;
    y = 0;
}

void Player::render() noexcept {
    if(engine->isUsingCamera()) {
        if(state == State::Stand) playerStand.render(engine, engine->getCamera()->x + 1920/2 - getW(), engine->getCamera()->y + 1080/2 - getH());
        else if(state == State::Right) playerRight.render(engine, engine->getCamera()->x + 1920/2 - getW(), engine->getCamera()->y + 1080/2 - getH());
        else if(state == State::Left) playerLeft.render(engine, engine->getCamera()->x + 1920/2 - getW(), engine->getCamera()->y + 1080/2 - getH());
    } else {
        if(state == State::Stand) playerStand.render(engine, x, y);
        else if(state == State::Right) playerRight.render(engine, x, y);
        else if(state == State::Left) playerLeft.render(engine, x, y);
    }
    //if(engine->isUsingCamera()) {
        engine->draw(0, 0, "x: " + std::to_string(getX()) + ", y: " + std::to_string(getY()));
        engine->draw(0, 50, "health: " + std::to_string(health));
    //}
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
        if(engine->getScene()->isConflictingWithOtherObject(this)) y += PLAYER_Y_VELOCITY;
    } else if(is_key_pressed(DOWN) && !engine->isUsingGravity()) {
        y += PLAYER_Y_VELOCITY;
        if(engine->getScene()->isConflictingWithOtherObject(this)) y -= PLAYER_Y_VELOCITY;
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

int Player::getX() noexcept {
    return x - getW();
}
void Player::setX(int x_) noexcept {
    x = x_ + getW();
}
int Player::getY() noexcept {
    return y - getH();
}
void Player::setY(int y_) noexcept {
    y = y_ + getH();
}
int Player::getW() noexcept {
    return 75;
}
int Player::getH() noexcept {
    return 100; // 50(size) * 3(lines amount)
}

const char* Player::getSceneName() noexcept {
    return ("player" + std::to_string(entityNameCounter)).c_str();
}