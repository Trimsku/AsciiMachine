#define GLOBAL_SIZE 50
//#include "../API/include/GUI_o.hpp"
#include "../API/include/utils.hpp"
//#include "../API/include/Config.hpp"
#include <SFML/Graphics.hpp>

int main() {
    //ascii::Configuration config;
    //config.global_size = 50;
    //config.path_to_main = ascii::getCurrentDir(__FILE__);
    //config.font_name = "10894.otf";
    //config.heightOfScreen = ascii::getDisplayHeight();
    //config.widthOfScreen = ascii::getDisplayWidth();
    //config.path_to_font = "font/10894.cpp";
    sf::RenderWindow window(sf::VideoMode(1000,1000), "Ascii-G", sf::Style::Fullscreen);
    //ascii::GUI_o HelloWorld("HelloWorld");
    //HelloWorld.Bind(config);
    //HelloWorld.setGlobalXY(config.widthOfScreen/3, config.heightOfScreen/2);
    //HelloWorld.isFontLoaded("10894.otf");
    //HelloWorld.addSprite("Hello World", false);

    while (window.isOpen()) {
        window.clear();

        EVENT;
        EVENT_CLOSED(Q);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) window.close();
        //GUI_O_LOAD(HelloWorld, Hello World);

        window.display();
    }

    return 0;
}