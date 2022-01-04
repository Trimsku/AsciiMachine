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

IScene::IScene(ascii::Engine *_engine) noexcept {
    engine = _engine;
}

IScene::~IScene() {}

short int createCollisionW(int numbers_of_chars_in_x, Engine *engine) noexcept {
    return ( engine->getFontSize() / 2 ) * numbers_of_chars_in_x;
}
short int createCollisionH(int numbers_of_chars_in_y, Engine *engine) noexcept {
    return engine->getFontSize() * ( numbers_of_chars_in_y + 1 );
}

void IScene::addObject(SceneObject object) noexcept {
    objects.push(object);
}

SceneObject *IScene::getSceneObject(const char *name) noexcept {
    for(int i = 0; i < objects.size(); i++) {
        if(objects[i].name == name) return &objects[i]; 
    }
    return nullptr;
}

SceneObject IScene::getCollisionEventObject() noexcept {
    return lastObject;
}

}