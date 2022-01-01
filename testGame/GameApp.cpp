#include "GameApp.hpp"

void GameApp::catchEvents(SDL_Event e, bool *quit) {
    if ( is_event(QUIT) ) *quit = true;
}

GameApp::~GameApp() {
}

void GameApp::onClose() {
}
void GameApp::tick(bool *quit) {
    cleanScreen();
    if ( is_key_pressed(Q) ) *quit = true;

    if(isUsingCamera()) {
        getCamera()->x = player.getX() - 1921/2;
        getCamera()->y = player.getY() - 1080/2;
        if( getCamera()->x < 0 ) getCamera()->x = 0;
        if( getCamera()->y < 0 ) getCamera()->y = 0;
        if( getCamera()->x > 1921 - getCamera()->w ) getCamera()->x = 1921 - getCamera()->w;
        if( getCamera()->y > 1080 - getCamera()->h ) getCamera()->y = 1080 - getCamera()->h;
    }
    mainMenu.render(this);

    if( gameMainObserver.isGotNewEvent() && gameMainObserver.getEventName() == "onCollisionEvent" ) {
        if( strcmp(getCurrentScene()->getCollisionEventObject().name, "tram") == 0) {
            draw(635, 300, astd::string("[Return]"));
        }
    }
    player.tick();
    player.render();
    presentScreen();
    SDL_Delay(2);
}

GameApp::GameApp() : player(this, 100) {
    createWindow("Ascii-G", 1920, 1080);
    loadFont("resources/fonts/10894.otf", 60, ascii::style::italic);
    for(int x = 0; x < 1921; x += 75) {
        pillar_line += "---";
    }
}

void GameApp::afterInit(bool *quit) {
    setCurrentScene(game::scene::main_menu::createMainMenuScene());
    player.setX(275);
    player.setY(270);
    game::scene::main_menu::defineMainMenuSceneObjects(this, getCurrentScene());
}