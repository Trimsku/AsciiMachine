#define GLOBAL_SIZE 50
#define ANONYMOUS_SIZE 50
#define FONT_PATH "../Example2/font/10894.otf"
#include <SFML/Graphics.hpp>
#include "../AsciiMachineCurrent/API/include/utils.hpp"
#include "../AsciiMachineCurrent/API/include/Entity.hpp"
#include "../AsciiMachineCurrent/API/include/Scene.hpp"
#include "../AsciiMachineCurrent/API/include/Color.hpp"
#include "../AsciiMachineCurrent/API/include/Server.hpp"


int main() {
    USE_ANONYMOUS;

    sf::RenderWindow window(sf::VideoMode(1000,1000), "Ascii-G", sf::Style::Fullscreen);
    window.setActive(false);
    window.setFramerateLimit(60);

    ascii::Palitra myNewPalitra("Default");
    myNewPalitra.PushColor("red", 10, 100, 50);
    myNewPalitra.PushColor("green", 20, 200, 10);
    myNewPalitra.printColors();
    
    ascii::Scene scene;
    scene.setWidthAndHeight(ascii::getDisplayWidth(), ascii::getDisplayHeight());
    scene.AnonymousSettings(50, "../Example2/font/10894.otf");

    ascii::Entity Player("player");
    Player.setGlobalXY(100,0);
    Player.isFontLoaded("../Example2/font/10894.otf");
    Player.newSprites("../Example2/textures/PlayerStand.rtxt", "PlayerStand");
    GENERATE_GUI_O_CLOCKS_FOR_ANIMATIONS(PlayerStand, "../Example2/textures/PlayerStand.rtxt");


    for(float i = -250; i < ascii::getDisplayWidth()/2; i+=250){
        ANONYMOUS_OBJECT("__________", i, 150);
    }

    for(float i = -(ascii::getDisplayWidth()/2); i < 0; i+=250){
        ANONYMOUS_OBJECT("__________", i, 150);
    }

    std::string Str = "[@94,64,8]";
    for(int i = 0; i < ascii::getDisplayWidth()/2; i+=275) {
        Str+="########## ";
    }

    for(float j = 200; j < ascii::getDisplayHeight(); j+=30){
        ANONYMOUS_OBJECT(Str, 0, j);
    }
    for(float j = 200; j < ascii::getDisplayHeight(); j+=30){
        ANONYMOUS_OBJECT(Str, -(ascii::getDisplayWidth()/2), j);
    }

    ANONYMOUS_OBJECT("../Example2/textures/B.rtxt", 150, 50)
    ANONYMOUS_OBJECT("../Example2/textures/B.rtxt", 1850, 50)
    while (window.isOpen())
    {
        window.clear();
        //SCENE_DRAW
        scene.DisplayMap(&window);
        // Process events
        EVENT;
        EVENT_CLOSED(Q);

        GUI_CLOCKS_TIMER(PlayerStand, 750);

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)){
                GUI_O_ANIMATED_MV(Player, PlayerStand, 20.0f, 0);
            }
            else {
                GUI_O_ANIMATED_MV(Player, PlayerStand, 10.0f, 0);
            }
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ){
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)){
                GUI_O_ANIMATED_MV(Player, PlayerStand, -20.0f, 0);
            }
            else {
                GUI_O_ANIMATED_MV(Player, PlayerStand, -10.0f, 0);
            }
        }
        else{
            GUI_O_ANIMATED(Player, PlayerStand);
        }
        if(Player.getX() < 0){
            scene.chunk_x_change(-1);
            Player.MoveX(1920);
        }
        if(Player.getX() > ascii::getDisplayWidth() ){
            scene.chunk_x_change(+1);
            Player.MoveX( -( ascii::getDisplayWidth() ) );
        }
        window.display();
    }
    return 0;
}

/*
 _   _ 
 o/ \o 
<#   %>
/ \ / \ 
&####&&##
*/