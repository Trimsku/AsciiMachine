#pragma once
#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "utils.hpp"
#include "assertvariables.hpp"
namespace ascii
{
    
    class Sprite{
        public:
            Sprite();
            ~Sprite();
            std::string GetSpriteResources(std::string PathToSprite);
            void LoadSprite(sf::Text sprite, sf::RenderWindow& window, float x, float y, int SpriteNum);

    };
    #include "Sprites.cpp"
} // namespace ascii