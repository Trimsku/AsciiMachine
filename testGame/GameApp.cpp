#include "GameApp.hpp"

void GameApp::catchEvents(SDL_Event e, bool *quit) {
    if ( is_event(QUIT) ) *quit = true;
}

GameApp::~GameApp() {
}

void GameApp::onClose() {
}
void GameApp::tick(bool *quit) {
    if ( is_key_pressed(Q) ) *quit = true;
    if( is_key_pressed(G) && elapsedTimeInKeyPressing.getEllapsedTime() / 1000.0f > 1.0f ) {
        Options::getInstance().setDebugging(!Options::getInstance().isDebugging());
        elapsedTimeInKeyPressing.restart();
    }

    if( gameMainObserver.isGotNewEvent() && gameMainObserver.getEventName() == "onSceneChangedEvent" ) {
        player.setX(getScene()->getDefaultEntitySpawnX());
        player.setY(getScene()->getDefaultEntitySpawnY());
        gameMainObserver.setEventChecked();
    }
    if( gameMainObserver.isGotNewEvent() && gameMainObserver.getEventName() == "onCollisionEvent" ) {
        if( strcmp(getScene()->getCollisionEventObject().name, "tram") == 0) {
            isTramCollision = true;
            gameMainObserver.setEventChecked();
        }
    } else {
        isTramCollision = false;
    }
    player.tick();
}

void GameApp::render(double deltaTime) {
    cleanScreen();
    getCamera()->x = player.getX() - getScrW() / 2 + player.getW() * 2;
    getCamera()->y = player.getY() - getScrH() / 2 + player.getH() * 2;
    if(player.getState() == State::Left) getCamera()->x -= PLAYER_X_VELOCITY * deltaTime;
    else if(player.getState() == State::Right) getCamera()->x += PLAYER_X_VELOCITY * deltaTime;
    getScene()->render(player.getX(), player.getY());
    if(isTramCollision) draw(635 - getCamera()->x - 75 / 2, 300 - getCamera()->y - 200 / 2, astd::string("[Return]"));

    player.render(deltaTime);
    presentScreen();
}

GameApp::GameApp() : player(this, 100) {
    createWindow("Ascii-G", -1, -1);
    loadFont("resources/fonts/10894.otf", 60, ascii::style::italic);
    setScene(new game::scene::MainMenuScene(this));
    Options::getInstance().setDebugging(false);
}