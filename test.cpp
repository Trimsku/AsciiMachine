#include <iostream>
#include <fstream>
#include <unistd.h>
#include <math.h>
#include <SFML/Graphics.hpp>
#include "cutFunctions.cpp"
#include "Sprites.cpp"


int main(){
    sf::Font font;
    std::string A = GetSpriteResources("textures/Tree.txt");
    std::string B = GetSpriteResources("textures/PlayerStand.txt");
    std::string C = GetSpriteResources("textures/PlayerRunLeft.txt");
    std::string D = GetSpriteResources("textures/PlayerRunRight.txt");
    std::string E = GetSpriteResources("textures/Pics.txt");
    std::string F = GetSpriteResources("textures/Home.txt");
    std::string G = GetSpriteResources("textures/Tree1.txt");
    std::string H = GetSpriteResources("textures/shrub.txt");
    //std::string E = GetSpriteResources("textures/road.txt");
    font.loadFromFile("fonts/10894.otf");
    sf::Text Tree0(A, font,50);
    sf::Text Tree1(G, font, 40);
    sf::Text Shrub(H, font, 50);
    sf::Text PlayerStand(B, font,50);
    sf::Text PlayerRunLeft(C, font,50);
    sf::Text PlayerRunRight(D, font,50);
    sf::Text Road("[#1[@7, 82, 0]_#1]", font, 50);
    sf::Text Pic(E, font, 50);
    sf::Text Home(F, font, 50);
    float PlayerY = 1024-PlayerRunLeft.getCharacterSize()*4, PlayerX = 200;
    
    PlayerRunRight.setStyle(sf::Text::Italic);
    PlayerRunLeft.setStyle(sf::Text::Italic);
    Tree0.setStyle(sf::Text::Italic);
    Tree1.setStyle(sf::Text::Italic);
    sf::Clock clock;
    sf::Clock clock1;
    sf::Clock clock2;
    int i = 1;
    int j = 1;
    sf::RenderWindow window(sf::VideoMode(2048, 1024), "I am testing, sorry program.");
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
            LoadSprite(Road, window, i, 970);
        }
        LoadSprite(Tree1, window, 0, 460);
        LoadSprite(Shrub, window, 0,875);
        LoadSprite(Shrub, window, 500,875);
        LoadSprite(Shrub, window, 800,875);
        LoadSprite(Shrub, window, 1500,875);
        LoadSprite(Shrub, window, 1400,875);
        LoadSprite(Pic, window, 1200, 550);
        LoadSprite(Home, window, 1500, 350);
        // Render Player
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            j=0;
            PlayerX+=0.4; 
            LoadSprite(PlayerRunRight, window, PlayerX, PlayerY, i);
        }

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            j=0;
            PlayerX-=0.3; 
            LoadSprite(PlayerRunLeft, window, PlayerX, PlayerY, i);
        }

        else {
            if (clock2.getElapsedTime().asMilliseconds() >= 800){
                ++j;
                if (j > 4){
                    j = 1;
                }
                clock2.restart();
            }
            LoadSprite(PlayerStand, window, PlayerX, PlayerY-50, j);
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
