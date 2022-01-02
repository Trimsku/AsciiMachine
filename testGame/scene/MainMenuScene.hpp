#ifndef MAIN_MENU_SCENE_HPP
#define MAIN_MENU_SCENE_HPP

#include "../../asciiengine/common/Scene.hpp"
#include "../../asciiengine/astd/String.hpp"
#include "../../asciiengine/core/Engine.hpp"

namespace game::scene {

class MainMenuScene : public ascii::scene::IScene {
    private:
        const astd::string tram_station = ascii::util::getFileResources("resources/textures/TramStation0.txt");
        const astd::string tram = ascii::util::getFileResources("resources/textures/Tram.txt");
        astd::string railway = "[@128, 119, 119]";
        astd::string railway1 = "[@128, 119, 119]";
    public: 
        MainMenuScene(ascii::Engine *engine);
        virtual bool isUsingCamera() noexcept override;
        virtual bool isUsingGravity() noexcept override;
        virtual int getDefaultEntitySpawnX() noexcept override;
        virtual int getDefaultEntitySpawnY() noexcept override;
        virtual void render(ascii::Engine *engine);
        virtual void tick();
};

inline void defineMainMenuSceneObjects(ascii::Engine *engine, ascii::scene::IScene *scene) noexcept {
}

}

#endif // !MAIN_MENU_SCENE_HPP