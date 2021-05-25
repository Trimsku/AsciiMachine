#define GLOBAL_SIZE 50
#include "../AsciiMachineCurrent/API/include/GUI_o.hpp"
#include "../AsciiMachineCurrent/API/include/utils.hpp"
#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(1000,1000), "Ascii-G", sf::Style::Fullscreen);
    ascii::GUI_o HelloWorld("HelloWorld");
    HelloWorld.setGlobalXY(0,0);
    HelloWorld.isFontLoaded("../font/10894.otf");
    HelloWorld.newSprites("Hello World!", "HW");

    while (window.isOpen()) {
        window.clear();

        EVENT;
        EVENT_CLOSED(Q);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) window.close();
        GUI_O_LOAD(HelloWorld, HW);

        window.display();
    }

    return 0;
}