#include "GameApp.hpp"

void GameApp::catchEvents(SDL_Event e) noexcept {
    if ( is_event(QUIT) ) close();
}

GameApp::~GameApp() noexcept {}

bool GameApp::isClosed() noexcept {
    return closed;
}
void GameApp::close() noexcept {
    closed = true;
}

void GameApp::tick() noexcept {
    if ( is_key_pressed(Q) ) close();
    if( is_key_pressed(G) && elapsedTimeInKeyPressing.getEllapsedTime() / 1000.0f > 1.0f ) {
        Options::getInstance().setDebugging(!Options::getInstance().isDebugging());
        elapsedTimeInKeyPressing.restart();
    }
    if( gameMainObserver.isGotNewEvent() && gameMainObserver.getEventName() == "onSceneChangedEvent" ) {
        player.setX(getScene()->getDefaultEntitySpawnX());
        player.setY(getScene()->getDefaultEntitySpawnY());
        gameMainObserver.setEventChecked();
    }
    getScene()->tick();
    player.tick();
}

void GameApp::render(double deltaTime) noexcept {
    cleanScreen();
    getCamera()->x = player.getX() - getScrW() / 2 + player.getW() * 2;
    getCamera()->y = player.getY() - getScrH() / 2 + player.getH() * 2;
    if(player.getState() == State::Left) getCamera()->x -= PLAYER_X_VELOCITY * deltaTime;
    else if(player.getState() == State::Right) getCamera()->x += PLAYER_X_VELOCITY * deltaTime;
    
    getScene()->render();
    player.render(deltaTime);
    presentScreen();
}

GameApp::GameApp() noexcept : player(this, 100) {
    createWindow("Ascii-G", -1, -1);
    loadFont("resources/fonts/10894.otf", 60, ascii::style::italic);
    setScene(new game::scene::MainMenuScene(this));
    Options::getInstance().setDebugging(false);
}