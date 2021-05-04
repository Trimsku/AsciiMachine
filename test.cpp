#include <iostream>
#include <fstream>
#include <unistd.h>
#include <typeinfo>
#include <math.h>
#include <string>
#include <SFML/Graphics.hpp>
#include "src/utils.hpp"
#include "src/Sprites.hpp"
#include "src/Entity.hpp"
#include "src/Server.hpp"
#include "src/Log.hpp"

int main(){
    int width, height;
    // Init for classes
    ascii::getDisplayYX(width, height);
    sf::Font font;
    ascii::Sprite sprite;
    ascii::Server server;
    //ascii::Log log("log.txt");
    sf::Clock clock;
    sf::Clock clock1;
    sf::Clock clock2;
    std::string A = sprite.GetSpriteResources("textures/Tree.txt");
    std::string B = sprite.GetSpriteResources("textures/PlayerStand.txt");
    std::string C = sprite.GetSpriteResources("textures/PlayerRunLeft.txt");
    std::string D = sprite.GetSpriteResources("textures/PlayerRunRight.txt");
    std::string E = sprite.GetSpriteResources("textures/Pics.txt");
    std::string F = sprite.GetSpriteResources("textures/Home.txt");
    std::string G = sprite.GetSpriteResources("textures/Tree1.txt");
    std::string H = sprite.GetSpriteResources("textures/shrub.txt");
    sf::Text Tree0(A, font,50);
    sf::Text Tree1(G, font, 40);
    sf::Text Shrub(H, font, 50);
    sf::Text PlayerStand(B, font,50);
    sf::Text PlayerRunLeft(C, font,50);
    sf::Text PlayerRunRight(D, font,50);
    sf::Text Road("[#1[@7, 82, 0]_#1]", font, 50);
    sf::Text Pic(E, font, 50);
    sf::Text Home(F, font, 50);
    ascii::Entity Player("Player");
    // Fill classes
    font.loadFromFile("fonts/10894.otf");
    Player.SetSprite(PlayerStand);
    Player.SetHitbox(200,300);
    server.SendStatus(&Player);
    PlayerRunRight.setStyle(sf::Text::Italic);
    PlayerRunLeft.setStyle(sf::Text::Italic);
    Tree0.setStyle(sf::Text::Italic);
    Tree1.setStyle(sf::Text::Italic);
    float PlayerY = 1024-PlayerRunLeft.getCharacterSize()*4, PlayerX = 200;
    int i = 1;
    int j = 1;
    std::cout<<"width is "<<width<<", height is "<<height<<'\n';
    //sf::FloatRect a = Tree0.getGlobalBounds();
    sf::RenderWindow window(sf::VideoMode(1920, 1024), "I am testing, sorry program.");
    while (window.isOpen())
	{
        window.clear();
		// Events
        sf::Event event;
		while (window.pollEvent(event))
			if (event.type == sf::Event::Closed) window.close();
        // Render road, and Trees, and Monuments
        if (clock.getElapsedTime().asMilliseconds() >= 100)// если прошла секунда, отнимаем 1 секунду у таймера
        {
            ++i;
            if(i > 4){
                i = 1;
            }
            clock.restart();
        }
        for(int i = 0; i < 2048; i+=Road.getCharacterSize()/2){
            sprite.LoadSprite(Road, window, i, 970);
        }
        sprite.LoadSprite(Tree1, window, 0, height-56-Tree1.getCharacterSize()*14);
        sprite.LoadSprite(Pic, window, 1200, 1024 - 450);
        sprite.LoadSprite(Shrub, window, 0,875);
        sprite.LoadSprite(Shrub, window, 500,875);
        sprite.LoadSprite(Shrub, window, 800,875);
        sprite.LoadSprite(Shrub, window, 1500,875);
        sprite.LoadSprite(Shrub, window, 1400,875);
        sprite.LoadSprite(Home, window, 1500, 1024-450-200);
        // Render Player
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            j=0;
            //PlayerRunRight.move(0.4, 0);
            PlayerX+=0.4; 
            sprite.LoadSprite(PlayerRunRight, window, PlayerX, PlayerY, i);
        }

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            j=0;
            PlayerX-=0.3; 
            sprite.LoadSprite(PlayerRunLeft, window, PlayerX, PlayerY, i);
        }

        else {
            if (clock2.getElapsedTime().asMilliseconds() >= 800){
                ++j;
                if (j > 4){
                    j = 1;
                }
                clock2.restart();
            }
            sprite.LoadSprite(PlayerStand, window, PlayerX, PlayerY, j);
        }
        if(PlayerX >= 2048 ){
            PlayerX = 1;
        } 
        if(PlayerX <= 0){
            PlayerX = 2047;
        }
        window.display();
    }
    
    return 0;
}
