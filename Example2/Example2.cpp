#define GLOBAL_SIZE 50
#define ANONYMOUS_SIZE 50
#define FONT_PATH "../font/10894.otf"
#include <SFML/Graphics.hpp>
#include "../AsciiMachineCurrent/API/include/utils.hpp"
#include "../AsciiMachineCurrent/API/include/Entity.hpp"
#include "../AsciiMachineCurrent/API/include/Scene.hpp"
#include "../AsciiMachineCurrent/API/include/Color.hpp"
#include "../AsciiMachineCurrent/API/include/Server.hpp"


int main() {
    USE_ANONYMOUS;

    sf::RenderWindow window(sf::VideoMode(1000,1000), "Ascii-G", sf::Style::Fullscreen);
    ascii::Palitra myNewPalitra("Default");
    myNewPalitra.PushColor("red", 10, 100, 50);
    myNewPalitra.PushColor("green", 20, 200, 10);
    myNewPalitra.printColors();
    
    ascii::Scene scene;
    scene.setWidthAndHeight(1920, 1080);
    scene.AnonymousSettings(50, "../font/10894.otf");

    ascii::Entity EvilEntity("e_entity");
    EvilEntity.setGlobalXY(800,100);
    EvilEntity.isFontLoaded("../font/10894.otf");
    EvilEntity.newSprites("../textures/EvilEntity.rtxt", "e_entity");

    ascii::Entity Player("player");
    Player.setGlobalXY(100,0);
    Player.isFontLoaded("../font/10894.otf");
    Player.newSprites("../textures/PlayerStand.rtxt", "PlayerStand");
    GENERATE_GUI_O_CLOCKS_FOR_ANIMATIONS(PlayerStand, "../textures/PlayerStand.rtxt");


    for(int i = -250; i < 1920; i+=250){
        ANONYMOUS_OBJECT("__________", i, 150);
    }

    std::string Str = "[@94,64,8]";
    for(int i = 0; i < 1920; i+=275) {
        Str+="########## ";
    }

    for(int j = 200; j < 1080; j+=30){
        ANONYMOUS_OBJECT(Str, 0, j);
    }

    ANONYMOUS_OBJECT("../textures/B.rtxt", 150, 50)
    if(!scene.ttexture.create(1920,1080))
        exit(0);
    
    scene.DrawMap();
    sf::Sprite MapTexture(scene.ttexture.getTexture());

    while (window.isOpen())
    {

        window.clear();
        //SCENE_DRAW
        // Process events
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }

        GUI_CLOCKS_TIMER(PlayerStand, 750);

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) window.close();
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            GUI_O_ANIMATED_MV(Player, PlayerStand, 0.3, 0);
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            GUI_O_ANIMATED_MV(Player, PlayerStand, -0.3, 0);
        }
        else{
            GUI_O_ANIMATED(Player, PlayerStand);
        }

        window.draw(MapTexture);
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