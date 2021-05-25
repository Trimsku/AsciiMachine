#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <math.h>

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
    int convertStringToInt(std::string rgb); 
    int getFileAnimationsCount(std::string path_to_file);

} // namespace ascii