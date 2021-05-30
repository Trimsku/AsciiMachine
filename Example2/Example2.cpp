#define FONT_NAME "10894.otf"
#include <SFML/Graphics.hpp>
#include "../API/include/utils.hpp"
#include "../API/include/Entity.hpp"
#include "../API/include/Scene.hpp"
#include "../API/include/Color.hpp"
#include "../API/include/Server.hpp"
#include "../API/include/Config.hpp"

int main() {
    //USE_ANONYMOUS;
    ascii::Configuration config;
    config.global_size = 50;
    config.heightOfScreen = ascii::getDisplayHeight();
    config.widthOfScreen = ascii::getDisplayWidth();
    config.path_to_main = ascii::getCurrentDir(__FILE__);
    config.font_name = "10894.otf";

    sf::RenderWindow window(sf::VideoMode(1000,1000), "Ascii-G", sf::Style::Fullscreen);
    window.setActive(false);
    window.setFramerateLimit(60);

    ascii::Palitra myNewPalitra("Default");
    myNewPalitra.PushColor("red", 10, 100, 50);
    myNewPalitra.PushColor("green", 20, 200, 10);
    myNewPalitra.printColors();
    
    ascii::Scene scene(config);
    ascii::Entity Player("player");
    Player.Bind(config);
    Player.setGlobalXY(100,0);
    Player.isFontLoaded("10894.otf");
    Player.newSprites("PlayerStand");
    GENERATE_GUI_O_CLOCKS_FOR_ANIMATIONS(PlayerStand, "PlayerStand");


    for(float i = -250; i < ascii::getDisplayWidth()/2; i+=250){
        scene.PushAnonymousObject("__________", i, 150, false);
    }

    for(float i = -(ascii::getDisplayWidth()/2); i < 0; i+=250){
        scene.PushAnonymousObject("__________", i, 150, false);
    }

    std::string Str = "[@94,64,8]";
    for(int i = 0; i < ascii::getDisplayWidth()/2; i+=275) {
        Str+="########## ";
    }

    for(float j = 200; j < ascii::getDisplayHeight(); j+=30){
        scene.PushAnonymousObject(Str, 0, j, false);
    }
    for(float j = 200; j < ascii::getDisplayHeight(); j+=30){
        scene.PushAnonymousObject(Str, -(ascii::getDisplayWidth()/2), j, false);
    }

    scene.PushAnonymousObject("Stone", 150, 50);
    scene.PushAnonymousObject("Stone", -100, 50);
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