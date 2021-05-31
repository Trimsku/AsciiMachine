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
    ascii::Server server;
    ascii::Configuration config;
    config.global_size = 50;
    config.heightOfScreen = ascii::getDisplayHeight();
    config.widthOfScreen = ascii::getDisplayWidth();
    config.path_to_main = ascii::getCurrentDir(__FILE__);
    config.font_name = "10894.otf";

    sf::RenderWindow window(sf::VideoMode(1000,1000), "Ascii-G", sf::Style::Fullscreen);
    window.setActive(false);
    window.setFramerateLimit(60);
    config.window = &window;

    ascii::Palitra myNewPalitra("Default");
    myNewPalitra.PushColor("red", 10, 100, 50);
    myNewPalitra.PushColor("green", 20, 200, 10);
    myNewPalitra.printColors();
    
    ascii::Scene scene(config);
    ascii::Entity Player("player");
    Player.Bind(config);
    Player.setGlobalXY(100,0);
    Player.addSprite("PlayerStand"); // this is auto. PlayerStand is in your_folder/textures/PlayerStand.rtxt
    Player.setHitbox(100, 175, 0, 200);
    Player.setHP(100);
    GENERATE_GUI_O_CLOCKS_FOR_ANIMATIONS(PlayerStand, "PlayerStand");

    ascii::GUI_o Zombie("zombie");
    Zombie.Bind(config);
    Zombie.setGlobalXY(200,50);
    Zombie.addSprite("Zombie");
    Zombie.setHitbox(200, 275, 50, 200);

    for(float i = -250; i < ascii::getDisplayWidth()/2; i+=250){
        scene.addText("RoadPart0","__________", i, 150, true);
    }

    for(float i = -(ascii::getDisplayWidth()/2); i < 0; i+=250){
        scene.addText("RoadPart1", "__________", i, 150, true);
    }

    std::string Str = "[@94,64,8]";
    for(int i = 0; i < ascii::getDisplayWidth(); i+=275) {
        Str+="########## ";
    }

    for(float j = 200; j < ascii::getDisplayHeight(); j+=30){
        scene.addText("RoadPart3",Str, -(ascii::getDisplayWidth()/2), j, true);
    }

    scene.addFromFile("Stone1", "Stone", 150, 50, true);
    scene.addFromFile("Stone2", "Stone", -100, 50, true);
    
    scene.PushObject(Zombie);
    server.sendStatus(&Zombie);
    while (window.isOpen())
    {
        window.clear();
        // Update Player's status in server and draw in client;
        server.update(&Player);
        if ( server.lookfor("zombie") ) {
            Player.MinusHP(5);
        }
        scene.loadText("PlayerHPBar", std::to_string(Player.getHP()), 0, 0);
        //SCENE_DRAW
        scene.DisplayMap();
        // Process events
        EVENT;
        EVENT_CLOSED(Q);

        GUI_CLOCKS_TIMER(PlayerStand, 750);
        //GUI_O_LOAD(Zombie, Zombie);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            GUI_O_ANIMATED_MV(Player, PlayerStand, 20.0f, 0);
            server.sendStatus(&Player);
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ){
            GUI_O_ANIMATED_MV(Player, PlayerStand, -10.0f, 0);
            server.sendStatus(&Player);
        }
        else GUI_O_ANIMATED(Player, PlayerStand);
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