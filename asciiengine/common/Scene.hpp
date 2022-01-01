#ifndef SCENE_HPP
#define SCENE_HPP

#include "../astd/Container.hpp"
#include "event/Subject.hpp"

namespace ascii {
    class Engine;
}

namespace ascii::scene {

class SceneObject {
    public:
        SceneObject(short int x, short int y, short int w, short int h, const char* name, bool isPushable) noexcept;
        SceneObject() noexcept;
        short int x;
        short int y;
        short int w;
        short int h;
        const char* name;
        bool isPushable;
};

short int createCollisionW(int numbers_of_chars_in_x, ascii::Engine *engine) noexcept;
short int createCollisionH(int numbers_of_chars_in_y, ascii::Engine *engine) noexcept;

enum Direction {
    RIGHT = 0,
    LEFT = 1,
    UP = 2,
    DOWN = 3
};

class Scene {
    private:
        astd::container<SceneObject> objects;
        bool camera;
        bool gravity;
        SceneObject lastObject;
    public:
        Scene(bool camera, bool gravity) noexcept;
        void addObject(SceneObject object) noexcept;
        SceneObject getCollisionEventObject() noexcept;
        template<typename T>
        bool isConflictingWithOtherObject(T *entity) noexcept {
            for(int i = 0; i < objects.size(); i++) {
                bool collisionX = entity->getX() + entity->getW() >= objects[i].x && objects[i].x + objects[i].w >= entity->getX();
                bool collisionY = entity->getY() + entity->getH() >= objects[i].y && objects[i].y + objects[i].h >= entity->getY();
                if(collisionX && collisionY && objects[i].isPushable) return true; 
                else if(collisionX && collisionY && !objects[i].isPushable) {
                    ascii::Listener::Subject::getInstance()->createMessage("onCollisionEvent");
                    lastObject = objects[i];
                }
            }
            return false;
        }
        bool isUsingCamera() noexcept;
        bool isUsingGravity() noexcept;
        int getDefaultEntitySpawnX() noexcept;
        int getDefaultEntitySpawnY() noexcept;
        // Return nullptr, if scene object not found;
        SceneObject *getSceneObject(const char *name) noexcept;
};

}

#endif // !SCENE_HPP