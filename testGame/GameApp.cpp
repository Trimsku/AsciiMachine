#include "GameApp.hpp"

void GameApp::catchEvents(SDL_Event e, bool *quit) {
    if ( is_event(QUIT) ) *quit = true;
    if( gameMainObserver.isGotNewEvent() && gameMainObserver.getEventName() == "onSceneChangedEvent" ) {
        player.setX(getScene()->getDefaultEntitySpawnX());
        player.setY(getScene()->getDefaultEntitySpawnY());
        gameMainObserver.setEventChecked();
    }
}

GameApp::~GameApp() {
}

void GameApp::onClose() {
}
void GameApp::tick(bool *quit) {
    cleanScreen();
    if ( is_key_pressed(Q) ) *quit = true;

    if(isUsingCamera()) {
        getCamera()->x = player.getX() - getScreenWeight()/2;
        getCamera()->y = player.getY() - getScreenHeight()/2;
        if( getCamera()->x < 0 ) getCamera()->x = 0;
        if( getCamera()->y < 0 ) getCamera()->y = 0;
        if( getCamera()->x > getScreenWeight() - getCamera()->w ) getCamera()->x = getScreenWeight() - getCamera()->w;
        if( getCamera()->y > getScreenHeight() - getCamera()->h ) getCamera()->y = getScreenHeight() - getCamera()->h;
    }
    getScene()->render(this);

    if( gameMainObserver.isGotNewEvent() && gameMainObserver.getEventName() == "onCollisionEvent" ) {
        if( strcmp(getScene()->getCollisionEventObject().name, "tram") == 0) {
            draw(635, 300, astd::string("[Return]"));
            gameMainObserver.setEventChecked();
        }
    }
    player.tick();
    player.render();
    presentScreen();
}

GameApp::GameApp() : player(this, 100) {
    createWindow("Ascii-G", -1, -1);
    loadFont("resources/fonts/10894.otf", 60, ascii::style::italic);
    for(int x = 0; x < getScreenWeight(); x += 75) {
        pillar_line += "---";
    }
}

void GameApp::afterInit(bool *quit) {
    setScene(new game::scene::MainMenuScene(this));
}