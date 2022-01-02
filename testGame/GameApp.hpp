#ifndef GAME_APP_HPP
#define GAME_APP_HPP

#include "../asciiengine/core/IApp.hpp"
#include "../asciiengine/client/AnimationManager.hpp"
#include "../asciiengine/client/AnimatedTexture.hpp"
#include "../asciiengine/client/AnimatedTextUTF8.hpp"
#include "../asciiengine/client/AnimatedTextBuilder.hpp"
#include "../asciiengine/client/AnimatedTextBuilderUTF8.hpp"
#include "../asciiengine/common/event/Subject.hpp"
#include "../asciiengine/common/event/Observer.hpp"
#include "scene/MainMenuScene.hpp"
#include "Player.hpp"

class GameApp : public ascii::IApp {
    public:
        ~GameApp();
        GameApp();
        void tick(bool *quit);
        void afterInit(bool *quit);
        void catchEvents(SDL_Event e, bool *quit);
        void onClose();
    private:
        SDL_DisplayMode mode;
        Player player;
        const astd::string GodsEnvoy = ascii::util::getFileResources("resources/textures/GodsEnvoy.txt");
        const astd::string tram_station_aeromald = ascii::util::getFileResources("resources/textures/AeromaldTramStation.txt");
        const astd::string beacon = ascii::util::getFileResources("resources/textures/beacon.txt");
        ascii::client::AnimatedTextBuilder gameStart = ascii::client::AnimatedTextBuilder()
            .addText("Hello. This is Ascii-G. Adventure with RPG elements.", 100)
            .addText("Use left, right, up and down buttons for move.", 50)
            .addText("Use _______________", 50)
            .addText("   |             | |", 25)
            .addText("   |  /__________| |", 25)
            .addText("   |  \\            |", 25)
            .addText("   |_______________|", 25)
            .addText("for shops,", 50)
            .addText("tram, cars, buttons and i.e", 50)
            .addText("Go to the tram, hero.", 50)
            .addText("[Return]", 50);

        ascii::client::AnimatedTextBuilderUTF8 japaneseBoy = ascii::client::AnimatedTextBuilderUTF8()
            .addText("Ну как, ветер ещё дует?", 35)
            .addText("А, мальчик из Японии?", 45);

        astd::string pillar = "[@41, 40, 38]\\|/\n |\n |\n |\n |";
        astd::string pillar_line = "[@41, 40, 38]";

        ascii::Observer gameMainObserver = ascii::Observer("gameMainObserver");
};

#endif // !GAME_APP_HPP