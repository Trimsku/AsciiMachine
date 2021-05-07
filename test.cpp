#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <SFML/Graphics.hpp>
#include "src/utils.hpp"
#include "src/Sprites.hpp"
#include "src/Entity.hpp"
#include "src/Server.hpp"
#include "src/Log.hpp"
#include "src/GlobalVars.hpp"


int main(){
    // Your display width and height.
    int width, height;
    ascii::setDisplayYX(width, height);
    // Init for classes

    ascii::Sprite sprite;
    ascii::Server server;
    sf::Clock forPlayerRun;
    sf::Clock forPlayerStand;
    sf::Clock forNPC;
    sf::Font font;
    // Init textures; part 0.

    std::string A = ascii::getFileResources("textures/Tree.rtxt"); 
    std::string B = ascii::getFileResources("textures/PlayerStand.rtxt");
    std::string C = ascii::getFileResources("textures/PlayerRunLeft.rtxt");
    std::string D = ascii::getFileResources("textures/PlayerRunRight.rtxt");
    std::string E = ascii::getFileResources("textures/Pics.rtxt");
    std::string F = ascii::getFileResources("textures/Home.rtxt");
    std::string G = ascii::getFileResources("textures/Tree1.rtxt");
    std::string H = ascii::getFileResources("textures/shrub.rtxt");
    std::string O = ascii::getFileResources("textures/NPC.rtxt");
    // Init textures; part 1;

    sf::Text Tree0(A, font,50);
    sf::Text Tree1(G, font, 40);
    sf::Text Shrub(H, font, 50);

    sf::Text NPCStand(O, font, 50);
    sf::Text PlayerStand(B, font,50);
    sf::Text PlayerRunLeft(C, font,50);
    sf::Text PlayerRunRight(D, font,50);

    sf::Text Road("[#1[@7, 82, 0]_#1]", font, 50);
    sf::Text YCoord("[#1[@7, 82, 0]|#1]", font, 50);

    sf::Text Pic(E, font, 50);
    sf::Text Home(F, font, 50);
    ascii::Entity Player("Player");
    ascii::Entity NPC("NPC");

    // Fill classes

    Player.setHP(100);
    NPC.setAttack(20);
    sf::Text TextBar("[#1"+std::to_string(Player.getHP())+"#1]", font, 50);
    font.loadFromFile("fonts/10894.otf");
    server.sendStatus(&Player);
    PlayerRunRight.setStyle(sf::Text::Italic);
    PlayerRunLeft.setStyle(sf::Text::Italic);
    Tree0.setStyle(sf::Text::Italic);
    Tree1.setStyle(sf::Text::Italic);
    float PlayerY = ascii::getDownY(PlayerStand), PlayerX = 200;
    NPC.setHitbox(500, ascii::getDownY(NPCStand), 600, ascii::getDisplayY());
    server.sendStatus(&NPC);
    int i = 1;
    int j = 1;

    std::cout<<"width is "<<width<<", height is "<<height<<'\n';
    // While
    while (window.isOpen())
	{
        TextBar.setString("[#1"+std::to_string(Player.getHP()) + "#1]");
        Player.setHitbox(PlayerX, PlayerY, PlayerX+50*2, ascii::getDisplayY());
        
        window.clear();

		// Events
        sf::Event event;
        if(Player.getHP() <= 0){
            PlayerY = ascii::getDownY(PlayerStand);
            PlayerX = 200;
            Player.setHP(100);
        }
        server.update(&Player);
        if(server.lookfor("NPC") && forNPC.getElapsedTime().asMilliseconds() >= 1000){
            Player.MinusHP(NPC.getAttack());
            forNPC.restart();
        }
        server.refresh();

		while (window.pollEvent(event))
			if (event.type == sf::Event::Closed) window.close();
        // Render road, and Trees, and Monuments
        if (forPlayerRun.getElapsedTime().asMilliseconds() >= 100)// 100 ms, to i++;
        {
            ++i;
            if(i > 4){
                i = 1;
            }
            forPlayerRun.restart();
        }
        for(int i = 0; i < width; i+=Road.getCharacterSize()/2){
            sprite.loadSprite(Road, i, height-55);
        }
        sprite.loadSprite(TextBar, 100, 100);
        sprite.loadSprite(Tree1, ascii::getLeftX(Tree1), ascii::getDownY(Tree1));
        sprite.loadSprite(Pic, ascii::getRightX(Pic), ascii::getDownY(Pic));
        sprite.loadSprite(Shrub, 500, ascii::getDownY(Shrub));
        sprite.loadSprite(Shrub, 800, ascii::getDownY(Shrub));
        sprite.loadSprite(Shrub, 500,ascii::getDownY(Shrub));
        sprite.loadSprite(Home, ascii::getRightX(Home),ascii::getDownY(Pic) * 2 - ascii::getDownY(Home)+50);
        sprite.loadSprite(NPCStand, 500, ascii::getDownY(NPCStand));
        // Render Player
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
            window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            j=0;
            PlayerX+=0.5; 
            sprite.loadSprite(PlayerRunRight, PlayerX, PlayerY, i);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            j=0;
            PlayerX-=0.5; 
            sprite.loadSprite(PlayerRunLeft, PlayerX, PlayerY, i);
        }

        else {
            if (forPlayerStand.getElapsedTime().asMilliseconds() >= 800){
                ++j;
                if (j > 4){
                    j = 1;
                }
                forPlayerStand.restart();
            }
            sprite.loadSprite(PlayerStand, PlayerX, PlayerY, j);
        }
        if(PlayerX > width){
            PlayerX = -50;
        } 
        if(PlayerX < -100){
            PlayerX = width-100;
        }
        window.display();
    }
    
    return 0;
}
