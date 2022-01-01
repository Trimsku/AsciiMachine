#include "MainMenuRenderer.hpp"

game::scene::main_menu::MainMenuRenderer::MainMenuRenderer() {
    for(int x = 0; x < 1921; x+=75) railway += "___";
    railway += '\n';
    const astd::string railwayAppend("[@128, 119, 119]__[@59, 38, 0]/");
    for(int x = 0; x < 1921; x+=75) railway.append(railwayAppend);
    for(int x = 14*25; x < 1921; x+=75) railway1 += "|__";
}

void game::scene::main_menu::MainMenuRenderer::render(ascii::Engine *engine) {
    engine->draw(0, 0, tram_station);
    engine->draw(0, 425, railway);
    engine->drawWithBackground(225, 110, tram);
}

void game::scene::main_menu::MainMenuRenderer::tick() {
}