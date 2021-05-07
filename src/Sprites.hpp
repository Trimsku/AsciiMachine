/***************************************************
****************************************************
AsciiMachine - Engine for create ascii games. Enjoy!
AsciiMachine is a free game engine, but you are:
    1. Don't copyright product. 

        You cannot to pose as an a project as your own 
        without the permission of Trimsky.

    2. You cannot to pose as an modified versions as your own.

If these conditions are met, you can use the product.
Copyright 2021-2021
*****************************************************
****************************************************/

#pragma once
#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "utils.hpp"
#include "GlobalVars.hpp"
namespace ascii
{
    
    class Sprite{
        public:
            Sprite();
            ~Sprite();
            void loadSprite(sf::Text sprite, float x, float y, int SpriteNum);
            //void LoadSprite(sf::Text sprite, sf::RenderWindow& window, std::string x, std::string y, int SpriteNum);
    };
    #include "Sprites.cpp"
} // namespace ascii