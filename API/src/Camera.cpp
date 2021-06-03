#include "../include/Camera.hpp"

ascii::Camera::Camera(Configuration cbind) {
    Bind(cbind);
    camera.reset(sf::FloatRect(0, 0, config.widthOfScreen, config.heightOfScreen));
}

void ascii::Camera::move(float y, float x) {
    camera.move(x, y);
}

void ascii::Camera::move(Vector2d mv_xy) {
    camera.move(mv_xy.global_x, mv_xy.global_y);
}

sf::View ascii::Camera::getCamera() {
    return camera;
}