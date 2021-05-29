#pragma once
#include <SFML/Graphics.hpp>
sf::RenderWindow window(sf::VideoMode(1920,1080), "test");
#define ENABLE_GUI_BASE
#define OBJECT_COUNT_ERROR "SIZE IS MORE THAN SIZE OF SPRITES."
#include "Log.hpp"
ascii::Log logs("log.txt");
