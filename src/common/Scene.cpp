#include "../../asciiengine/common/Scene.hpp"
#include "../../asciiengine/core/Engine.hpp"

namespace ascii::scene {

SceneObject::SceneObject() noexcept {}
SceneObject::SceneObject(short int _x, short int _y, short int _w, short int _h, const char* _name, bool _isPushable) noexcept {
    x = _x;
    y = _y;
    w = _w;
    h = _h;
    name = _name;
    isPushable = _isPushable;
};

Scene::Scene(bool camera_, bool gravity_) noexcept {
    camera = camera_;
    gravity = gravity_;
}

short int createCollisionW(int numbers_of_chars_in_x, Engine *engine) noexcept {
    return ( engine->getFontSize() / 2 ) * numbers_of_chars_in_x;
}
short int createCollisionH(int numbers_of_chars_in_y, Engine *engine) noexcept {
    return engine->getFontSize() * ( numbers_of_chars_in_y + 1 );
}

void Scene::addObject(SceneObject object) noexcept {
    objects.push(object);
}
int Scene::getDefaultEntitySpawnX() noexcept {
    return 0;
}
int Scene::getDefaultEntitySpawnY() noexcept {
    return 0;
}

SceneObject *Scene::getSceneObject(const char *name) noexcept {
    for(int i = 0; i < objects.size(); i++) {
        if(objects[i].name == name) return &objects[i]; 
    }
    return nullptr;
}

bool Scene::isUsingCamera() noexcept {
    return camera;
}

bool Scene::isUsingGravity() noexcept {
    return gravity;
}

SceneObject Scene::getCollisionEventObject() noexcept {
    return lastObject;
}

}