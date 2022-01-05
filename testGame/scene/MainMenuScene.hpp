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
        astd::string railway_wall = "[@128, 119, 119]";
        astd::string pillar_line = "[@41, 40, 38]";
        ascii::Observer observer = ascii::Observer("mainMenuScene");
        bool isTramCollision = false;
    public: 
        MainMenuScene(ascii::Engine *engine) noexcept;
        virtual bool isUsingGravity() noexcept override;
        virtual int getDefaultEntitySpawnX() noexcept override;
        virtual int getDefaultEntitySpawnY() noexcept override;
        virtual void render() noexcept override;
        virtual void tick() noexcept override;
};

#endif // !MAIN_MENU_SCENE_HPP