#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <math.h>
#include <vector>
#include <SFML/Graphics.hpp>
#if WIN32
    #include <window.h>
#else
    #include <X11/Xlib.h>
#endif

#define SIG_BREAK 1
#define SIG_ERR 0

#define EVENT \
    sf::Event event; \
    while (window.pollEvent(event)){ \
        if (event.type == sf::Event::Closed) \
            window.close(); \
    }
#define EVENT_CLOSED(KeyC) \
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::KeyC)) window.close();

namespace ascii {

    std::string getFileResources(std::string path_to_file);
    template<typename T>
    T convertStringToInt(std::string rgb){
        T torgb = 0;
        for(T i = 0; i < rgb.length(); i++){
            torgb += static_cast<T>(rgb[i] * pow(10, rgb.length() - i - 1)); 
        }
        return torgb;
    } 
    int getFileAnimationsCount(std::string path_to_file);
    signed int getChunkX(signed int global_x);
    signed int getChunkY(signed int global_y);

    int getDisplayWidth();
    int getDisplayHeight();

    // Sprite utils
    int getMaxCol(sf::Text sprite, int SpriteNum = 1);
    int getRows(sf::Text TextR, int SpriteNum = 1);
    bool isOneSprite(std::string fsprite);

} // namespace ascii