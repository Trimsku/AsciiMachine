#ifndef MAIN_MENU_RENDERER
#define MAIN_MENU_RENDERER

#include "../../asciiengine/client/ITickingRenderer.hpp"
namespace game::scene::main_menu {

class MainMenuRenderer : ascii::client::ITickingRenderer {
    public:
        MainMenuRenderer();
        MAKE_ITICKING_RENDERER;
    private:
        const astd::string tram_station = ascii::util::getFileResources("resources/textures/TramStation0.txt");
        const astd::string tram = ascii::util::getFileResources("resources/textures/Tram.txt");
        astd::string railway = "[@128, 119, 119]";
        astd::string railway1 = "[@128, 119, 119]";
};

}

#endif // !MAIN_MENU_RENDERER