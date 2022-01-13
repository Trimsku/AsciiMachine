#ifndef GAME_APP_HPP
#define GAME_APP_HPP

// Add Input class(keyboard wrapper)
// Add Log class
#include "../asciiengine/core/IApp.hpp"
#include "../asciiengine/client/AsciiClient.hpp"
#include "../asciiengine/common/event/Subject.hpp"
#include "../asciiengine/common/event/Observer.hpp"
#include "scene/MainMenuScene.hpp"
#include "Player.hpp"
#include "Options.hpp"

class GameApp : public ascii::IApp {
    public:
        ~GameApp() noexcept;
        GameApp() noexcept;
        void update() noexcept;
        void render(double deltaTime) noexcept;
        void catchEvents(SDL_Event e) noexcept;
        ascii::client::Shader getCurrentShader() noexcept override;
    private:
        ascii::client::Shader shader;
        Player player;
        astd::Clock elapsedTimeInKeyPressing;
        const astd::string GodsEnvoy = ascii::util::getFileResources("resources/textures/GodsEnvoy.txt");
        const astd::string tram_station_aeromald = ascii::util::getFileResources("resources/textures/AeromaldTramStation.txt");
        const astd::string beacon = ascii::util::getFileResources("resources/textures/beacon.txt");
        ascii::client::AnimatedTextBuilder gameStart = ascii::client::AnimatedTextBuilder()
            .addText("Hello. This is Ascii-G. Adventure with RPG elements.", 100)
            .addText("Use left, right, up and down buttons for move.", 50)
            .addText("Use _______________", 50)
            .addText("   |               |", 25)
            .addText("   |  /__________| |", 25)
            .addText("   |  \\            |", 25)
            .addText("   |_______________|", 25)
            .addText("for shops,tram, cars, buttons and i.e", 50)
            .addText("[Return]", 50);

        ascii::client::AnimatedTextBuilderUTF8 japaneseBoy = ascii::client::AnimatedTextBuilderUTF8()
            .addText(astd::string("Ну как, ветер ещё дует?"), 35)
            .addText(astd::string("А, мальчик из Японии?"), 45);

        astd::string pillar = "[@41, 40, 38]\\|/\n |\n |\n |\n |";

        ascii::Observer gameMainObserver = ascii::Observer("gameMainObserver");
};

#endif // !GAME_APP_HPP