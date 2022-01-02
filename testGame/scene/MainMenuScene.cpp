#include "MainMenuScene.hpp"

namespace game::scene {

MainMenuScene::MainMenuScene(ascii::Engine *engine) {
    addObject(ascii::scene::SceneObject(-30, 200, 
                ascii::scene::createCollisionW(1, engine), 
                ascii::scene::createCollisionH(25, engine), "left_invisible_wall", true));
    addObject(ascii::scene::SceneObject(1625, 200, 
                ascii::scene::createCollisionW(1, engine), 
                ascii::scene::createCollisionH(25, engine), "right_invisible_wall", true));
    addObject(ascii::scene::SceneObject(625, 200, 
                ascii::scene::createCollisionW(3, engine), 
                ascii::scene::createCollisionH(3, engine), "tram", false));

    for(int x = 0; x < engine->getScreenWeight(); x+=75) railway += "___";
    railway += '\n';
    const astd::string railwayAppend("[@128, 119, 119]__[@59, 38, 0]/");
    for(int x = 0; x < engine->getScreenWeight(); x+=75) railway.append(railwayAppend);
    for(int x = 14*25; x < engine->getScreenWeight(); x+=75) railway1 += "|__";
}

bool MainMenuScene::isUsingCamera() noexcept {
    return false;
}
bool MainMenuScene::isUsingGravity() noexcept {
    return true;
}
int MainMenuScene::getDefaultEntitySpawnX() noexcept {
    return 275;
}
int MainMenuScene::getDefaultEntitySpawnY() noexcept {
    return 270;
}
void MainMenuScene::render(ascii::Engine *engine) {
    engine->draw(0, 0, tram_station);
    engine->draw(0, 425, railway);
    engine->drawWithBackground(225, 110, tram);
}
void MainMenuScene::tick() {

}

}