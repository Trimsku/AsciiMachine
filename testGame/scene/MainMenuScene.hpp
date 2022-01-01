#ifndef MAIN_MENU_SCENE_HPP
#define MAIN_MENU_SCENE_HPP

#include "../../asciiengine/common/Scene.hpp"
#include "../../asciiengine/astd/String.hpp"

namespace game::scene::main_menu {

inline ascii::scene::Scene createMainMenuScene() noexcept {
    return ascii::scene::Scene(false, true);
}

inline void defineMainMenuSceneObjects(ascii::Engine *engine, ascii::scene::Scene *scene) noexcept {
    scene->addObject(ascii::scene::SceneObject(-30, 200, 
                ascii::scene::createCollisionW(1, engine), 
                ascii::scene::createCollisionH(25, engine), "left_invisible_wall", true));
    scene->addObject(ascii::scene::SceneObject(1625, 200, 
                ascii::scene::createCollisionW(1, engine), 
                ascii::scene::createCollisionH(25, engine), "right_invisible_wall", true));
                scene->addObject(ascii::scene::SceneObject(625, 200, 
                ascii::scene::createCollisionW(3, engine), 
                ascii::scene::createCollisionH(3, engine), "tram", false));
}

}

#endif // !MAIN_MENU_SCENE_HPP