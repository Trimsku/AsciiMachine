#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <SDL2/SDL.h>


namespace ascii {
    enum Direction {
        Left = 1,
        Right = 2,
        Up = 3,
        Down = 4,
        Stand = 5,
        None = 6
    };

    class Engine;

    class Camera {
        private:
            SDL_Rect camera;
            Engine *engine;
            int w, h;
            int needToAdd;
        public:
            Camera(Engine *engine) noexcept;
            void onRendering(double deltaTime, int direction, int velocity) noexcept;
            void update(int x, int y, int w, int h) noexcept;
            inline int getObjectX(int x) noexcept;
            inline int getObjectY(int y) noexcept;
    };
    int Camera::getObjectX(int x) noexcept {
        return x - camera.x - w / 2;
    }
    int Camera::getObjectY(int y) noexcept {
        return y - camera.y - h / 2;
    }
}

#endif // !CAMERA_HPP