#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>
namespace ascii{
    
    class Object{
        private:
            //Make a miltiple add sf::Text.
            std::string Name;
        public:
            std::vector<sf::Text> sprites; 
            int x,y;
            Object(std::string Name);
            void SetHitbox(int x1, int y1);
            void SetSprite(sf::Text name); // Save class sprites.
            std::string getName();
    };
    #include "Object.cpp"

}