#include "../../asciiengine/common/Camera.hpp"
#include "../../asciiengine/core/Engine.hpp"

namespace ascii {

Camera::Camera(ascii::Engine *_engine) noexcept {
    engine = _engine;
    camera = {0, 0, engine->getScrW(), engine->getScrH()};
}

void Camera::update(int _x, int _y, int _w, int _h) noexcept {
    camera.x = _x - engine->getScrW() / 2 + _w * 2;
    camera.y = _y - engine->getScrH() / 2 + _h * 2;
    w = _w;
    h = _h;
}
void Camera::onRendering(double deltaTime, int direction, int velocity) noexcept {
}

}