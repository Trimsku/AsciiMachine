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

void GameApp::update() noexcept {
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
    getScene()->update();
    player.update();
    getCamera()->update(player.getX(), player.getY(), player.getW(), player.getH());
}

void GameApp::render(double deltaTime) noexcept {
    getCamera()->onRendering(deltaTime, player.getState(), PLAYER_X_VELOCITY);
    getScene()->render();
    player.render(deltaTime);
}

GameApp::GameApp() noexcept : player(this, 100) {
    createWindow("Ascii-G", -1, -1);
    shader = ascii::client::Shader("resources/shaders/shader.vert", "resources/shaders/shader.frag");
    loadFont("resources/fonts/10894.otf", 60, ascii::style::italic);
    setScene(new game::scene::MainMenuScene(this));
    Options::getInstance().setDebugging(false);
}

ascii::client::Shader GameApp::getCurrentShader() noexcept {
    return shader;
}