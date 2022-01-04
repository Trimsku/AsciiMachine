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

class IScene {
    private:
        astd::container<SceneObject> objects;
        SceneObject lastObject;
    protected:
        ascii::Engine *engine;
    public:
        virtual ~IScene() noexcept;
        IScene(ascii::Engine *engine) noexcept;
        virtual bool isUsingGravity() noexcept = 0;
        virtual int getDefaultEntitySpawnX() noexcept = 0;
        virtual int getDefaultEntitySpawnY() noexcept = 0;
        virtual void render(int playerX, int playerY) = 0;
        virtual void tick() = 0;
        template<typename T>
        bool isConflictingWithOtherObject(T *entity) noexcept;
        // Return nullptr, if scene object not found;
        SceneObject *getSceneObject(const char *name) noexcept;
        SceneObject getCollisionEventObject() noexcept;
        void addObject(SceneObject object) noexcept;
};

template<typename T>
bool IScene::isConflictingWithOtherObject(T *entity) noexcept {
    for(int i = 0; i < objects.size(); i++) {
        bool collisionX = entity->getX() + entity->getW() >= objects[i].x && objects[i].x + objects[i].w >= entity->getX();
        bool collisionY = entity->getY() + entity->getH() >= objects[i].y && objects[i].y + objects[i].h >= entity->getY();
        if(collisionX && collisionY && objects[i].isPushable) return true; 
        else if(collisionX && collisionY && !objects[i].isPushable) {
            ascii::Listener::Subject::getInstance().createMessage("onCollisionEvent");
            lastObject = objects[i];
        }
    }
    return false;
}

}

#endif // !SCENE_HPP