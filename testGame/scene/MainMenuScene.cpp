#include "MainMenuScene.hpp"

namespace game::scene {

MainMenuScene::MainMenuScene(ascii::Engine *engine) : ascii::scene::IScene(engine) {
    addObject(ascii::scene::SceneObject(-60, 200, 
                ascii::scene::createCollisionW(1, engine), 
                ascii::scene::createCollisionH(25, engine), "left_invisible_wall", true));
    addObject(ascii::scene::SceneObject(1615, 200, 
                ascii::scene::createCollisionW(1, engine), 
                ascii::scene::createCollisionH(25, engine), "right_invisible_wall", true));
    addObject(ascii::scene::SceneObject(625, 200, 
                ascii::scene::createCollisionW(3, engine), 
                ascii::scene::createCollisionH(3, engine), "tram", false));

    for(int x = 0; x < engine->getScrW()*3; x+=75) railway += "___";
    railway += '\n';
    const astd::string railwayAppend("[@128, 119, 119]__[@59, 38, 0]/");
    for(int x = 0; x < engine->getScrW() * 3; x+=75) railway.append(railwayAppend);
    for(int x = 14*25; x < engine->getScrW(); x+=75) railway_wall += "|__";
    for(int x = 0; x < engine->getScrW() * 3; x += 75) pillar_line += "---";
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
void MainMenuScene::render(int playerX, int playerY) {
    engine->draw(0 - engine->getCamera()->x - 75/2, 0 - engine->getCamera()->y - 200/2, tram_station);
    engine->draw(-1920 - engine->getCamera()->x - 75/2, 425 - engine->getCamera()->y - 200/2, railway);
    engine->draw(-1870 - engine->getCamera()->x - 75/2, 545 - engine->getCamera()->y - 200/2, railway_wall);
    engine->draw(1720 - engine->getCamera()->x - 75/2, 545 - engine->getCamera()->y - 200/2, railway_wall);
    engine->drawWithBackground(225 - engine->getCamera()->x - 75/2, 110 - engine->getCamera()->y - 200/2, tram);
    engine->draw(-engine->getScrW() - engine->getCamera()->x - 75/2, 115 - engine->getCamera()->y - 200/2, pillar_line);
}
void MainMenuScene::tick() {

}

}